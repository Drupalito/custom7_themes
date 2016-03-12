<?php

/**
 * @file
 * Returns the HTML for comments.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728216
 */

hide($content['links']);
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="comment__header">
    <p class="mvn">
      <?php if (!empty($submitted)): ?>
        <?php print $picture ?>
        <span class="inbl amiddle">
          <?php print render($meta_author); ?>
          <?php if ($new): ?>
             <mark class="mark mark--new"><?php print $new; ?></mark>
          <?php endif; ?>
          <?php if ($status == 'comment-unpublished'): ?>
             <mark class="mark mark--unpublished"><?php print t('Unpublished'); ?></mark>
          <?php endif; ?>
          <br />
          <?php print render($meta_comment_created); ?>
          <?php print render($meta_comment_updated); ?>
        </span>
    <?php endif; ?>
    </p>
  </div>
  <div<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>
  <?php if ($signature): ?>
    <footer class="comment__user-signature user-signature clearfix">
      <?php print $signature; ?>
    </footer>
  <?php endif; ?>
  <?php print render($content['links']); ?>
</div>
