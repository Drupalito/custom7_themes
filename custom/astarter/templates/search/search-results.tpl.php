<?php

/**
 * @file
 * Default theme implementation for displaying search results.
 *
 * @see template_preprocess_search_results()
 *
 * @ingroup themeable
 */
?>
<div class="<?php print $classes; ?> clearfix">
  <?php if ($search_results): ?>
    <div id="item_grid" class="clearfix">
      <?php print $search_results; ?>
    </div>
  <?php else: ?>
    <div class="messages messages--info messages--icon mbn clearfix">
      <div class="messages__content">
        <p class="messages__description mvn"><?php print t('No result for your search'); ?> <q class="bold"></q>.</p>
        <?php print search_help('search#noresults', drupal_help_arg()); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>
</div>
