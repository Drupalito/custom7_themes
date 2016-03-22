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
 * @see hook_preprocess()
 */
function astarter_preprocess_links(&$variables) {
  // Change modifier classes to use BEM syntax.
  if (isset($variables['attributes']['class'])) {
    $variables['attributes']['class'] = preg_replace('/^inline$/', 'list-inline', $variables['attributes']['class']);
  }
}
