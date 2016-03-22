<?php

/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header class="header mbm">
      <?php if (!$page && $title): ?>
        <?php print render($title_prefix); ?>
          <h2<?php print $title_attributes; ?>><a class="node__link" href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <?php print render($title_suffix); ?>
      <?php endif; ?>

      <?php if ($display_submitted): ?>
        <div class="node__submitted submitted">
          <?php print render($submitted); ?>
        </div>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="mark mark--unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that
      // we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
