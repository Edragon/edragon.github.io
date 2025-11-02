
# double-side-PCB-dat

- [[fab-stencil-double-side]]


## General Rules

| Factor                            | Rule of Thumb                                                                 | Reason                                                           |
| --------------------------------- | ----------------------------------------------------------------------------- | ---------------------------------------------------------------- |
| **Component size & weight**       | **Lighter / smaller SMD components are placed first**, usually on the bottom. | Heavy parts may fall off during second reflow.                   |
| **Through-hole parts**            | Always populated **after reflow** (usually last step).                        | Reflow ovens are for SMD; THT is wave-soldered or hand-soldered. |
| **BGA, QFN, Fine-pitch ICs**      | Usually go on the **primary (top) side**.                                     | Better solder joint reliability and inspection access.           |
| **Connectors, mechanical parts**  | Preferably on the **primary side**.                                           | Reduces stress during use.                                       |
| **Assembly process optimization** | PCB side with **more components** usually chosen as **first (primary) side**. | Reduces machine setup time and cost.                             |


- [[fab-stencil]]





## ref 

- [[double-side-PCB]] - [[PCB-design]]