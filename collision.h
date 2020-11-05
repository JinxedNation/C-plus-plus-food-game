#ifndef COLLISION_H
#define COLLISION_H

#include "AABB.h"
#include "AABBLinkedList.h"

/**
* @class Collision
* @brief Class used to detect collisions from the player and world objects
*
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

class Collision
{
public:

	Collision() {}
	virtual ~Collision() {}

			/**
			* @brief Sets the MaxX
			*
			* Sets the maxX of the AABB
			*
			* @return void
			*/
	void SetAABBMaxX(const int & tempIndex, const double &tempX) {m_AABB.SetMaxX(tempIndex, tempX);}

			/**
			* @brief Sets the MinX
			*
			* Sets the maxX of the AABB
			*
			* @return void
			*/
	void SetAABBMinX(const int & tempIndex, const double &tempX) {m_AABB.SetMinX(tempIndex, tempX);}

			/**
			* @brief Sets the MaxY
			*
			* Sets the maxX of the AABB
			*
			* @return void
			*/
	void SetAABBMaxY(const int & tempIndex, const double &tempY) {m_AABB.SetMaxY(tempIndex, tempY);}

			/**
			* @brief Sets the MinY
			*
			* Sets the maxX of the AABB
			*
			* @return void
			*/
	void SetAABBMinY(const int & tempIndex, const double &tempY) {m_AABB.SetMinY(tempIndex, tempY);}

			/**
			* @brief Sets the MaxY
			*
			* Sets the maxX of the AABB
			*
			* @return void
			*/
	void SetAABBMaxZ(const int & tempIndex, const double &tempZ) {m_AABB.SetMaxZ(tempIndex, tempZ);}

			/**
			* @brief Sets the MinZ
			*
			* Sets the maxX of the AABB
			*
			* @return void
			*/
	void SetAABBMinZ(const int & tempIndex, const double &tempZ) {m_AABB.SetMinZ(tempIndex, tempZ);}

			/**
			* @brief Sets the world size for x
			*
			* @return void
			*/
	void SetWorldX(const double &tempX) {m_worldSizeX = tempX;}

			/**
			* @brief Sets the world size for z
			*
			* @return void
			*/
	void SetWorldZ(const double &tempZ) {m_worldSizeZ = tempZ;}

			/**
			* @brief Sets the bounding boxes
			*
			* @return void
			*/
	void SetNoBoundingBoxes(const int & tempSize) {m_AABB.SetNoBoundingBoxes(tempSize);}

			/**
			* @brief Gets the maxX
			*
			* Gets the max X from the AABB
			*
			* @return AABB m_AABB.GetMaxX
			*/
	double GetAABBMaxX (const int & tempIndex) {return m_AABB.GetMaxX (tempIndex);}

			/**
			* @brief Gets the minX
			*
			* Gets the min X from the AABB
			*
			* @return AABB m_AABB.GetMinX
			*/
	double GetAABBMinX (const int & tempIndex) {return m_AABB.GetMinX (tempIndex);}

			/**
			* @brief Gets the maxY
			*
			* Gets the max y from the AABB
			*
			* @return AABB m_AABB.GetMaxY
			*/
	double GetAABBMaxY (const int & tempIndex) {return m_AABB.GetMaxY (tempIndex);}

			/**
			* @brief Gets the minY
			*
			* Gets the min y from the AABB
			*
			* @return AABB m_AABB.GetMinY
			*/
	double GetAABBMinY (const int & tempIndex) {return m_AABB.GetMinY (tempIndex);}

			/**
			* @brief Gets the maxZ
			*
			* Gets the max z from the AABB
			*
			* @return AABB m_AABB.GetMaxZ
			*/
	double GetAABBMaxZ (const int & tempIndex) {return m_AABB.GetMaxZ (tempIndex);}

			/**
			* @brief Gets the minZ
			*
			* Gets the min z from the AABB
			*
			* @return AABB m_AABB.GetMinZ
			*/
	double GetAABBMinZ (const int & tempIndex) {return m_AABB.GetMinZ (tempIndex);}

			/**
			* @brief Gets the number of bounding boxes
			*
			* @return m_AABB.GetNoBoundingBoxes()
			*/
	int GetNoBoundingBoxes() {return m_AABB.GetNoBoundingBoxes();}

			/**
			* @brief Checks if a collision has been made
			*
			* @return bool
			*/
	bool Collide (double endX, double endY, double endZ);

			/**
			* @brief Creates a linked list
			*
			* @return void
			*/
	void CreateLinkedList();

private:
	///initially stores BB info in AABB (dynamic array) before copying to Linked List
	AABB m_AABB;

	///lists to store bounding box info in each quadrant
	AABBLinkedList m_list[4];

	///Stores the list size of each linked list
	int m_listSize[4];

	///stores world co-ordinates X
	double m_worldSizeX;
	///stores world co-ordinates Z
	double m_worldSizeZ;

			/**
			* @brief Checks if a collision has been made
			*
			* @return bool
			*/
	bool CheckCollision(int index, double endX, double endY, double endZ);


    // Privatised copy constructor and assignment operator
    Collision (const Collision &coll) {};
    Collision &operator = (const Collision &coll) {};
};

#endif