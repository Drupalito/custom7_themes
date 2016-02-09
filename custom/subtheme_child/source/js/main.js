
/**
 * @file
 * A JavaScript file for the theme.
 *
 */

(function ($, window, Drupal) {

  'use strict';

  var jsChildTheme = (function() {
    var custom = {};
    custom.customMethod = function (context, settings) {
      console.log(context);
      console.log(settings);
    };
    return custom;
  }());

  Drupal.behaviors.subtheme_child = {
    attach: function (context, settings) {

      jsChildTheme.customMethod(context, settings);

      // Open links in new window
      $('body', context).on('click', 'a[rel*="external"]', function() {
        window.open($(this).attr('href'));
        return false;
      });

      // Smooth scroll anchor
      $('.scroll, #scrollToTop').on('click', function (e) {
        e.preventDefault();
        var target = (this.hash) ? this.hash : 'html';
        $('html, body').stop().animate({
            'scrollTop': $(target).offset().top
        }, 900, function () {
            window.location.hash = target;
        });
      });

      // Scrolltop visible or invisible
      var $scrolltoTop = $('#scrollToTop');
      $(window).scroll(function() {
        ($(this).scrollTop() > 300) ? $scrolltoTop.addClass('scrollToTop-visible') : $scrolltoTop.removeClass('scrollToTop-visible scrollToTop-invisible');
        if ($(this).scrollTop() > 1200) {
          $scrolltoTop.addClass('scrollToTop-invisible');
        }
      });

    }
  };

})(jQuery, window, Drupal);
