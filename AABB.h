#ifndef AABB_H
#define AABB_H

#include <iostream>
#include <math.h>
#include <gl/glut.h>
#include "BoundingBox.h"

/**
* @class AABB
* @brief AA Bounding box storing in a dynamic array
*
* Dynamic array that stores the co-ordinated of the bounding boxes. Used for collision.
*
*  Shay created this class originally before using linked lists to store the BB info. But decided
*  to keep it has the stored data can be easily copied across into different linked lists
*  in any prefered order. (i.e. the data is copied into across into linked lists for different
*  quadrants) (taken from original comments), As of september 2020, instead of using structure XYZ and BoundingBox, a class for bounding box is now used
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

class AABB
{
private:

		///dynamic array to store info
	BoundingBox *m_BBox;
		///number of BB created (i.e. array size)
	int m_NoOfBoxes;

			/**
			* @brief Clear bounding boxes
			*
			* Deletes the array and clears the memory
			*
			* @return void
			*/
	void ClearBB (BoundingBox* &tempArray);


    // Privatised copy constructor and assignment operator
    AABB (const AABB &aabb) {};
    AABB &operator = (const AABB &aabb) {};

public:
	AABB () {}
    virtual ~AABB () {ClearBB(m_BBox);}
	
			/**
			* @brief Set maxX at a specific index
			*
			* @return void
			*/
	void SetMaxX(const int & tempIndex, const GLdouble &tempX) {m_BBox[tempIndex].SetMaxX(tempX);}

			/**
			* @brief Set minX at a specific index
			*
			* @return void
			*/
	void SetMinX(const int & tempIndex, const GLdouble &tempX) {m_BBox[tempIndex].SetMinX(tempX);}

			/**
			* @brief Set maxY at a specific index
			*
			* @return void
			*/
	void SetMaxY(const int & tempIndex, const GLdouble &tempY) {m_BBox[tempIndex].SetMaxY(tempY);}

			/**
			* @brief Set minY at a specific index
			*
			* @return void
			*/
	void SetMinY(const int & tempIndex, const GLdouble &tempY) {m_BBox[tempIndex].SetMinY(tempY);}

			/**
			* @brief Set maxZ at a specific index
			*
			* @return void
			*/
	void SetMaxZ(const int & tempIndex, const GLdouble &tempZ) {m_BBox[tempIndex].SetMaxZ(tempZ);}

			/**
			* @brief Set minZ at a specific index
			*
			* @return void
			*/
	void SetMinZ(const int & tempIndex, const GLdouble &tempZ) {m_BBox[tempIndex].SetMinZ(tempZ);}

			/**
			* @brief Sets the number of bounding boxes to the array
			*
			* @return void
			*/
	void SetNoBoundingBoxes(const int & tempSize);

			/**
			* @brief Get maxX at a specific index
			*
			* @return GLdouble m_BBox[tempIndex].max.x
			*/
	GLdouble GetMaxX (const int & tempIndex) {return m_BBox[tempIndex].GetMaxX();}

			/**
			* @brief Get minX at a specific index
			*
			* @return GLdouble m_BBox[tempIndex].min.x
			*/
	GLdouble GetMinX (const int & tempIndex) {return m_BBox[tempIndex].GetMinX();}

			/**
			* @brief Get maxY at a specific index
			*
			* @return GLdouble m_BBox[tempIndex].max.y
			*/
	GLdouble GetMaxY (const int & tempIndex) {return m_BBox[tempIndex].GetMaxY();}

			/**
			* @brief Get minY at a specific index
			*
			* @return GLdouble m_BBox[tempIndex].min.y
			*/
	GLdouble GetMinY (const int & tempIndex) {return m_BBox[tempIndex].GetMinY();}

			/**
			* @brief Get maxZ at a specific index
			*
			* @return GLdouble m_BBox[tempIndex].max.Z
			*/
	GLdouble GetMaxZ (const int & tempIndex) {return m_BBox[tempIndex].GetMaxZ();}

			/**
			* @brief Get minZ at a specific index
			*
			* @return GLdouble m_BBox[tempIndex].min.z
			*/
	GLdouble GetMinZ (const int & tempIndex) {return m_BBox[tempIndex].GetMinZ();}

			/**
			* @brief Gets the number of bounding boxes
			*
			* @return int m_NoOfBoxes
			*/
	int GetNoBoundingBoxes () {return m_NoOfBoxes;}
};

#endif
//--------------------------------------------------------------------------------------