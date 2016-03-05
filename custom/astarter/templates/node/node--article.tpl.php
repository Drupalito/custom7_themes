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
    <header class="header">
      <?php if (!$page && $title): ?>
        <?php print render($title_prefix); ?>
          <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <?php print render($title_suffix); ?>
      <?php endif; ?>
      <?php if ($unpublished): ?>
        <mark class="mark mark--unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
      <?php if ($display_submitted) : ?>
        <?php if (!empty($teaser)) : ?>
        <?php elseif (!empty($page)) : ?>
          <meta itemprop="url" content="<?php print url('node/' . $node->nid, array('absolute' => TRUE)); ?>" />
          <meta itemprop="commentCount" content="<?php print $comment_count; ?>" />
          <ul>
            <?php if (!empty($node->uid)) : ?><li><span id="author-<?php print check_plain(strip_tags($variables['name'])); ?>" itemprop="author" itemscope itemtype="http://schema.org/Person"><?php print l($variables['name'], 'user/' . $node->uid, array('html' => TRUE, 'attributes' => array('itemprop' => array('url')))); ?></span></li><?php endif; ?>
            <li><?php print format_plural($comment_count, t('@count comment'), t('@count comments')); ?></li>
            <li><time datetime="<?php print format_date($node->created, 'custom', 'c'); ?>" itemprop="datePublished dateCreated"><?php print format_date($created); ?></time></li>
            <?php if ($node->created != $node->changed) : ?>
              <li><time datetime="<?php print format_date($node->changed, 'custom', 'c'); ?>" itemprop="dateModified"><?php print format_date($changed); ?></time></li>
            <?php endif; ?>
          </ul>
        <?php endif; ?>
      <?php endif; ?>
    </header>
  <?php endif; ?>
  <div class="node__content"<?php print (!empty($teaser)) ? '' : ' itemprop="articleBody"'; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['field_image']);
      hide($content['comments']);
      hide($content['links']);
    ?>

    <?php
      $image_node = render($content['field_image']);
      if (!empty($image_node)) :
        print $image_node;
      endif;
    ?>

    <?php print render($content); ?>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
