

(function ($, window, Drupal) {
  Drupal.behaviors.scrolltotop = {
    attach: function (context, settings) {
      $("#share").jsSocials({
        url: window.location.href,
        showLabel: false,
        showCount: "inside",
        shares: ["email", "twitter", "facebook", "googleplus", "linkedin"]
      });
    }
  };
})(jQuery, window, Drupal);
