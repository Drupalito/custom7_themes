<?php

/**
 * @file
 * Contains the theme function override for 'ife_form_element'.
 */

/**
 * Implements theme_ife_form_element().
 *
 * Theme the form element, add the error, when one occurred.
 *
 * @ingroup themeable
 */
function astarter_ife_form_element($variables) {
  $output = '';

  $element = $variables['element']['#children'];
  // Add in the error if set.
  if (isset($variables['element']['#ife_error']) && $variables['element']['#ife_error']) {

    $new_element = str_replace("\n</div>\n", '', $element);
    $error = '<p class="smaller text--error mvn">' . $variables['element']['#ife_error'] . '</p>';

    if (isset($variables['element']['#ife_error_position']) && $variables['element']['#ife_error_position'] == IFE_POSITION_INLINE_MESSAGE_BEFORE) {
      $output = $new_element . $error . '</div>';
    }
    else {
      $output = $new_element . $error . '</div>';
    }
  }
  return $output;
}
