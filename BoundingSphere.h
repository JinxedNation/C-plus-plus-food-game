#pragma once
#include<string>
#include<iostream>
#include<cmath>
#include<sstream>
#include<fstream>
#include<glm.hpp>
#include<vector>
#include<GL/glut.h>
#include "OBJLoader.h"

/**
* @class BoundingSphere
* @brief Creates a bounding sphere from a vertex
*
* A class that creates a bounding shere by finding the center point, and calculating the radius of the object
*
* @author Christopher Logan
* @version 01
* @date 10/09/2020
*
*
* @bug no known bugs, but there may be some out there...
*/

class BoundingSphere
{
public:
	BoundingSphere();
	BoundingSphere(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos);

		/**
		* @brief Creates the bounding sphere
		*
		* This uses a vector<vertex> to find the center of the object, and also to find the radius of the object
		*
		* @return void
		*/
	void CreateSphere(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos);

		/**
		* @brief Displays the bounding sphere
		*
		*
		* @return void
		*/
	void Display();

		/**
		* @brief Sets the radius to r
		*
		*
		* @return void
		*/
	void SetRadius(GLfloat r);

		/**
		* @brief Gets the radius
		*
		*
		* @return GLfloat radius
		*/
	GLfloat GetRadius() const;

		/**
		* @brief Sets the center to c
		*
		*
		* @return void
		*/
	void SetCenter(glm::vec3 c);

		/**
		* @brief Gets the center
		*
		*
		* @return vec3 center
		*/
	glm::vec3 GetCenter() const;

		/**
		* @brief Gets the distance
		*
		* Gets the distance between col vec3 and the center position
		*
		* @return GLfloat
		*/
	GLfloat Distance(glm::vec3 col);

private:

		///Radius of the object
	GLfloat radius;
		///The center co-ordinants of the object
	glm::vec3 center;
};

