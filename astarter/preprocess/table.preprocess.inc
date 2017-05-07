<?php

/**
 * @file
 * Contains a pre-process hook for 'table'.
 */

/**
 * Implements hook_preprocess_table().
 *
 * Add class `.table`
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see hook_preprocess()
 * @see hook_preprocess_table()
 */
function astarter_preprocess_table(&$variables) {
  if (isset($variables['attributes']['class']) && is_string($variables['attributes']['class'])) {
    // Convert classes to an array.
    $variables['attributes']['class'] = explode(' ', $variables['attributes']['class']);
  }

  $variables['attributes']['class'][] = 'table';
}
