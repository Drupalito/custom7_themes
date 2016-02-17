<?php

/**
 * @file
 * Contains the theme function override for 'status_messages'.
 */

/**
 * Implements theme_status_messages().
 *
 * Change output HTML
 *
 * @ingroup themeable
 */
function astarter_status_messages($variables) {

  $display = $variables['display'];
  $output  = '';

  $status_heading = array(
    'status'  => t('Status message'),
    'error'   => t('Error message'),
    'warning' => t('Warning message'),
    'info'    => t('Informative message'),
  );

  foreach (drupal_get_messages($display) as $type => $message) {
    $output .= '<div class="messages messages--icon messages--' . $type . ' clearfix">';
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="messages__title hide">' . $status_heading[$type] . '</h2>';
    }
    $output .= '<div class="messages__content">';
    if (count($message) > 1) {
      $output .= '<ul class="messages__list">';
      foreach ($message as $message) {
        $output .= '<li class="messages__item">' . $message . '</li>';
      }
      $output .= '</ul>';
    }
    elseif (strpos($message[0], '<pre>') !== TRUE) {
      $output .= '<div class="messages__description">' . $message[0] . '</div>';
    }
    else {
      $output .= '<p class="messages__description">' . $message[0] . '</p>';
    }
    $output .= '</div>';
    $output .= '</div>';
  }
  return $output;
}
