<?php
/**
 * @file
 * Default theme implementation to present a picture configured for the
 * user's account.
 *
 * @see template_preprocess_user_picture()
 */
?>
<?php if ($user_picture): ?>
  <span class="user-picture">
    <?php print $user_picture; ?>
  </span>
<?php endif; ?>
