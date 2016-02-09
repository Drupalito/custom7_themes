<?php

/**
 * @file
 * Template to display rows in a grid.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="table-responsive">
  <table class="<?php print $class; ?>"<?php print $attributes; ?>>
    <?php if (!empty($caption)) : ?>
      <caption><?php print $caption; ?></caption>
    <?php endif; ?>
    <tbody>
      <?php foreach ($rows as $row_number => $columns): ?>
        <tr<?php if ($row_classes[$row_number]) : print ' class="' . $row_classes[$row_number] . '"'; endif; ?>>
          <?php foreach ($columns as $column_number => $item): ?>
            <td<?php if ($column_classes[$row_number][$column_number]) : print ' class="' . $column_classes[$row_number][$column_number] . '"'; endif; ?>>
              <?php print $item; ?>
            </td>
          <?php endforeach; ?>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
</div>
