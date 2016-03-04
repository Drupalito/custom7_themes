<?php

/**
 * @file
 * Contains the theme function override for 'menu_local_tasks'.
 */

/**
 * Implements theme_menu_local_tasks().
 *
 * Remove Title Hn
 *
 * @ingroup themeable
 */
function astarter_menu_local_tasks(array $variables) {
  global $user;

  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '';
    $variables['primary']['#prefix'] .= '<ul class="tabs tabs--primary primary">';
    $variables['primary']['#suffix'] = '</ul></div>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}
