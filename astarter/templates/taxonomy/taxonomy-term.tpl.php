<?php

/**
 * @file
 * Default theme implementation to display a term.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */

?>
<div<?php print $attributes; ?>>
  <?php if (!$page): ?>
    <h2<?php print $content_attributes_title; ?>><a href="<?php print $term_url; ?>"><?php print $term_name; ?></a></h2>
  <?php endif; ?>
  <div<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>
</div>
