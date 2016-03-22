<?php

/**
 * @file
 * Contains a pre-process hook for 'webform'.
 */

/**
 * Implements template_preprocess_webform_element().
 *
 * Override or insert variables into the block templates.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_webform_element(&$variables) {
  $element = &$variables['element'];

  // Ensure defaults.
  $element += array(
    '#title_display' => 'before',
    '#wrapper_attributes' => array(
      'class' => array(),
    ),
  );

  // All elements using this for display only are given the "display" type.
  if (isset($element['#format']) && $element['#format'] == 'html') {
    $type = 'display';
  }
  else {
    $type = ($element['#webform_component']['type'] == 'select' && isset($element['#type'])) ? $element['#type'] : $element['#webform_component']['type'];
  }

  // Convert the parents array into a string, excluding the "submitted" wrapper.
  $nested_level = $element['#parents'][0] == 'submitted' ? 1 : 0;
  $parents = str_replace('_', '-', implode('--', array_slice($element['#parents'], $nested_level)));

  // Build up a list of classes to apply on the element wrapper.
  $wrapper_classes = array(
    'form-item',
    'webform-component',
    'webform-component-' . str_replace('_', '-', $type),
    'webform-component--' . $parents,
  );

  if (isset($element['#title_display']) && in_array($element['#title_display'], array('above', 'before'))) {
    // $wrapper_classes[] = 'webform-container-inline';
    $wrapper_classes[] = 'form-item--block';
  }

  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#webform_component']['extra']['disabled'])) {
    $wrapper_classes[] = 'form-item--disabled';
  }

  // Add class error input.
  if (isset($element['#parents']) && form_get_error($element)) {
    $wrapper_classes[] = 'has--error';
  }

  $element['#wrapper_attributes']['class'] = array_merge($element['#wrapper_attributes']['class'], $wrapper_classes);

  // If #title_display is none, set it to invisible instead - none only used if
  // we have no title at all to use.
  if ($element['#title_display'] == 'none') {
    $variables['element']['#title_display'] = 'invisible';
    $element['#title_display'] = 'invisible';
    if (empty($element['#attributes']['title']) && !empty($element['#title'])) {
      $element['#attributes']['title'] = $element['#title'];
    }
  }

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
}
