<?php

/**
 * @file
 * Contains the theme function override for 'pager'.
 */

/**
 * Implements theme_views_mini_pager().
 *
 * TODO
 *
 * @ingroup themeable
 */
function astarter_views_mini_pager($vars) {
  global $pager_page_array, $pager_total;

  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];

  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  if ($pager_total[$element] > 1) {

    $li_previous = theme('pager_previous', array(
      'text' => (isset($tags[1]) ? $tags[1] : t('‹‹')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters,
    ));
    if (empty($li_previous)) {
      $li_previous = "&nbsp;";
    }

    $li_next = theme('pager_next', array(
      'text' => (isset($tags[3]) ? $tags[3] : t('››')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters,
    ));

    if (empty($li_next)) {
      $li_next = "&nbsp;";
    }

    $items[] = array(
      'class' => array('pagination__item', 'pager-previous'),
      'data' => $li_previous,
    );

    $items[] = array(
      'class' => array('pagination__item', 'pager-current'),
      'data' => '<strong class="current">' . t('@current of @max', array('@current' => $pager_current, '@max' => $pager_max)) . '</strong>',
    );

    $items[] = array(
      'class' => array('pagination__item', 'pager-next'),
      'data' => $li_next,
    );

    return '
    <div class="pagination mtl text-center clearfix">
      <h2 class="pagination__title hide">' .
        t('Page @current of @max', array('@current' => $pager_current, '@max' => $pager_max))
      . '</h2>' . theme('item_list', array(
        'items' => $items,
        'attributes' => array(
          'class' => array(
            'pagination__list',
            'list-inline',
          ),
        ),
      )) . '</div>';

    // return theme('item_list', array(
    //   'items' => $items,
    //   'title' => NULL,
    //   'type' => 'ul',
    //   'attributes' => array('class' => array('pager')),
    // ));
  }
}
