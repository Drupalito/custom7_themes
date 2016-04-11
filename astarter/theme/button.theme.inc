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

  if (isset($element['#attributes']['id'])) {

    if (strstr($element['#attributes']['id'], 'edit-submit-') != FALSE || strstr($element['#attributes']['id'], 'edit-actions-submit') != FALSE) {
      $element['#attributes']['class'][] = 'btn--edit-submit';
    }
    if (strstr($element['#attributes']['id'], 'edit-add') != FALSE) {
      $element['#attributes']['class'][] = 'btn--edit-add';
    }
    if (strstr($element['#attributes']['id'], 'edit-delete') != FALSE) {
      $element['#attributes']['class'][] = 'btn--edit-add';
    }

    $element['#attributes']['class'][] = 'btn--' . $element['#attributes']['id'];
  }

  $element['#attributes']['class'] = array_unique($element['#attributes']['class']);

  return '<button' . drupal_attributes($element['#attributes']) . '>' . $label . '</button>';
}
