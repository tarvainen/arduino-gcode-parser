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

## TODO

* write about installation
* write some examples
