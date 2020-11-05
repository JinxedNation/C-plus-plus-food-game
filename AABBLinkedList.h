#ifndef AABBLINKED_LIST_H
#define AABBLINKED_LIST_H

#include "AABBNode.h"
#include <gl/glut.h>

/**
* @class AABBLinkedList
* @brief AA Bounding box storing in a linked list
*
* Linked list that stores AABBNode nodes that have the BoundingBox co-ordinants
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

class AABBLinkedList
{
public:
	// constructor creates pointer to first node
	AABBLinkedList() {m_first = new AABBNode;}

	virtual ~AABBLinkedList() {Clear();}

			/**
			* @brief Clears the linked list, freeing the memory
			*
			* @return void
			*/
	void Clear();

			/**
			* @brief Adds a node to the start of the linked list
			*
			* @return void
			*/
	bool AddToStart (GLdouble maxX, GLdouble minX, GLdouble maxY, GLdouble minY, GLdouble maxZ, GLdouble minZ);
	
			/**
			* @brief Sets the values inside the linked list
			*
			* @return void
			*/
	void SetData(const int &ptrCount, const GLdouble maxX, const GLdouble minX,const GLdouble maxY, const GLdouble minY, const GLdouble maxZ, const GLdouble minZ);

			/**
			* @brief Gets the maxX of the node
			*
			* @return GLdouble maxX
			*/
	GLdouble GetMaxX (int ptrCount);

			/**
			* @brief Gets the minX of the node
			*
			* @return GLdouble minX
			*/
	GLdouble GetMinX (int ptrCount);

			/**
			* @brief Gets the maxY of the node
			*
			* @return GLdouble maxY
			*/
	GLdouble GetMaxY (int ptrCount);

			/**
			* @brief Gets the minY of the node
			*
			* @return GLdouble minY
			*/
	GLdouble GetMinY (int ptrCount);

			/**
			* @brief Gets the maxZ of the node
			*
			* @return GLdouble maxZ
			*/
	GLdouble GetMaxZ (int ptrCount);

			/**
			* @brief Gets the minZ of the node
			*
			* @return GLdouble minZ
			*/
	GLdouble GetMinZ (int ptrCount);
	
			/**
			* @brief Gets the size of the linked list
			*
			* @return int tmpSize
			*/
	int GetListSize ();
	
			/**
			* @brief Gets the address to the next linked list
			*
			* @return AABBNode m_first->GetNext
			*/
    AABBNode *GetNext () const {return m_first->GetNext();}

			/**
			* @brief Gets the first node in the linked list
			*
			* @return AABBNode m_first
			*/
	AABBNode *GetFirst() const {return m_first;}

private:
		///pointer to first node in list
	AABBNode *m_first;

			/**
			* @brief Used to clear memory
			*
			* @return void
			*/
	void Delete (AABBNode *before);

	AABBLinkedList (const AABBLinkedList &ll) {};
	AABBLinkedList &operator = (const AABBLinkedList &ll) {};
};

#endif