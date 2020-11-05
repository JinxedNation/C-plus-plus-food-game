

//  camera.h
//  Header file for the camera class
//	Allows the camera to be navigated around the world. 
//	Also sets Plains, Bounding Boxes and view Maps
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#define PI 3.1415962654

#include "collision.h"
#include "cameraMap.h"
#include "PlainLinkedList.h"
#include "EasySound.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "Level.h"
#include "Item.h"
#include "game_Manager.h"

/**
* @class Camera
* @brief The class for the camera, also setting plains, bounding boxes and the location of loaded in objects
*
* @author  Shay Leary
* @version 01
* @date March 2005
* 
* @author Christopher Logan
* @version 02
* @date 09/9/2020
*
* @author Christopher Logan
* @version 03
* @date 1/10/2020
*
*
* @bug no known bugs, but there may be some out there...
*/

class Camera
{
public:

	Camera();
	virtual ~Camera() {}

            /**
            * @brief Sets the max x of the AABB
            *
            * @return void
            */
	void SetAABBMaxX(const int & tempIndex, const GLdouble &tempX) {m_colDetect.SetAABBMaxX(tempIndex, tempX);}

            /**
            * @brief Sets the min x of the AABB
            *
            * @return void
            */
	void SetAABBMinX(const int & tempIndex, const GLdouble &tempX) {m_colDetect.SetAABBMinX(tempIndex, tempX);}

            /**
            * @brief Sets the max y of the AABB
            *
            * @return void
            */
	void SetAABBMaxY(const int & tempIndex, const GLdouble &tempY) {m_colDetect.SetAABBMaxY(tempIndex, tempY);}

            /**
            * @brief Sets the min y of the AABB
            *
            * @return void
            */
	void SetAABBMinY(const int & tempIndex, const GLdouble &tempY) {m_colDetect.SetAABBMinY(tempIndex, tempY);}


            /**
            * @brief Sets the max z of the AABB
            *
            * @return void
            */
	void SetAABBMaxZ(const int & tempIndex, const GLdouble &tempZ) {m_colDetect.SetAABBMaxZ(tempIndex, tempZ);}


            /**
            * @brief Sets the min z of the AABB
            *
            * @return void
            */
	void SetAABBMinZ(const int & tempIndex, const GLdouble &tempZ) {m_colDetect.SetAABBMinZ(tempIndex, tempZ);}

			/**
			* @brief sets the step size
			*
			* @return void
			*/
	void SetRotateSpeed (const GLdouble &tempSpeed) {m_rotateSpeed = tempSpeed;}

			/**
			* @brief sets the roation size
			*
			* @return void
			*/
	void SetMoveSpeed (const GLdouble &tempSpeed) {m_moveSpeed = tempSpeed;}



			/**
			* @brief Sets the collision detection (if on of off)
			*
			* @return void
			*/
	void SetCollisionDetectionOn (const bool &tempCol) {m_CollisionDetectionOn = tempCol;}
	
			/**
			* @brief Sets the number of bounding boxes used
			*
			* @return void
			*/
	void SetNoBoundingBoxes(const int & tempSize) {m_colDetect.SetNoBoundingBoxes(tempSize);}

			/**
			* @brief Sets the co-ordinants for the world
			*
			* @return void
			*/
	void SetWorldCoordinates (const GLdouble &tempX, const GLdouble &tempZ);

			/**
			* @brief initiates the bounding boxes
			*
			* creates a linked list for each quadrant of the world and places the bounding box
			* data in each.  Then clears and deletes AABB array.
			*
			* @return void
			*/
	void InitiateBoundingBoxes() {m_colDetect.CreateLinkedList();}

			/**
			* @brief sets the co-ordinatns of each plain
			*
			* @return void
			*/
	void SetPlains (const int tempType,
				    const GLdouble tempXs, const GLdouble tempXe,
				    const GLdouble tempYs, const GLdouble tempYe,
				    const GLdouble tempZs, const GLdouble tempZe);

