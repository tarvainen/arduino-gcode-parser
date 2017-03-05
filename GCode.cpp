#include "GCode.h"

/**
 * Default constructor here.
 * Please use the parametric constructor for simpler code.
 */
GCode::GCode() {
	// Do nothing here
	this->empty();
}

/**
 * Parametric constructor.
 * The text passed as a parameter is automatically parsed into the g-code values.
 */
GCode::GCode(char *str) {
	this->parse(str);
}

/**
 * Gets the value for the char.
 *
 * @return 	float	The value matching the character.
 */
float GCode::get(char c) {
	return this->values[c - 'A'].value;
}

/**
 * Sets lastReceivedString to the given value.
 * Calls the private parse method to actually parse values.
 */
void GCode::parse(char *str) {
	this->lastReceivedString = str;
	this->parse();
}

// Private methods

/**
 * Parses the lastReceivedString to the values array.
 *
 * After calling this function the values array is populated with values.
 * They may then be accessed like GCode::get('C') etc.
 */
void GCode::parse() {
	char *ptr = this->lastReceivedString;
	this->empty();

	char i = 0;

	// find the length of the string
	while (*ptr != '\0') {
		ptr++;
		i++;
	}

	float currentValue = 0.0f;
	long factor = 1L;

	/**
	 * Loop down from the end of the string.
	 * If number is found, multiply the current value by the factor.
	 * Else if character is found put the current value to the array and reset values.
	 * Else if separator dot is found, divide the current value by the factor.
	 * Else just reset values.
	 */
	for (; i >= 0; i--, ptr--) {
		if (*ptr >= 'A' && *ptr <= 'Z') {
			this->set(*ptr, currentValue);
			currentValue = 0.0f;
			factor = 1L;
		} else if (*ptr >= '0' && *ptr <= '9') {
			currentValue += factor * (*ptr - '0');
			factor *= 10;
		} else if (*ptr == '.') {
			currentValue /= factor;
			factor = 1L;
		} else if (*ptr == '-'){
			currentValue *= -1;
		} else {
			currentValue = 0.0f;
			factor = 1L;
		}

		*ptr = '\0';
	}
}

/**
 * Tells if the given character has matching value in the values array.
 *
 * @returns bool	Is there a value.
 */
bool GCode::has(char c) {
	return this->values[c - 'A'].set;
}

/**
 * Sets the value for the char.
 */
void GCode::set(char c, float f) {
	this->values[c - 'A'].value = f;
	this->values[c - 'A'].set = true;
}

/**
 * Empties the values array (fills it with null pointers).
 */
void GCode::empty() {
	for (char i = 0; i < 26; i++) {
		this->values[i].value = 0.0f;
		this->values[i].set = false;
	}
}
