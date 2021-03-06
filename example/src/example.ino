#include <Stepper.h>

Stepper stepper(11, 13, 8, 200, 240);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);

  stepper.setDirection(1);

  for (int i = 0; i < 500; i++) {
    stepper.step();
    delayMicroseconds(stepper.getDelay());
  }

  stepper.setDirection(0);

  for (int i = 0; i < 500; i++) {
    stepper.step();
    delayMicroseconds(stepper.getDelay());
  }

  stepper.disable();

  delay(2000);

  stepper.enable();

  Serial.println(stepper.getDelay());
}
