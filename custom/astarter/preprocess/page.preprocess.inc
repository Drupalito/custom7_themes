<?php

/**
 * @file
 * Contains a pre-process hook for 'page'.
 */

/**
 * Implements hook_preprocess_page().
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_page(&$variables) {
  $status = drupal_get_http_header("status");

  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__node__' . $variables['node']->type;
  }
  // If is 404
  if ($status == "404 Not Found") {
    $variables['theme_hook_suggestions'][] = 'page__404';
  }

  // If is Frontpage
  if (arg(0) == 'user' || drupal_is_front_page() || $status == "404 Not Found") {
    // Layout
    unset($variables['page']['sidebar_first']);
    unset($variables['page']['sidebar_second']);
  }

  $variables['main_prefix'] = array();
  $variables['main_suffix'] = array();

  $variables['content_attributes_array']['id'] = 'content';
  $variables['title_attributes_array']['class'][] = 'main__title';

  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    // Layout
    $variables['content_attributes_array']['class'][] = 'col-xs-12';
    $variables['content_attributes_array']['class'][] = 'col-sm-4';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    // Layout
    $variables['content_attributes_array']['class'][] = 'col-xs-12';
    $variables['content_attributes_array']['class'][] = 'col-sm-8';
  }
  else {
    // Layout
    $variables['content_attributes_array']['class'][] = 'col-xs-12';
  }

  // If is page node article
  if (isset($variables['node']->nid) && $variables['node']->type == 'article') {
    // Add div on first
    $variables['title_attributes_array']['itemprop'] = 'name';
    array_unshift($variables['main_prefix'], array('#markup' => '<div itemscope itemtype="http://schema.org/BlogPosting">'));
    // Close div on end
    array_push($variables['main_suffix'], array('#markup' => '</div>'));
  }

  // If page different to frontpage
  if (!drupal_is_front_page()) {
    // Add div on first
    array_unshift($variables['title_prefix'], array('#markup' => '<div class="main__header">'));
    // Close div on end
    array_push($variables['title_suffix'], array('#markup' => '</div>'));
  }
}
