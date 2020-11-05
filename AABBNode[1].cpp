//  AABBNode.cpp
//
//  Implementation file for AABBNode Class
//  Defines all the methods declared, but not defined, in AABBNode.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "AABBNode.h"

//----------------------------------------------------------------

void AABBNode::Clear()
{
	m_next = NULL;
}

//----------------------------------------------------------------


void AABBNode::SetData(const GLdouble maxX, const GLdouble minX,
					   const GLdouble maxY, const GLdouble minY,
				       const GLdouble maxZ, const GLdouble minZ)
{
	glm::vec3 max(maxX, maxY, maxZ);
	glm::vec3 min(minX, minY, minZ);
	m_BBox.SetMax(max);
	m_BBox.SetMin(min);
}

//----------------------------------------------------------------
