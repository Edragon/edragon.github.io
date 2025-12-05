# Three-Phase BLDC Motor Data

The common three thick motor wires (yellow, green, blue) found on electric scooters are actually:

## ✅ Brushless DC Motor (BLDC) or Permanent Magnet Synchronous Motor (PMSM)

Also known as:

- Three-phase brushless motor
- Hub Motor
- Brushless DC Motor

These three wires are the motor's three-phase power lines, used by the controller to drive the motor's rotation.

## 🔍 Structure Features of Three-Wire Motors in Electric Scooters

### 1️⃣ Three-phase windings (U / V / W phases)

The usual colors are: yellow, green, blue

These three phases are commutated in sequence to make the motor spin.

### 2️⃣ Permanent magnet rotor (magnets inside the wheel)

The center is the rotor (with magnets).

Bicycles and scooters both use hub-type structures.

### 3️⃣ Stator on the outer ring of the coil

The motor is an outer rotor structure (the shell rotates).

The stationary part is inside the coil.

## ⚡ Why are there only three thick wires? Isn't that too few?

It's not too few, because:

These three wires are the power wires.

Some motors also have Hall sensors (5 thin wires).

Electric scooters usually have two types:

| Type                | Number of Wires         | Features                                 |
|---------------------|------------------------|------------------------------------------|
| Sensorless BLDC     | Only 3 thick wires     | Starts by induction, more vibration at low speed |
| With Hall PMSM/BLDC | 3 thick + 5 thin wires | Smooth start, suitable for FOC control    |

## 🛴 Why do electric scooters use three-phase brushless motors?

Because the advantages are obvious:

- High torque
- High efficiency
- Silent operation
- Maintenance-free (brushless, no wear)
- Simple structure (directly integrated in the wheel)

Almost all modern scooters (Xiaomi, Ninebot, Kaabo, etc.) use this type.


## ref 

- [[motor-BLDC-dat]] - [[motor-hub-dat]]