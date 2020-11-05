#pragma once
#include "MovingAgent.h"
#include "FrameTimer.h"
/**
* @class AgentX
* @brief Inherited MovingAgent class used to move an ai on the X Axis
*
*
* @author Christopher Logan
* @version 01
* @date 30/9/2020
*
* @bug no known bugs, but there may be some out there...
*/
class AgentX : public MovingAgent
{
	public:
		AgentX() {}
		AgentX(int i, Object obj, float s, float mX, float mN);

            /**
            * @brief Adds information, such as id, object, speed, max position and min position in one call
            *
            * @return void
            */
		void AddInfo(int i, Object obj, float s, float mX, float mN);

	private:

	        /**
            * @brief Moves the agent
            *
            * @return void
            */
		virtual void Move();

			///Time between frames
		FrameTimer time;

        /**
        * @brief Updates the current state of the agent
        *
        * @return void
        */
        void UpdateState(State s);

        /**
        * @brief Moves the agent in a positive direction
        *
        * @return void
        */
        void MovePositive();

        /**
        * @brief Moves the agent in a negative direction
        *
        * @return void
        */
        void MoveNegative();

        /**
        * @brief Checks the players position whilst moving in a positive direction
        *
        * @return bool
        */
        virtual bool CheckPlayerPos();

        /**
        * @brief Checks the players position whilst moving in a negative direction
        *
        * @return bool
        */
        virtual bool CheckPlayerNeg();
};

