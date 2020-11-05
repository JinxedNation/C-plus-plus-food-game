
#pragma once
#include<GL/glut.h>
#include<iostream>

/**
* @class FrameTimer
* @brief Creates a timer that checks how long its been between frame
*
* The purpose is for this class to be used for checking time
*
* @author Christopher Logan
* @version 01
* @date 30/09/2020
*
* @bug no known bugs, but there may be some out there...
*/

class FrameTimer
{
	public:

		FrameTimer();

			///Public float that is the time since the last frame, public so it is easily accessable
		float deltaTime;

            /**
            * @brief Updates the current delta time
			*
            * @return void
            */
		void Update();

	private:
			///The current time
		int time;

			///The old time value
		int oldTime;
};

