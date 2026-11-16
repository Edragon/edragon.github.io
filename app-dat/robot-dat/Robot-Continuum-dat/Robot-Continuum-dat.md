


# Robot-Continuum-dat

- [[Robot-Continuum-dat]] - [[robot-dat]] 

## Open-source continuum arms — a practical route

Yes, and the path is fairly clear. One reality check first: hardware-type open-source continuum arms generally have low star counts (tens to a few hundred), and the ones that are genuinely **active + backed by a paper + reproduced by someone** are concentrated in a handful of lab repositories. Sorted below by ease of getting started.

### 1. Easiest to start with: ENDO (~£100, Arduino library ready-made)

ENDO, from Open Source Medical Robots — a 3-segment, 3-DOF continuum arm:

| Item | Detail |
| --- | --- |
| **Backbone** | Rigid discs (ABS, φ15×4 mm) + flexible ligaments (TPU, 2×1 mm cross-section), all 3D printed |
| **Tendons** | 4-tendon drive (saves motor torque versus a 3-tendon triangle layout, and is simpler to control) |
| **Actuation** | 6 × MG996R servos + progressive pulley set |
| **Controller** | Arduino Uno + 16-channel PWM servo board |
| **Software** | "Endo-Continuum-Robot-Library" — **searchable directly in the Arduino Library Manager** |
| **Cost** | About £100 for the full set; ~4 hours to assemble if you are handy |

The advantage is a central through-bore you can pass tools through (light, gripper, cutting head), and it also comes with a one-piece gripper printed in a single run. This is what I recommend most for a first continuum arm.

- Repo: https://github.com/OpenSourceMedicalRobots
- Same-lineage earlier version (includes parametric SolidWorks files and a full parameter table: backbone diameter 15 mm, disc spacing 6 mm, ligament angle 40°, 5 discs per segment, 3 segments total):
  https://github.com/VisakanMathy/Continuum-Robot
- Paper (IEEE RA-L 2021): https://arxiv.org/html/2101.01080v1

