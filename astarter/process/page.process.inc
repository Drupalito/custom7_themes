<?php

/**
 * @file
 * Contains a process hook for 'page'.
 */

/**
 * Implements hook_process_page().
 *
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the bootstrap hook to invoke.
 * @see hook_process()
 */
function astarter_process_page(&$variables, $hook) {
  // Flatten out html_attributes.
  $variables['content_attributes'] = drupal_attributes($variables['content_attributes_array']);
}
