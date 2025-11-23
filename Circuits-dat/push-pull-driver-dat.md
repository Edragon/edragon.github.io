
# push-pull-driver-dat.md

```markdown
# Push-Pull Driver (Totem-Pole Output)

A **push-pull driver** is an output stage that uses **two active transistors**:

- One transistor **pushes** the output HIGH  
- Another transistor **pulls** the output LOW  

The output is actively driven in **both directions**.

---

# How Push-Pull Works

- **HIGH output:**  
  The upper transistor turns ON → output driven to Vcc  
- **LOW output:**  
  The lower transistor turns ON → output driven to GND  
- Never both ON at the same time (to avoid shoot-through)

This is also called a **totem-pole output**.

---

# Characteristics

| Feature | Push-Pull Driver |
|--------|-------------------|
| Drives HIGH? | ✔️ Yes (actively) |
| Drives LOW? | ✔️ Yes (actively) |
| Needs pull-up resistor? | ❌ No |
| Speed | Very fast edges |
| Output impedance | Low |
| Can multiple outputs connect together? | ❌ No (will short-circuit) |

---

# Advantages

- Fast transitions  
- Strong driving capability  
- No external pull-up needed  
- Precise logic levels  

---

# Disadvantages

- **Cannot be wired together** with another push-pull output  
- If two devices drive the same line at different levels → **short circuit**

A **push-pull driver** is an output that actively drives both HIGH and LOW, unlike open-drain/open-collector which only pull LOW and rely on a pull-up resistor for HIGH.


## ref 

- [[circuits-dat]]