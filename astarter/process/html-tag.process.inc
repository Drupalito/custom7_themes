<?php

/**
 * @file
 * Contains a process hook for 'html_tag'.
 */

/**
 * Implements hook_process_html_tag().
 *
 * Override or insert variables in the html_tag theme function.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the bootstrap hook to invoke.
 * @see hook_process()
 */
function astarter_process_html_tag(&$variables) {
  if (in_array($variables['element']['#tag'], array('script', 'style'))) {
    // Remove type="something" and CDATA prefix/suffix.
    unset($variables['element']['#attributes']['type'], $variables['element']['#value_prefix'], $variables['element']['#value_suffix']);

    if (isset($variables['element']['#attributes']['media']) && $variables['element']['#attributes']['media'] == 'all') {
      // Remove media="all" but leave others unaffected.
      unset($variables['element']['#attributes']['media']);
    }
  }
}
