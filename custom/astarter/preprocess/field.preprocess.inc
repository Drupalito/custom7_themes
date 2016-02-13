<?php

/**
 * @file
 * Contains a pre-process hook for 'field'.
 */

/**
 * Implements hook_preprocess_field().
 *
 * Intercepts the links to change inline class to list-inline.
 *
 * Exemple to use : Create another function :
 *   astarter_preprocess_field__FIELD_NAME
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_field(&$variables) {
  $function = __FUNCTION__ . '__' . $variables['element']['#field_name'];
  if (function_exists($function)) {
    $function($variables);
  }

  // Change field classes to use BEM syntax.
  $variables['classes_array'] = preg_replace('/^field-(?!-)/', 'field--', $variables['classes_array']);
  $variables['label_display_css'] = drupal_clean_css_identifier($variables['element']['#label_display']);
}
