#ifndef ARDUINO_DRIVER_STEPPER_H
#define ARDUINO_DRIVER_STEPPER_H

class Stepper {
private:
  int direction;
  int stepPin;
  int directionPin;
  long stepsPerRevolution;
  long rpm;
  unsigned long delay;

  unsigned long calculateDelay();

public:
  Stepper(char, char, int, int);

  void step();
  void step(unsigned long);

  void setDirection(char);
  char getDirection();

  void setSpeed(int);
  unsigned long getDelay();
};


#endif // ARDUINO_DRIVER_STEPPER_H
