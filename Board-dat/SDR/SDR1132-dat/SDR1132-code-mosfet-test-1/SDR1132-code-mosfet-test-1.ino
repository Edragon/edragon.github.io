/*
 * SDR1132 - MOSFET & buzzer output test (ESP32)
 *
 * Sequence: ALL outputs are switched ON together for 5 s, then
 *           ALL outputs are switched OFF together for 5 s.
 *           Repeats, unless REPEAT_CYCLE is set to 0.
 *
 * Outputs (from SDR1132-dat.md):
 *   MOSFET 1 -> IO27
 *   MOSFET 2 -> IO32
 *   MOSFET 3 -> IO22
 *   MOSFET 4 -> IO13
 *   BUZZER   -> IO25
 *
 * Outputs are driven active-HIGH (HIGH = ON).
 * Set ACTIVE_LOW to 1 if your driver stage is inverted.
 */

// ---- Output pins ----
const uint8_t PIN_MOSFET_1 = 27;
const uint8_t PIN_MOSFET_2 = 32;
const uint8_t PIN_MOSFET_3 = 22;
const uint8_t PIN_MOSFET_4 = 13;
const uint8_t PIN_BUZZER   = 25;

// 1 = outputs are active-LOW (inverted driver)
#define ACTIVE_LOW 0

// 1 = keep repeating the ON/OFF cycle, 0 = run the cycle only once
#define REPEAT_CYCLE 1

// ---- Timing (ms) ----
const unsigned long ON_TIME  = 5000; // time all outputs stay ON
const unsigned long OFF_TIME = 5000; // time all outputs stay OFF

// ---- Output table ----
const uint8_t OUT_PINS[] = {
    PIN_MOSFET_1,
    PIN_MOSFET_2,
    PIN_MOSFET_3,
    PIN_MOSFET_4,
    PIN_BUZZER,
};
const char *const OUT_NAMES[] = {
    "MOSFET IO27",
    "MOSFET IO32",
    "MOSFET IO22",
    "MOSFET IO13",
    "BUZZER IO25",
};
const uint8_t OUT_COUNT = sizeof(OUT_PINS) / sizeof(OUT_PINS[0]);

// ---- Forward declarations ----
void outputWrite(uint8_t pin, bool on);
void allOn();
void allOff();

void setup()
{
    Serial.begin(115200);
    delay(200); // let the USB serial settle

    Serial.println(F("SDR1132 MOSFET / buzzer test (all outputs together)"));

    for (uint8_t i = 0; i < OUT_COUNT; i++)
    {
        pinMode(OUT_PINS[i], OUTPUT);
        Serial.printf("out %u: %s\n", i + 1, OUT_NAMES[i]);
    }

    allOff(); // start from a known OFF state
}

void loop()
{
    // 1) All outputs ON together
    Serial.println(F("ALL ON"));
    allOn();
    delay(ON_TIME);

    // 2) All outputs OFF together
    Serial.println(F("ALL OFF"));
    allOff();
    delay(OFF_TIME);

#if !REPEAT_CYCLE
    Serial.println(F("--- single pass done, halted ---"));
    while (true)
        delay(1000);
#endif
}

// ---- Helpers ----

// Drive one output, honouring the ACTIVE_LOW setting
void outputWrite(uint8_t pin, bool on)
{
#if ACTIVE_LOW
    on = !on;
#endif
    digitalWrite(pin, on ? HIGH : LOW);
}

// Switch every output ON together
void allOn()
{
    for (uint8_t i = 0; i < OUT_COUNT; i++)
        outputWrite(OUT_PINS[i], true);
}

// Switch every output OFF together
void allOff()
{
    for (uint8_t i = 0; i < OUT_COUNT; i++)
        outputWrite(OUT_PINS[i], false);
}

