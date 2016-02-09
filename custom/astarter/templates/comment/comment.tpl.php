<?php

/**
 * @file
 * Returns the HTML for comments.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728216
 */
?>
<div class="<?php print $classes; ?> row"<?php print $attributes; ?>>
  <div class="comment__header mbs col-xs-12 col-sm-3">
    <p class="mvn">
      <?php if ($new): ?>
        <mark class="mark mark--new"><?php print $new; ?></mark>
      <?php endif; ?>
      <?php if ($status == 'comment-unpublished'): ?>
        <mark class="mark mark--unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
      <?php if ($submitted): ?>
        <cite itemprop="creator name"><?php print $author; ?></cite><br /><time datetime="<?php print format_date($comment->created, 'custom', 'c'); ?>" itemprop="commentTime"><?php print $created; ?></time>
        <?php if ($comment->created != $comment->changed): ?>
          <time datetime="<?php print format_date($comment->changed, 'custom', 'c'); ?>"><?php print $changed; ?></time>
        <?php endif; ?>
    <?php endif; ?>
    </p>
  </div>
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['links']);
      print render($content);
    ?>
    <?php print render($content['links']); ?>
    <?php if ($signature): ?>
      <footer class="user-signature comment__signature clearfix">
        <?php print $signature; ?>
      </footer>
    <?php endif; ?>
  </div>

</div>
