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
function astarter_preprocess_user_profile(&$variables) {
  $variables['attributes_array']['class'][] = 'profile';
}
