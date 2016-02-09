<?php

/**
 * @file
 * Theme setting callbacks for the sub theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function subtheme_child_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes.
  // See issue #943212.
  if (isset($form_id)) {
    return;
  }
}
