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

  // Enable logo module for display logo.
  $variables['site_logo'] = module_exists('logo') ? theme('logo') : NULL;

  if (module_exists('token')) {
    $variables['content'] = token_replace($variables['content']);
  }
}
