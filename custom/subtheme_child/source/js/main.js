
/**
 * @file
 * A JavaScript file for the theme.
 *
 * subtheme_child Drupal Theme
 */

;(function($, window, document, undefined) {

  $.navigation = function(element, options) {

    var defaults = {
      title: "Menu",
      expanded: {
        title: "Open",
        icon: '<span class="i i-arrow-down" aria-hidden="true"></span>'
      }
    }

    var plugin = this;

    plugin.settings = {}

    var $element = $(element),
         element = element;

    var submenu = function() {

      $element.find('.menu__item--hasmenu').prepend('<button class="menu__btn menu__btn-menu">' + plugin.settings.expanded.icon + ' <span class="hide">' + plugin.settings.expanded.title + '</span></button>');
      $element.find('.menu__btn').on('click', function(e) {
        var $el = $(this);
        var $ulSibling = $el.siblings('ul');

        $el.toggleClass('submenu-opened');
        if ($ulSibling.hasClass('is-opened')) {
          $ulSibling.removeClass('is-opened').hide();
        }
        else {
          $ulSibling.addClass('is-opened').show();
        }
      });
    };

    plugin.init = function() {
      plugin.settings = $.extend({}, defaults, options);

      return $element.each(function() {
        $(this).prepend('<p class="menu-button">' + plugin.settings.title + '</p>');
        $(this).find('.menu-button').on('click', function() {
          $(this).toggleClass('is-actived');
          var mainmenu = $(this).next('ul');
          if (mainmenu.hasClass('is-opened')) {
            mainmenu.hide().removeClass('is-opened');
          }
          else {
            mainmenu.show().addClass('is-opened');
          }
        });

        submenu();

      });
    };

    plugin.init();
  }

  $.fn.navigation = function(options) {
    return this.each(function() {
      if (undefined == $(this).data('navigation')) {
        var plugin = new $.navigation(this, options);
        $(this).data('navigation', plugin);
      }
    });
  }
})(jQuery, window, document);

(function ($, window, Drupal) {

  // 'use strict';

  // var jsChildTheme = (function() {
  //   var custom = {};
  //   custom.customMethod = function (context, settings) {
  //     console.log(context);
  //     console.log(settings);
  //   };
  //   return custom;
  // }());

  Drupal.behaviors.subtheme_child = {
    attach: function (context, settings) {

      // jsChildTheme.customMethod(context, settings);

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

      $("#block-system-main-menu").navigation();

    }
  };

})(jQuery, window, Drupal);
