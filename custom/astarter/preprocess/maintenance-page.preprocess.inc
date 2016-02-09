<?php

/**
 * @file
 * Contains a pre-process hook for 'maintenance_page'.
 */

/**
 * Implements hook_preprocess_maintenance_page().
 *
 * Override or insert variables into the maintenance page template.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_maintenance_page(&$variables, $hook) {
  astarter_preprocess_html($variables, $hook);
  // There's nothing maintenance-related in astarter_preprocess_page(). Yet.
  // astarter_preprocess_page($variables, $hook);
}
