/**
 * Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
 * For licensing, see LICENSE.html or http://ckeditor.com/license
 */

/**
 * WARNING: clear browser's cache after you modify this file.
 * If you don't do this, you may notice that browser is ignoring all your changes.
 */
CKEDITOR.editorConfig = function(config) {

  config.allowedContent = true;
  config.contentsCss = 'css/screen-editor.css';

  config.indentClasses = [ 'pls', 'plm', 'pll' ];
  config.justifyClasses = [ 'text-left', 'text-center', 'text-right', 'text-justify' ];

  // The minimum editor width, in pixels, when resizing it with the resize handle.
  config.resize_minWidth = 320;

  // Protect PHP code tags (<?...?>) so CKEditor will not break them when
  // switching from Source to WYSIWYG.
  // Uncommenting this line doesn't mean the user will not be able to type PHP
  // code in the source. This kind of prevention must be done in the server side
  // (as does Drupal), so just leave this line as is
  // PHP Code
  config.protectedSource.push(/<\?[\s\S]*?\?>/g);

  // Code tags
  config.protectedSource.push(/<code>[\s\S]*?<\/code>/gi);
  config.extraPlugins = '';
}
