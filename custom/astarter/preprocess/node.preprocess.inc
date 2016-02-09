<?php

/**
 * @file
 * Contains a pre-process hook for 'node'.
 */

/**
 * Implements hook_preprocess_node().
 *
 * Override or insert variables into the node templates.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_node(&$variables, $hook) {

  $function = __FUNCTION__ . '__' . $variables['type'] . '__' . $variables['view_mode'];
  if (function_exists($function)) {
    $function($variables, $hook);
  }

  if ($variables['elements']['#view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__teaser';
  }

  // Make "node--NODETYPE--VIEWMODE.tpl.php" templates available for nodes
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  // Add css class "node--NODETYPE--VIEWMODE" to nodes
  $variables['classes_array'][] = 'node-' . $variables['type'] . '-' . $variables['view_mode'];

  // Add $unpublished variable to submitted variable.
  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;

  // Add pubdate to submitted variable.
  $variables['pubdate'] = $variables['date'];

  // Add display_submitted.
  if ($variables['display_submitted']) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['pubdate']));
  }

  $variables['name'] = $variables["elements"]["#node"]->name;

  if ($variables['nid']) {
    $variables['classes_array'][] = 'node-' . $variables['nid'];
  }

  // Add a class for the view mode.
  // if (!$variables['teaser']) {
  // $variables['classes_array'][] = 'view-mode-' . $variables['view_mode'];
  // }

  // // Add a class to show node is authored by current user.
  // if ($variables['uid'] && $variables['uid'] == $GLOBALS['user']->uid) {
  // $variables['classes_array'][] = 'node--by-viewer';
  // }

  $css_node_type = drupal_clean_css_identifier($variables['type']);
  $css_view_mode = drupal_clean_css_identifier($variables['view_mode']);

  // Add BEM element classes.
  $variables['title_attributes_array']['class'][] = 'node__title';
  $variables['content_attributes_array']['class'][] = 'node__content';
  $variables['content']['links']['#attributes']['class'][] = 'node__links';
  $variables['content']['links']['#attributes']['class'][] = 'list-separate';

  // Add modifier classes for view mode.
  $variables['classes_array'][] = 'node-' . $css_view_mode;
  $variables['classes_array'][] = 'node-' . $css_node_type . '--' . $css_view_mode;

  // Change modifier classes to use BEM syntax.
  $variables['classes_array'] = preg_replace('/^node-/', 'node--', $variables['classes_array']);


  if ($css_view_mode == 'teaser') {
    $variables['title_attributes_array']['class'][] = 'mbn';
    // Teaser : clean link 'number comments'
    if (isset($variables['content']['links']['comment']['#links']['comment-comments'])) {
      $variables['content']['links']['comment']['#links']['comment-comments']['attributes']['class'][] = 'node__link--comments';
      $variables['content']['links']['comment']['#links']['comment-comments']['attributes']['title'] = $variables['content']['links']['comment']['#links']['comment-comments']['title'] . ' ' . t('on') . ' ' . $variables['title'];
    }
    // Teaser : clean link 'add comment'
    if (isset($variables['content']['links']['comment']['#links']['comment-add'])) {
      $variables['content']['links']['comment']['#links']['comment-add']['attributes']['class'][] = 'node__link--comments';
      $variables['content']['links']['comment']['#links']['comment-add']['attributes']['title'] = $variables['content']['links']['comment']['#links']['comment-add']['title'] . ' ' . t('on') . ' ' .  $variables['title'];
    }
    // Teaser : clean link 'readmore'
    $variables['content']['links']['node']['#links']['node-readmore']['attributes']['rel'] = 'bookmark';
    $variables['content']['links']['node']['#links']['node-readmore']['title'] = '<span class="i i-chevron-right"></span> ' . t('Read more');
    $variables['content']['links']['node']['#links']['node-readmore']['attributes']['class'][] = 'node__link--readmore';
    $variables['content']['links']['node']['#links']['node-readmore']['attributes']['title'] = $variables['title'] . ' (' . t('Read more') . ')';
  }

}
