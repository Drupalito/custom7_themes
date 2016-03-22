<?php

/**
 * @file
 * Contains the theme function override for 'pager_link'.
 */

/**
 * Implements hook_pager_link().
 *
 * TODO
 *
 * @ingroup themeable
 */
function astarter_pager_link($variables) {
  global $pager_page_array, $pager_total;
  $text       = $variables['text'];
  $page_new   = $variables['page_new'];
  $element    = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  // Ccurrent is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }
  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('<span class="i i-arrow-left"></span> First page') => array(
          t('Go to first page (@first/@max)', array('@first' => 1, '@max' => $pager_max)),
          NULL,
        ),
        t('<span class="i i-arrow-left"></span> Previous page') => array(
          t('Go to previous page (@previous/@max)', array('@previous' => $pager_current - 1, '@max' => $pager_max)),
          'prev',
        ),
        t('Next page <span class="i i-arrow-right"></span>') => array(
          t('Go to next page (@next/@max)', array('@next' => $pager_current + 1, '@max' => $pager_max)),
          'next',
        ),
        t('Last page <span class="i i-arrow-right"></span>') => array(
          t('Go to last page (@last/@max)', array('@last' => $pager_max, '@max' => $pager_max)),
          NULL,
        ),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text][0];
      if (isset($titles[$text][1])) {
        $attributes['rel'] = $titles[$text][1];
      }
    }
    elseif (is_numeric($text)) {
      if ($text !== 1) {
        $attributes['rel'] = 'nofollow';
      }

      $attributes['title'] = t('Go to page @number of @max',
        array(
          '@number' => $text,
          '@max'  => $pager_max,
        )
      );
    }
  }
  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['class'] = array('pagination__link');
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . ($text) . '</a>';
}
