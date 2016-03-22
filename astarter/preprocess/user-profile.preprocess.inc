<?php

/**
 * @file
 * Contains a pre-process hook for 'user'.
 */

/**
 * Implements hook_preprocess_user_profile_category().
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_user_profile(&$variables) {
  $variables['attributes_array']['class'][] = 'profile';
}
