#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
	glm::vec3 zero(0, 0, 0);
	min = zero;
	max = zero;
}

BoundingBox::BoundingBox(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos)
{
	CreateBox(v, s, pos);
}

void BoundingBox::CreateBox(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos)
{
	glm::vec3 zero(0, 0, 0);
	min = zero;
	max = zero;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i].pos.x * s.x > max.x)
			max.x = v[i].pos.x * s.x;
		else if (v[i].pos.x * s.x < min.x)
			min.x = v[i].pos.x * s.x;

		if (v[i].pos.y * s.y > max.y)
			max.y = v[i].pos.y * s.y;
		else if (v[i].pos.y * s.y < min.y)
			min.y = v[i].pos.y * s.y;

		if (v[i].pos.z * s.z > max.z * s.z)
			max.z = v[i].pos.z * s.z;
		else if (v[i].pos.z < min.z * s.z)
			min.z = v[i].pos.z * s.z;
	}

	min.x += pos.x;
	min.y += pos.y;
	min.z += pos.z;
	max.x += pos.x;
	max.y += pos.y;
	max.z += pos.z;
}

bool BoundingBox::CheckCollision(glm::vec3 col)
{
	return (col.x >= min.x && col.x <= max.x) && (col.y >= min.y && col.y <= max.y) && (col.z >= min.z && col.z <= max.z);
}

void BoundingBox::Display()
{
	//face 1
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, max.y, max.z);
		glVertex3f(max.x, max.y, max.z);
		glVertex3f(max.x, min.y, max.z);
		glVertex3f(min.x, min.y, max.z);
	}
	glEnd();

	//face 2
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, max.y, min.z);
		glVertex3f(max.x, max.y, min.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(min.x, min.y, min.z);
	}
	glEnd();

	//face 3
	glBegin(GL_QUADS);
	{
		glVertex3f(max.x, max.y, max.z);
		glVertex3f(max.x, max.y, min.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(max.x, min.y, max.z);
	}
	glEnd();

	//face 4
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, max.y, max.z);
		glVertex3f(min.x, max.y, min.z);
		glVertex3f(min.x, min.y, min.z);
		glVertex3f(min.x, min.y, max.z);
	}
	glEnd();

	//face 5
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, max.y, max.z);
		glVertex3f(min.x, max.y, min.z);
		glVertex3f(max.x, max.y, min.z);
		glVertex3f(max.x, max.y, max.z);
	}
	glEnd();


	//face 6
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, min.y, max.z);
		glVertex3f(min.x, min.y, min.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(max.x, min.y, max.z);
	}
	glEnd();
}

void BoundingBox::DisplayFloor()
{
	float reduction = 900.0f;
	//face 1
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, max.y - reduction, max.z);
		glVertex3f(max.x, max.y - reduction, max.z);
		glVertex3f(max.x, min.y, max.z);
		glVertex3f(min.x, min.y, max.z);
	}
	glEnd();

	//face 2
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, max.y - reduction, min.z);
		glVertex3f(max.x, max.y - reduction, min.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(min.x, min.y, min.z);
	}
	glEnd();

	//face 3
	glBegin(GL_QUADS);
	{
		glVertex3f(max.x, max.y - reduction, max.z);
		glVertex3f(max.x, max.y - reduction, min.z);
		glVertex3f(max.x, min.y, min.z);
		glVertex3f(max.x, min.y, max.z);
	}
	glEnd();

	//face 4
	glBegin(GL_QUADS);
	{
		glVertex3f(min.x, max.y - reduction, max.z);
		glVertex3f(min.x, max.y - reduction, min.z);
		glVertex3f(min.x, min.y, min.z);
		glVertex3f(min.x, min.y, max.z);
	}
	glEnd();

}

void BoundingBox::SetMin(glm::vec3 m)
{
	min = m;
}

glm::vec3 BoundingBox::GetMin() const
{
	return min;
}

void BoundingBox::SetMax(glm::vec3 m)
{
	max = m;
}

glm::vec3 BoundingBox::GetMax() const
{
	return max;
}


void BoundingBox::SetMaxX(GLfloat x)
{
	max.x = x;
}

GLfloat BoundingBox::GetMaxX()
{
	return max.x;
}

void BoundingBox::SetMaxY(GLfloat y)
{
	max.y = y;
}

GLfloat BoundingBox::GetMaxY()
{
	return max.y;
}

void BoundingBox::SetMaxZ(GLfloat z) 
{
	max.z = z;
}

GLfloat BoundingBox::GetMaxZ()
{
	return max.z;
}

void BoundingBox::SetMinX(GLfloat x)
{
	min.x = x;
}

GLfloat BoundingBox::GetMinX()
{
	return min.x;
}

void BoundingBox::SetMinY(GLfloat y)
{
	min.y = y;
}

GLfloat BoundingBox::GetMinY()
{
	return min.y;
}

void BoundingBox::SetMinZ(GLfloat z)
{
	min.z = z;
}

GLfloat BoundingBox::GetMinZ()
{
	return min.z;
}

void BoundingBox::UpdateZ(float value)
{
	min.z += value;
	max.z += value;
}

void BoundingBox::UpdateX(float value)
{
	min.x += value;
	max.x += value;
}

void BoundingBox::UpdateY(float value)
{
	min.y += value;
	max.y += value;
}