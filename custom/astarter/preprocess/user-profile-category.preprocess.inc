<?php

/**
 * @file
 * Contains a pre-process hook for 'user'.
 */

/**
 * Implements hook_preprocess_user_profile_category().
 *
 * Backports the following changes made to Drupal 8:
 * - #1190218: Convert user-profile-category.tpl.php to HTML5.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_user_profile_category(&$variables) {
  $variables['title_attributes_array']['class'][] = 'profile__title';
  $variables['attributes_array']['class'][] = 'definition-inline';
  $variables['attributes_array']['class'][] = 'profile__list';
  $variables['attributes_array']['class'][] = 'profile__list--category-' . drupal_html_class($variables['title']);
}
