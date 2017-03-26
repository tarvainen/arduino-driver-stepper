#ifndef ARDUINO_DRIVER_STEPPER_H
#define ARDUINO_DRIVER_STEPPER_H

class Stepper {
private:
  int direction;
  char stepPin;
  char directionPin;
  char enablePin;
  long stepsPerRevolution;
  long rpm;
  unsigned long delay;

  unsigned long calculateDelay();

public:
  Stepper(char, char, char, int, int);

  void step();
  void step(unsigned long);

  void setDirection(char);
  char getDirection();

  void setSpeed(int);
  unsigned long getDelay();

  void enable();
  void disable();
};


#endif // ARDUINO_DRIVER_STEPPER_H
