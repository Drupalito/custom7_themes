<?php

/**
 * @file
 * Contains a pre-process hook for 'links'.
 */

/**
 * Implements hook_preprocess_links().
 *
 * Intercepts the links to change inline class to list-inline.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see hook_preprocess()
 * @see hook_preprocess_links()
 */
function astarter_preprocess_links(&$variables) {
  // Change modifier classes to use BEM syntax.
  if (isset($variables['attributes']['class'])) {
    $variables['attributes']['class'] = preg_replace('/^inline$/', 'list-inline noprint', $variables['attributes']['class']);
  }
}
