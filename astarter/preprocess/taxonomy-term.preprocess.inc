<?php

/**
 * @file
 * Contains a pre-process hook for 'taxonomy_term'.
 */

/**
 * Implements hook_preprocess_taxonomy_term().
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see hook_preprocess()
 * @see hook_preprocess_taxonomy_term()
 */
function astarter_preprocess_taxonomy_term(&$variables) {
  $view_mode = drupal_html_class($variables['view_mode']);
  $machine_name = drupal_html_class($variables['vocabulary_machine_name']);

  $variables['attributes_array']['class'] = array(
    'taxonomy-term--' . $machine_name,
    'taxonomy-term--' . $view_mode,
    'taxonomy-term--' . $machine_name . '--' . $view_mode,
  );

  $variables['title_attributes_array']['class'][] = 'taxonomy__title';
  $variables['content_attributes_array']['class'][] = 'taxonomy__content';
}
