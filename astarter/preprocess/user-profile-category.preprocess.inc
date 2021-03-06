<?php

/**
 * @file
 * Contains a pre-process hook for 'user'.
 */

/**
 * Implements hook_preprocess_user_profile_category().
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see hook_preprocess()
 * @see hook_preprocess_user_profile_category()
 */
function astarter_preprocess_user_profile_category(&$variables) {
  $variables['title_attributes_array']['class'][] = 'profile__title';
  $variables['attributes_array']['class'][] = 'definition-inline';
  $variables['attributes_array']['class'][] = 'profile__list';
  $variables['attributes_array']['class'][] = 'profile__list--category-' . drupal_html_class($variables['title']);
}
