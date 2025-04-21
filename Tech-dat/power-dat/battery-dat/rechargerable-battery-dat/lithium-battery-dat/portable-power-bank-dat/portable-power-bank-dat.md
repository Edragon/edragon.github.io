
# portable-power-bank-dat

### How Power Bank Capacity (e.g., 20000 mAh) is Calculated

The capacity advertised on a power bank, such as 20000 mAh, typically represents the **total combined capacity of its internal battery cells**. Here's the breakdown:

1.  **Internal Battery Cells:**
    *   Power banks contain one or more individual battery cells, usually Lithium-ion (Li-ion) or Lithium-polymer (Li-Po).

2.  **Individual Cell Capacity:**
    *   Each internal cell has its own capacity rating, measured in milliampere-hours (mAh). Examples include 2500mAh, 3350mAh, 5000mAh per cell.

3.  **Parallel Connection:**
    *   To achieve a higher total capacity, these individual cells are connected **in parallel** inside the power bank.
    *   In a parallel circuit, the total capacity is the sum of the individual capacities.

4.  **Calculation Example:**
    *   A 20000 mAh power bank might be constructed using:
        *   4 cells × 5000 mAh/cell = `20000 mAh`
        *   6 cells × ~3350 mAh/cell ≈ `20100 mAh` (often rounded down or marketed as 20000 mAh)
        *   8 cells × 2500 mAh/cell = `20000 mAh`

**Key Considerations:**

*   **Cell Voltage:** This advertised capacity (e.g., 20000 mAh) is based on the **nominal voltage of the internal cells** (typically 3.6V or 3.7V).
*   **Output Voltage & Efficiency:** When charging a device, the power bank converts the internal cell voltage to the required output voltage (e.g., 5V, 9V, 12V via USB). This conversion process isn't 100% efficient; some energy is lost as heat.
*   **Rated Capacity:** Because of the voltage conversion and efficiency losses, the actual amount of charge delivered *to your device* at the output voltage will be lower than the internal cell capacity. This usable output is often listed separately as the **Rated Capacity** (e.g., "Rated Capacity: 12500mAh at 5V").


## ref


- [[injoinic-dat]] - [[IP5306-dat]] - [[IP5316-dat]]


