<?php

/**
 * @file progress-bar.theme.inc
 * Contains the theme function override for 'progress_bar'.
 */

/**
 * Implements theme_progress_bar().
 *
 * Change output HTML
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see theme_progress_bar()
 * @ingroup themeable
 */
function astarter_progress_bar($variables) {
  $output = '<div id="progress" class="progress">';
  $output .= '<div class="bar"><div class="filled" style="width: ' . $variables['percent'] . '%"></div></div>';
  $output .= '<div class="percentage"><p class="bold my-0">' . $variables['percent'] . '%</p></div>';
  $output .= '<div class="message"><p class="my-0">' . $variables['message'] . '</p></div>';
  $output .= '</div>';

  return $output;
}
