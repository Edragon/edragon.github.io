
# freertos-dat

| Feature / RTOS          | FreeRTOS                          | Zephyr RTOS                              | ThreadX (Azure RTOS)               | Bare-Metal (No RTOS)           |
| ----------------------- | --------------------------------- | ---------------------------------------- | ---------------------------------- | ------------------------------ |
| **License**             | MIT (Permissive, Free)            | Apache 2.0 (Permissive, Free)            | Microsoft EULA (Free, but limited) | None                           |
| **Footprint**           | Very Small (<10 KB)               | Medium (~50–100 KB)                      | Small (~10–20 KB)                  | Very Small                     |
| **Real-Time**           | Yes (preemptive, deterministic)   | Yes (configurable RT, preemptive)        | Yes (deterministic RTOS)           | Depends on implementation      |
| **Ease of Use**         | Simple API, easy learning curve   | More complex, powerful config system     | Easy API, good documentation       | Full control but more effort   |
| **Hardware Support**    | Very wide (ARM, RISC-V, etc.)     | Very wide + device trees                 | Good (mainly ARM, RISC-V, x86)     | Manual per-device work         |
| **Task Management**     | Yes (tasks, priorities)           | Yes (threads, priorities, SMP)           | Yes (threads, priorities)          | Manual state machine           |
| **Synchronization**     | Semaphores, mutexes, queues       | Semaphores, FIFOs, message queues        | Semaphores, mutexes, event flags   | Manual implementation          |
| **File System Support** | External (e.g., FatFs)            | Native FS (e.g., LittleFS, FatFS)        | With Azure FileX                   | Manual or third-party          |
| **Networking**          | External (e.g., lwIP)             | Native (TCP/IP stack, 6LoWPAN)           | Azure NetX Duo (IPv4/IPv6)         | External, complex to integrate |
| **Power Management**    | Basic, user-implemented           | Advanced (built-in PM framework)         | Good (some MCU-specific features)  | Manual                         |
| **Security/IoT**        | AWS IoT support (via Amazon RTOS) | Secure boot, crypto, OTA, TLS            | Azure IoT support, TLS, OTA        | Manual, very limited           |
| **Trace & Debug**       | Tools: SystemView, Tracealyzer    | Zephyr logging & tracing                 | NetX, ThreadX tracing tools        | Manual logging                 |
| **Community Support**   | Huge, mature ecosystem            | Growing fast, backed by Linux Foundation | Good, backed by Microsoft          | None (solo dev)                |

simple example 1 

    #include "FreeRTOS.h"
    #include "task.h"
    #include <stdio.h>

    void vTask1(void *pvParameters) {
        while (1) {
            printf("Task 1 running\n");
            vTaskDelay(pdMS_TO_TICKS(1000));  // Delay 1000 ms
        }
    }

    void vTask2(void *pvParameters) {
        while (1) {
            printf("Task 2 running\n");
            vTaskDelay(pdMS_TO_TICKS(2000));  // Delay 2000 ms
        }
    }

    int main(void) {
        xTaskCreate(vTask1, "Task1", 128, NULL, 1, NULL);
        xTaskCreate(vTask2, "Task2", 128, NULL, 1, NULL);

        vTaskStartScheduler();  // Start FreeRTOS
        while (1);
    }