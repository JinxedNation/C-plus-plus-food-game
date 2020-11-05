//  cameraMap.cpp
//
//  Implementation file for CameraMap Class
//  Defines all the methods declared, but not defined, in cameraMap.h
//
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#include "cameraMap.h"

//--------------------------------------------------------------------------------------
//  Display a map with a cursor on it, which moves with the camera
//--------------------------------------------------------------------------------------

void CameraMap::DisplayMap(const int & screenWidth, const int & screenHeight,
				           const GLdouble &xPos, const GLdouble & zPos, const GLuint & tempImage)
{
	GLdouble tempX = xPos/163.0 - 2096/163;
	GLdouble tempZ = zPos/164.0 - 4688/164;
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glScalef(1, -1, 1);
	
	// mover the origin from the bottom left corner
	// to the upper left corner
	glTranslatef(0, -screenHeight, 0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// display the cursor of the camera position
	glBegin(GL_QUADS);		
		glVertex3f(219.0 - tempX - 2.0, 256.0 - tempZ - 2.0, 0.0);
		glVertex3f(219.0 - tempX + 2.0, 256.0 - tempZ - 2.0,  0.0);
		glVertex3f(219.0 - tempX + 2.0, 256.0 - tempZ + 2.0,  0.0);
		glVertex3f(219.0 - tempX - 2.0, 256.0 - tempZ + 2.0, 0.0);
	glEnd();
	
	// display map
	glBindTexture(GL_TEXTURE_2D, tempImage);
	glCallList(448);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

//--------------------------------------------------------------------------------------
//  Displays a welcome or exit screen
//--------------------------------------------------------------------------------------
void CameraMap::DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight, 
									  const int & tempExit, const GLuint & tempImage)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glScalef(1, -1, 1);
	
	// move to centre of screen
	glTranslatef(screenWidth/2 -256.0, -screenHeight/2 -256.0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	// display exit screen or welcome screen
	if (tempExit == 1)
	{
		glBindTexture(GL_TEXTURE_2D, tempImage);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, tempImage);
	}
	// display image
	glCallList(449);
	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void CameraMap::DisplayNoExit (const int & screenWidth, const int & screenHeight, 
							   const GLuint & tempImage)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glScalef(1, -1, 1);
	
	// move to centre of screen
	glTranslatef(screenWidth/2 -128.0, -screenHeight/2 -32.0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	// display sign
	glBindTexture(GL_TEXTURE_2D, tempImage);
	// display image
	glCallList(454);
	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void CameraMap::DisplayIcon(const int& screenWidth, const int& screenHeight,
	const GLuint& tempImage)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(screenWidth/2 - 600, -screenHeight/2 + 200, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// display sign
	glBindTexture(GL_TEXTURE_2D, tempImage);
	// display image
	glCallList(800);
	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void CameraMap::DisplayCross(const int& screenWidth, const int& screenHeight,
	const GLuint& tempImage)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(screenWidth / 2 - 12, -screenHeight / 2 - 12, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// display sign
	glBindTexture(GL_TEXTURE_2D, tempImage);
	// display image
	glCallList(801);
	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void CameraMap::DisplayPower(const int& screenWidth, const int& screenHeight,
	const GLuint& tempImage)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(screenWidth / 2 - 450, -screenHeight / 2 + 264, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// display sign
	glBindTexture(GL_TEXTURE_2D, tempImage);
	// display image
	glCallList(454);
	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void CameraMap::RenderText(const int& screenWidth, const int& screenHeight, std::string text, int posX, int posY)
{
	glPushMatrix();
	{
		glMatrixMode(GL_PROJECTION);
		double* matrix = new double[16];
		glGetDoublev(GL_PROJECTION_MATRIX, matrix);
		glLoadIdentity();
		gluOrtho2D(0, screenWidth, 0, screenHeight);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		{
			glLoadIdentity();
			glTranslatef(screenWidth / 2 + posX, screenHeight / 2 + posY, 0);
			glScalef(0.3, 0.3, 1);
			glColor3f(1, 1, 1);
			for (int i = 0; i < text.length(); i++)
			{
				glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)text.at(i));
			}
		}
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixd(matrix);
		glMatrixMode(GL_MODELVIEW);
	}
	glPopMatrix();
}

void CameraMap::DisplayBack(const int& screenWidth, const int& screenHeight, int posX, int posY)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glScalef(1, -1, 1);

	// move to centre of screen
	glTranslatef(screenWidth / 2 + posX, -screenHeight / 2 + posY, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// display sign
	// display image
	glColor3f(0, 0, 0);
	glCallList(802);
	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}