<?php

/**
 * @file
 * Contains the theme function override for 'tablesort_indicator'.
 */

/**
 * Implements hook_tablesort_indicator().
 *
 * Change image with icon font
 *
 * @ingroup themeable
 */
function astarter_tablesort_indicator($variables) {
  if ($variables['style'] == "asc") {
    $output = '<span class="i i-arrow-down2" aria-hidden="true"></span>';
    return $output;
  }
  else {
    $output = '<span class="i i-arrow-up2" aria-hidden="true"></span>';
    return $output;
  }
}
