<?php

/**
 * @file
 * Contains a pre-process hook for 'html'.
 */

/**
 * Implements hook_preprocess_html().
 *
 * Override or insert variables into the html template.
 *
 * @see hook_preprocess()
 */
function subtheme_child_preprocess_html(&$variables, $hook) {
  global $theme_key;

  // Google Font
  drupal_add_css('https://fonts.googleapis.com/css?family=Lato:400,700,400italic', array('type' => 'external'));

}
