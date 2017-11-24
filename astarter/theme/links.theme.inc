<?php

/**
 * @file
 * Contains the theme function override for 'links'.
 */

/**
 * Implements theme_links().
 *
 * TODO : comment_reply
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see theme_links()
 * @ingroup themeable
 */
function astarter_links($links, $attributes = array('class' => 'links')) {
  // Remove the link "reply".
  if (isset($links['comment_reply'])) {
    // Dissect link urls.
    $parts = explode('/', $links['comment_reply']['href']);
    // Execute rest if we have a numeric node ID.
    if (ctype_digit($parts[2])) {
      // Load the node.
      $node = node_load($parts[2]);
      // Variable to check.
      $variable = 'comment_form_location_' . $node->type;
      // Indicate whether we display the comment form below the post/comments.
      $form_below = variable_get($variable, COMMENT_FORM_BELOW) == COMMENT_FORM_BELOW;
      // If displayed on same page then remove 'reply' link.
      if ($node && $form_below) {
        unset($links['comment_reply']);
      }
    }
  }

  return theme_links($links, $attributes);
}
