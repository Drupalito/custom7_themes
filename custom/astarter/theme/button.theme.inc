<?php

/**
 * @file
 * Contains the theme function override for 'button'.
 */

/**
 * Implements theme_button().
 *
 * Change `input` to `button`
 * Add default class `.btn`
 * Add default class `.btn--<type>`
 *
 * @ingroup themeable
 */
function astarter_button($variables) {
  $element = $variables['element'];
  $label = check_plain($element['#value']);
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  $element['#attributes']['class'][] = 'btn';
  $element['#attributes']['class'][] = 'btn--' . $element['#button_type'];
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];

  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'btn--disabled';
  }

  $element['#attributes']['class'] = array_unique($element['#attributes']['class']);

  return '<button' . drupal_attributes($element['#attributes']) . '>' . $label . '</button>';
}
