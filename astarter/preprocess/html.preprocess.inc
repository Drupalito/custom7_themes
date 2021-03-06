<?php

/**
 * @file
 * Contains a pre-process hook for 'html'.
 */

/**
 * Implements hook_preprocess_html().
 *
 * Override or insert variables into the html template.
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the theme hook being called ("html" in this case).
 * @see hook_preprocess()
 * @see hook_preprocess_html()
 */
function astarter_preprocess_html(&$variables, $hook) {
  global $theme_key;

  // Attributes for html element.
  $variables['html_attributes_array'] = array(
    'lang'  => $variables['language']->language,
    'dir' => $variables['language']->dir,
    'class' => array('no-js'),
  );

  // Show a warning when the Omega theme is the active theme.
  if ($GLOBALS['theme'] == 'astarter') {
    drupal_set_message(t('astarter is a base theme and should never be used directly. Please see the included README or our <a href="http://aquelito.fr">support</a>.'), 'warning');
  }

  if ($variables['is_admin']) {
    // Active Style CSS Debug Grid for Admin.
    if (theme_get_setting('astarter_debug_css_grid')) {
      drupal_add_css(drupal_get_path('theme', $theme_key) . '/css/screen-debug-grid.css', array(
        'group'      => CSS_THEME,
        'preprocess' => FALSE,
      ));
    }
  }

  // Return early, so the maintenance page does not
  // call any of the code below.
  if ($hook != 'html') {
    return;
  }

  // If on an individual node page, add the node type to body classes.
  if ($node = menu_get_object()) {
    $variables['classes_array'][] = drupal_html_class('page--node-full');
  }

  // Classes for body element.
  // Allows advanced theming based on context.
  // (home page, node of certain type, etc.).
  if (!$variables['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    // Add unique class for each website section.
    list($section) = explode('/', $path, 2);
    $arg = explode('/', $_GET['q']);
    if ($arg[0] == 'node' && isset($arg[1])) {
      if ($arg[1] == 'add') {
        $section = 'node--add';
      }
      elseif (isset($arg[2]) && is_numeric($arg[1]) && ($arg[2] == 'edit' || $arg[2] == 'delete')) {
        $section = 'node--' . $arg[2];
      }
    }
    $variables['classes_array'][] = drupal_html_class('section--' . $section);
  }

  // Store the menu item since it has some useful information.
  $variables['menu_item'] = menu_get_item();
  if ($variables['menu_item']) {
    switch ($variables['menu_item']['page_callback']) {
      case 'views_page':
        // Is this a Views page ?
        $variables['classes_array'][] = 'page--views';
        break;

      case 'page_manager_blog':
      case 'page_manager_blog_user':
      case 'page_manager_contact_site':
      case 'page_manager_contact_user':
      case 'page_manager_node_add':
      case 'page_manager_node_edit':
      case 'page_manager_node_view_page':
      case 'page_manager_page_execute':
      case 'page_manager_poll':
      case 'page_manager_search_page':
      case 'page_manager_term_view_page':
      case 'page_manager_user_edit_page':
      case 'page_manager_user_view_page':
        // Is this a Panels page ?
        $variables['classes_array'][] = 'page--panels';
        break;
    }
  }

  $variables['attributes_array']['class'] = array();
  $variables['attributes_array']['class'] = $variables['classes_array'] + $variables['attributes_array']['class'];
}
