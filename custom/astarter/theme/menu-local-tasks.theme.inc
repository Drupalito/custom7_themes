<?php

/**
 * @file
 * Contains the theme function override for 'menu_link'.
 */

/**
 * Implements theme_menu_link().
 *
 * Remove Title Hn
 *
 * @ingroup themeable
 */
function astarter_menu_local_tasks(array $variables) {
  global $user;

  $output = '';

  if (!empty($variables['primary']) && arg(0) == 'user') {

    $variables['primary']['#prefix'] = '';
    $variables['primary']['#prefix'] .= '<ul class="tabs tabs--user">';
    $variables['primary']['#suffix'] = '</ul></div>';
    $output .= drupal_render($variables['primary']);
  }
  else if (!empty($variables['primary'])) {
    // $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] = '';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
     // $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] = '';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}
