<?php

/**
 * @file
 * Contains a process hook for 'maintenance_page'.
 */

/**
 * Implements hook_process_maintenance_page().
 *
 * Override or insert variables into the maintenance page template.
 *
 * @see hook_process()
 */
function astarter_process_maintenance_page(&$variables, $hook) {
  astarter_process_html($variables, $hook);
  // Ensure default regions get a variable.
  // Theme authors often forget to remove
  // a deleted region's variable in maintenance-page.tpl.

  $regions_availables = array(
    'header',
    'navigation',
    'highlighted',
    'help',
    'content',
    'sidebar_first',
    'sidebar_second',
    'footer',
    'bottom',
  );

  foreach ($regions_availables as $region) {
    if (!isset($variables[$region])) {
      $variables[$region] = '';
    }
  }
}
