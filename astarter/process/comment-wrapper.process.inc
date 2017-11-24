<?php

/**
 * @file
 * Contains a process hook for 'comment_wrapper'.
 */

/**
 * Implements hook_process_comment_wrapper().
 *
 * Override or insert variables into the comment wrapper templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the bootstrap hook to invoke.
 * @see hook_process()
 */
function astarter_process_comment_wrapper(&$variables) {
  // Flatten the attributes array.
  $variables['form_title_attributes'] = drupal_attributes($variables['form_title_attributes_array']);
}