One pitfall the paper itself admits: tendon-driven assembly needs manual zero calibration (so that every segment's tendon has equal tension at motor position 0). This error is unavoidable — the paper's own wording is that it introduces "a number of potential inaccuracies due to human errors". You will hit this immediately when you DIY it.

### 2. Research-grade platform: DLR tendon-driven continuum mechanism

TendonDrivenContinuum from DLR (German Aerospace Center), positioned as "a common platform for benchmarking across the field":

> The proposed mechanical design including all components is open source, whereas electronics and actuation are off-the-shelf.

- Repo: https://github.com/DLR-RM/TendonDrivenContinuum
- Paper: Deutschmann, Reinecke, Dietrich, "Open Source Tendon-driven Continuum Mechanism", RoboSoft 2022

Its value is not that it is "fun" — it is that the mechanical design has been calibrated and validated. If your goal is control / state-estimation research rather than playing with mechanisms, using it as a baseline saves you six months over designing your own.

### 3. Modular assembly: CRAFT (new in 2026, the most flexible)

CRAFT from the University of Toronto Continuum Robotics Lab — a library of 3D-printed modules; 6 stiffness modules can be joined in any order:

`Low Stiffness` / `Medium` / `High` / `Directional` / `Uni-Directional` / `Extensible`

Each module is built from discs, rings, flexure elements (Octo-Flex / leaf spring / reinforced infill / parallel springs) and rivets, with STEP + STL both provided. You can deliberately build multi-segment arms with stiffness varying along the length — something none of the other open-source projects offer.

- Repo: https://github.com/ContinuumRoboticsLab/CRAFT
- Paper (npj Robotics 2026): https://www.nature.com/articles/s44182-026-00107-x

The same lab also has OpenCR-Hardware, with a spatial tendon-driven prototype (LOTR_TDCR-spatial, type-II segments, 3 tendons) and reusable actuation modules (BOM included; tendons are McMaster 9442T4):

https://github.com/ContinuumRoboticsLab/OpenCR-Hardware

### 4. Most advanced and most expensive: CoLI

CoLI's selling point is single-run multi-material printing (PLA body + TPU 95A flexure hinges), so almost no assembly, plus matching isomorphic teleoperation (direct master-slave mapping, no kinematic model needed), and support for imitation learning.

| Item | Detail |
| --- | --- |
| **Printer** | Bambu Lab H2D (or another dual-nozzle machine) |
| **Slave arm** | 9 × Dynamixel XC430-T240BB-T |
| **Master arm** | 9 × Dynamixel XL330-M288-T |
| **Tendon** | 1.5 mm Kevlar |

- Project page: https://tangrobot.github.io/CoLI-website
- Repo: https://github.com/TangRobot/CoLI

18 Dynamixels add up to a four-figure USD cost. Not recommended as a starting point unless learning-based control is exactly what you want to do.

### 5. Side-by-side comparison

| Project | Segments / DOF | Tendons | Actuation | Cost | Best for |
| --- | --- | --- | --- | --- | --- |
| ENDO / VisakanMathy | 3 segments / 3-DOF | 4 | MG996R ×6 | ~£100 | A first build |
| DLR TDCM | Single mechanism | Multiple | Off-the-shelf industrial parts | Mid | Control / calibration research |
| CRAFT | Multi-segment, configurable | Configurable | Your choice | Mid | Variable stiffness / custom geometry |
| CoLI | 3 segments | 9 | Dynamixel ×18 | High | Learning-based control research |

### 6. What I would advise you to do (matched to your build skills)

1. **Step one: ENDO.** The reason is the ready-made Arduino library, a coffee-machine-level cost, and something working in 4 hours. Use it first to get a feel for tendon drive — tension, backlash, gravity sag, zero calibration. You have to step on those pitfalls yourself.
2. **Step two: rebuild ENDO using CRAFT modules.** ENDO's backbone is fixed-stiffness; CRAFT gives you 6 stiffness modules. Swap ENDO's segments for CRAFT's `High` + `Directional` combination and you can feel for yourself how variable stiffness affects end-effector accuracy. This step pays off far more than changing motors.
3. **Step three: move to the DLR mechanism when you need precise experiments.** Its mechanical parts are calibrated, so you can align your results with the published data.

### 7. Two realities you must know in advance

**① No continuum arm comes with a complete "open source and it just runs" stack.** Every project above gives you either pure CAD, or CAD plus Arduino-level control. The kinematic model (Cosserat rod / constant-curvature assumption), state estimation, and visual servoing all have to be built by you. On the simulation side you can plug in PyElastica (open-source Cosserat rod implementation) or SoRoSim (a MATLAB toolbox for geometrically exact variable-strain models) — but that is a separate chain of work.

**② The accuracy ceiling of tendon drive is set by the tendon and friction, not by your control algorithm.** To improve accuracy, prioritise a low-friction tendon sheath (PTFE / Teflon liner) plus closed-loop tension sensing, not PID tuning. The ENDO paper specifically mentions routing a separate fixed-length PTFE tube so that the gripper tendon does not disturb backbone motion — that is a pitfall they had already stepped on.


## ref


- ENDO paper (£100 cost, ABS+TPU, 4 tendons, 6 servos, zero-calibration issue):
  https://arxiv.org/html/2101.01080v1 ／ IEEE https://ieeexplore.ieee.org/document/9273083
- DLR tendon-driven continuum mechanism (RoboSoft 2022): https://github.com/DLR-RM/TendonDrivenContinuum
- CRAFT module library (npj Robotics 2026): https://github.com/ContinuumRoboticsLab/CRAFT
- OpenCR-Hardware (includes actuation-module BOM and spatial 3-tendon prototype): https://github.com/ContinuumRoboticsLab/OpenCR-Hardware
- CoLI (single-unit multi-material printing + isomorphic teleoperation): https://tangrobot.github.io/CoLI-website


