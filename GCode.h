#ifndef ARDUINO_GCODE_PARSER_H
#define ARDUINO_GCODE_PARSER_H

/**
 * GCode
 *
 * The utility class to parse G-codes from serial inputs.
 */
class GCode {

	// private structure to handle also the 0.00 values
	typedef struct code {
		float value;
		bool set;
	} code;

private:
	code values[26];
	char *lastReceivedString;

	// private functions
	void parse();
	void set(char, float);
	void empty();

public:
	GCode();
	GCode(char *);

	float get(char);

	void parse(char *);
	bool has(char);
};

#endif // ARDUINO_GCODE_PARSER_H
