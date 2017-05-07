<?php

/**
 * @file
 * Contains a pre-process hook for 'region'.
 */

/**
 * Implements hook_preprocess_region().
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the theme hook being called ("node" in this case).
 * @see hook_preprocess()
 * @see hook_preprocess_region()
 */
function astarter_preprocess_region(&$variables, $hook) {
  // Sidebar regions get some extra classes and a common template suggestion.
  if (strpos($variables['region'], 'sidebar_') === 0) {
    unset($variables['classes_array'][0]);
    unset($variables['classes_array'][1]);
    array_unshift($variables['theme_hook_suggestions'], 'region__no_wrapper');
  }
  // Use a template with no wrapper for the content region.
  elseif (
    $variables['region'] == 'header' ||
    $variables['region'] == 'navigation' ||
    $variables['region'] == 'content' ||
    $variables['region'] == 'footer'
  ) {
    unset($variables['classes_array'][1]);
    array_unshift($variables['theme_hook_suggestions'], 'region__no_wrapper');
  }
  elseif ($variables['region'] == 'breadcrumb') {
    unset($variables['classes_array'][0]);
    unset($variables['classes_array'][1]);
    $variables['classes_array'][] = 'breadcrumb';
    $variables['classes_array'][] = 'col-xs-12';
  }
}
