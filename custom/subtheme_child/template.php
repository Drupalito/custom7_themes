<?php

/**
 * @file
 * Theme functions overrides
 */

/**
 * Implements hook_menu_link_alter().
 *
 * @see hook_menu_link_alter()

function subtheme_child_menu_link_alter(&$item) {

}
 */

/**
 * Implements hook_form_alter().
 *
 * @see hook_form_alter()

function subtheme_child_form_alter(&$form, &$form_state, $form_id) {

}
*/

/**
 * Implements hook_page_alter().
 *
 * @see hook_page_alter()

function subtheme_child_page_alter(&$page) {

}
*/

/**
 * Implements hook_html_head_alter().
 *
 * @ingroup themeable

function subtheme_child_html_head_alter(&$head_elements) {

}
*/

/**
 * Implements hook_js_alter().
 *
 * @see hook_js_alter()

function subtheme_child_js_alter(&$js) {
  $exclude = array();
  $js = array_diff_key($js, $exclude);
}
*/

/**
 * Implements hook_css_alter().
 *
 * @see hook_css_alter()
function subtheme_child_css_alter(&$css) {
  $exclude = array();
  $css = array_diff_key($css, $exclude);
}
*/
