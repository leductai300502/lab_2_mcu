/*
 * software_timer.h
 *
 *  Created on: Oct 11, 2022
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
void setTimer0(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
