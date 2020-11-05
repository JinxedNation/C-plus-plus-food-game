//  camera.cpp
//
//  Implementation file for Camera Class
//  Defines all the methods declared, but not defined, in camera.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "Camera.h"

#include <cmath>
#include <gl/glut.h>

//--------------------------------------------------------------------------------------
// Set initial values
//--------------------------------------------------------------------------------------
Camera::Camera()
{
	m_rotateSpeed = 0.0f;
	m_moveSpeed = 0.0f;
	p_radius = 0;

	ResetXYZ();

	m_deltaMoveFB = 0;
	m_deltaMoveLR = 0;
	m_deltaMoveUD = 0;

	m_rotateAngleLR = 0.0;
	m_rotateAngleUD = 0.0;
	m_deltaAngleLR = 0.0;
	m_deltaAngleUD = 0.0;

	m_CollisionDetectionOn = true;

}

//--------------------------------------------------------------------------------------
// Reset camera values
//--------------------------------------------------------------------------------------
void Camera::ResetXYZ()
{
	m_x = 0.0f;
	m_y = 1.75f;
	m_z = 0.0f;
	
	m_lookX = 0.0f;
	m_lookY = 0.0f;
	m_lookZ = -1.0f;
	
	m_lookXX = 1.0f;
	m_lookYY = 1.0f;
	m_lookZZ = 0.0f;
}

//--------------------------------------------------------------------------------------
//  Determine direction
//--------------------------------------------------------------------------------------
void Camera::DirectionFB(int const & tempMove)
{
	m_deltaMoveFB = tempMove;
}
//--------------------------------------------------------------------------------------
void Camera::DirectionLR(int const & tempMove)
{
	m_deltaMoveLR = tempMove;
}
//--------------------------------------------------------------------------------------
// Not used but allows up and don movement
void Camera::DirectionUD(int const & tempMove)
{
	m_deltaMoveUD = tempMove;
}

//--------------------------------------------------------------------------------------
void Camera::DirectionRotateLR(GLdouble const & tempMove)
{
	m_deltaAngleLR = tempMove * m_rotateSpeed;
}

//--------------------------------------------------------------------------------------
void Camera::DirectionLookUD(int const & tempMove)
{
	m_deltaAngleUD = tempMove * m_rotateSpeed;
}


