// Google Analytics (gtag.js)
window.dataLayer = window.dataLayer || [];
function gtag(){dataLayer.push(arguments);}
gtag('js', new Date());

// Load Google Analytics script and configure when it's ready
(function() {
  var script = document.createElement('script');
  script.async = true;
  script.src = 'https://www.googletagmanager.com/gtag/js?id=G-ZCWWBBG7BH';
  script.onload = function() {
    // Configure Google Analytics after script loads
    gtag('config', 'G-ZCWWBBG7BH', {
      'anonymize_ip': true,
      'cookie_expires': 63072000  // 2 years
    });
  };
  document.head.appendChild(script);
})();