
# image-dat

## image formats

## 🆔 Quick Comparison

| Format   | Bits/Pixel | Colors          | Memory Size | Quality       | Typical Use           |
|----------|------------|----------------|-------------|--------------|-----------------------|
| RGB888   | 24         | ~16.7M         | High        | Excellent    | Photography, UI, HDMI |
| RGB565   | 16         | ~65K           | Medium      | Good         | Small LCD, IoT        |
| YUV422   | 16         | N/A (diff model)| Medium     | Good for video | Cameras, streaming    |

---

💡 **Summary:**  
- **RGB888** → Best color accuracy.  
- **RGB565** → Saves memory, okay for displays.  
- **YUV422** → Efficient for video, focuses on brightness detail.

## YUV422

- **Meaning:** Y = Luma (brightness), U & V = Chrominance (color).
- **"422"** means:
- Y (brightness) sampled for **every pixel**.
- U and V sampled for **every 2 pixels** (horizontally).
- **Bits per pixel:** Usually 16 bits.
- **Layout example (2 pixels):**

    Y0 U0 Y1 V0

- **Usage:** Video compression, cameras — reduces bandwidth while keeping brightness sharp.

## RGB565

- **Meaning:** Red — 5 bits, Green — 6 bits, Blue — 5 bits.
- **Bits per pixel:** `5 + 6 + 5 = 16 bits` (2 bytes)
- **Color depth:** 65,536 colors.
- **Layout example (per pixel):**

    RRRRR GGGGGG BBBBB

- **Usage:** LCD displays, embedded systems where memory and bandwidth are limited.

## RGB888

- **Meaning:** Red, Green, Blue — 8 bits per color channel.
- **Bits per pixel:** `8 + 8 + 8 = 24 bits` (3 bytes)
- **Color depth:** 16,777,216 colors.
- **Layout example (per pixel):**

    RRRRRRRR GGGGGGGG BBBBBBBB

- **Usage:** High-quality images, full color fidelity.


## ref 

- [[image-dat]]