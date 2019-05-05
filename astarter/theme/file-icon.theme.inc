<?php

function astarter_file_icon($variables) {
  $file = $variables['file'];
  $alt = $variables['alt'];
  $icon_directory = $variables['icon_directory'];
  $mime = check_plain($file->filemime);
  $icon_url = file_icon_url($file, $icon_directory);

  $mime_icon = array(
    'application/msword' => '<span class="fa fas fa-file-word-o" aria-hidden="true"></span>',
    'application/vnd.ms-excel' => '<span class="fa fas fa-file-excel-o" aria-hidden="true"></span>',
    'application/vnd.ms-powerpoint' => t('Office presentation icon'),
    'application/pdf' => '<span class="fa fas fa-file-pdf-o" aria-hidden="true"></span>',
    'video/quicktime' => '<span class="fa fas fa-file-video-o" aria-hidden="true"></span>',
    'audio/mpeg' => '<span class="fa fas fa-file-audio-o" aria-hidden="true"></span>',
    'audio/wav' => '<span class="fa fas fa-file-audio-o" aria-hidden="true"></span>',
    'image/jpeg' => '<span class="fa fas fa-file-image-o" aria-hidden="true"></span>',
    'image/png' => '<span class="fa fas fa-file-image-o" aria-hidden="true"></span>',
    'image/gif' => '<span class="fa fas fa-file-image-o" aria-hidden="true"></span>',
    'application/zip' => '<span class="fa fas fa-file-archive-o" aria-hidden="true"></span>',
    'text/html' => '<span class="fa fas fa-file-code-o" aria-hidden="true"></span>',
    'text/plain' => '<span class="fa fas fa-file-o" aria-hidden="true"></span>',
    'application/octet-stream' => '<span class="fa fas fa-file-text" aria-hidden="true"></span>',
  );

  if (isset($mime_icon[$mime])) {
    return $mime_icon[$mime];
  }
  else {
    return '<img class="file-icon" alt="" src="' . $icon_url . '" />';
  }
}
