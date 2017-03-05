# arduino-gcode-parser

## Why this is for?

This simple parser allows you to easily utilize GCode's all it's good parts
in to your awesome Arduino machinery project (or anything else!).

## What is GCode?

You can find more from GCode online, but as it's simplest for it's just
commands with prefix character like 'G'. For example, `G01 X02.05 Y05.02` is
a simple GCode, which usually tells to the controlled machine to move to
desired XY-position.

## Usage

Simply parse the input data array with the GCode class itself after which it will
contain the values in itself. All values are stored as float values.

```
void loop() {
  if (Serial.available() > 0) {
  char result[100];

    // Read input data to the array
  Serial.readBytesUntil('\n', result, 100);

    // Parse the input
  code.parse(result);

    // Check if the received gcode had 'X' value given and print it
    if (code.has('X')) {
      Serial.println(code.get('X'));
    }
  }
}
```

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
  https://gitlab.com/tarvainen/arduino-gcode-parser.git#master
```

### Other ways

Read more ways from the Arduino's official docs here: https://www.arduino.cc/en/guide/libraries

## TODO
* write some examples

## License

MIT
