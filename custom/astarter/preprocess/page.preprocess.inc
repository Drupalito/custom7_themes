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

  if ($status == "404 Not Found") {
    $variables['theme_hook_suggestions'][] = 'page__404';
    // Remove sidebar left.
    unset($variables['page']['sidebar_first']);
    unset($variables['page']['sidebar_second']);
  }

  if (drupal_is_front_page()) {
    // Remove sidebar left.
    $variables['content_column_class'] = ' class="col-xs-12"';
    unset($variables['page']['sidebar_first']);
    unset($variables['page']['sidebar_second']);
  }

  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-xs-12 col-sm-4"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-xs-12 col-sm-8"';
  }
  else {
    $variables['content_column_class'] = ' class="col-xs-12 col-sm-12"';
  }

  $variables['title_attributes_array']['class'][] = 'main__title';

  if (isset($variables['node']->nid) && $variables['node']->type == 'article') {
    $variables['main_prefix'] = '<div itemscope itemtype="http://schema.org/BlogPosting">';
    $variables['main_suffix'] = '</div>';
    $variables['title_attributes_array']['itemprop'] = 'name';
  }

  if (arg(0) == 'user') {
    $variables['title_prefix'] = '<div class="main__header">';
  }
  else {
    if (!drupal_is_front_page()) {
      $variables['title_prefix'] = '<div class="main__header">';
      $variables['title_suffix'] = '</div>';
    }
  }
}
