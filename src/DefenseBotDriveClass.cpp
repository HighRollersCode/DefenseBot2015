/*
 * DefenseBotDriveClass.cpp

 *
 *  Created on: Oct 24, 2015
 *      Author: Student
 */

#include "DefenseBotDriveClass.h"
float clamp(float in,float min,float max)
{
	if (in > max) return max;
	if (in < min) return min;
	return in;
}


DefenseBotDriveClass::DefenseBotDriveClass
(
	int left_pwm0,
	int left_pwm1,
	int left_pwm2,
	int right_pwm0,
	int right_pwm1,
	int right_pwm2
) :
	LeftJag0(left_pwm0),
	LeftJag1(left_pwm1),
	LeftJag2(left_pwm2),
	RightJag0(right_pwm0),
	RightJag1(right_pwm1),
	RightJag2(right_pwm2)
{

}

void DefenseBotDriveClass::Tank_Drive(float left_stick_cmd,float right_stick_cmd)
{
	LeftJag0.Set(left_stick_cmd);
	LeftJag1.Set(left_stick_cmd);
	LeftJag2.Set(left_stick_cmd);

	RightJag0.Set(-right_stick_cmd);
	RightJag1.Set(-right_stick_cmd);
	RightJag2.Set(-right_stick_cmd);
}


void DefenseBotDriveClass::Arcade_Drive(float fwd_cmd,float turn_cmd)
{
	float left_fwd = fwd_cmd + turn_cmd;
	float right_fwd = fwd_cmd - turn_cmd;

	left_fwd = clamp(left_fwd, -1.0f, 1.0f);
	right_fwd = clamp(right_fwd, -1.0f, 1.0f);

	Tank_Drive(left_fwd,right_fwd);
}

void DefenseBotDriveClass::Stop()
{
	Tank_Drive(0.0f,0.0f);
}
