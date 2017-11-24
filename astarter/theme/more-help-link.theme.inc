<?php

/**
 * @file
 * Contains the theme function override for 'more_help_link'.
 */

/**
 * Implements theme_more_help_link().
 *
 * Add icon
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see theme_more_help_link()
 * @ingroup themeable
 */
function astarter_more_help_link($variables) {
  return '<div class="more-link more-link-help">' . l(t('<span class="i i-help"></span> More help'), $variables['url'], array('html' => TRUE)) . '</div>';
}