			/**
			* @brief Gets moveX
			*
			* @return GLDouble m_x
			*/
	GLdouble GetLR () {return m_x;}

			/**
			* @brief Gets moveY
			*
			* @return GLDouble m_y
			*/
	GLdouble GetUD () {return m_y;}

			/**
			* @brief Gets moveZ
			*
			* @return GLDouble m_z
			*/
	GLdouble GetFB () {return m_z;}	

			/**
			* @brief Gets MaxX of tempIndex
			*
			* @return MaxX[tempIndex]
			*/
	GLdouble GetAABBMaxX (const int & tempIndex) {return m_colDetect.GetAABBMaxX (tempIndex);}

			/**
			* @brief Gets MinX of tempIndex
			*
			* @return MinX[tempIndex]
			*/
	GLdouble GetAABBMinX (const int & tempIndex) {return m_colDetect.GetAABBMinX (tempIndex);}

			/**
			* @brief Gets MaxY of tempIndex
			*
			* @return MaxY[tempIndex]
			*/
	GLdouble GetAABBMaxY (const int & tempIndex) {return m_colDetect.GetAABBMaxY (tempIndex);}

			/**
			* @brief Gets MinY of tempIndex
			*
			* @return MinY[tempIndex]
			*/
	GLdouble GetAABBMinY (const int & tempIndex) {return m_colDetect.GetAABBMinY (tempIndex);}

			/**
			* @brief Gets MaxZ of tempIndex
			*
			* @return MaxZ[tempIndex]
			*/
	GLdouble GetAABBMaxZ (const int & tempIndex) {return m_colDetect.GetAABBMaxZ (tempIndex);}

			/**
			* @brief Gets MinZ of tempIndex
			*
			* @return MinZ[tempIndex]
			*/
	GLdouble GetAABBMinZ (const int & tempIndex) {return m_colDetect.GetAABBMinZ (tempIndex);}
	
			/**
			* @brief Sets the camera to given parameters
			*
			* Takes in x, y, z and angle valeus, and changes the camera position based of that
			*
			* @return void
			*/
	void Position (GLdouble const & tempX,
				   GLdouble const & tempY,
				   GLdouble const & tempZ,
				   GLdouble const & tempAngle);

			/**
			* @brief Checks if moves have been made
			*
			* @return void
			*/
	void CheckCamera();

			/**
			* @brief Sets a value for foward, backward move
			*
			* @return void
			*/
	void DirectionFB(int const & tempMove);

			/**
			* @brief Sets a value for left and right
			*
			* @return void
			*/
	void DirectionLR(int const & tempMove);

			/**
			* @brief Sets a value for up and down
			*
			* @return void
			*/
	void DirectionUD(int const & tempMove);

			/**
			* @brief Sets a value for left and right rotation
			*
			* @return void
			*/
	void DirectionRotateLR(GLdouble const & tempMove);

			/**
			* @brief Sets a value for up and down rotation
			*
			* @return void
			*/
	void DirectionLookUD(int const & tempMove);

			/**
			* @brief Displays the map
			*
			* @return void
			*/
	void DisplayMap(const int & screenWidth, const int & screenHeight, 
		            const GLuint & tempImage);

