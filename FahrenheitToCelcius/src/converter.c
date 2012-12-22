/*
 * converter.c
 *
 *  Created on: 22.12.2012
 *      Author: lumannnn
 *
 * Of course this is free to use. It's common knowledge ;)
 */

/*
 * F¡ = (C¡ * 9/5) + 32
 */
float convert_to_fahrenheit(float celcius) {
	return (celcius * 9.0/5.0) + 32;
}

/*
 * C¡ = (5/9) * (F¡ - 32)
 */
float convert_to_celcius(float fahrenheit) {
	return 5.0/9.0 * (fahrenheit - 32);
}
