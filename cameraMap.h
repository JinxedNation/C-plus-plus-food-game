//  cameraMap.h
//  Header file for the cameraMap class
//  Displays a map and welcome screen in 2D on the screen
//  
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef CAMERA_MAP_H
#define CAMERA_MAP_H

#include <gl/glut.h>
#include<string>
#include <vector>
#include <iostream>

/**
* @class CameraMap
* @brief Class used to display a map on a 2D screen
*
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

class CameraMap
{
public:
	CameraMap() {};
	virtual ~CameraMap() {};

			/**
			* @brief Displays the map onto the screen
			*
			*
			* @return void
			*/
	void DisplayMap(const int & screenWidth, const int & screenHeight,
				    const GLdouble & xPos, const GLdouble & zPos,
					const GLuint & tempImage);

			/**
			* @brief Displays the welcome screen onto the screen
			*
			*
			* @return void
			*/
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight, 
		                       const int & tempExit, const GLuint & tempImage);

			/**
			* @brief Displays the exit onto the screen
			*
			*
			* @return void
			*/
	void DisplayNoExit (const int & screenWidth, const int & screenHeight, 
						const GLuint & tempImage);

			/**
			* @brief Displays the icons
			*
			*
			* @return void
			*/
	void DisplayIcon(const int& screenWidth, const int& screenHeight,
		const GLuint& tempImage);


			/**
			* @brief Displays the crosshair
			*
			*
			* @return void
			*/
	void DisplayCross(const int& screenWidth, const int& screenHeight,
		const GLuint& tempImage);

			/**
			* @brief Displays the power bar
			*
			*
			* @return void
			*/
	void DisplayPower(const int& screenWidth, const int& screenHeight,
		const GLuint& tempImage);


			/**
			* @brief Renders the text
			*
			*
			* @return void
			*/
	void RenderText(const int& screenWidth, const int& screenHeight, std::string text, int posX, int posY);

			/**
			* @brief Displays the back
			*
			*
			* @return void
			*/
	void DisplayBack(const int& screenWidth, const int& screenHeight, int posX, int posY);

private:
    // Privatised copy constructor and assignment operator
    CameraMap (const CameraMap &cam) {};
    CameraMap &operator = (const CameraMap &cam) {};
};

#endif