			/**
			* @brief Displays the welcome or exit screen
			*
			* @return void
			*/
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight,
							   const int & tempExit, const GLuint & tempImage);

			/**
			* @brief Displays the welcome or exit screen
			*
			* @return void
			*/
	void DisplayNoExit (const int & screenWidth, const int & screenHeight, 
						const GLuint & tempImage);

			/**
			* @brief Displays the icon
			*
			* @return void
			*/
	void DisplayIcon(const int& screenWidth, const int& screenHeight,
		const GLuint& tempImage);

			/**
			* @brief Displays the crosshair
			*
			* @return void
			*/
	void DisplayCross(const int& screenWidth, const int& screenHeight,
		const GLuint& tempImage);

			/**
			* @brief DisplayPower
			*
			* @return void
			*/
	void DisplayPower(const int& screenWidth, const int& screenHeight,
		const GLuint& tempImage);

			/**
			* @brief Renders the text
			*
			* @return void
			*/
	void RenderText(const int& screenWidth, const int& screenHeight, std::string text, int posX, int posY);

			/**
			* @brief Displays the back
			*
			* @return void
			*/
	void DisplayBack(const int& screenWidth, const int& screenHeight, int posX, int posY);

			/**
			* @brief Pushes a bounding box onto the vector holding the bounding boxes
			*
			* @return void
			*/
	void AddBoundBox(BoundingBox b);

			/**
			* @brief Sets a bounding box to positon i of the vector
			*
			* @return void
			*/
	void SetBoundBox(int i, BoundingBox b);

			/**
			* @brief Gets a bounding box from positon i of the vector
			*
			* @return BoundingBox bBoxs[i]
			*/
	BoundingBox GetBoundBox(int i);

			/**
			* @brief Pushes a bounding sphere onto the vector holding the bounding spheres
			*
			* @return void
			*/
	void AddBoundSphere(BoundingSphere b);

			/**
			* @brief Sets a bounding sphere to positon i of the vector
			*
			* @return void
			*/
	void SetBoundSphere(int i, BoundingSphere b);

			/**
			* @brief Gets a bounding sphere from positon i of the vector
			*
			* @return BoundingSphere bSpheres[i]
			*/
	BoundingSphere GetBoundSphere(int i);

			/**
			* @brief Checks the collision of each bounding box
			*
			* @return bool
			*/
	bool CheckBoundBoxColision(glm::vec3 col);

			/**
			* @brief Checks the collision of each bounding sphere
			*
			* @return bool
			*/
	bool CheckBoundSphereColision(glm::vec3 col);

			/**
			* @brief Sets the players radius to p
			*
			* @return void
			*/
	void SetPlayerRadius(GLfloat p);

			/**
			* @brief Gets the players radius
			*
			* @return GLfloat p_radius
			*/
	GLfloat GetPlayerRadius() const;

			/**
			* @brief Displays the bounding boxes set
			*
			* @return void
			*/
	void ShowBox();

			/**
			* @brief Checks the ai collision
			*
			* @return void
			*/
	bool CheckAiCollision(glm::vec3 col);


			/**
			* @brief Gets the players position
			*
			* @return vec3
			*/
	glm::vec3 GetPlayerPos() {glm::vec3 a(m_x, m_y, m_z); return a; }

			/**
			* @brief Gets the players rotation
			*
			* @return vec3
			*/
	glm::vec3 GetRotation() { glm::vec3 a(m_lookX, m_lookY, m_lookZ); return a; }

			/**
			* @brief Sets the aiX vector
			*
			* @return void
			*/
	void SetAiX(std::vector<AgentX> x) { aiX = x; }

			/**
			* @brief Sets the aiY vector
			*
			* @return void
			*/
	void SetAiY(std::vector<AgentY> y) { aiY = y; }

			/**
			* @brief Sets the aiZ vector
			*
			* @return void
			*/
	void SetAiZ(std::vector<AgentZ> z) { aiZ = z; }

			/**
			* @brief Sets the wait ai vector
			*
			* @return void
			*/
	void SetWaitAi(std::vector<WaitingAi> ai) { waitAi = ai; }

			/**
			* @brief Gets the waiting ai vector
			*
			* @return vector<WaitingAi> waitAi
			*/
	std::vector<WaitingAi> GetWaitAi() const { return waitAi; }
	
			/**
			* @brief Checks the tags to see if it hit an object
			*
			* @return int
			*/
	int CheckTagAi(glm::vec3 col, std::string tag);

			/**
			* @brief Adds a bounding box to the floor collision
			*
			* @return void
			*/
	void AddFloorCol(BoundingBox b);

			/**
			* @brief Checks the floor collision
			*
			* @return bool
			*/
	bool CheckFloorColision(glm::vec3 col);
	
