<?php

/**
 * @file
 * Theme functions override
 */

/**
 * Implements hook_theme_registry_alter().
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
 * @see theme_menu_tree()
 */
function astarter_menu_tree__main_menu($variables) {
  return '<ul class="menu list-inline">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_form_alter().
 *
 * @see hook_form_alter()
 */
function astarter_form_alter(&$form, &$form_state, $form_id) {

  if ($form_id == 'user_login_block') {

  }

  if ($form_id == 'comment_node_article_form') {
    $form['#prefix'] = '<div id="commentsAdd" class="commentsAdd">';
    $form['#prefix'] .= '<h2 class="comments__title commentsAdd__title">' . t('Add new comment') . '</h2>';
    $form['#suffix'] = '</div>';
    $form['actions']['#prefix'] = '<div class="commentsSubmit">';
    $form['actions']['#suffix'] = '</div>';
    $form['actions']['submit']['#attributes']['class'][] = 'btn--primary';
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
 * @see hook_page_alter()
 */
function astarter_page_alter(&$page) {

  // Logged in
  if (!empty($page['content']['system_main']['content']['search_form'])) {
    unset($page['content']['system_main']['content']['search_form']);
  }

  // Not logged in
  if (!empty($page['content']['system_main']['search_form'])) {
    unset($page['content']['system_main']['search_form']);
  }

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
 *
 * @ingroup themeable
 */
function astarter_html_head_alter(&$head_elements) {

  $remove = array(
    'system_meta_generator',
    'metatag_generator_0',
    'system_meta_content_type',
    'viewport',
  );

  foreach ($remove as $key) {
    if (isset($head_elements[$key])) {
      unset($head_elements[$key]);
    }
  }
}

/**
 * Implements hook_js_alter().
 *
 * Remove files_undo_remove.js
 * Remove tableheader.js
 *
 * @see hook_js_alter()
 */
function astarter_js_alter(&$js) {
  $exclude = array(
    'misc/tableheader.js' => FALSE,
    // 'misc/textarea.js' => FALSE,
  );
  $js = array_diff_key($js, $exclude);
}

/**
 * Implements hook_css_alter().
 *
 * Removes some default Drupal CSS.
 *
 * @see hook_css_alter()
 */
function astarter_css_alter(&$css) {
  $exclude = array(
    'misc/vertical-tabs.css' => FALSE,
    'sites/all/modules/contrib/date/date_api/date.css' => FALSE,
    'sites/all/modules/contrib/date/date_repeat_field/date_repeat_field.css' => FALSE,
    'sites/all/modules/contrib/date/date_popup/themes/datepicker.1.7.css' => FALSE,
    'sites/all/modules/contrib/files_undo_remove/files_undo_remove.css' => FALSE,
    'modules/aggregator/aggregator.css' => FALSE,
    'modules/aggregator/aggregator-rtl.css' => FALSE,
    'modules/block/block.css' => FALSE,
    'modules/block/block-rtl.css' => FALSE,
    'modules/book/book.css' => FALSE,
    'modules/book/book-rtl.css' => FALSE,
    'modules/comment/comment.css' => FALSE,
    'modules/comment/comment-rtl.css' => FALSE,
    'modules/contextual/contextual.css' => FALSE,
    'modules/dashboard/dashboard.css' => FALSE,
    'modules/dashboard/dashboard-rtl.css' => FALSE,
    'modules/system/defaults.css' => FALSE,
    'modules/system/defaults-rtl.css' => FALSE,
    'modules/dblog/dblog.css' => FALSE,
    'modules/dblog/dblog-rtl.css' => FALSE,
    'modules/field/theme/field.css' => FALSE,
    'modules/field/field-rtl.css' => FALSE,
    'modules/field_ui/field_ui.css' => FALSE,
    'modules/field_ui/field_ui-rtl.css' => FALSE,
    'sites/all/modules/contrib/field_group/field_group.field_ui.css' => FALSE,
    'modules/contrib/file/file.css' => FALSE,
    'modules/contrib/filter/filter.css' => FALSE,
    'modules/contrib/filter/filter-rtl.css' => FALSE,
    'modules/forum/forum.css' => FALSE,
    'modules/forum/forum-rtl.css' => FALSE,
    'modules/help/help.css' => FALSE,
    'modules/locale/locale.css' => FALSE,
    'modules/locale/locale-rtl.css' => FALSE,
    'modules/menu/menu.css' => FALSE,
    'modules/node/node.css' => FALSE,
    'modules/node/node-rtl.css' => FALSE,
    'sites/all/modules/contrib/openid/openid.css' => FALSE,
    'sites/all/modules/openid/openid-rtl.css' => FALSE,
    'modules/poll/poll.css' => FALSE,
    'modules/poll/poll-rtl.css' => FALSE,
    'modules/profile/profile.css' => FALSE,
    'modules/search/search.css' => FALSE,
    'modules/search/search-rtl.css' => FALSE,
    'modules/statistics/statistics.css' => FALSE,
    'modules/syslog/syslog.css' => FALSE,
    'modules/system/admin.css' => FALSE,
    'modules/system/admin-rtl.css' => FALSE,
    'modules/system/maintenance.css' => FALSE,
    'modules/system/system.css' => FALSE,
    'modules/system/system-rtl.css' => FALSE,
    'modules/system/system-log.css' => FALSE,
    'modules/system/system.admin.css' => FALSE,
    'modules/system/system.base.css' => FALSE,
    'modules/system/system.base-rtl.css' => FALSE,
    'modules/system/system.behavior.css' => FALSE,
    'modules/system/system.behavior-rtl.css' => FALSE,
    'modules/system/system.maintenance.css' => FALSE,
    'modules/system/system.menus.css' => FALSE,
    'modules/system/system.menus-rtl.css' => FALSE,
    'modules/system/system.messages.css' => FALSE,
    'modules/system/system.messages-rtl.css' => FALSE,
    'modules/system/system.theme.css' => FALSE,
    'modules/system/system.theme-rtl.css' => FALSE,
    'sites/all/modules/contrib/taxonomy/taxonomy.css' => FALSE,
    'sites/all/modules/contrib/tracker/tracker.css' => FALSE,
    'modules/contrib/update/update.css' => FALSE,
    'modules/user/user.css' => FALSE,
    'modules/user/user-rtl.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor-rtl.css' => FALSE,
    'sites/all/modules/contrib/panels/css/panels.css' => FALSE,
    'sites/all/modules/contrib/views/css/views.css' => FALSE,
    'sites/all/modules/contrib/ctools/css/ctools.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}
