#include "WPILib.h"
#include "DefenseBotDriveClass.h"


#define GAMEPAD 0



/**
 * This starter template is for building a robot program from the
 * SimpleRobot base class.  This template does nothing - it merely
 * provides method stubs that you can use to begin your implementation.
 */
class SimpleRobotDemo : public SimpleRobot
{

	DefenseBotDriveClass Drive;
	Joystick LeftStick;
	Joystick RightStick;
	Joystick GamePad;

public:
	SimpleRobotDemo() :
		Drive(4,5,6,1,2,3),
		LeftStick(1),
		RightStick(2),
		GamePad(3)
	{
	}

	/**
	 * Your code for autonomous goes here.  You must be certain to exit the function when
	 * the Autonomous period is over!  Otherwise your program will never transition to
	 * OperatorControl.  You can use a loop similar to below, or otherwise frequently check
	 * IsAutonomous() and return when it returns false.
	 */
	void Autonomous()
	{
		Drive.Arcade_Drive(0.5f,0.0f);
		Wait(0.5);
		Drive.Stop();
		Wait(0.5);
		Drive.Arcade_Drive(0.0f,0.5f);
		Wait(0.5);
		Drive.Stop();


		while (IsAutonomous() && IsEnabled()) {
			// Update actuators based on sensors, elapsed time, etc here....


			/*
			 * Wait a short time before reiterating.  The wait period can be
			 * changed, but some time in a wait state is necessary to allow
			 * the other tasks, such as the Driver Station communication task,
			 * running on your cRIO to have some processor time. This also
			 * gives time for new sensor inputs, etc. to collect prior to
			 * further updating actuators on the subsequent iteration.
			 */
			Wait(0.005);
		}
	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled()) {
			// Update actuators here based on driver input, sensors, etc....

			float left_cmd = 0.0f;
			float right_cmd = 0.0f;
#if GAMEPAD
			// read the gamepad for the drive command
			left_cmd = // TODO
			right_cmd = // TODO
#else
			// read the drive joysticks
			left_cmd = -LeftStick.GetY();
			right_cmd = -RightStick.GetY();
#endif

			// pass command to the drive
			Drive.Tank_Drive(left_cmd,right_cmd);

			/*
			 * Wait a short time before reiterating.  The wait period can be
			 * changed, but some time in a wait state is necessary to allow
			 * the other tasks, such as the Driver Station communication task,
			 * running on your cRIO to have some processor time. This also
			 * gives time for new control information to arrive from the Driver
			 * Station, sensor inputs to collect, etc. prior to
			 * further updating actuators on the subsequent iteration.
			 */
			Wait(0.005);
		}
	}

	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

/*
 * This macro invocation tells WPILib that the named class is your "main" robot class,
 * providing an entry point to your robot code.
 */
START_ROBOT_CLASS(SimpleRobotDemo);

