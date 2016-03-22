<?php

/**
 * @file
 * Returns the HTML for the basic html structure of a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728208
 */
?>
<!DOCTYPE html>
<!--[if IE 9]><html class="ie9 no-js"<?php print $html_attributes; ?>><![endif]-->
<html class="no-js"<?php print $html_attributes; ?>>
<head>
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title><?php print $head_title; ?></title>
<?php print $head; ?>
<?php print $styles; ?>
<?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>"<?php print $attributes; ?>>
<p id="skiplinks" class="skiplinks">
  <a href="#navigation"><?php print t('Navigation'); ?></a>
  <a href="#main"><?php print t('Main content'); ?></a>
</p>
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>
</body>
</html>
