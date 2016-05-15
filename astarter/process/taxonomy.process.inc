<?php

/**
 * @file
 * Contains a process hook for 'taxonomy'.
 */

/**
 * Implements hook_process_taxonomy().
 *
 * Override or insert variables into the taxonomy templates.
 *
 * @see hook_process()
 */
function astarter_process_taxonomy(&$variables, $hook) {
  // Flatten out html_attributes.
  $variables['title_attributes'] = drupal_attributes($variables['title_attributes_array']);
}
