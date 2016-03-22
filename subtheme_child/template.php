<?php

/**
 * @file
 * Theme functions overrides
 */

/**
 * Implements hook_menu_link_alter().
 *
 * @param $item
 *   Associative array defining a menu link as passed into menu_link_save().
 *
 * @see hook_translated_menu_link_alter()
 * @see hook_menu_link_alter()
 */
function subtheme_child_menu_link_alter(&$item) {
}

/**
 * Implements hook_form_alter().
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
function subtheme_child_form_alter(&$form, &$form_state, $form_id) {
}

/**
 * Implements hook_page_alter().
 *
 * @param $page
 *   Nested array of renderable elements that make up the page.
 *
 * @see hook_page_alter()
 */
function subtheme_child_page_alter(&$page) {
}

/**
 * Implements hook_html_head_alter().
 *
 * @param $head_elements
 *   An array of all Head elements
 *   being requested on the page.
 *
 * @see hook_html_head_alter()
 */
function subtheme_child_html_head_alter(&$head_elements) {
  $exclude = array();
  $head_elements = array_diff_key($head_elements, $exclude);
}

/**
 * Implements hook_js_alter().
 *
 * @param $js
 *   An array of all JS items (files and inline JS)
 *   being requested on the page.
 *
 * @see hook_js_alter()
 */
function subtheme_child_js_alter(&$js) {
  $exclude = array();
  $js = array_diff_key($js, $exclude);
}

/**
 * Implements hook_css_alter().
 *
 * @param $css
 *   An array of all CSS items (files and inline CSS)
 *   being requested on the page.
 *
 * @see hook_css_alter()
 */
function subtheme_child_css_alter(&$css) {
  $exclude = array();
  $css = array_diff_key($css, $exclude);
}
