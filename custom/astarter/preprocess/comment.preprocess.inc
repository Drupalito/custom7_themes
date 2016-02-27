<?php

/**
 * @file
 * Contains a pre-process hook for 'comment'.
 */

/**
 * Implements hook_preprocess_comment().
 *
 * Override or insert variables into the comment templates.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_comment(&$variables) {

  // Added ID to each comment.
  $variables['attributes_array']['id'][] = 'comment-' . $variables['comment']->cid;

  $variables['attributes_array']['itemscope'][] = 'itemscope';
  $variables['attributes_array']['itemtype'][] = 'http://schema.org/UserComments';

  // Helpful $content variable for templates.
  if (!empty($variables['comment']->pid)) {
    $variables['attributes_array']['itemprop'][] = 'discusses';
  }
  else {
    $variables['attributes_array']['itemprop'][] = 'comment';
  }

  $variables['picture'] = !empty($variables['picture']) ? '<span class="mrm">' . theme('user_picture', array('account' => $variables['elements']['#comment'])) . '</span>' : '';

  // If comment subjects are disabled, don't display them.
  if (variable_get('comment_subject_field_' . $variables['node']->type, 1) == 0) {
    $variables['title'] = '';
  }

  // Zebra striping.
  if ($variables['id'] == 1) {
    $variables['classes_array'][] = 'comment-first';
    $variables['classes_array'][] = 'first';
  }

  if (isset($variables['node']->comment_count) && $variables['id'] == $variables['node']->comment_count) {
    $variables['classes_array'][] = 'comment-last';
    $variables['classes_array'][] = 'last';
  }

  $variables['classes_array'] = preg_replace('/^comment-/', 'comment--', $variables['classes_array']);

  $variables['classes_array'][] = $variables['zebra'];

  // Add pubdate to submitted variable.
  $variables['pubdate'] = $variables['created'];
  $variables['submitted'] = t('!username replied on !datetime', array('!username' => $variables['author'], '!datetime' => $variables['pubdate']));

  // Clean reply link.
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['id'] = 'comment-' . $variables['comment']->cid . '-reply';
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['itemprop'] = 'replyToUrl';
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['rel'] = 'nofollow';
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['class'][] = 'comment__link';

  // Add Title to reply link.
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['title'] = t('Reply to comment !username of !date at !time', array(
    '!username' => $variables['author'],
    '!date' => format_date($variables['comment']->created, 'custom', 'd/m/Y'),
    '!time' => format_date($variables['comment']->created, 'custom', 'H:i'),
    )
  );
}
