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
          <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <?php print render($title_suffix); ?>
      <?php endif; ?>

      <?php if ($display_submitted): ?>
        <p class="node__submitted submitted mtn">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="mark mark--unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['field_image']);
    hide($content['comments']);
    hide($content['links']);

    $image_node = render($content['field_image']);
  ?>
  <div class="row">
    <?php if (!empty($image_node)) : ?>
      <div class="col-xs-12 col-sm-4">
        <?php print $image_node; ?>
      </div>
      <div class="col-xs-12 col-sm-8">
    <?php else: ?>
      <div class="col-xs-12">
    <?php endif; ?>
      <?php print render($content); ?>
    </div>
    <?php if (!empty($image_node)) : ?>
      <div class="col-xs-12 col-sm-push-4 col-sm-8 mtm">
    <?php else: ?>
      <div class="col-xs-12 mtm">
    <?php endif; ?>
      <?php print render($content['links']); ?>
    </div>
  </div>

</div>