//--------------------------------------------------------------------------------------
// Is ok to move camera backwards and forwards
//--------------------------------------------------------------------------------------
bool Camera::MoveFBOK()
{
	bool tempReturn;
	if (m_deltaMoveFB < 0 || m_deltaMoveFB > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}

//--------------------------------------------------------------------------------------
// Is ok to move camera sideways
//--------------------------------------------------------------------------------------
bool Camera::MoveLROK()
{
	bool tempReturn;
	if (m_deltaMoveLR < 0 || m_deltaMoveLR > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}

//--------------------------------------------------------------------------------------
// Is ok to move camera up and down (not used)
//--------------------------------------------------------------------------------------
bool Camera::MoveUDOK()
{
	bool tempReturn;
	if (m_deltaMoveUD < 0 || m_deltaMoveUD > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}

//--------------------------------------------------------------------------------------
// Is ok to rotate sideways
//--------------------------------------------------------------------------------------
bool Camera::RotateLROK()
{
	bool tempReturn;
	if ((m_deltaAngleLR/m_rotateSpeed) < 0 || (m_deltaAngleLR/m_rotateSpeed) > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}

//--------------------------------------------------------------------------------------
// Is ok to rotate up and down
//--------------------------------------------------------------------------------------
bool Camera::LookUDOK()
{
	bool tempReturn;
	if ((m_deltaAngleUD/m_rotateSpeed) < 0 || (m_deltaAngleUD/m_rotateSpeed) > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}

//--------------------------------------------------------------------------------------
// Move camera backwards and forwards
//--------------------------------------------------------------------------------------
void Camera::MoveFB()
{
	// record previous co-ordinates
	m_xLast = m_x;
	m_zLast = m_z;

	// set movement step
	GLdouble moveZ = (m_deltaMoveFB * (m_lookZ) * m_moveSpeed);
	GLdouble moveX = (m_deltaMoveFB * (m_lookX) * m_moveSpeed);

	if (m_CollisionDetectionOn)
	{
		GLdouble startX = m_x + moveX * 5.0;
		GLdouble startZ = m_z + moveZ * 5.0;
		glm::vec3 col(startX + m_lookX, m_y + m_lookY, startZ + m_lookZ);

		// check if collsion
		if (!(m_colDetect.Collide(startX + m_lookX, m_y + m_lookY, startZ + m_lookZ)) && !(CheckBoundBoxColision(col)) && !(CheckBoundSphereColision(col)) && !(CheckAiCollision(col)))
		{
			// increment position
			m_x += moveX;
			m_z += moveZ;
			// check plain
			SetPlains(moveX, moveZ);
			// redisplay
			callGLLookAt();
		}
	}
	else
	{
		// increment position
		m_x += moveX;
		m_z += moveZ;
		// check plain
		SetPlains(moveX, moveZ);
		// redisplay
		callGLLookAt();
	}	
}

//--------------------------------------------------------------------------------------
// Move camera left and right (sideways)
//--------------------------------------------------------------------------------------
void Camera::MoveLR()
{
	// record previous co-ordinates
	m_zLast = m_z;
	m_xLast = m_x;

	// set movement step
	GLdouble moveZ = (m_deltaMoveLR * (m_lookZZ) * m_moveSpeed);
	GLdouble moveX = (m_deltaMoveLR * (m_lookXX) * m_moveSpeed);

	if (m_CollisionDetectionOn)
	{
		GLdouble startX = m_x + moveX * 1.0;
		GLdouble startZ = m_z + moveZ * m_moveSpeed * 1.0;
		glm::vec3 col(startX + m_lookX, m_y + m_lookY, startZ + m_lookZ);

		// check if collsion
		if (!(m_colDetect.Collide(startX + m_lookX, m_y + m_lookY, startZ + m_lookZ)) && !(CheckBoundBoxColision(col)) && !(CheckBoundSphereColision(col)) && !(CheckAiCollision(col)))
		{
			// increment position
			m_x += moveX;
			m_z += moveZ;
			// check plain
			SetPlains(moveX, moveZ);
			// redisplay
			callGLLookAt();
		}
	}
	else
	{
		// increment position
		m_x += moveX;
		m_z += moveZ;
		SetPlains(moveX, moveZ);
		// redisplay
		callGLLookAt();
	}
}

//----------------------------------------------------------------------------------------
//  Places camera at the correct level on the current plain
//----------------------------------------------------------------------------------------
void Camera::SetPlains(const int & moveX, const int & moveZ)
{
	// store number of plains (stops from looping through linked list each time)
	if (m_No_Plains == 0) m_No_Plains = m_Plain.GetListSize();

	for (int i = 0;  i < m_No_Plains; i++)
	{
		// if camera is positioned on a plain
		if ((m_z <= m_Plain.GetZend(i)) && (m_z >= m_Plain.GetZstart(i))
			&& (m_x <= m_Plain.GetXend(i)) && (m_x >= m_Plain.GetXstart(i)))
		{
			// if flat plain
			if (m_Plain.GetType(i) == 0)
			{
				m_y = m_Plain.GetYstart(i);

				m_plainNo = i;
				m_plainHeight = m_Plain.GetYstart(i);
			}
			// if plain slopes in z direction
			if (m_Plain.GetType(i) == 2)
			{
				// if plain slopes up or down
				if (m_zLast > m_z)
				{
					m_incrementZ = ((m_y - m_Plain.GetYstart(i)) / (m_z - m_Plain.GetZstart(i)));
				}
				else
				{
					m_incrementZ = ((m_Plain.GetYend(i) - m_y) / (m_Plain.GetZend(i) - m_z));
				}
				m_y += (m_incrementZ * moveZ);
			}
			// if plain slopes in x direction	
			if (m_Plain.GetType(i) == 1)
			{
				// if plain slopes up or down
				if (m_xLast > m_x)
				{
					m_incrementX = ((m_y - m_Plain.GetYstart(i)) / (m_x - m_Plain.GetXstart(i)));
				}
				else
				{
					m_incrementX = ((m_Plain.GetYend(i) - m_y) / (m_Plain.GetXend(i) - m_x));
				}
				m_y += (m_incrementX * moveX);
			}		
		}
	}
}

//----------------------------------------------------------------------------------------
// Moves camera up and down (NOT USED)
//----------------------------------------------------------------------------------------
void Camera::MoveUD()
{
	if (m_CollisionDetectionOn)
	{
		GLdouble startY = m_y + m_deltaMoveUD * (m_lookYY) * m_moveSpeed * 5.0;
		glm::vec3 col(m_x + m_lookXX, startY + m_lookYY, m_z + m_lookZZ);

		if (!(m_colDetect.Collide(m_x + m_lookXX, startY + m_lookYY, m_z + m_lookZZ)) && !(CheckBoundBoxColision(col)) && !(CheckBoundSphereColision(col)) && !(CheckAiCollision(col)))
		{
			m_y += m_deltaMoveUD * (m_lookYY) * m_moveSpeed;
			callGLLookAt();
		}
	}
	else
	{
		m_y += m_deltaMoveUD * (m_lookYY) * m_moveSpeed;
		callGLLookAt();
	}
}

//----------------------------------------------------------------------------------------
// Rotates camera left and right
//----------------------------------------------------------------------------------------
void Camera::RotateLR()
{
	m_rotateAngleLR += m_deltaAngleLR;
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	callGLLookAt();
}

//----------------------------------------------------------------------------------------
//  Rotates camera up and down
//----------------------------------------------------------------------------------------
void Camera::LookUD()
{
	if (m_rotateAngleUD + m_deltaAngleUD < 0.75 && m_rotateAngleUD + m_deltaAngleUD > -0.75)
	{
		m_rotateAngleUD += m_deltaAngleUD;
		m_lookY = sin(m_rotateAngleUD);
		callGLLookAt();
	}
	//std::cout << m_rotateAngleUD << std::endl;
}

//----------------------------------------------------------------------------------------
// Positions camera at co-ordinates of parameters
//----------------------------------------------------------------------------------------
void Camera::Position (GLdouble const & tempX, GLdouble const & tempY,
			           GLdouble const & tempZ, GLdouble const & tempAngle)
{
	ResetXYZ();
	
	m_x = tempX;
	m_y = tempY;
	m_z = tempZ;

	// rotate to correct angle
	m_rotateAngleLR = tempAngle * (PI / 180);
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	m_rotateAngleUD = 0.0;
	m_deltaAngleUD = 0.0;

	// redislay
	callGLLookAt();
}

//----------------------------------------------------------------------------------------
// Check ok to move
//----------------------------------------------------------------------------------------
void Camera::CheckCamera()
{
	if (MoveFBOK()) MoveFB();
	if (MoveLROK()) MoveLR();
	if (MoveUDOK()) MoveUD();
	if (RotateLROK()) RotateLR();
	if (LookUDOK()) LookUD();
}


//----------------------------------------------------------------------------------------
//  Redisplay new camera view
//----------------------------------------------------------------------------------------
void Camera::callGLLookAt()
{
	glLoadIdentity();
	gluLookAt(m_x, m_y, m_z, 
		      m_x + m_lookX, m_y + m_lookY, m_z + m_lookZ,
			  0.0f, 1.0f, 0.0f);


	//std::cout << "pos: " << m_x << " " << m_y << " " << m_z << std::endl;
	//std::cout << "Look (x,y,z): " << m_lookX << "," << m_lookY << "," << m_lookZ << std::endl;
}

//--------------------------------------------------------------------------------------
// Display map of world
//----------------------------------------------------------------------------------------

void Camera::DisplayMap(const int & screenWidth, const int & screenHeight, 
		                const GLuint & tempImage)
{
	m_map.DisplayMap(screenWidth, screenHeight, GetLR (), GetFB (), tempImage);
}

//--------------------------------------------------------------------------------------
// Display welcome or exit page
//----------------------------------------------------------------------------------------

void Camera::DisplayWelcomeScreen(const int & screenWidth, const int & screenHeight, 
		                const int & tempExit, const GLuint & tempImage)
{
	 m_map.DisplayWelcomeScreen(screenWidth, screenHeight, tempExit, tempImage);
}

//--------------------------------------------------------------------------------------
// Display welcome or exit page
//----------------------------------------------------------------------------------------

void Camera::DisplayNoExit(const int & screenWidth, const int & screenHeight, 
		                   const GLuint & tempImage)
{
	 m_map.DisplayNoExit(screenWidth, screenHeight, tempImage);
}

void Camera::DisplayIcon(const int & screenWidth, const int & screenHeight,
		                   const GLuint & tempImage)
{
	 m_map.DisplayIcon(screenWidth, screenHeight, tempImage);
}

void Camera::DisplayCross(const int& screenWidth, const int& screenHeight,
	const GLuint& tempImage)
{
	m_map.DisplayCross(screenWidth, screenHeight, tempImage);
}


void Camera::DisplayPower(const int& screenWidth, const int& screenHeight,
	const GLuint& tempImage)
{
	m_map.DisplayPower(screenWidth, screenHeight, tempImage);
}
//----------------------------------------------------------------------------------------

void Camera::RenderText(const int& screenWidth, const int& screenHeight, std::string text, int posX, int posY)
{
	m_map.RenderText(screenWidth, screenHeight, text, posX, posY);
}

void Camera::DisplayBack(const int& screenWidth, const int& screenHeight, int posX, int posY)
{
	m_map.DisplayBack(screenWidth, screenHeight, posX, posY);
}

void Camera::SetWorldCoordinates (const GLdouble &tempX, const GLdouble &tempZ)
{
	m_colDetect.SetWorldX(tempX);
	m_colDetect.SetWorldZ(tempZ);
}

//----------------------------------------------------------------------------------------

void Camera::SetPlains (const int tempType,
				        const GLdouble tempXs, const GLdouble tempXe,
				        const GLdouble tempYs, const GLdouble tempYe,
				        const GLdouble tempZs, const GLdouble tempZe)
{
	m_Plain.AddToStart(tempType, tempXs, tempXe, tempYs, tempYe, tempZs, tempZe);
}

//--------------------------------------------------------------------------------------
// THE BELOW FUNCTIONS ARE NOT IMPLEMENTED
// Originally created to climb stairs
// The Plain object is used instead
//----------------------------------------------------------------------------------------
void Camera::CheckSteps()
{

	//ClimbSteps(10000.0, 9430.0, 48.0, 142.0, 4);
	//ClimbSteps(8920.0, 8210.0, 48.0, 142.0, 5);
	//ClimbSteps(7698.0, 6988.0, 48.0, 142.0, 5);
	//ClimbSteps(6476.0, 5766.0, 48.0, 142.0, 5);
}

//----------------------------------------------------------------------------------------

void Camera::ClimbSteps(GLdouble stepStart, GLdouble stepFinish, GLdouble stepHeight, GLdouble stepWidth, int noSteps)
{	
	GLdouble tempUpSteps;
	if ((m_z < stepStart) && (m_z > stepFinish))
	{
		bool stepped = false;
		if (m_z > m_zLast)
		{
			m_direction = 1.0;
			tempUpSteps = stepWidth;
		}
		else
		{
			m_direction = -1.0;
			tempUpSteps = 0.0;
		}

		for (int i = 0; i < noSteps + 1; i++)
		{
			if ((m_z < (stepStart - (i * stepWidth) + stepWidth/2) - tempUpSteps)
				&& (m_z > (stepStart - (i * stepWidth) - stepWidth/2) - tempUpSteps))
			{
				if (stepped== false) 
				{	
					m_z = stepStart - (stepWidth * i) + (m_direction * stepWidth) - tempUpSteps;
					m_y += stepHeight * m_direction;
				
					stepped = true;
					DirectionFB(0);
					DirectionLR(0);
				}			
			}
		}
	}
}

void Camera::AddBoundBox(BoundingBox b)
{
	bBoxs.push_back(b);
}

void Camera::SetBoundBox(int i, BoundingBox b)
{
	bBoxs[i] = b;
}

BoundingBox Camera::GetBoundBox(int i)
{
	return bBoxs[i];
}

bool Camera::CheckBoundBoxColision(glm::vec3 col)
{
	
	for (int i = 0; i < bBoxs.size(); i++)
	{
		if (bBoxs[i].CheckCollision(col))
		{
			return true;
		}
			
	}
	return false;
}


bool Camera::CheckBoundSphereColision(glm::vec3 col)
{

	for (int i = 0; i < bSpheres.size(); i++)
	{
		if (bSpheres[i].Distance(col) < (bSpheres[i].GetRadius() + p_radius))
		{
			return true;
		}
		
	}
	return false;
}

void Camera::SetPlayerRadius(GLfloat p)
{
	p_radius = p;
}

GLfloat Camera::GetPlayerRadius() const
{
	return p_radius;
}

void Camera::AddBoundSphere(BoundingSphere b)
{
	bSpheres.push_back(b);
}

void Camera::SetBoundSphere(int i, BoundingSphere b)
{
	bSpheres[i] = b;
}

BoundingSphere Camera::GetBoundSphere(int i)
{
	return bSpheres[i];
}

void Camera::ShowBox()
{
	for (int i = 0; i < bBoxs.size(); i++)
	{
		bBoxs[i].Display();
	}

	for (int i = 0; i < floor.size(); i++)
		floor[i].Display();
}

bool Camera::CheckAiCollision(glm::vec3 col)
{
	BoundingBox checkBox;
	bool collision = false;

	//std::cout << "collision checked" << std::endl;

	for (int i = 0; i < aiZ.size(); i++)
	{
		checkBox = aiZ[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			aiZ[i].SetCollision(true);
			collision = true;
		}
		else
			aiZ[i].SetCollision(false);
	}

	for (int i = 0; i < aiX.size(); i++)
	{
		checkBox = aiX[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			aiX[i].SetCollision(true);
			collision = true;
		}
		else
			aiX[i].SetCollision(false);
	}

	for (int i = 0; i < aiY.size(); i++)
	{
		checkBox = aiY[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			aiY[i].SetCollision(true);
			collision = true;
		}
		else
			aiY[i].SetCollision(false);
	}

	for (int i = 0; i < waitAi.size(); i++)
	{
		checkBox = waitAi[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			collision = true;
		}
	}
	
	return collision;
}

int Camera::CheckTagAi(glm::vec3 col, std::string tag)
{
	BoundingBox checkBox;
	for (int i = 0; i < waitAi.size(); i++)
	{
		checkBox = waitAi[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			if (tag == waitAi[i].GetTag())
			{
				if (!waitAi[i].IsDone())
				{
					waitAi[i].SetDone();
					//std::cout << "score: " << waitAi[i].Score() << std::endl;
					return waitAi[i].Score();
				}
			}
		}
	}

	return 0;
}

void Camera::AddFloorCol(BoundingBox b)
{
	floor.push_back(b);
}

bool Camera::CheckFloorColision(glm::vec3 col)
{

	for (int i = 0; i < floor.size(); i++)
	{
		if (floor[i].CheckCollision(col))
		{
			return true;
		}
	}
	return false;
}