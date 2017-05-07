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
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the theme hook being called ("maintenance_page" in this case).
 * @see hook_preprocess()
 * @see hook_preprocess_maintenance_page()
 */
function astarter_preprocess_maintenance_page(&$variables, $hook) {

  // Enable logo module for display logo.
  $variables['site_logo'] = module_exists('logo') ? theme('logo') : NULL;

  if (module_exists('token')) {
    $variables['content'] = token_replace($variables['content']);
  }
}
