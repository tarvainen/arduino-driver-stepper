# arduino-driver-stepper

## What is this for?

This library is for driving stepper motors using the stepper motor driver which
allows controlling stepper motor with just two wires.

## Usage

See the `/example` directory for the actual Arduino example.

## Installation

### Using PlatformIO library manager (recommended)

There is one absolutely cool tool called PlatformIO which allows you to
run your awesome IOT projects more easily and with less amount of stress. I
personally highly recommend using PlatformIO since it makes these things a lots
of easier.

Read more from their official docs here: http://docs.platformio.org/en/stable/userguide/lib/cmd_install.html

Installation with the PlatformIO library manager goes like this:
1. Define this repository as a dependency to the platformio.ini file (see example below)
2. Build the project (PlatformIO automatically loads the dependencies)

```
[env:uno]
platform = atmelavr
board = uno
framework = arduino

lib_deps =
  https://gitlab.com/tarvainen/arduino-driver-stepper.git#master
```

### Other ways

Read more ways from the Arduino's official docs here: https://www.arduino.cc/en/guide/libraries

## TODO
* Implement support for accelerations and that kind of other stuff
* Fill keywords.txt

## License

MIT
