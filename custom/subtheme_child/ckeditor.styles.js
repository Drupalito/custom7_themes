/**
 * Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
 * For licensing, see LICENSE.html or http://ckeditor.com/license
 */

/**
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default
 */
if(typeof(CKEDITOR) !== 'undefined') {
  CKEDITOR.addStylesSet('drupal',
  [
    // Block Styles
    { name: 'Paragraph', element: 'p' },
    { name: 'Heading 2', element: 'h2' },
    { name: 'Heading 3', element: 'h3' },
    { name: 'Heading 4', element: 'h4' },
    { name: 'Heading 5', element: 'h5' },
    { name: 'Heading 6', element: 'h6' },
    { name: 'Pre Text', element: 'pre' },
    { name: 'Address', element: 'address' },

    // Inline Styles
    // { name: 'Strong'        , element: 'strong', overrides : 'b' },
    // { name: 'Emphasis'      , element: 'span', attributes: { 'class': 'italic' } },
    // { name: 'Underline'     , element: 'span', attributes: { 'class': 'underline' } },
    // { name: 'Strikethrough' , element: 'span', attributes: { 'class': 'strike' } },
    // { name: 'Subscript'     , element: 'sub' },
    // { name: 'Superscript'   , element: 'sup' },

    // { name: 'Big'           , element: 'big' },
    // { name: 'Small'         , element: 'small' },
    // { name: 'Typewriter'    , element: 'tt' },

    // { name: 'Variable'      , element: 'var' },

    // { name: 'Deleted Text'  , element: 'del' },
    // { name: 'Inserted Text' , element: 'ins' },

    // Inline Style
    { name: 'Computer Code'    , element: 'code' },
    { name: 'Keyboard Phrase'  , element: 'kbd' },
    { name: 'Sample Text'      , element: 'samp' },
    { name: 'Cited Work'       , element: 'cite' },
    { name: 'Inline Quotation' , element: 'q' },

    // Image Style
    { name: 'Image on Left', element: 'img', attributes: { 'class': 'alignleft' }},
    { name: 'Image on center', element: 'img', attributes: { 'class': 'aligncenter' }},
    { name: 'Image on Right', element: 'img', attributes: { 'class': 'alignright' } },
    { name: 'Image none', element: 'img', attributes: { 'class': 'alignnone' } },

    // Language direction
    { name: 'Language: RTL', element: 'span', attributes: { 'dir': 'rtl' } },
    { name: 'Language: LTR', element: 'span', attributes: { 'dir': 'ltr' } },
  ]);
}
