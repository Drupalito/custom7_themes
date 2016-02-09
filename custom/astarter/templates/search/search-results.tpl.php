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
    <div class="message message--info mbn clearfix">
      <div class="message__content">
        <p class="messsage__description mvn"><?php print t('No result for your search'); ?> <q class="bold"><?php print _get_current_search_terms(); ?></q>.</p>
        <?php print search_help('search#noresults', drupal_help_arg()); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>
</div>
