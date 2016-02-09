<?php

/**
 * @file
 * Returns the HTML for a wrapping container around comments.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728230
 */

$comments = render($content['comments']);
$comment_form = render($content['comment_form']);
?>
<div<?php print $attributes; ?>>
  <div id="commentsList" class="commentsList">
    <?php print render($title_prefix); ?>
    <?php if ($comments && $node->type != 'forum'): ?>
      <h2<?php print $title_attributes; ?>>
        <?php if ($node->comment_count == 0): ?>
          <?php print t('No comments'); ?>
        <?php else: ?>
          <?php print t('@comments', array(
            '@comments' => format_plural($node->comment_count, '1 comment', '@count comments'),
          )); ?>
        <?php endif; ?>
      </h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php print $comments; ?>
  </div>
  <?php if ($comment_form): ?>
    <?php print $comment_form; ?>
  <?php endif; ?>
</div>
