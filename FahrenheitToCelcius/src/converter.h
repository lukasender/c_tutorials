/*
 * converter.h
 *
 *  Created on: 22.12.2012
 *      Author: lumannnn
 *
 * Of course this is free to use. It's common knowledge ;)
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

/*
 * F¡ = (C¡ * 9/5) + 32
 */
float convert_to_fahrenheit(float celcius);

/*
 * C¡ = (5/9) * (F¡ - 32)
 */
float convert_to_celcius(float fahrenheit);


#endif /* CONVERTER_H_ */
