<?php

/**
 * @file theme-settings.php
 *
 * Theme setting callbacks for the ASTARTER theme.
 *
 * @package     ASTARTER
 * @author      OWNER_NAME <OWNER_EMAIL>
 * @version     v.1.0 (CURRENT_YEAR)
 * @copyright   Copyright (c) CURRENT_YEAR, aquelito
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
  $form['themeheader'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'fieldset',
    '#title'         => t('Header'),
    '#weight'        => 0,
  );
  $form['themeheader']['astarter_bannercolor'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'radios',
    '#title'         => t('Banner background color'),
    '#default_value' => theme_get_setting('astarter_bannercolor'),
    '#options'       => array(
      'light' => t('Lighten'),
      'dark'  => t('Darken'),
    ),
  );
  $form['themeheader']['astarter_menu_home_item'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Convert Home item menu to icon'),
    '#default_value' => theme_get_setting('astarter_menu_home_item'),
    '#description'   => t('Font icon'),
  );

  $form['themenavigation'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'fieldset',
    '#title'         => t('Navigation'),
    '#weight'        => 1,
  );
  $form['themenavigation']['astarter_navigation_fix'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Navigation Fix on top page'),
    '#default_value' => theme_get_setting('astarter_navigation_fix'),
    '#description'   => t('Fixed Navigation.'),
  );

  // Create the form using Forms API.
  $form['themesettings'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'fieldset',
    '#title'         => t('Breadcrumb'),
    '#weight'        => 2,
  );
  $form['themesettings']['astarter_breadcrumb'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'select',
    '#title'         => t('Display breadcrumb'),
    '#default_value' => theme_get_setting('astarter_breadcrumb'),
    '#options'       => array(
      'yes'   => t('Yes'),
      'no'    => t('No'),
    ),
  );
  $form['themesettings']['breadcrumb_options'] = array(
    '#group'  => 'verticalTabs',
    '#type'   => 'container',
    '#states' => array(
      'invisible' => array(
        ':input[name="astarter_breadcrumb"]' => array('value' => 'no'),
      ),
    ),
  );
  $form['themesettings']['breadcrumb_options']['astarter_breadcrumb_separator'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'textfield',
    '#title'         => t('Breadcrumb separator'),
    '#description'   => t('Text only. Don’t forget to include spaces.'),
    '#default_value' => theme_get_setting('astarter_breadcrumb_separator'),
    '#size'          => 5,
    '#maxlength'     => 10,
  );
  $form['themesettings']['breadcrumb_options']['astarter_breadcrumb_home'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Show home page link in breadcrumb'),
    '#default_value' => theme_get_setting('astarter_breadcrumb_home'),
  );
  $form['themesettings']['breadcrumb_options']['astarter_breadcrumb_trailing'] = array(
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


  if (libraries_get_path('wow') || libraries_get_path('bootstrap') || libraries_get_path('owl-carousel')) {

    // Create the form using Forms API.
    $form['themelibraries'] = array(
      '#group'         => 'verticalTabs',
      '#type'          => 'fieldset',
      '#title'         => t('Libraries'),
      '#weight'        => 3,
    );

    if (libraries_get_path('wow')) {
      $form['themelibraries']['astarter_libraries_wow'] = array(
        '#group'         => 'verticalTabs',
        '#type'          => 'checkbox',
        '#title'         => t('Actived WOW libraries'),
        '#default_value' => theme_get_setting('astarter_libraries_wow'),
        '#description'   => t('Documentation and plugins, <a href="http://mynameismatthieu.com/WOW" target="_blank">read this link</a>'),
      );
    }

    if (libraries_get_path('owl-carousel')) {
      $form['themelibraries']['astarter_libraries_owl'] = array(
        '#group'         => 'verticalTabs',
        '#type'          => 'checkbox',
        '#title'         => t('Actived owl-carousel libraries'),
        '#default_value' => theme_get_setting('astarter_libraries_owl'),
        '#description'   => t('Documentation and plugins, <a href="https://owlcarousel2.github.io/OwlCarousel2/" target="_blank">read this link</a>'),
      );
    }

    if (libraries_get_path('bootstrap')) {
      $form['themelibraries']['astarter_libraries_bootstrap'] = array(
        '#group'         => 'verticalTabs',
        '#type'          => 'checkbox',
        '#title'         => t('Actived Bootstrap libraries'),
        '#default_value' => theme_get_setting('astarter_libraries_bootstrap'),
        '#description'   => t('Documentation and plugins, <a href="http://getbootstrap.com/javascript" target="_blank">read this link</a>'),
      );
    }
  }

  // Create the form using Forms API.
  $form['themedev'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'fieldset',
    '#title'         => t('Theme development settings'),
    '#weight'        => 5,
  );
  $form['themedev']['astarter_debug_css_grid'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Debug CSS rythm and grid'),
    '#default_value' => theme_get_setting('astarter_debug_css_grid'),
    '#description'   => t('Display rythm and grid overlay (Only admin).'),
  );
}
