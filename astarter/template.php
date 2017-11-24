<?php

/**
 * @file template.php
 *
 * Theme functions override.
 *
 * @package     ASTARTER
 * @author      OWNER_NAME <OWNER_EMAIL>
 * @version     v.1.0 (CURRENT_YEAR)
 * @copyright   Copyright (c) CURRENT_YEAR, aquelito
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
    $form['#prefix'] = '<div id="comments-add" class="comments-add noprint">';
    $form['#prefix'] .= '<h2 class="comments__title comments-add__title">' . t('Add comment') . '</h2>';
    $form['#suffix'] = '</div>';
    $form['actions']['#prefix'] = '<div class="comments-submit">';
    $form['actions']['#suffix'] = '</div>';
  }

  if (in_array($form_id, array('comment_node_forum_form', 'comment_node_book_form'))) {
    $form['#prefix'] = '<div id="comments-add" class="comments-add noprint">';
    $form['#prefix'] .= '<h2 class="comments__title comments-add__title">' . t('Your reply') . '</h2>';
    $form['#suffix'] = '</div>';
    $form['actions']['#prefix'] = '<div class="comments-submit">';
    $form['actions']['#suffix'] = '</div>';
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
  $theme_parent_path = $GLOBALS['theme_path'];

  foreach ($css as &$item) {
    if ($item['media'] == 'screen') {
      $item['group'] = CSS_SYSTEM;
      $item['weight'] = $item['weight'] - 100;
    }
  }

  // Clean up core and contrib module CSS.
  $overrides = array(
    'addressfield' => array(
      'addressfield.css' => array(
        'theme' => 'addressfield.css',
      ),
      'addressfield-rtl.css' => array(
        'theme' => 'addressfield-rtl.css',
      ),
    ),
    'block' => array(
      'block.css' => array(
        'theme' => 'block.css',
      ),
    ),
    'book' => array(
      'book.css' => array(
        'theme' => 'book.css',
      ),
    ),
    'comment' => array(
      'comment.css' => array(
        'theme' => 'comment.css',
      ),
      'comment-rtl.css' => array(
        'theme' => 'comment-rtl.css',
      ),
    ),
    'contextual' => array(
      'contextual.css' => array(
        'theme' => 'contextual.css',
      ),
      'contextual-rtl.css' => array(
        'theme' => 'contextual-rtl.css',
      ),
    ),
    'date' => array(
      'date_api/date.css' => array(
        'theme' => 'date_api.css',
      ),
      'date_api/date-rtl.css' => array(
        'theme' => 'date_api-rtl.css',
      ),
    ),
    'lang_dropdown' => array(
      'ddslick/ddsDefault.css' => array(
        'theme' => 'ddslick.css',
      ),
    ),
    'field' => array(
      'theme/field.css' => array(
        'theme' => 'field.css',
      ),
      'theme/field-rtl.css' => array(
        'theme' => 'field-rtl.css',
      ),
    ),
    'field_collection' => array(
      'field_collection.css' => array(
        'theme' => 'field_collection.css',
      ),
      'field_collection-rtl.css' => array(
        'theme' => 'field_collection-rtl.css',
      ),
    ),
    'file' => array(
      'file.css' => array(
        'theme' => 'file.css',
      ),
    ),
    'filter' => array(
      'filter.css' => array(
        'theme' => 'filter.css',
      ),
    ),
    'forum' => array(
      'forum.css' => array(
        'theme' => 'forum.css',
      ),
      'forum-rtl.css' => array(
        'theme' => 'forum-rtl.css',
      ),
    ),
    'node' => array(
      'node.css' => array(
        'theme' => 'node.css',
      ),
      'node-rtl.css' => array(
        'theme' => 'node-rtl.css',
      ),
    ),
    'poll' => array(
      'poll.css' => array(
        'theme' => 'poll.css',
      ),
      'poll-rtl.css' => array(
        'theme' => 'poll-rtl.css',
      ),
    ),
    'search' => array(
      'search.css' => array(
        'theme' => 'search.css',
      ),
      'search-rtl.css' => array(
        'theme' => 'search-rtl.css',
      ),
    ),
    'system' => array(
      'system.base.css' => array(
        'base' => 'system.base.css',
      ),
      'system.base-rtl.css' => array(
        'base' => 'system.base-rtl.css',
      ),
      'system.theme.css' => array(
        'theme' => 'system.theme.css',
      ),
      'system.theme-rtl.css' => array(
        'theme' => 'system.theme-rtl.css',
      ),
      'system.admin.css' => array(
        'admin' => 'system.admin.css',
      ),
      'system.admin-rtl.css' => array(
        'admin' => 'system.admin-rtl.css',
      ),
      'system.messages.css' => array(
        'theme' => 'system.messages.css',
      ),
      'system.menus.css' => array(
        'theme' => 'system.menus.css',
      ),
      'system.menus-rtl.css' => array(
        'theme' => 'system.menus-rtl.css',
      ),
    ),
    // 'vertical-tabs' => array(
    //   'misc/vertical-tabs.css' => array(
    //     'theme' => 'vertical-tabs.css',
    //   ),
    //   'misc/vertical-tabs-rtl.css' => array(
    //     'theme' => 'vertical-tabs-rtl.css',
    //   ),
    // ),
    'webform' => array(
      'css/webform.css' => array(
        'theme' => 'webform.css',
      ),
      'css/webform-rtl.css' => array(
        'theme' => 'webform-rtl.css',
      ),
    ),
  );

  // Check if we are on an admin page. Otherwise, we can skip admin CSS.
  $path = current_path();
  $types = path_is_admin($path) ? array('base', 'theme', 'admin') : array('base', 'theme');
  // Add a special case for the block demo page.
  $types = strpos($path, 'admin/structure/block/demo') === 0 ? array_merge($types, array('demo')) : $types;

  foreach ($overrides as $module => $files) {
    // We gathered the CSS files with paths relative to the providing module.
    $path = drupal_get_path('module', $module);

    if (module_exists($module) === true) {
      foreach ($files as $file => $items) {
        if (isset($css[$path . '/' . $file]) || empty($path) && isset($css[$file])) {
          // Keep a copy of the original file array so we can merge that with our
          // overrides in order to keep the 'weight' and 'group' declarations.

          if (!empty($path)) {
            $original = $css[$path . '/' . $file];
            unset($css[$path . '/' . $file]);
          }
          else {
            $original = $css[$file];
            unset($css[$file]);
          }

          // Omega 4.x tries to follow the pattern described in
          // http://drupal.org/node/1089868 for declaring CSS files. Therefore, it
          // may take more than a single file to override a .css file added by
          // core. This gives us better granularity when overriding .css files
          // in a sub-theme.
          foreach ($types as $type) {
            if (isset($items[$type])) {
              $original['weight'] = isset($original['weight']) ? $original['weight'] : 0;

              // Always add a tiny value to the weight, to conserve the insertion order.
              $original['weight'] += count($css) / 10000;

              $css[$theme_parent_path . '/css/modules/' . $module . '/' . $items[$type]] = array(
                'data' => $theme_parent_path . '/css/modules/' . $module . '/' . $items[$type],
              ) + $original;
            }
          }
        }
      }
    }
  }

  // Define banner background color
  $logo_color = theme_get_setting('astarter_bannercolor');
  if (isset($logo_color) && $logo_color == 'light') {
    $css[$theme_parent_path . '/css/theme.banner.darken.css']['data'] = $theme_parent_path . '/css/theme.banner.lighten.css';
  }

  $exclude = array(
    'misc/vertical-tabs.css' => FALSE,
    'modules/aggregator/aggregator.css' => FALSE,
    'modules/aggregator/aggregator-rtl.css' => FALSE,
    // 'modules/book/book-rtl.css' => FALSE,
    'modules/dashboard/dashboard.css' => FALSE,
    'modules/dashboard/dashboard-rtl.css' => FALSE,
    'modules/dblog/dblog.css' => FALSE,
    'modules/dblog/dblog-rtl.css' => FALSE,
    'modules/field_ui/field_ui.css' => FALSE,
    'modules/field_ui/field_ui-rtl.css' => FALSE,
    'sites/all/modules/contrib/field_group/field_group.field_ui.css' => FALSE,
    'modules/help/help.css' => FALSE,
    'modules/locale/locale.css' => FALSE,
    'modules/locale/locale-rtl.css' => FALSE,
    'modules/menu/menu.css' => FALSE,
    'modules/openid/openid.css' => FALSE,
    'modules/openid/openid-rtl.css' => FALSE,
    'modules/profile/profile.css' => FALSE,
    'modules/system/system.admin.css' => FALSE,
    'modules/system/system.admin-rtl.css' => FALSE,
    'modules/system/system.base-rtl.css' => FALSE,
    'modules/system/system.maintenance.css' => FALSE,
    'modules/system/system.menus-rtl.css' => FALSE,
    'modules/system/system.messages-rtl.css' => FALSE,
    'modules/system/system.theme-rtl.css' => FALSE,
    'modules/taxonomy/taxonomy.css' => FALSE,
    'modules/tracker/tracker.css' => FALSE,
    'modules/update/update.css' => FALSE,
    'modules/user/user.css' => FALSE,
    'modules/user/user-rtl.css' => FALSE,
    'sites/all/modules/contrib/files_undo_remove/files_undo_remove.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor.editor.css' => FALSE,
    'sites/all/modules/contrib/ckeditor/css/ckeditor-rtl.css' => FALSE,
    'sites/all/modules/contrib/panels/css/panels.css' => FALSE,
    'sites/all/modules/contrib/views/css/views.css' => FALSE,
    'sites/all/modules/contrib/views/css/views-rtl.css' => FALSE,
    'sites/all/modules/contrib/ctools/css/ctools.css' => FALSE,
    'sites/all/modules/contrib/better_exposed_filters/better_exposed_filters.css' => FALSE,
    'sites/all/modules/contrib/date/date_views/css/date_views.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}
