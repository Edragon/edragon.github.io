

# https://www.espressif.com/sites/default/files/documentation/esp8684_hardware_design_guidelines_en.pdf

1. Set the module to UART Download mode by pulling IO9 (pulled up by default) low and IO8 high.

| pin | set  |
| --- | ---- |
| IO9 | low  |
| IO8 | high |
