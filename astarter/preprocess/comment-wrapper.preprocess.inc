<?php

/**
 * @file
 * Contains a pre-process hook for 'comment_wrapper'.
 */

/**
 * Implements hook_preprocess_comment_wrapper().
 *
 * Override or insert variables into the comment wrapper templates.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_comment_wrapper(&$variables) {

  $variables['attributes_array']['id'] = 'comments';

  $variables['attributes_array']['class'][] = 'comments';
  $variables['attributes_array']['class'][] = 'clearfix';

  $variables['title_attributes_array']['class'][] = 'comments__title';
  $variables['form_title_attributes_array']['class'][] = 'comments__title';
  $variables['form_title_attributes_array']['class'][] = 'commentsAdd__title';

  if (isset($variables['content']['comment_form']['#node'])) {
    array_splice($variables['attributes_array']['class'], 1, 0, array('comments--' . $variables['content']['comment_form']['#node']->type));
  }
}
