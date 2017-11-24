<?php

/**
 * @file
 * Contains a process hook for 'html'.
 */

/**
 * Implements hook_process_html().
 *
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the bootstrap hook to invoke.
 * @see hook_process()
 */
function astarter_process_html(&$variables, $hook) {
  // Flatten out html_attributes.
  $variables['html_attributes'] = drupal_attributes($variables['html_attributes_array']);
}