private:

		///Holds aiX information
	std::vector<AgentX> aiX;

		///Holds aiY information
	std::vector<AgentY> aiY;

		///Holds aiZ information
	std::vector<AgentZ> aiZ;

		///Holds the waitAi information
	std::vector<WaitingAi> waitAi;

		///The players radius
	GLfloat p_radius;

		///steep incline increments x
	GLdouble m_incrementX;

		///steep incline increments z
	GLdouble m_incrementZ;

		///Number of plains
	int m_No_Plains;

		///current plain
	int m_plainNo;

		///plain height
	GLdouble m_plainHeight;

		///Left and right rotation value
	GLdouble m_rotateAngleLR;

		///Left and right delta rotation
	GLdouble m_deltaAngleLR;

		///Up and down roation value
	GLdouble m_rotateAngleUD;	

		///Up and down delta rotation
	GLdouble m_deltaAngleUD;

		///Move x, y, z, last z, last x values
	GLdouble m_x, m_y, m_z, m_zLast, m_xLast;

		///Look x, y, z values
	GLdouble m_lookX, m_lookY,m_lookZ;

		///Looking at x, y, z
	GLdouble m_lookXX, m_lookYY, m_lookZZ;

		///Movement left and right
	GLdouble m_deltaMoveLR;

		///Movement foward and back
	GLdouble m_deltaMoveFB;

		///Movement up and down
	GLdouble m_deltaMoveUD;

		///Movement direction 
	GLdouble m_direction;

		///Rotation speed
	GLdouble m_rotateSpeed;

		///Movement speed
	GLdouble m_moveSpeed;

		///Bounding box positions
	std::vector<BoundingBox> bBoxs;

		///Bounding sphere positions/radius
	std::vector<BoundingSphere> bSpheres;

		///Floor bounding boxes
	std::vector<BoundingBox> floor;
	
			/**
			* @brief Checks if it is okay to move the player foward or back
			*
			* @return bool true or false
			*/
	bool MoveFBOK();

			/**
			* @brief Checks if it is okay to move the player left or right
			*
			* @return bool true or false
			*/
	bool MoveLROK();

			/**
			* @brief Checks if it is okay to move the player up and down
			*
			* @return bool true or false
			*/
	bool MoveUDOK();

			/**
			* @brief Checks if it is okay to rotate left or right
			*
			* @return bool true or false
			*/
	bool RotateLROK();

			/**
			* @brief Checks if it is okay to rotate up or down
			*
			* @return bool true or false
			*/
	bool LookUDOK();

			/**
			* @brief Moves the player foward or back
			*
			* @return void
			*/
	void MoveFB();

			/**
			* @brief Moves the player left or right
			*
			* @return void
			*/
	void MoveLR();

			/**
			* @brief Moves the player up or down
			*
			* @return void
			*/
	void MoveUD();

			/**
			* @brief Rotates left or right
			*
			* @return void
			*/
	void RotateLR();

			/**
			* @brief Rotates the camera up or down
			*
			* @return void
			*/
	void LookUD();
	
			/**
			* @brief Overload for setting plains
			*
			* @return void
			*/
	void SetPlains(const int & moveX, const int & moveZ);

			/**
			* @brief Resets the camera position
			*
			* @return void
			*/
	void ResetXYZ();

			/**
			* @brief Display new view
			*
			* @return void
			*/
	void callGLLookAt();


		///Did a collision happen
	bool m_CollisionDetectionOn;

		///AABB collision object
	Collision m_colDetect;

		///The map
	CameraMap m_map;

		///Plains link list
	PlainLinkedList m_Plain;

	// These functions were set up to climb stairs, but are not used.
	// The Plain object is used instead
	void ClimbSteps(GLdouble stepStart, GLdouble stepFinish, GLdouble stepHeight, GLdouble stepWidth, int noSteps);
	void CheckSteps();

    Camera (const Camera &cam) {};
    Camera &operator = (const Camera &cam) {};
};

#endif