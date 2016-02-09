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
  config.resize_minWidth = 450;

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

  /**
   * Append here extra CSS rules that should be applied into the editing area.
   * Example:
   * config.extraCss = 'body { color:#FF0000; }';
   */
  config.extraCss = '';

  /**
   * Sample extraCss code for the "marinelli" theme.
   */
  if (Drupal.settings.ckeditor.theme == "astarter") {
    config.extraCss += "";
  }

  /**
   * CKEditor's editing area body ID & class.
   * See http://drupal.ckeditor.com/tricks
   * This setting can be used if CKEditor does not work well
   * with your theme by default.
   */
  config.bodyClass = '';
  config.bodyId = '';

  /**
   * Sample bodyClass and BodyId for the "marinelli" theme.
   */
  if (Drupal.settings.ckeditor.theme == "astarter") {
    config.bodyClass = 'singlepage';
    config.bodyId = 'primary';
  }
}

/**
 * Sample toolbars
 */

// Toolbar definition for basic buttons
Drupal.settings.cke_toolbar_DrupalBasic = [ [ 'Format', 'Bold', 'Italic', '-', 'NumberedList','BulletedList', '-', 'Link', 'Unlink', 'Image' ] ];

// Toolbar definition for Advanced buttons
Drupal.settings.cke_toolbar_DrupalAdvanced = [
  ['Source'],
  ['Cut','Copy','Paste','PasteText','PasteFromWord','-','SpellChecker'],
  ['Undo','Redo','Find','Replace','-','SelectAll','RemoveFormat'],
  ['Image','Flash','Table','HorizontalRule','Smiley','SpecialChar','Iframe'],
  ['Maximize', 'ShowBlocks'],
  '/',
  ['Format'],
  ['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
  ['NumberedList','BulletedList','-','Outdent','Indent','Blockquote','CreateDiv'],
  ['JustifyLeft','JustifyCenter','JustifyRight','-','BidiRtl','BidiLtr'],
  ['Link','Unlink']
];

// Toolbar definiton for all buttons
Drupal.settings.cke_toolbar_DrupalFull = [
  ['Source'],
  ['Cut','Copy','Paste','PasteText','PasteFromWord','-','SpellChecker'],
  ['Undo','Redo','Find','Replace','-','SelectAll','RemoveFormat'],
  ['Image','Flash','Table','HorizontalRule','Smiley','SpecialChar','Iframe'],
  '/',
  ['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
  ['NumberedList','BulletedList','-','Indent','Blockquote','CreateDiv'],
  ['JustifyLeft','JustifyCenter','JustifyRight','-','BidiRtl','BidiLtr'],
  ['Link','Unlink'],
  '/',
  ['Format','Font','FontSize'],
];
