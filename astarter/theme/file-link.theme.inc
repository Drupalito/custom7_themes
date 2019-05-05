<?php

function astarter_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];
  $url = file_create_url($file->uri);

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
    'icon_directory' => $icon_directory,
    'alt' => !empty($mime_name[$mimetype]) ? $mime_name[$mimetype] : t('File'),
  ));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
      'class' => array('file media-element'),
    ),
    'html' => TRUE
  );

  if (property_exists($file, 'override')) {
    if (in_array('attributes', array($file->override))) {
      $options['attributes']['class'][] = $file->override['attributes']['class'][1];
    }
  }

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    // $options['attributes']['title'] = check_plain($file->filename);
  }

  $options['attributes']['title'] = ($link_text) . ' (' . $mime_name[$mimetype] . ' - ' . format_size($file->filesize) . ')';

  $html = '<span class="file__icon">' . $icon . '</span> <span class="file__content"><span>' . $link_text . '</span></span>';

  $output = l($html, $url, $options);
  return $output;
}
