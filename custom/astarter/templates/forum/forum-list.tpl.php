<?php

/**
 * @file
 * Displays a list of forums and containers.
 *
 * Available variables:
 * - $forums: An array of forums and containers to display. It is keyed to the
 *   numeric IDs of all child forums and containers. Each $forum in $forums
 *   contains:
 *   - $forum->is_container: TRUE if the forum can contain other forums. FALSE
 *     if the forum can contain only topics.
 *   - $forum->depth: How deep the forum is in the current hierarchy.
 *   - $forum->zebra: 'even' or 'odd' string used for row class.
 *   - $forum->icon_class: 'default' or 'new' string used for forum icon class.
 *   - $forum->icon_title: Text alternative for the forum icon.
 *   - $forum->name: The name of the forum.
 *   - $forum->link: The URL to link to this forum.
 *   - $forum->description: The description of this forum.
 *   - $forum->new_topics: TRUE if the forum contains unread posts.
 *   - $forum->new_url: A URL to the forum's unread posts.
 *   - $forum->new_text: Text for the above URL, which tells how many new posts.
 *   - $forum->old_topics: A count of posts that have already been read.
 *   - $forum->num_posts: The total number of posts in the forum.
 *   - $forum->last_reply: Text representing the last time a forum was posted or
 *     commented in.
 * - $forum_id: Forum ID for the current forum. Parent to all items within the
 *   $forums array.
 *
 * @see template_preprocess_forum_list()
 * @see theme_forum_list()
 *
 * @ingroup themeable
 */
?>
<table id="forum-<?php print $forum_id; ?>" class="forum-list forum-list--<?php print $forum_id; ?>">
  <thead>
    <tr>
      <th><?php print t('Forum'); ?></th>
      <th><?php print t('Topics');?></th>
      <th><?php print t('Posts'); ?></th>
      <th><?php print t('Last post'); ?></th>
    </tr>
  </thead>
  <tbody>
  <?php foreach ($forums as $child_id => $forum): ?>
    <tr id="forum-list-<?php print $child_id; ?>" class="<?php print $forum->zebra; ?>">
      <td <?php print $forum->is_container ? 'colspan="4" class="forum-list__detail forum-list--container"' : 'class="forum-list__detail forum-list--forum"'; ?>>
        <?php /* Enclose the contents of this cell with X divs, where X is the
               * depth this forum resides at. This will allow us to use CSS
               * left-margin for indenting.
               */ ?>
        <?php print str_repeat('<div class="indent">', $forum->depth); ?>
          <div class="forum-icon forum-status-<?php print $forum->icon_class; ?>">
            <span><?php print $forum->icon_title; ?></span>
          </div>
          <div class="topic-details__name"><a class="topic-details__link" href="<?php print $forum->link; ?>"><?php print $forum->name; ?></a></div>
          <?php if ($forum->description): ?>
            <div class="topic-details__description"><?php print $forum->description; ?></div>
          <?php endif; ?>
        <?php print str_repeat('</div>', $forum->depth); ?>
      </td>
      <?php if (!$forum->is_container): ?>
        <td class="topic-details__count">
          <?php print $forum->num_topics ?>
          <?php if ($forum->new_topics): ?>
            <br />
            <a href="<?php print $forum->new_url; ?>"><?php print $forum->new_text; ?></a>
          <?php endif; ?>
        </td>
        <td class="topic-details__posts"><?php print $forum->num_posts ?></td>
        <td class="topic-details__last-reply"><?php print $forum->last_reply ?></td>
      <?php endif; ?>
    </tr>
  <?php endforeach; ?>
  </tbody>
</table>
