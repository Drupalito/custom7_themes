<?php

/**
 * @file
 * Theme functions override
 */

/**
 * Implements hook_theme_registry_alter().
 *
 * @param $theme_registry
 *   The entire cache of theme registry information, post-processing.
 *
 * @see hook_theme_registry_alter()
 */
function astarter_theme_registry_alter(&$registry) {
  require_once dirname(__FILE__) . '/includes/registry.inc';

  // dpm($registry);
  // For maintainability reasons, some of this code lives in a class.
  $handler = new OmegaThemeRegistryHandler($registry, $GLOBALS['theme']);

  $trail = omega_theme_trail($GLOBALS['theme']);
  foreach ($trail as $theme => $name) {
    $handler->registerHooks($theme);
    $handler->registerThemeFunctions($theme, $trail);
  }
}

/**
 * Implements theme_menu_tree().
 *
 * @param $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @see template_preprocess_menu_tree()
 * @see theme_menu_tree()
 * @ingroup themeable
 */
function astarter_menu_tree__main_menu($variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_tree().
 *
 * @param $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @see template_preprocess_menu_tree()
 * @see theme_menu_tree()
 * @ingroup themeable
 */
function astarter_links__locale_block(&$variables) {
  $variables['attributes']['class'][] = 'list-inline';
  $variables['attributes']['class'][] = 'list-separate';
  $content = theme_links($variables);
  return $content;
}

/**
 * Implements hook_menu_breadcrumb_alter().
 *
 * @param $active_trail
 *   An array containing breadcrumb links for the current page.
 * @param $item
 *   The menu router item of the current page.
 *
 * @see drupal_set_breadcrumb()
 * @see menu_get_active_breadcrumb()
 * @see menu_get_active_trail()
 * @see menu_set_active_trail()
 */
function astarter_menu_breadcrumb_alter(&$active_trail, $item) {
  foreach ($active_trail as $id => $trail) {
    $active_trail[$id]['title'] = '<span itemprop="title">' . $trail['title'] . '</span>';
    $active_trail[$id]['localized_options']['html'] = TRUE;
    $active_trail[$id]['localized_options']['attributes']['itemprop'] = 'url';
  }
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
function astarter_form_alter(&$form, &$form_state, $form_id) {

  if (in_array($form_id, array('comment_node_article_form'))) {
    $form['#prefix'] = '<div id="comments-add" class="comments-add">';
    $form['#prefix'] .= '<h2 class="comments__title comments-add__title">' . t('Add new comment') . '</h2>';
    $form['#suffix'] = '</div>';
    $form['actions']['#prefix'] = '<div class="comments-submit">';
    $form['actions']['#suffix'] = '</div>';
    $form['actions']['submit']['#attributes']['class'][] = 'btn--primary';
  }

  if (in_array($form_id, array('comment_node_forum_form'))) {
    $form['#prefix'] = '<div id="comments-add" class="comments-add">';
    $form['#prefix'] .= '<h2 class="comments__title comments-add__title">' . t('Your reply') . '</h2>';
    $form['#suffix'] = '</div>';
    $form['actions']['#prefix'] = '<div class="comments-submit">';
    $form['actions']['#suffix'] = '</div>';
    $form['actions']['submit']['#attributes']['class'][] = 'btn--primary';
  }

  if ($form_id == 'user_login_block') {

  }

  if ($form_id == 'user_register_form' ||
     $form_id == 'user_pass' ||
     $form_id == 'user_login' ||
     $form_id == 'user_profile_form') {
    $form['actions']['submit']['#attributes']['class'][] = 'btn--primary';
  }

  if ($form_id == 'user_register_form' ||
     $form_id == 'user_login' ||
     $form_id == 'user_profile_form') {
    $form['actions']['#prefix'] = '<div class="form-actions">';
    $form['actions']['#suffix'] = '</div>';
  }
}

/**
 * Implements hook_page_alter().
 *
 * @param $page
 *   Nested array of renderable elements that make up the page.
 *
 * @see hook_page_alter()
 */
function astarter_page_alter(&$page) {

  // Look in each visible region for blocks.
  foreach (system_region_list($GLOBALS['theme'], REGIONS_VISIBLE) as $region => $name) {
    if (!empty($page[$region])) {
      // Find the last block in the region.
      $blocks = array_reverse(element_children($page[$region]));
      while ($blocks && !isset($page[$region][$blocks[0]]['#block'])) {
        array_shift($blocks);
      }
      if ($blocks) {
        $page[$region][$blocks[0]]['#block']->last_in_region = TRUE;
      }
    }
  }
}

/**
 * Implements hook_html_head_alter().
 *
 * Remove meta generator
 * Remove meta generator (module metatag)
 * Remove viewport (module metatag)
 * Remove meta content type
 * Remove shortlink
 *
 * @param $head_elements
 *   An array of all Head elements
 *   being requested on the page.
 *
 * @see hook_html_head_alter()
 */
function astarter_html_head_alter(&$head_elements) {

  $remove = array(
    'system_meta_generator' => FALSE,
    'metatag_generator_0' => FALSE,
    'system_meta_content_type' => FALSE,
    'viewport' => FALSE,
    'metatag_shortlink' => FALSE,
  );

  $head_elements = array_diff_key($head_elements, $remove);
}

/**
 * Implements hook_js_alter().
 *
 * Remove files_undo_remove.js
 * Remove tableheader.js
 *
 * @param $js
 *   An array of all JS items (files and inline JS)
 *   being requested on the page.
 *
 * @see hook_js_alter()
 */
function astarter_js_alter(&$js) {
  $exclude = array(
    // 'misc/tableheader.js' => FALSE,
  );
  $js = array_diff_key($js, $exclude);
}

/**
 * Implements hook_css_alter().
 *
 * Removes some default Drupal CSS.
 *
 * @param $css
 *   An array of all CSS items (files and inline CSS)
 *   being requested on the page.
 *
 * @see hook_css_alter()
 */
function astarter_css_alter(&$css) {
  global $theme_key;

  if (isset($css['modules/system/system.base.css'])) {
    $name = 'modules/system/system.base.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/system.base.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/system/system.menus.css'])) {
    $name = 'modules/system/system.menus.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/system.menus.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['misc/vertical-tabs.css'])) {
    $name = 'misc/vertical-tabs.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/vertical-tabs.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/contextual/contextual.css'])) {
    $name = 'modules/contextual/contextual.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/contextual.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/field/theme/field.css'])) {
    $name = 'modules/field/theme/field.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/field.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/filter/filter.css'])) {
    $name = 'modules/filter/filter.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/filter.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/poll/poll.css'])) {
    $name = 'modules/poll/poll.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/poll.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/search/search.css'])) {
    $name = 'modules/search/search.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/search.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/node/node.css'])) {
    $name = 'modules/node/node.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/node.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/block/block.css'])) {
    $name = 'modules/block/block.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/block.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/comment/comment.css'])) {
    $name = 'modules/comment/comment.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/comment.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/file/file.css'])) {
    $name = 'modules/file/file.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/file.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['modules/forum/forum.css'])) {
    $name = 'modules/forum/forum.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/forum.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['sites/all/modules/contrib/webform/css/webform.css'])) {
    $name = 'sites/all/modules/contrib/webform/css/webform.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/webform.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['sites/all/modules/contrib/date/date_api/date.css'])) {
    $name = 'sites/all/modules/contrib/date/date_api/date.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/date_api.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }
  if (isset($css['sites/all/modules/contrib/addressfield/addressfield.css'])) {
    $name = 'sites/all/modules/contrib/addressfield/addressfield.css';
    $css[$name]['data'] = drupal_get_path('theme', $theme_key) . '/css/modules/addressfield.css';
    $css[$name]['type'] = 'file';
    $css[$name]['group'] = CSS_THEME;
    $css[$name]['weight'] = 0.0001;
    // $css[$name]['every_page'] = TRUE;
  }

  // Load custom CSS module after
  foreach ($css as $key => $value) {
    if (preg_match("@sites\/all\/modules\/custom@", $key)) {
      $css[$key]['group'] = CSS_THEME;
      $css[$key]['weight'] = 0.0001;
    }
  }

  // [TODO]
  if (isset($css['sites/all/themes/custom/subtheme_child/css/print.css'])) {
    $name = 'sites/all/themes/custom/subtheme_child/css/print.css';
    $css[$name]['group'] = 200;
    $css[$name]['weight'] = 9999999;
    // $css[$name]['every_page'] = TRUE;
  }

  $exclude = array(
    // 'misc/vertical-tabs.css' => FALSE,
    // 'sites/all/modules/contrib/date/date_api/date.css' => FALSE,
    // 'sites/all/modules/contrib/date/date_repeat_field/date_repeat_field.css' => FALSE,
    'modules/aggregator/aggregator.css' => FALSE,
    'modules/aggregator/aggregator-rtl.css' => FALSE,
    // 'modules/block/block.css' => FALSE,
    'modules/book/book.css' => FALSE,
    'modules/book/book-rtl.css' => FALSE,
    // 'modules/comment/comment.css' => FALSE,
    'modules/comment/comment-rtl.css' => FALSE,
    // 'modules/contextual/contextual.css' => FALSE,
    'modules/dashboard/dashboard.css' => FALSE,
    'modules/dashboard/dashboard-rtl.css' => FALSE,
    'modules/dblog/dblog.css' => FALSE,
    'modules/dblog/dblog-rtl.css' => FALSE,
    // 'modules/field/theme/field.css' => FALSE,
    'modules/field/theme/field-rtl.css' => FALSE,
    'modules/field/field-rtl.css' => FALSE,
    'modules/field_ui/field_ui.css' => FALSE,
    'modules/field_ui/field_ui-rtl.css' => FALSE,
    'sites/all/modules/contrib/field_group/field_group.field_ui.css' => FALSE,
    // 'modules/file/file.css' => FALSE,
    // 'modules/filter/filter.css' => FALSE,
    'modules/filter/filter-rtl.css' => FALSE,
    // 'modules/forum/forum.css' => FALSE,
    'modules/forum/forum-rtl.css' => FALSE,
    'modules/help/help.css' => FALSE,
    'modules/locale/locale.css' => FALSE,
    'modules/locale/locale-rtl.css' => FALSE,
    'modules/menu/menu.css' => FALSE,
    // 'modules/node/node.css' => FALSE,
    'modules/node/node-rtl.css' => FALSE,
    'modules/openid/openid.css' => FALSE,
    'modules/openid/openid-rtl.css' => FALSE,
    // 'modules/poll/poll.css' => FALSE,
    'modules/poll/poll-rtl.css' => FALSE,
    'modules/profile/profile.css' => FALSE,
    // 'modules/search/search.css' => FALSE,
    'modules/search/search-rtl.css' => FALSE,
    'modules/system/system.admin.css' => FALSE,
    'modules/system/system.admin-rtl.css' => FALSE,
    // 'modules/system/system.base.css' => FALSE,
    'modules/system/system.base-rtl.css' => FALSE,
    'modules/system/system.maintenance.css' => FALSE,
    // 'modules/system/system.menus.css' => FALSE,
    'modules/system/system.menus-rtl.css' => FALSE,
    'modules/system/system.messages.css' => FALSE,
    'modules/system/system.messages-rtl.css' => FALSE,
    'modules/system/system.theme.css' => FALSE,
    'modules/system/system.theme-rtl.css' => FALSE,
    'modules/taxonomy/taxonomy.css' => FALSE,
    'modules/tracker/tracker.css' => FALSE,
    'modules/update/update.css' => FALSE,
    'modules/user/user.css' => FALSE,
    'modules/user/user-rtl.css' => FALSE,
    // 'sites/all/modules/contrib/webform/css/webform.css' => FALSE,
    'sites/all/modules/contrib/files_undo_remove/files_undo_remove.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor.editor.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor-rtl.css' => FALSE,
    'sites/all/modules/contrib/panels/css/panels.css' => FALSE,
    'sites/all/modules/contrib/views/css/views.css' => FALSE,
    'sites/all/modules/contrib/views/css/views-rtl.css' => FALSE,
    'sites/all/modules/contrib/ctools/css/ctools.css' => FALSE,
    'sites/all/modules/contrib/better_exposed_filters/better_exposed_filters.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}
