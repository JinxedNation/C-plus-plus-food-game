#pragma once
/**********************************************************************************************
 * @class game_Physics
 *
 *
 * @brief Purpose of class: Enabling of basic game physics through the use of vec3s
 *		  Class will contain the following physics and is open for expansion at a later date
 *		  Acceleration of our OBJ models
 *		  Gravity as a const float of 0, 9.81, 0 as Gravity on earth is 9.81ms
 *		  Velocity of the object for how fast it is moving
 *
 *
 * @Author William Halling 32233703
 * @Date   October 2020
 *
 *
 * @Version 01
 *
 * @bug no known bugs, but there may be some out there...
 ************************************************************************************************/


#include "game_Physics.h"
#include "FrameTimer.h"


#include "Object.h"
#include <glm.hpp>



class game_Physics
{

public:
	/**
	 * @brief Setter for the gravity acting on the game OBJ Models
	 *
	 *
	 * Sets the gravitational downforce on OBJ game objects
	 *
	 *
	 * @return void
	 */
	void set_Current_Obj_Gravity(glm::vec3 temp_Game_Obj_Grav) { gravity_Of_Game_Obj_ = temp_Game_Obj_Grav; }


	/**
	 * @brief getter for the gravity acting on the game OBJ Models
	 *
	 *
	 * Sets the gravitational downforce on OBJ game objects
	 *
	 *
	 * @return gravity_Of_Game_Obj_ (vector3)
	 */
	glm::vec3 get_Game_OBJ_Gravity()      const { return gravity_Of_Game_Obj_; }


	/**
	 * @brief Setter for the velocity acting on the game OBJ Models
	 *
	 *
	 * Sets the velocity which is acting on the OBJ model in the three dimensional plane
	 *
	 *
	 * @return void
	 */
	void set_Current_Game_OBJ_Velocity(glm::vec3 temp_Velocity_Of_Game_Obj_) { velocity_Of_Game_Obj_ = temp_Velocity_Of_Game_Obj_; }


	/**
	 * @brief getter for the velocity acting on the game OBJ Models
	 *
	 *
	 * gets the velocity in the three dimensional plane on OBJ game objects
	 *
	 *
	 * @return velocity_Of_Game_Obj_ (vector3)
	 */
	glm::vec3 get_Game_OBJ_Vellocity()    const { return velocity_Of_Game_Obj_; }


	/**
	 * @brief Setter for the acceleration acting on the game OBJ Models
	 *
	 *
	 * Sets the acceleration which is acting on the OBJ model in the three dimensional plane
	 *
	 *
	 * @return void
	 */
	void set_Current_Game_OBJ_Acceleration(glm::vec3 temp_Acceleration_Of_Game_Obj) { Acceleration_Of_Game_Obj_ = temp_Acceleration_Of_Game_Obj; }


	/**
	 * @brief Setter for determining if the OBJ model is in motion or not
	 *
	 *
	 * Sets the Obj_Model_In_Motion
	 *
	 *
	 * @return void
	 */
	glm::vec3 get_Game_OBJ_Acceleration() const { return Acceleration_Of_Game_Obj_; }


	/**
	 * @brief Setter for determining if the OBJ model is in motion or not
	 *
	 *
	 * Sets the Obj_Model_In_Motion
	 *
	 *
	 * @return void
	 */
	void set_Obj_Model_In_Motion(bool temp_Obj_Model_In_Motion) { Obj_Model_In_Motion_ = temp_Obj_Model_In_Motion; }


	/**
	 * @brief getter for determining if the OBJ model is in motion or not
	 *
	 *
	 * gets the Obj_Model_In_Motion
	 *
	 *
	 * @return Obj_Model_In_Motion_ (boolean)
	 */
	bool get_Obj_Model_In_Motion()        const { return Obj_Model_In_Motion_; }


	/**
	 * @brief Setter for the Obj model Name
	 *
	 *
	 * Sets the Obj_Model_In_Motion
	 *
	 *
	 * @return void
	 */
	void set_Obj_Model_Name(Object temp_obj_Model_Name) { obj_Model_Name = temp_obj_Model_Name; }


	/**
	 * @brief getter for the Obj model Name
	 *
	 *
	 * gets the Obj_Model_In_Motion
	 *
	 *
	 * @return void
	 */
	Object get_Obj_Model_Name() const { return obj_Model_Name; }


	/**
	 * @brief updates the game model during run time
	 *
	 *
	 * @return void
	 */
	void update_Game_Model();


private:

	/// is an object of the objct class
	Object obj_Model_Name;


	/// keeps note of teh time at each frame
	FrameTimer time;

	/// tracks whether an obj game model is currently in motion or not 
	bool Obj_Model_In_Motion_;


	/// graviational force acting on the OBJ model
	glm::vec3 gravity_Of_Game_Obj_;


	/// velocity force of the OBJ model
	glm::vec3 velocity_Of_Game_Obj_;


	/// current rate of acceleration of the obj Model 
	glm::vec3 Acceleration_Of_Game_Obj_;
};