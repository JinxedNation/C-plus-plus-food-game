#ifndef AABBNODE_H
#define AABBNODE_H

#include <vector>
#include <gl/glut.h>
#include "BoundingBox.h"
#include <glm.hpp>

/**
* @class AABBNode
* @brief AA Bounding box storing in a dynamic array
*
* Stores the details of each bounding box used for collision detection
* As of september 2020, instead of using structure XYZ and BoundingBox, a class for bounding box is now used
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

class AABBNode
{
public:
	AABBNode () {Clear();}
    virtual ~AABBNode () {Clear();}

			/**
			* @brief Clears the next node stored
			*
			* @return void
			*/
	void  Clear();

			/**
			* @brief Gets maxX of the bounding box
			*
			* @return GLdouble m_BBox.max.x
			*/
	GLdouble GetMaxX () {return m_BBox.GetMaxX();}

			/**
			* @brief Gets minX of the bounding box
			*
			* @return GLdouble m_BBox.min.x
			*/
	GLdouble GetMinX () {return m_BBox.GetMinX();}

			/**
			* @brief Gets maxY of the bounding box
			*
			* @return GLdouble m_BBox.max.y
			*/
	GLdouble GetMaxY () {return m_BBox.GetMaxY();}

			/**
			* @brief Gets minY of the bounding box
			*
			* @return GLdouble m_BBox.min.y
			*/
	GLdouble GetMinY () {return m_BBox.GetMinY();}

			/**
			* @brief Gets maxZ of the bounding box
			*
			* @return GLdouble m_BBox.max.z
			*/
	GLdouble GetMaxZ () {return m_BBox.GetMaxZ();}

			/**
			* @brief Gets minZ of the bounding box
			*
			* @return GLdouble m_BBox.min.z
			*/
	GLdouble GetMinZ () {return m_BBox.GetMinZ();}

			/**
			* @brief Gets the next node
			*
			* @return AABBNode m_next
			*/
    AABBNode *GetNext () const {return m_next;}

			/**
			* @brief Sets the data for the bounding box
			*
			* @return void
			*/
	void SetData(const GLdouble maxX, const GLdouble minX,  const GLdouble maxY, const GLdouble minY,  const GLdouble maxZ, const GLdouble minZ);

			/**
			* @brief Sets a node into m_next
			*
			* @return void
			*/
    void SetNext (AABBNode *next) {m_next = next;}

private:
    // The address of the next node in the list
    AABBNode *m_next;

	///stores above info
	BoundingBox m_BBox;


    // Privatised copy constructor and assignment operator
    AABBNode (const AABBNode &newNode) {};
    AABBNode &operator = (const AABBNode &newNode) {};
};

#endif