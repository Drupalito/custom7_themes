<?php

/**
 * @file
 * Contains a pre-process hook for 'search_results'.
 */

/**
 * Implements hook_preprocess_search_results().
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_search_results(&$variables) {

  $index = 0;
  $len = count($variables['results']);

  $variables['search_results'] = '';
  foreach ($variables['results'] as $result) {

    $class_css = array();
    $class_css[] = (0 == $index % 2) ? 'views-row-odd' : 'views-row-even';
    $class_css[] = ($index == 0) ? 'views-row-first' : '';
    $class_css[] = ($index == $len - 1) ? 'view-row-last' : '';

    $variables['search_results'] .= theme('search_result',
      array(
        'result' => $result,
        'module' => $variables['module'],
        'extra_classes' => implode(' ', $class_css),
      )
    );
    ++$index;
  }

}
