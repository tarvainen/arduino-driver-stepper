#include "Arduino.h"
#include "Stepper.h"

Stepper::Stepper(char directionPin, char stepPin, int stepsPerRevolution, int rpm) {
  this->stepPin = stepPin;
  this->directionPin = directionPin;
  this->direction = 0;
  this->delay = 1000;
  this->stepsPerRevolution = stepsPerRevolution;
  this->setSpeed(rpm);

  pinMode(this->stepPin, OUTPUT);
  pinMode(this->directionPin, OUTPUT);
}

void Stepper::step() {
  digitalWrite(this->stepPin, !digitalRead(this->stepPin));
}

void Stepper::step(unsigned long steps) {
  for (long i = 0; i < steps; i++) {
    this->step();
    delayMicroseconds(this->delay);
  }
}

void Stepper::setDirection(char direction) {
  if (direction > 0) {
    this->direction = 1;
  } else {
    this->direction = 0;
  }

  digitalWrite(this->directionPin, this->direction);
}

char Stepper::getDirection() {
  return this->direction;
}

void Stepper::setSpeed(int rpm) {
  if (rpm < 0) {
    this->rpm = 1;
  } else {
    this->rpm = rpm;
  }

  this->delay = this->calculateDelay();
}

unsigned long Stepper::getDelay() {
  return this->delay;
}

////// PRIVATE METHODS ///////

unsigned long Stepper::calculateDelay() {
  long rps = this->rpm / 60;
  unsigned long us = 1000L * 1000L;

  return us / (this->stepsPerRevolution * rps);
}
