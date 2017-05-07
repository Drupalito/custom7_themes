<?php

/**
 * @file
 * Contains a pre-process hook for 'block'.
 */

/**
 * Implements hook_preprocess_block().
 *
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the theme hook being called ("block" in this case).
 * @see hook_preprocess()
 * @see hook_preprocess_block()
 */
function astarter_preprocess_block(&$variables, $hook) {

  $array_block_no_wrapper = array(
    'block-system-navigation',
    'block-system-main',
    'block-search-form',
  );

  $array_block_region = array(
    'footer',
  );

  // Use a template with no wrapper for the page's main content.
  if (isset($variables['block_html_id']) && in_array($variables['block_html_id'], $array_block_no_wrapper)) {
    $variables['theme_hook_suggestions'][] = 'block__no_wrapper';
  }

  // Classes describing the position of the block within the region.
  if ($variables['block_id'] == 1) {
    $variables['classes_array'][] = 'block-first first';
  }

  // The last_in_region property is set in astarter_page_alter().
  if (isset($variables['block']->last_in_region)) {
    $variables['classes_array'][] = 'block-last last';
  }

  $variables['classes_array'][] = $variables['block_zebra'];

  // Classes describing the position of the block within the region.
  if (isset($variables['block_html_id']) && $variables['block_html_id'] == 'block-system-main-menu') {
    $variables['theme_hook_suggestions'][] = 'block__minimal';
    unset($variables['classes_array']);
    $variables['classes_array'][] = 'col-sm-12';
  }

  // Add default CSS class on block region.
  if (isset($variables['block']->region) && in_array($variables['block']->region, $array_block_region)) {
    $variables['classes_array'][] = 'col-xs-12';
    $variables['classes_array'][] = 'col-sm-6';
    $variables['classes_array'][] = 'col-md-3';
  }

  $variables['classes_array'] = preg_replace('/^block-/', 'block--', $variables['classes_array']);

  $variables['title_attributes_array']['class'][] = 'block__title';
  $variables['content_attributes_array']['class'][] = 'block__content';
}
