<?php

/**
 * @file
 * Default theme implementation to display voting form for a poll.
 *
 * @see template_preprocess_poll_vote()
 *
 * @ingroup themeable
 */
?>
<div class="poll-vote-form">
  <div class="poll-vote-form__choices">
    <?php if ($block): ?>
      <p class="h4 bold"><?php print $title; ?></p>
    <?php endif; ?>
    <?php print $choice; ?>
  </div>
  <?php print $vote; ?>
</div>
<?php print $rest ?>
