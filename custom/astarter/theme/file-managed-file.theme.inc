<?php

/**
 * @file
 * Contains the theme function override for 'file_managed_file'.
 */

/**
 * Implements theme_file_managed_file().
 *
 * Add default class `.btn--file`
 *
 * @ingroup themeable
 */
function astarter_file_managed_file($variables) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'form-managed-file';
  $element['fid']['#attributes']['class'][] = 'btn--file';

  // This wrapper is required to apply JS behaviors and CSS styling.
  $output = '';
  $output .= '<div' . drupal_attributes($attributes) . '>';
  $output .= drupal_render_children($element);
  $output .= '</div>';
  return $output;
}
