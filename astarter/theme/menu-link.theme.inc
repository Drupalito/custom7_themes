<?php

/**
 * @file
 * Contains the theme function override for 'menu_link'.
 */

/**
 * Implements theme_menu_link().
 *
 * Remove \n.
 *
 * @ingroup themeable
 */
function astarter_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  // Add support HTML.
  $element['#localized_options']['html'] = TRUE;

  array_unshift($element['#attributes']['class'], 'menu__item');

  // Add class if item is expanded.
  if (in_array('expanded', $element['#attributes']['class'])) {
    array_splice($element['#attributes']['class'], 1, 0, array('menu__item--expanded'));
  }

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
    // Add class if item has submenu.
    array_splice($element['#attributes']['class'], 1, 0, array('menu__item--hasmenu'));
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
}
