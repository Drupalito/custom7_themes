<?php

/**
 * @file
 * Contains a process hook for 'block'.
 */

/**
 * Implements hook_process_block().
 *
 * Override or insert variables into the block templates.
 *
 * @see hook_process()
 */
function astarter_process_block(&$variables, $hook) {
  $variables['title'] = $variables['block']->subject;
}
