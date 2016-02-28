<?php

/**
 * @file
 * Contains the theme function override for 'mark'.
 */

/**
 * Implements theme_mark().
 *
 * Change class name
 *
 * @ingroup themeable
 */
function astarter_mark($variables) {
  global $user;
  if ($user->uid) {
    if ($variables['type'] == MARK_NEW) {
      return ' <mark class="mark mark--new">' . t('new') . '</mark>';
    }
    elseif ($variables['type'] == MARK_UPDATED) {
      return ' <mark class="mark mark--updated">' . t('updated') . '</mark>';
    }
  }
}
