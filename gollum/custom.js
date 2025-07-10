// Google Analytics (gtag.js)
(function() {
  var script = document.createElement('script');
  script.async = true;
  script.src = 'https://www.googletagmanager.com/gtag/js?id=G-ZCWWBBG7BH';
  document.head.appendChild(script);
})();

window.dataLayer = window.dataLayer || [];
function gtag(){dataLayer.push(arguments);}
gtag('js', new Date());
gtag('config', 'G-ZCWWBBG7BH', {
  'anonymize_ip': true,
  'cookie_expires': 63072000  // 2 years
});