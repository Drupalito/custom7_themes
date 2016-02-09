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
function astarter_preprocess_comment(&$variables, $hook) {

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

  // If comment subjects are disabled, don't display them.
  if (variable_get('comment_subject_field_' . $variables['node']->type, 1) == 0) {
    $variables['title'] = '';
  }

  $comment_class_extend = '';
  // Zebra striping.
  if ($variables['id'] == 1) {
    $comment_class_extend = 'comment-first first';
  }

  if (isset($variables['node']->comment_count) && $variables['id'] == $variables['node']->comment_count) {
    $comment_class_extend = 'comment-last last';
  }

  $variables['classes_array'][] = $comment_class_extend;

  // Check if a commenter is registered. If true then add a class showing so and
  // also add a class to allow styling based on commenter name. Otherwise flag
  // the commenter as anonymous.
  if ($variables['comment']->uid > 0) {
    $variables['classes_array'][]  = 'comment-author-' . strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $variables['comment']->registered_name));
  }
  else {
    $variables['classes_array'][]  = 'comment-author-anonymous';
  }

  $variables['classes_array'] = preg_replace('/^comment-/', 'comment--', $variables['classes_array']);

  $variables['classes_array'][] = $variables['zebra'];

  // $variables['title_attributes_array']['class'][] = 'comment__title';
  $variables['content_attributes_array']['class'][] = 'comment__description';
  $variables['content_attributes_array']['class'][] = ' col-xs-12 col-sm-9';
  $variables['content_attributes_array']['itemprop'][] = 'commentText';

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
