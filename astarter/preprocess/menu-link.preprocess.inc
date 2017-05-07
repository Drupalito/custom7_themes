<?php

/**
 * @file
 * Contains a pre-process hook for 'menu_link'.
 */

/**
 * Implements hook_preprocess_menu_link().
 *
 * Intercepts the links to change inline class to list-inline.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see hook_preprocess()
 * @see hook_preprocess_menu_link()
 */
function astarter_preprocess_menu_link(&$variables) {
  // Reference the menu item
  $element = &$variables['element'];
  // If the path the menu links to is 'my_account', and
  // The user is on their account page, add a class of
  // .active to the menu item
  $homeicon = theme_get_setting('astarter_menu_home_item');
  if(!empty($homeicon) && $element['#href'] == '<front>' && $element['#title'] == 'Home') {
    $element['#title'] = '<span class="i i-home" aria-hidden="true"></span>';
  }
}
