// Motor control for DRV8871 using ATtiny
// PB0: CW input (HIGH = CW)
// PB1: CCW input (HIGH = CCW)
// PB3, PB4: Outputs to DRV8871

#define CW_INPUT   0  // PB0
#define CCW_INPUT  1  // PB1
#define OUT1       3  // PB3
#define OUT2       4  // PB4

void setup() {
  pinMode(CW_INPUT, INPUT);
  pinMode(CCW_INPUT, INPUT);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);

  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
}

void loop() {
  bool cw  = digitalRead(CW_INPUT);
  bool ccw = digitalRead(CCW_INPUT);

  if (cw && !ccw) {
    // Clockwise: OUT1 HIGH, OUT2 LOW
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
  } else if (!cw && ccw) {
    // Counterclockwise: OUT1 LOW, OUT2 HIGH
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, HIGH);
  } else {
    // Stop: both LOW
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, LOW);
  }
}