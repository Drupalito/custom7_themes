<?php

/**
 * @file
 * Default theme implementation to present profile categories (groups of
 * profile items).
 *
 * @see template_preprocess_user_profile_category()
 */
?>
<?php if ($title): ?>
<h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
<?php endif; ?>
<dl<?php print $attributes; ?>>
  <?php print $profile_items; ?>
</dl>
