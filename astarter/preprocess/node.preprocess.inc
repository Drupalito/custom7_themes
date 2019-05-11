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
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @param $hook
 *   The name of the theme hook being called ("node" in this case).
 * @see hook_preprocess()
 * @see hook_preprocess_node()
 */
function astarter_preprocess_node(&$variables, $hook) {

  $function = __FUNCTION__ . '__' . $variables['type'] . '__' . $variables['view_mode'];
  if (function_exists($function)) {
    $function($variables, $hook);
  }

  if ($variables['elements']['#view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__teaser';
  }

  // Make "node--NODETYPE--VIEWMODE.tpl.php" templates available for nodes.
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  // Add css class "node--NODETYPE--VIEWMODE" to nodes.
  $variables['classes_array'][] = 'node-' . $variables['type'] . '-' . $variables['view_mode'];

  // Add $unpublished variable to submitted variable.
  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;
  // Add pubdate to submitted variable.
  $variables['pubdate'] = $variables['date'];

  if ($variables['nid']) {
    $variables['classes_array'][] = 'node-' . $variables['nid'];
  }

  $css_node_type = drupal_clean_css_identifier($variables['type']);
  $css_view_mode = drupal_clean_css_identifier($variables['view_mode']);

  // Add modifier classes for view mode.
  $variables['classes_array'][] = 'node-' . $css_view_mode;
  $variables['classes_array'][] = 'node-' . $css_node_type . '--' . $css_view_mode;

  // Add BEM element classes.
  $variables['title_attributes_array']['class'][] = 'node__title';
  $variables['content_attributes_array']['class'][] = 'node__content';
  $variables['content']['links']['#attributes']['class'][] = 'node__links';
  $variables['content']['links']['#attributes']['class'][] = 'noprint';

  // Change modifier classes to use BEM syntax.
  $variables['classes_array'] = preg_replace('/^node-/', 'node--', $variables['classes_array']);

  // Add display_submitted.
  $variables['submitted'] = array();

  if ($variables['display_submitted'] && $css_view_mode == 'full' && $variables['type'] == 'article') {

    $variables['content_attributes_array']['itemprop'] = 'articleBody';

    if (!empty($variables['uid'])) {
      $node_meta[] = '<span id="author-' . check_plain(strip_tags($variables['name'])) . '" itemprop="author publisher" itemscope itemtype="http://schema.org/Person">' . l('<span itemprop="name">' . strip_tags($variables['name']) . '</span>', 'user/' . $variables['uid'], array('html' => TRUE, 'attributes' => array('itemprop' => array('url')))) . '</span>';
    }

    if ($variables['nid'] && defined('COMMENT_NODE_CLOSED') && $variables['comment'] != COMMENT_NODE_CLOSED) {

      $node_meta[] = l(format_plural($variables['comment_count'], t('@count comment'), t('@count comments')), 'node/' . $variables['nid'], array('fragment' => 'comments', 'attributes' => array('class' => array('scroll')))) . '<meta itemprop="commentCount" content="' . $variables['comment_count'] . '" />';
    }

    $node_meta[] = '<time datetime="' . format_date($variables['created'], 'custom', 'c') . '" itemprop="datePublished dateCreated">' . format_date($variables['created']) . '</time>';

    if ($variables['created'] != $variables['changed']) {

      $node_meta[] = '<time datetime="' . format_date($variables['changed'], 'custom', 'c') . '" itemprop="dateModified">' . format_date($variables['changed']) . '</time>';
    }
  }

  elseif ($variables['display_submitted']) {

    if (!empty($variables['uid'])) {

      $node_meta[] = '<span id="author-' . check_plain(strip_tags($variables['name'])) . '">' . l($variables['name'], 'user/' . $variables['uid'], array('html' => TRUE)) . '</span>';
    }

    $node_meta[] = '<time datetime="' . format_date($variables['created'], 'custom', 'c') . '">' . format_date($variables['created']) . '</time>';

    if ($variables['created'] != $variables['changed']) {

      $node_meta[] = '<time datetime="' . format_date($variables['changed'], 'custom', 'c') . '">' . format_date($variables['changed']) . '</time>';
    }
  }

  if ($variables['display_submitted'] && !empty($node_meta)) {
    $variables['submitted']['meta_list'] = array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#items' => $node_meta,
      '#attributes' => array('class' => array('meta')),
    );
  }

  // Clean link 'add comment'.
  if (isset($variables['content']['links']['comment']['#links']['comment-add'])) {
    $variables['content']['links']['comment']['#links']['comment-add']['attributes']['class'][] = 'node__link--comments';
    $variables['content']['links']['comment']['#links']['comment-add']['attributes']['class'][] = 'scroll';
    $variables['content']['links']['comment']['#links']['comment-add']['fragment'] = 'commentsAdd';
    $variables['content']['links']['comment']['#links']['comment-add']['attributes']['title'] = $variables['content']['links']['comment']['#links']['comment-add']['title'] . ' ' . t('on') . ' ' .  $variables['title'];
  }

  if ($css_view_mode == 'teaser') {
    $variables['title_attributes_array']['class'][] = 'mb-0';

    // Teaser : clean link 'number comments'.
    if (isset($variables['content']['links']['comment']['#links']['comment-comments'])) {
      $variables['content']['links']['comment']['#links']['comment-comments']['attributes']['class'][] = 'node__link--comments';
      $variables['content']['links']['comment']['#links']['comment-comments']['attributes']['title'] = $variables['content']['links']['comment']['#links']['comment-comments']['title'] . ' ' . t('on') . ' ' . $variables['title'];
    }

    // Teaser : remove add comment link.
    if (isset($variables['content']['links']['comment']['#links']['comment-add'])) {
      unset($variables['content']['links']['comment']['#links']['comment-add']);
    }

    // Teaser : remove new comment link.
    if (isset($variables['content']['links']['comment']['#links']['comment-new-comments'])) {
      unset($variables['content']['links']['comment']['#links']['comment-new-comments']);
    }

    // Teaser : remove forbidden comment link.
    if (isset($variables['content']['links']['comment']['#links']['comment_forbidden'])) {
      unset($variables['content']['links']['comment']['#links']['comment_forbidden']);
    }

    // Teaser : clean link 'readmore'.
    $variables['content']['links']['node']['#links']['node-readmore']['attributes']['rel'] = 'bookmark';
    $variables['content']['links']['node']['#links']['node-readmore']['title'] = '<span class="i i-arrow-right2" aria-hidden="true"></span> ' . t('Read more');
    $variables['content']['links']['node']['#links']['node-readmore']['attributes']['class'][] = 'node__link--readmore';
    $variables['content']['links']['node']['#links']['node-readmore']['attributes']['title'] = $variables['title'] . ' (' . t('Read more') . ')';
  }
}
