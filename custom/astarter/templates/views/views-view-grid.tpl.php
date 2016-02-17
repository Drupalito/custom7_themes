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
<div class="ta">
  <!-- <table class="<?php print $class; ?>"<?php print $attributes; ?>> -->
    <?php if (!empty($caption)) : ?>
      <!-- <caption><?php print $caption; ?></caption> -->
    <?php endif; ?>
    <!-- <tbody> -->
      <?php foreach ($rows as $row_number => $columns): ?>
        <?php $col_count = count($columns); ?>
        <!-- <tr<?php if ($row_classes[$row_number]) : print ' class="' . $row_classes[$row_number] . '"'; endif; ?>> -->
        <div<?php if ($row_classes[$row_number]) : print ' class="row ' . $row_classes[$row_number] . '"'; endif; ?>>
          <?php foreach ($columns as $column_number => $item): ?>
            <div class="col-xs-12 col-sm-6 col-md-3">

            <!-- <td<?php if ($column_classes[$row_number][$column_number]) : print ' class="' . $column_classes[$row_number][$column_number] . '"'; endif; ?>> -->
              <?php print $item; ?>
            <!-- </td> -->

            </div>
          <?php endforeach; ?>
        <!-- </tr> -->
        </div>
      <?php endforeach; ?>
    <!-- </tbody> -->
  <!-- </table> -->
</div>
