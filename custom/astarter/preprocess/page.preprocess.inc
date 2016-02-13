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
    // Remove sidebar left
    unset($variables['page']['sidebar_first']);
    unset($variables['page']['sidebar_second']);
  }

  if (drupal_is_front_page()) {
    // Remove sidebar left
    $variables['content_column_class'] = ' class="col-xs-12"';
    unset($variables['page']['sidebar_first']);
    unset($variables['page']['sidebar_second']);
  }

  // if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
  //   unset($variables['page']['content']['system_main']['term_heading']['#prefix']);
  //   unset($variables['page']['content']['system_main']['term_heading']['#suffix']);
  // }

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
    // itemscope itemtype="http://schema.org/BlogPosting"
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

  // if ((arg(0) == 'search')) {

  //   // Search.module shows 10 items per page (this isn't customizable).
  //   $items_per_page = 10;

  //   // Determine which page is being viewed.
  //   // If $_REQUEST['page'] is not set, we are on page 1.
  //   $current_page = (isset($_REQUEST['page']) ? $_REQUEST['page'] : 0) + 1;

  //   // Get the total number of results from the global pager.
  //   global $pager_total_items;
  //   $total = $pager_total_items[0];

  //   // Determine which results are çbeing shown.
  //   // ("Showing results x through y").
  //   $start = (10 * $current_page) - 9;
  //   // If on the last page, only go up to $total, not the total that COULD be.
  //   // shown on the page. This prevents things like "Displaying 11-20 of 17".
  //   $end = (($items_per_page * $current_page) >= $total) ? $total : ($items_per_page * $current_page);

  //   // If there is more than one page of results.
  //   if ($total > $items_per_page) {
  //     $variables['title'] = t('!total results for your search', array(
  //       '!start' => $start,
  //       '!end'   => $end,
  //       '!total' => $total,
  //     ));
  //   }
  //   else {
  //     if (!empty($total)) {
  //       // Only one page of results, so make it simpler.
  //       $variables['title'] = t('!results_label for "!search_term"', array(
  //         '!total' => !empty($total) ? $total : t('No'),
  //         // Be smart about labels: show "result" for one, "results" for multiple.
  //         '!results_label' => format_plural($total, t('@count result'), t('@count results')),
  //         '!search_term' => _get_current_search_terms(),
  //       ));
  //     }
  //     else {
  //       $variables['title'] = t('No result for "!search_term"', array(
  //         '!search_term' => _get_current_search_terms(),
  //       ));
  //     }
  //   }
  // }
}
