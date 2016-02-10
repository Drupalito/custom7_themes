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
    $output .= '<div class="message message--' . $type . ' clearfix">';
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="message__title hide">' . $status_heading[$type] . '</h2>';
    }
    $output .= '<div class="message__content">';
    if (count($message) > 1) {
      $output .= '<ul class="message__list">';
      foreach ($message as $message) {
        $output .= '<li class="message__item">' . $message . '</li>';
      }
      $output .= '</ul>';
    }
    else if (strpos($message[0], '<pre>') !== false) {
      $output .= '<div class="message__description">' . $message[0] . '</div>';
    }
    else {
      $output .= '<p class="message__description">' . $message[0] . '</p>';
    }
    $output .= '</div>';
    $output .= '</div>';
  }
  return $output;
}
