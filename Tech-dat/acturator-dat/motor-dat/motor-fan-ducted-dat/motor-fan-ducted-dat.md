

# motor-fan-ducted-dat

- [[motor-fan-ducted-dat]] - [[motor-dat]] - [[fan-dat]] - [[FPV-whoop-cine-dat]] - [[FPV-dat]] - [[FUS-X111-dat]] - [[indoor-fly-dat]]


- [[propeller-FPV-dat]] - [[motor-fan-ducted-dat]]



## tech 

大螺距是为高速设计的，而涵道机的工作场景是低速/悬停 → 两者目标冲突。

🔬 原理：螺距和涵道的"矛盾"

螺距的本质：

    大螺距 = 桨叶角度大 = 每转"抓"更多空气
        → 需要「足够的前进速度」让气流顺畅通过
        → 前进慢了 → 桨叶攻角过大 → 【失速】⚠️


涵道机的实际工况：

    涵道机 = 低速/悬停为主（拍摄、室内穿梭）
        → 前进速度低
        → 大螺距桨在这种状态下：气流失速、推力骤降、电流暴涨


⭐️ 一句话：大螺距桨在涵道机上"吃不进气"（低速失速），费力不讨好。

📊 涵道 vs 开放桨的桨设计差异

涵道桨的特点：
- 多叶（3-5 叶）—— 靠叶数增加推力和响应，而不是靠螺距
- 螺距中低（相对同尺寸开放桨）
- 叶尖间隙小（靠涵道抑制叶尖涡流损失）
- 针对低速流场优化

开放桨的特点：
- 少叶（2-3 叶）—— 效率优先
- 螺距可以更大（高速时气流顺畅）
- 无涵道约束 → 高速效率好

核心逻辑：
涵道的"增益"发生在【低速/悬停】（抑制叶尖损失）
大螺距的"优势"发生在【高速】（气流顺畅通过桨盘）
          ↓
两者不在同一个工况区间 → 涵道机放大螺距 = 自相矛盾


📌 换桨的正确逻辑（涵道机）

推力不足
• 正确做法: 加叶数（3→5 叶）
• 错误做法: ❌ 加大螺距

续航/省电
• 正确做法: 减叶数（3→2 叶）+ 降螺距
• 错误做法: ❌ 加大螺距

响应更快
• 正确做法: 加叶数 / 减螺距
• 错误做法: ❌ 加大螺距

更静音
• 正确做法: 加叶数（5 叶）
• 错误做法: —

⚠️ 换桨的铁律：螺距必须匹配电机 KV + 电压
大螺距 + 高 KV + 高电压 = 电流爆炸（烧电机/电调）


🎯 对你的 X111（2540-3 原配）

2540-3 是厂家选配的合理方案：
2.5" 涵道 + 1106 3800KV + 3S-4S → 2540 三叶


改进方向（如果想换桨）：
- 想更稳/更静 → 试 5 叶涵道桨（如 Gemfan D63-5）→ 但效率会降（续航短）
- 想更省电 → 试 2 叶/低螺距（响应变弱）
- ⚠️ 别换大螺距（如 2.5×4.8）→ X111 的电机在 3S 下带不动（你悬停油门已经 60% 了，电机余量本来就小）

💡 结论

涵道机的桨选择原则：
1. 优先用【原厂/同规格】桨（厂家已匹配电机+涵道+电压）
2. 想调性能 → 改【叶数】，而非螺距 ⭐️
3. 大螺距 = 高速桨 = 与涵道机工况不匹配
4. ⚠️ 螺距必须与电机 KV/电压匹配（这是硬约束）






## fan-ducted for FPV 



Ducted fan machines (Ducted Fan / Cinewhoop class) — designs where the props are enclosed by a ring-shaped duct. The characteristics are very distinctive:

### Pros

1. High safety ⭐️ Biggest selling point
- Props are enclosed in the guard ring → hitting people/pets basically causes no injury and won't cut objects
- Can safely film indoors, near crowds, and close to people

2. Crash resistant and durable
- On impact the duct takes the force first → props and motors are protected (high survival rate after crashes)

3. "Duct gain" at low speed / hover
- Physics: the duct suppresses tip vortex losses → static thrust at hover +10~20%
- Airflow is constrained to be more regular

4. Stable flight
- Airflow constrained by the duct → more stable attitude, more stable footage (Cine friendly)

5. Can fly hugging objects
- Can hug walls, hug the ground, slip through gaps (guard ring protects the props)

6. Noise is partially shielded (some designs)

### Cons

1. Heavy ⚠️
- 4 duct structures + mounts → much heavier than an open-prop machine with the same wheelbase
- Naturally low thrust-to-weight ratio

2. Efficiency collapses at high speed ⚠️ Most fatal
- Large duct frontal area → a drag monster when flying forward fast
- Duct gain only holds at hover / low speed; once speed builds up, drag loss >> gain
- → Short endurance, cannot fly fast, cannot do long range

3. Zero tolerance for overweight
- Efficiency is already low; add weight → hover throttle spikes → motors overheat (the 2200mAh example from your last question is exactly this)

4. Poor wind resistance
- Low thrust-to-weight + large frontal area → drifts as soon as the wind blows

5. Bulky
- One size larger than an open-prop machine at the same wheelbase (not portable)

6. Poor heat dissipation
- Motors / ESCs are enclosed → poor cooling (especially fully enclosed designs)

7. Cost / maintenance
- Complex structure, expensive parts; duct deformation / damage hurts performance

### Three main ducted-fan classes

**Tiny Whoop**
• Size: 65-85mm
• Use: safe indoor flying

**Cinewhoop**
• Size: 2.5-3.5 inch
• Use: cinematic camera moves (filming close to people / objects)

**Large ducted fan**
• Size: e.g. DJI Avata
• Use: safe experience flying (with prop guards)

- [[DJI-dat]] - [[DJI-avata-dat]]

### tips 

What this means for your X111

The positioning of the X111 (2.5-inch ducted) perfectly reflects the ducted-fan traits:

✅ Safe to fly at home / in the garage (can't hit people / pets)
• Limitation, don't expect: ❌ no long-range / long-endurance flying (low efficiency)

✅ Crash resistant, low cost to practice
• Limitation, don't expect: ❌ no flying in strong wind (low thrust-to-weight)

✅ Smooth close-range filming****
• Limitation, don't expect: ❌ don't compare speed / endurance with the Mobula8

✅ Can fly hugging walls and slipping through gaps
• Limitation, don't expect: ❌ never add weight (extremely weight sensitive)

So your fleet split makes sense:
- X111 (ducted) → safe close range / indoor / filming people
- Mobula8 (open-prop 2-inch) → outdoor / wind resistance / longer range


## ref 