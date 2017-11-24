<?php

/**
 * @file
 * Contains the theme function override for 'from_required_marker'.
 */

/**
 * Implements theme_form_required_marker().
 *
 * Change `span` to `abbr`
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see theme_form_required_marker()
 * @ingroup themeable
 */
function astarter_form_required_marker($variables) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();
  $attributes = array(
    'class' => 'field-required',
    'title' => $t('This field is required.'),
  );
  return '<abbr' . drupal_attributes($attributes) . '>*</abbr>';
}
