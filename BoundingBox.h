#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<glm.hpp>
#include<vector>
#include<GL/glut.h>
#include "OBJLoader.h"

/**
* @class BoundingBox
* @brief Creates a bounding box from a vertex
*
* A class that creates a bounding box, with min and max co-ordinants.
* It is created using a vector of vertexes
*
* @author Christopher Logan
* @version 01
* @date 1/09/2020
*
*
* @bug no known bugs, but there may be some out there...
*/

class BoundingBox
{

	public:
		BoundingBox();
		BoundingBox(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos);

        void DisplayFloor();
            /**
            * @brief Displays the bounding box
            *
            * This displays the bounding box, used to make sure it is in the right spot
            *
            * @return void
            */
		void Display();


            /**
            * @brief Sets the minimum
            *
            * Sets the minimum x, y, z values
            *
            * @return void
            */
		void SetMin(glm::vec3 m);

            /**
            * @brief Gets the minimum
            *
            * Gets the minimum x, y, z values
            *
            * @return vec3 min
            */
		glm::vec3 GetMin() const;

            /**
            * @brief Sets the maximum
            *
            * Sets the maximum x, y, z values
            *
            * @return void
            */
		void SetMax(glm::vec3 m);

            /**
            * @brief Gets the maximum
            *
            * Gets the maximum x, y, z values
            *
            * @return vec3 min
            */
		glm::vec3 GetMax() const;

            /**
            * @brief Creates the bounding box
            *
            * Creates the bounding box from the vector, position and scale
            *
            * @return vec3 min
            */
		void CreateBox(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos);
		
            /**
            * @brief Sets the x maximum
            *
            * Takes in a GLfloat and sets it to the max x
            *
            * @return void
            */
        void SetMaxX(GLfloat x);


            /**
            * @brief Gets the x maximum
            *
            * Gets the x from the max vec3
            *
            * @return vec3 max.x
            */
        GLfloat GetMaxX();

            /**
            * @brief Sets the y maximum
            *
            * Takes in a GLfloat and sets it to the max y
            *
            * @return void
            */
        void SetMaxY(GLfloat y);


            /**
            * @brief Gets the y maximum
            *
            * Gets the y from the max vec3
            *
            * @return vec3 max.y
            */
        GLfloat GetMaxY();

            /**
            * @brief Sets the z maximum
            *
            * Takes in a GLfloat and sets it to the max z
            *
            * @return void
            */
        void SetMaxZ(GLfloat z);

            /**
            * @brief Gets the z maximum
            *
            * Gets the z from the max vec3
            *
            * @return vec3 max.z
            */
        GLfloat GetMaxZ();

            /**
            * @brief Sets the x minimum
            *
            * Takes in a GLfloat and sets it to the min x
            *
            * @return void
            */
        void SetMinX(GLfloat x);


            /**
            * @brief Gets the x minimum
            *
            * Gets the x from the min vec3
            *
            * @return vec3 min.x
            */
        GLfloat GetMinX();

            /**
            * @brief Sets the y minimum
            *
            * Takes in a GLfloat and sets it to the min y
            *
            * @return void
            */
        void SetMinY(GLfloat y);

            /**
            * @brief Gets the y minimum
            *
            * Gets the y from the min vec3
            *
            * @return vec3 min.y
            */
        GLfloat GetMinY();

            /**
            * @brief Sets the z minimum
            *
            * Takes in a GLfloat and sets it to the min z
            *
            * @return void
            */
        void SetMinZ(GLfloat z);

            /**
            * @brief Gets the z minimum
            *
            * Gets the z from the min vec3
            *
            * @return vec3 min.z
            */
        GLfloat GetMinZ();

            /**
            * @brief checks if the point is inside the bounding box
            *
            *
            * @return bool
            */
        bool CheckCollision(glm::vec3 col);


            /**
            * @brief Updates the position of the bounding box moving in the z direction
            *
            * @return void
            */
        void UpdateZ(float value);

            /**
            * @brief Updates the position of the bounding box moving in the x direction
            *
            * @return void
            */
        void UpdateX(float value);

            /**
            * @brief Updates the position of the bounding box moving in the y direction
            *
            * @return void
            */
        void UpdateY(float value);



	private:

            ///Minimum values
		glm::vec3 min;

            ///Maximum values
		glm::vec3 max;
};

