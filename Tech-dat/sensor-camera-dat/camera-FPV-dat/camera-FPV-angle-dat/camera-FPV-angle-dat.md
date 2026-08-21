


# camera-FPV-angle-dat

- [[camera-FPV-angle-dat]] - [[camera-FPV-dat]]


## Control

**“Feels inverted” with a 30° camera is usually not a wiring problem — it is a camera-tilt illusion.**

---

### Case 1: Normal — camera tilt illusion (most common)

**What happens:**

- Camera mounted at 30° up-tilt → in level flight the horizon sits in the lower third of the screen
- Your brain thinks the nose is pointing up (the aircraft is actually level)
- To make the image “look level” you instinctively push forward, which pitches down
- The aircraft is already diving, so pushing forward feels like “pitching into the ground”
- Result: you believe the controls are inverted

**Truth:** the channels are fine. Your reference frame is just offset 30° from the aircraft’s.

**Fixes:**

|   #   | Fix                                                                                                             |
| :---: | :-------------------------------------------------------------------------------------------------------------- |
|   1   | Climb first after takeoff — push the horizon back to the center to rebuild the “level view = level flight” feel |
|   2   | Get used to the tilt — practice in a simulator with the camera set to 30°; muscle memory will correct it        |
|   3   | Lower the tilt — beginners should start at 15-20°; 30° is for experienced freestyle pilots                      |

---

### Case 2: Real fault — reversed FC direction (check this)

If the aircraft moves the **opposite** way when you push pitch forward while hovering, the channels really are reversed:

| Check                    | What to look at                                                               |
| :----------------------- | :---------------------------------------------------------------------------- |
| Motor direction          | Verify motor spin and prop direction (a reversed prop pushes the wrong way)   |
| FC mounting              | FC board installed front-to-back reversed → pitch channel is inverted         |
| Radio channel direction  | Pitch channel set to REV/NOR incorrectly                                      |
| Betaflight receiver test | Push the stick and confirm the channel value changes in the correct direction |

**Verification in Betaflight:**

- Receiver tab: push pitch forward → Pitch should move from 1500 → 1900 (positive)
- If it goes the wrong way → set the Pitch channel to REV in your radio
- Motors tab: spin each motor and check direction with props on top:
  - Top-left / bottom-right: clockwise (CW)
  - Top-right / bottom-left: counter-clockwise (CCW)
  - Wrong direction = reversed

---

### Quick self-test

| Test                                               | Result                                | Verdict                                             |
| :------------------------------------------------- | :------------------------------------ | :-------------------------------------------------- |
| Hover, then slowly push pitch forward              | Aircraft noses down and moves forward | ✅ Channels fine → camera tilt illusion              |
| Hover, then push pitch forward                     | Aircraft pitches backward             | ❌ Channels really reversed → check FC / radio setup |
| Push forward, aircraft noses down but “drops fast” | Normal dive, but the view feels wrong | ✅ Tilt illusion + needs adaptation                  |

---

### Bottom line

**“Feels inverted” under a 30° camera = your view is offset 30° from the aircraft’s real attitude, not a reversed radio.**

Do the hover test to confirm the channels are correct, then spend half an hour in a simulator with a 30° view — the feeling disappears on its own.

If the aircraft genuinely moves the opposite way to your input, inspect the FC mounting and radio channel settings. If you need help, tell me your flight controller and radio model and I can help you troubleshoot.


## angle view 

A 0° camera angle is relative to the aircraft body, not relative to the ground.

---

**Key physics: forward flight = the whole aircraft tilts nose-down**

A multirotor cannot "raise its nose and run forward" (that is fixed-wing behavior). It moves forward entirely by tilting the whole airframe:

| State            | Hovering               | Forward flight                           |
| :--------------- | :--------------------- | :--------------------------------------- |
| Thrust direction | Upward                 | Tilted, so it has a horizontal component |
| Airframe         | Level                  | Nose-down 20-30°                         |
| Camera view      | Level / straight ahead | Pointing down                            |

To fly forward, the airframe must tilt nose-down (diverting part of the thrust to the horizontal). The faster the flight, the greater the tilt.

---

**What does a "0° camera angle" actually mean?**

0° camera angle = the camera is mounted parallel to the airframe (0° between camera and frame).

But when flying with the airframe tilted 25° forward:

- Actual camera pointing = airframe tilt (25°) + camera mount angle (0°) = **pointing 25° downward**
- Result: the view is almost all ground

**Angle compensation** = mounting the camera tilted upward (for example 25°) to cancel the airframe tilt:

- 25° mount angle + 25° airframe tilt = 0° → camera points level → the view sees ahead

---

**At a glance**

| Flight state        | Airframe tilt | Camera aim with 0° mount | View                   |
| :------------------ | :------------ | :----------------------- | :--------------------- |
| Hovering            | 0°            | Level ✅                  | Horizon centered       |
| Slow forward flight | 10°           | 10° downward             | Lots of ground in view |
| Fast forward flight | 25°           | 25° downward             | Almost all ground ⚠️    |
| Full-speed sprint   | 40°+          | 40° downward             | Purely ground ❌        |

---

**So what does it mean in practice?**

A 0° angle does not mean "you will never look down at the ground". It means "level view when hovering, but immediately looking at the ground during forward flight".

The purpose of tilt angle is **pre-compensation**: tilt the camera upward ahead of time so that when the airframe pitches down, the angles cancel out and you still look straight ahead at speed.

---

**Analogy**

| Camera angle | Analogy                                                                                                               |
| :----------- | :-------------------------------------------------------------------------------------------------------------------- |
| 0° camera    | Walking while looking straight ahead → once you accelerate (body leans forward), you only see the ground at your feet |
| 30° camera   | Running while looking up → when you lean forward under acceleration, your line of sight returns to straight ahead     |

This is why freestyle and racing pilots use a 25-35° tilt angle: they fly at full speed the whole time and need to "run looking up" to see ahead. Beginners flying slowly find 0° more intuitive, because the airframe barely tilts when hovering or flying slowly.