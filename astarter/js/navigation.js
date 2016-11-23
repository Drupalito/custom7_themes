
;(function($, window, document, undefined) {

  "use strict";

  // Create the defaults once
  var pluginName = "navigation",
    defaults = {
      title: 'Menu',
      type: 'inline', // inline|block
      expanded: {
        title: 'Open',
        icon: '<span class="i i-arrow-down" aria-hidden="true"></span>'
      }
    };

  // The actual plugin constructor
  function Plugin ( element, options ) {
    this.element = element;
    this.settings = $.extend({}, defaults, options);
    this._defaults = defaults;
    this._name = pluginName;
    this.init();
  }

  // Avoid Plugin.prototype conflicts
  $.extend(Plugin.prototype, {
    init: function() {
      var plugin = this,
          $this = $(this.element);

      return $this.each(function() {
        $(this).prepend('<p class="menu-button">' + plugin.settings.title + '</p>');
        $(this).find('.menu-button').on('click', function() {
          $(this).toggleClass('is-actived');
          var $mainMenu = $(this).next('ul');
          if ($mainMenu.hasClass('is-opened')) {
            $mainMenu.hide().removeClass('is-opened');
          }
          else {
            $mainMenu.show().addClass('is-opened');
          }
        });
        plugin.submenu();
      });
    },
    openSubmenu: function() {

    },
    hasSubmenu: function() {

    },
    submenu: function() {
      var plugin = this,
          $this = $(this.element);

      var $menuItem = $this.find('.menu__item--hasmenu');
      $menuItem.prepend('<button class="menu__btn menu__btn-menu">' + plugin.settings.expanded.icon + ' <span class="hide">' + plugin.settings.expanded.title + '</span></button>');

      $this.find('.menu__btn').on('click', function(e) {
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
    }
  });

  // A really lightweight plugin wrapper around the constructor,
  // preventing against multiple instantiations
  $.fn[pluginName] = function(options) {
    return this.each(function() {
      if (!$.data(this, 'plugin_' + pluginName)) {
        $.data(this, 'plugin_' +
          pluginName, new Plugin(this, options));
      }
    });
  };

})(jQuery, window, document);
