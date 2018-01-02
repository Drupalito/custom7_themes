
(function ($, Drupal) {

  // Smooth scroll anchor.
  // @example Drupal.smoothScroll('.scroll');
  var smoothScroll = function (element) {
    $(element).on('click', function (e) {
      e.preventDefault();
      var target = (this.hash) ? this.hash : 'html';
      $('html, body').stop().animate({
        'scrollTop': $(target).offset().top
      }, 900, function () {
        window.location.hash = target;
      });
    });
  };

  Drupal.behaviors.astarter = {
    attach: function(context, settings) {

      var position = $(window).scrollTop();

      // Open links in new window
      $('body', context).on('click', 'a[rel*="external"]', function(event) {
        window.open($(this).attr('href'));
        return false;
      });

      smoothScroll('.scroll');

      // Responsive menu
      if (jQuery.fn.navigation) {
        $('#block-system-main-menu', context).navigation();
      }

    }
  };

})(jQuery, Drupal);
