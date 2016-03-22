<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <p<?php print $title_attributes; ?>><?php print $block->subject ?></p>
<?php endif;?>
  <?php print render($title_suffix); ?>
  <div<?php print $content_attributes; ?>>
    <?php print $content ?>
  </div>
</div>
