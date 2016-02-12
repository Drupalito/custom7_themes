<?php

/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * @see template_preprocess()
 * @see template_preprocess_search_result()
 * @see template_process()
 *
 * @ingroup themeable
 */

?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="node node--table">
    <div class="node__content">
      <a class="node__link" href="<?php echo $url; ?>">
        <h2 class="node__title caps mvn"><?php echo $title; ?></h2>
        <p class="node__excerpt mtn mbs"><strong><?php print $result['node']->type; ?></strong> — <small><?php print t('Create at !date', array('!date' => $info_split['date'])); ?></small></p>
        <p class="highlighter mts"><?php print $result['snippet']; ?></p>
      </a>
    </div>
  </div>
</div>
