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
  <div>
    <div class="comment__header">
      <p class="mvn">

        <?php if ($submitted): ?>
          <?php print $picture ?>
          <span class="inbl amiddle">
            <cite itemprop="creator name"><span class="bold"><?php print $author; ?></span></cite>
            <?php if ($new): ?>
               <mark class="mark mark--new"><?php print $new; ?></mark>
            <?php endif; ?>
            <?php if ($status == 'comment-unpublished'): ?>
               <mark class="mark mark--unpublished"><?php print t('Unpublished'); ?></mark>
            <?php endif; ?>
            <br /><time class="small" datetime="<?php print format_date($comment->created, 'custom', 'c'); ?>" itemprop="commentTime"><?php print $created; ?></time>
            <?php if ($comment->created != $comment->changed): ?>
              <time class="small" datetime="<?php print format_date($comment->changed, 'custom', 'c'); ?>"><?php print $changed; ?></time>
            <?php endif; ?>
          </span>
      <?php endif; ?>
      </p>
    </div>
    <div class="comment__description">
      <?php print render($content); ?>
      <?php if ($signature): ?>
        <footer class="comment__signature user-signature clearfix">
          <?php print $signature; ?>
        </footer>
      <?php endif; ?>
      <?php print render($content['links']); ?>
    </div>
  </div>
</div>
