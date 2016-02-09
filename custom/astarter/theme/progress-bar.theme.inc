<?php

/**
 * @file
 * Contains the theme function override for 'progress_bar'.
 */

/**
 * Implements theme_progress_bar().
 *
 * Change output HTML
 *
 * @ingroup themeable
 */
function astarter_progress_bar($variables) {
  $output = '<div id="progress" class="progress">';
  $output .= '<div class="bar"><div class="filled" style="width: ' . $variables['percent'] . '%"></div></div>';
  $output .= '<div class="percentage"><p class="bold mvn">' . $variables['percent'] . '%</p></div>';
  $output .= '<div class="message"><p class="mvn">' . $variables['message'] . '</p></div>';
  $output .= '</div>';

  return $output;
}
