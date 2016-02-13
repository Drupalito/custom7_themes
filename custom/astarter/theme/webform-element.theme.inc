<?php

/**
 * @file
 * Contains the theme function override for 'textfield'.
 */

/**
 * Implements theme_form_element().
 *
 * Change description
 * Change class name
 * Add class error field
 *
 * @ingroup themeable
 */
function astarter_webform_element($variables) {
  $element = $variables['element'];

  // managed_file uses a different id, make sure the label points to the correct id.
  if (isset($element['#type']) && $element['#type'] === 'managed_file') {
    if (!empty($variables['element']['#id'])) {
      $variables['element']['#id'] .= '-upload';
    }
  }

  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $element['#wrapper_attributes']['class'][] = 'form-item--disabled';
  }

  // Add class error input
  if (isset($element['#parents']) && form_get_error($element)) {
    $element['#wrapper_attributes']['class'][] = 'has--error';
  }

  $output = '<div ' . drupal_attributes($element['#wrapper_attributes']) . '>' . "\n";
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . webform_filter_xss($element['#field_prefix']) . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . webform_filter_xss($element['#field_suffix']) . '</span>' : '';

  switch ($element['#title_display']) {
    case 'inline':
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<small class="description show">' . $element['#description'] . "</small>\n";
  }

  $output .= "</div>\n";

  return $output;
}
