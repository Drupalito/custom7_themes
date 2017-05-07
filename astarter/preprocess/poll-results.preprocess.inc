<?php

/**
 * @file
 * Contains a pre-process hook for 'poll_results'.
 */

/**
 * Implements hook_preprocess_poll_results__block().
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see hook_preprocess()
 * @see hook_preprocess_poll_results__block()
 */
function astarter_preprocess_poll_results(&$variables) {
  // Change the links to a render array with sensible.
  $variables['links'] = array(
    '#theme' => 'links',
    '#links' => $variables['raw_links'],
    '#attributes' => array('class' => array('links', 'poll-results__links')),
  );
}
