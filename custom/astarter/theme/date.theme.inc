<?php

/**
 * @file
 * Contains the theme function override for 'date'.
 */

/**
 * Implements theme_date().
 *
 * Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date($variables) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'container-inline';

  return '<div' . drupal_attributes($attributes) . '>' . drupal_render_children($element) . '</div>';
}

/**
 * @file
 * Theme files for Date API.
 */

/**
 * Returns HTML for a date timezone element.
 *
 * TODO : Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date_timezone($variables) {
  $element = $variables['element'];
  $attributes = $element['#attributes'];
  $wrapper_attributes = array();
  // Add an wrapper to mimic the way a single value field works, for ease in
  // using #states.
  if (isset($element['#children'])) {
    $element['#children'] = '<div id="' . $element['#id'] . '" ' . drupal_attributes($wrapper_attributes) . '>' . $element['#children'] . '</div>';
  }
  return '<div ' . drupal_attributes($attributes) . '>' . theme('form_element', $element) . '</div>';
}

/**
 * Returns HTML for a date select element.
 *
 * TODO : Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date_select($variables) {
  $element = $variables['element'];
  $attributes = !empty($element['#wrapper_attributes']) ? $element['#wrapper_attributes'] : array('class' => array());
  $attributes['class'][] = 'container-inline-date';
  $wrapper_attributes = array('class' => array('date-padding'));
  $wrapper_attributes['class'][] = 'clearfix';
  // Add an wrapper to mimic the way a single value field works, for ease in
  // using #states.
  if (isset($element['#children'])) {
    $element['#children'] = '<div id="' . $element['#id'] . '" ' . drupal_attributes($wrapper_attributes) . '>' . $element['#children'] . '</div>';
  }
  return '<div ' . drupal_attributes($attributes) . '>' . theme('form_element', $element) . '</div>';
}

/**
 * Returns HTML for a date text element.
 *
 * TODO : Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date_text($variables) {
  $element = $variables['element'];
  $attributes = !empty($element['#wrapper_attributes']) ? $element['#wrapper_attributes'] : array('class' => array());
  $attributes['class'][] = 'container-inline-date';
  // If there is no description, the floating date elements need some extra
  // padding below them.
  $wrapper_attributes = array('class' => array('date-padding'));
  if (empty($element['date']['#description'])) {
    $wrapper_attributes['class'][] = 'clearfix';
  }
  // Add an wrapper to mimic the way a single value field works, for ease in
  // using #states.
  if (isset($element['#children'])) {
    $element['#children'] = '<div id="' . $element['#id'] . '" ' . drupal_attributes($wrapper_attributes) . '>' . $element['#children'] . '</div>';
  }
  return '<div ' . drupal_attributes($attributes) . '>' . theme('form_element', $element) . '</div>';
}

/**
 * Returns HTML for a date select input form element.
 *
 * TODO : Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date_select_element($variables) {
  $element = $variables['element'];
  $parents = $element['#parents'];
  $part = array_pop($parents);
  return '<div class="date-' . $part . '">' . theme('select', $element) . '</div>';
}

/**
 * Returns HTML for a date textfield input form element.
 *
 * TODO : Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date_textfield_element($variables) {
  $element = $variables['element'];
  $parents = $element['#parents'];
  $part = array_pop($parents);
  return '<div class="date-' . $part . '">' . theme('textfield', $element) . '</div>';
}

/**
 * Returns HTML for a 'hour' date part prefix.
 *
 * TODO : Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date_part_hour_prefix($variables) {
  $element = $variables['element'];
  if ($element['#date_label_position'] != 'above') {
    return '<span class="form-item date-spacer">&nbsp;-&nbsp;</span>';
  }
}

/**
 * Returns HTML for a 'minutes and seconds' date part prefix.
 *
 * TODO : Initial function theme
 *
 * @ingroup themeable
 */
function astarter_date_part_minsec_prefix($variables) {
  $element = $variables['element'];
  if ($element['#date_label_position'] != 'above') {
    return '<span class="form-item date-spacer">:</span>';
  }
}
