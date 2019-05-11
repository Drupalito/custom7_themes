<?php

/**
 * @file
 * Theme callbacks for the file entity module.
 */

/**
 * Copy of theme_file_link() for linking to the file download URL.
 *
 * @see theme_file_link()
 */
function astarter_file_entity_download_link($variables) {
  $file = $variables['file'];
  $uri = file_entity_download_uri($file);

  // Human-readable names, for use as text-alternatives to icons.
  $mime_name = array(
    'application/msword' => t('Microsoft Word'),
    'application/vnd.ms-excel' => t('Microsoft Excel'),
    'application/vnd.ms-powerpoint' => t('Microsoft Powerpoint'),
    'application/pdf' => t('PDF'),
    'video/quicktime' => t('Movie'),
    'audio/mpeg' => t('Audio'),
    'audio/wav' => t('Audio'),
    'image/jpeg' => t('Image'),
    'image/png' => t('Image'),
    'image/gif' => t('Image'),
    'application/zip' => t('Package'),
    'text/html' => t('HTML'),
    'text/plain' => t('Texte'),
    'application/octet-stream' => t('Binaire'),
  );

  $mimetype = file_get_mimetype($file->uri);
  $icon = theme('file_icon', array(
    'file' => $file,
    'icon_directory' => $variables['icon_directory'],
    'alt' => !empty($mime_name[$mimetype]) ? $mime_name[$mimetype] : t('File'),
  ));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $uri['options']['attributes']['type'] = $file->filemime . '; length=' . $file->filesize;

  $uri['options']['attributes']['class'][] = 'file media-element';
  $uri['options']['attributes']['class'][] = 'file--entity';
  $uri['options']['attributes']['class'][] = 'file--pdf';
  $uri['options']['html'] = TRUE;

  if (property_exists($file, 'override')) {
    if (in_array('attributes', array($file->override))) {
      $uri['options']['attributes']['class'][] = $file->override['attributes']['class'][1];
    }
  }

  // Provide the default link text.
  if (!isset($variables['text'])) {
    $variables['text'] = t('Download') . '&nbsp;: ' . t('[file:name]');
  }

  // Perform unsanitized token replacement if $uri['options']['html'] is empty
  // since then l() will escape the link text.
  $variables['text'] = token_replace($variables['text'], array('file' => $file), array('clear' => TRUE, 'sanitize' => !empty($uri['options']['html'])));

  $html = '<span class="file__icon">' . $icon . '</span><span class="file__content"><span class="file__title h4 my-0">' . $variables['text'] . '</span> <small class="file__meta default-color">' . $mime_name[$mimetype] . ' - ' . format_size($file->filesize) . '</small></span>';

  $output = l($html, $uri['path'], $uri['options']);
  return $output;
}
