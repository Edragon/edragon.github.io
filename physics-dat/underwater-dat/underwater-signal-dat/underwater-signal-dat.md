

# underwater-signal-dat


- [[underwater-signal-dat]] - [[underwater-dat]] - [[USV-dat]] - [[waterproof-dat]]

- [[WIFI-USB-pocket-dat]] - [[wifi-dat]]

The phone antenna is built into the device, so it cannot be physically extended externally without disassembly. However, there are several practical ways to work around this limitation, ranging from simple trials to engineering-level solutions.

---

## 1. USB Cable Out to External Network Module (Most Reliable) ✅

Although the phone cannot be opened, every phone has a USB interface, which acts as a natural external communication channel:

```text
Phone (inside waterproof housing)
  │ USB-C / Lightning cable (passes through waterproof seal)
  ▼
Floating buoy with external 4G modem / WiFi modem
  (antenna stays above the water)
```

The idea is simple: the phone itself does not communicate directly. Instead, the communication task is handed off to an external modem mounted on the buoy, and the phone connects to it through USB.

### Android
- Implementation: USB OTG + external 4G modem (RNDIS mode) or external WiFi modem ✅

### iPhone
- Implementation: USB-C to external modem (support is limited and must be confirmed) ⚠️

### General solution
- Implementation: USB to Ethernet + surface router

### Key challenge
The USB cable must pass through the waterproof enclosure using a sealed cable gland (IP68 rated) or a marine-grade underwater connector such as Subconn.

---

## 2. The "Air Bag" Workaround (Zero Modification, Worth Trying) ✅

Keep an air pocket inside the waterproof bag or shell, and orient the phone so its antenna side faces upward.

This creates a layer of air around the antenna rather than water, which can significantly improve signal quality.

### Principle
The phone antenna is inside the body. If it is separated from water by a small air gap and a waterproof membrane, the attenuation is much lower than when the antenna is directly submerged. The membrane is also a dielectric and causes some loss, but it is still much better than having the antenna directly in water—typically a 10–20 dB improvement in many practical cases.

### How to do it
- Place the phone vertically in the waterproof bag
- Keep the bag opening at the top, with the antenna side facing upward
- Leave roughly one-third of the bag volume as air for buoyancy

At depths within 1 meter, it may change from "no signal at all" to "barely usable". This is worth trying because the cost is zero.

---

## 3. Functional Separation (Most Practical in Real Use) ✅

The phone does not need to communicate underwater; it only records data. Communication is handled by separate equipment:

- Underwater: phone or action camera → captures video and stores locally
- On the surface: buoy device with 4G module → uploads data
- Return path: buoy data → cloud → viewed on your phone

This is the common pattern in many underwater recording systems. For example, GoPro captures underwater, while a WiFi float transmits data when the device is near the surface.

Key advantage:
- The phone can focus on image capture
- Data transfer happens after the device surfaces or when a buoy is used

---

## 4. Custom Waterproof Housing with Cable Pass-Through (Engineering Level)

If you insist on keeping the phone in hand while maintaining real-time communication:

Custom waterproof case → drilled opening with waterproof connector (IP68 gland)
→ USB cable routed out → external modem on floating buoy → antenna above water

### Risks
- Drilling the housing can compromise waterproof integrity
- Professional sealing is required
- The housing must be designed carefully to avoid leakage

### Cost estimate
- Cable gland + modem + buoy hardware: approximately ¥100–300

---

## Comparison Summary

| Solution | Cost | Difficulty | Effectiveness | Best Use Case |
| --- | --- | --- | --- | --- |
| USB external modem | ¥150–300 | Medium | ✅ Good | Real-time communication |
| Air bag workaround | ¥0 | Low | ⚠️ Limited | Quick test, low-cost trial |
| Functional separation | ¥0 | Low | ✅ Good | Recording-focused missions |
| Custom shell with cable pass-through | ¥300+ | High | ✅ Best | Professional engineering scenarios |

---

## Recommended Approach

1. First try the air bag method: it costs nothing, and if it works within 1 meter depth, you can use it immediately.
2. For real-time communication, use USB out to a floating 4G modem. Android is the preferred option.
3. If your main goal is recording, use underwater recording on the phone and upload data separately from a surface buoy. This is the simplest and most reliable setup.

In short, if the requirement is real-time connectivity, the best technical path is to move the communication hardware out of the underwater housing and keep the antenna above the water. If the requirement is only capture and later upload, functional separation is the most practical solution.



## ref 

