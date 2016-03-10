<?php

/**
 * @file
 * Theme setting callbacks for the starter theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form. The arguments
 *   that drupal_get_form() was originally called with are available in the
 *   array $form_state['build_info']['args'].
 * @param $form_id
 *   String representing the name of the form itself. Typically this is the
 *   name of the function that generated the form.
 *
 * @see hook_form_FORM_ID_alter()
 * @see hook_form_alter()
 */
function astarter_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  $form['verticalTabs'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => -10,
    '#prefix' => '<h2>' . t('Configuration') . '</h2>',
  );

  // Create the form using Forms API.
  $form['breadcrumb'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'fieldset',
    '#title'         => t('Breadcrumb settings'),
    '#weight'        => 4,
  );
  $form['breadcrumb']['astarter_breadcrumb'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'select',
    '#title'         => t('Display breadcrumb'),
    '#default_value' => theme_get_setting('astarter_breadcrumb'),
    '#options'       => array(
      'yes'   => t('Yes'),
      'admin' => t('Only in admin section'),
      'no'    => t('No'),
    ),
  );
  $form['breadcrumb']['breadcrumb_options'] = array(
    '#group'  => 'verticalTabs',
    '#type'   => 'container',
    '#states' => array(
      'invisible' => array(
        ':input[name="astarter_breadcrumb"]' => array('value' => 'no'),
      ),
    ),
  );
  $form['breadcrumb']['breadcrumb_options']['astarter_breadcrumb_separator'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'textfield',
    '#title'         => t('Breadcrumb separator'),
    '#description'   => t('Text only. Don’t forget to include spaces.'),
    '#default_value' => theme_get_setting('astarter_breadcrumb_separator'),
    '#size'          => 5,
    '#maxlength'     => 10,
  );
  $form['breadcrumb']['breadcrumb_options']['astarter_breadcrumb_home'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Show home page link in breadcrumb'),
    '#default_value' => theme_get_setting('astarter_breadcrumb_home'),
  );
  $form['breadcrumb']['breadcrumb_options']['astarter_breadcrumb_trailing'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Append a separator to the end of the breadcrumb'),
    '#default_value' => theme_get_setting('astarter_breadcrumb_trailing'),
    '#description'   => t('Useful when the breadcrumb is placed just before the title.'),
    '#states' => array(
      'disabled' => array(
        ':input[name="astarter_breadcrumb_title"]' => array('checked' => TRUE),
      ),
    ),
  );

  // Create the form using Forms API.
  $form['themedev'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'fieldset',
    '#title'         => t('Theme development settings'),
    '#weight'        => 5,
  );
  $form['themedev']['astarter_header_fix'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#prefix'        => '<h3>' . t('Options page') . '</h3>',
    '#title'         => t('Header Fix on top page'),
    '#default_value' => theme_get_setting('astarter_header_fix'),
    '#description'   => t('Fixed Banner'),
  );
  $form['themedev']['astarter_debug_css_grid'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Debug CSS rythm and grid'),
    '#default_value' => theme_get_setting('astarter_debug_css_grid'),
    '#description'   => t('Display rythm and grid overlay.'),
  );
}
