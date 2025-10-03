
# sunxi-errors-dat

- [[sunxi-log-dat]]

## Unable to mount root fs on unknown-block


```
[    3.170114] ---[ end Kernel panic - not syncing: VFS: Unable to mount root fs on unknown-block(0,0) ]---
```


## **Error Meaning**
- **VFS: Unable to mount root fs** → Kernel started but could not find or mount the root filesystem.
- **unknown-block(0,0)** → Kernel didn’t find the block device for rootfs (often means missing drivers or wrong parameters).

---

### **Common Causes**

| Cause | Explanation |
|-------|-------------|
| **Incorrect rootfs path in bootloader** | Kernel parameter `root=` may point to a wrong device. |
| **Missing storage drivers** | Kernel was built without drivers for your storage device (SD card, eMMC, SATA, etc.). |
| **Corrupted root filesystem** | Root filesystem may be damaged or missing. |
| **Wrong DTB (Device Tree Blob)** | Device tree does not match hardware, so root device isn’t recognized. |
| **Wrong kernel configuration** | Missing CONFIG support for your filesystem type (ext4, squashfs, etc.). |

On Sunxi devices (Allwinner), bootloader is usually **u-boot** or **barebox**.

- Look at the boot command in `boot.cmd` or `boot.scr`.
- Check the `root=` parameter:

Here:
- `/dev/mmcblk0p2` means second partition of SD/eMMC.
- `rootwait` → wait for device to be ready.

**Possible issues:**
- Wrong partition number.
- Missing `rootwait` (device might not be ready when kernel tries to mount).

