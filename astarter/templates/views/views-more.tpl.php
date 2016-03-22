<?php

/**
 * @file
 * Theme the more link.
 *
 * - $view: The view object.
 * - $more_url: the url for the more link.
 * - $link_text: the text for the more link.
 *
 * @ingroup views_templates
 */
?>

<div class="more-link">
  <a class="btn btn--primary btn--more-link" href="<?php print $more_url ?>"><span class="i i-arrow-right2" aria-hidden="true"></span> <?php print $link_text; ?></a>
</div>
