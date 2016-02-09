<?php

/**
 * @file
 * Contains a pre-process hook for 'image'.
 */

/**
 * Implements hook_preprocess_hook().
 *
 * Ajout attribut image
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_image(&$variables) {
  $variables['attributes']['itemprop'] = array('image');
}
