<?php

/**
 * @file breadcrumb.theme.inc
 * Contains the theme function override for 'breadcrumb'.
 */

/**
 * Implements theme_breadcrumb().
 *
 * @param $variables
 *   An array of variables to pass to the theme function.
 * @see theme_breadcrumb()
 * @ingroup themeable
 */
function astarter_breadcrumb(&$variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {

    // Provide a navigational heading to give
    // context for breadcrumb links to
    // screen-reader users.
    if (empty($variables['title'])) {
      $variables['title'] = t('You are here');
    }

    global $user;
    if ($user->uid && arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'password') {
      $crumbs[] = l('<span itemprop="title">' . t('Home') . '</span>', '<front>', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = l('<span itemprop="title">' . t('User') . '</span>', 'user', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = t('Edit my password');
    }
    elseif ($user->uid && arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'edit') {
      $crumbs[] = l('<span itemprop="title">' . t('Home') . '</span>', '<front>', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = l('<span itemprop="title">' . t('User') . '</span>', 'user', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = t('Edit my profil');
    }
    elseif ($user->uid && arg(0) == 'user') {
      $crumbs[] = l('<span itemprop="title">' . t('Home') . '</span>', '<front>', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = l('<span itemprop="title">' . t('User') . '</span>', 'user', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = t('My account');
    }
    elseif (arg(0) == 'user' && arg(1) == 'register') {
      $crumbs[] = l('<span itemprop="title">' . t('Home') . '</span>', '<front>', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = l('<span itemprop="title">' . t('User account') . '</span>', 'user', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = t('Create new account');
    }
    elseif (arg(0) == 'user' && arg(1) == 'password') {
      $crumbs[] = l('<span itemprop="title">' . t('Home') . '</span>', '<front>', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = l('<span itemprop="title">' . t('User account') . '</span>', 'user', array('attributes' => array('itemprop' => array('url')), 'html' => TRUE));
      $crumbs[] = t('Request new password');
    }
    else {
      $crumbs = $variables['breadcrumb'];
      $crumbs[] = drupal_get_title();
    }

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $array_size = count($crumbs);

    $breadcrumb_separator = theme_get_setting('astarter_breadcrumb_separator');

    $i = 0;

    $output_breadcrumb = '';
    while ($i < $array_size) {
      if ($i == 0) {
        $output_breadcrumb .= '<span';
        $output_breadcrumb .= ' class="breadcrumb-' . $i . ' first"';
        $output_breadcrumb .= ' itemscope itemtype="http://data-vocabulary.org/Breadcrumb"';
        $output_breadcrumb .= '>' . $crumbs[$i] . '</span> ' . $breadcrumb_separator . ' ';
      }
      elseif (($i + 1) == $array_size) {
        $output_breadcrumb .= '<span';
        $output_breadcrumb .= ' class="breadcrumb-' . $i . ' active"';
        $output_breadcrumb .= '>' . $crumbs[$i] . '</span>';
      }
      else {
        $output_breadcrumb .= '<span';
        $output_breadcrumb .= ' class="breadcrumb-' . $i . '"';
        $output_breadcrumb .= ' itemscope itemtype="http://data-vocabulary.org/Breadcrumb"';
        $output_breadcrumb .= '>' . $crumbs[$i] . '</span> ' . $breadcrumb_separator . ' ';
      }
      $i++;
    }

    $output = '<p class="mvn">';
    $output .= '<span>' . $variables['title'] . '&nbsp;:</span> ';
    $output .= $output_breadcrumb;
    $output .= '</p>';

    $render_output = array(
      '#theme' => 'container',
      '#children' => $output,
      '#attributes' => array(
        'id' => 'breadcrumb',
      ),
    );
    return render($render_output);
  }
}
