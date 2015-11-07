/*
 * DefenseBotDriveClass.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Student
 */

#ifndef DEFENSEBOTDRIVECLASS_H_
#define DEFENSEBOTDRIVECLASS_H_


#include "WPILib.h"


class DefenseBotDriveClass {
public:
	DefenseBotDriveClass(int left_pwm0, int left_pwm1, int left_pwm2, int right_pwm0,int right_pwm1, int right_pwm2);

	void Tank_Drive(float left_stick_cmd,float right_stick_cmd);

	// Arcade_Drive
	// fwd_cmd - how hard to drive fwd
	// turn_cmd - how hard to turn to the right (negative = turn to the left)
	void Arcade_Drive(float fwd_cmd,float turn_cmd);

	void Stop();

private:

	Jaguar LeftJag0;
	Jaguar LeftJag1;
	Jaguar LeftJag2;

	Jaguar RightJag0;
	Jaguar RightJag1;
	Jaguar RightJag2;

};

#endif /* DEFENSEBOTDRIVECLASS_H_ */
