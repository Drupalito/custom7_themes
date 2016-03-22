<?php

/**
 * @file
 * Contains the theme function override for 'pager'.
 */

/**
 * Implements hook_pager().
 *
 * TODO
 *
 * @ingroup themeable
 */
function astarter_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // lLast is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('<span class="i i-arrow-left"></span> First page')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('<span class="i i-arrow-left"></span> Previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('Next page <span class="i i-arrow-right"></span>')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('Last page <span class="i i-arrow-right"></span>')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array(
          'pagination__item', 'pagination--first',
        ),
        'data'  => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array(
          'pagination__item', 'pagination--previous',
        ),
        'data'  => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pagination__item', 'pagination--ellipsis'),
          'data'  => '<span>…</span>',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pagination__item'),
            'data'  => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pagination__item', 'pagination--current'),
            'data'  => '<strong class="current">' . $i . '</strong>',
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pagination__item'),
            'data'  => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pagination__item', 'pagination--ellipsis'),
          'data'  => '<span>…</span>',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pagination__item', 'pagination--next'),
        'data'  => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pagination__item', 'pagination--last'),
        'data'  => $li_last,
      );
    }
    return '
    <div class="pagination text-center clearfix">
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
  }
}
