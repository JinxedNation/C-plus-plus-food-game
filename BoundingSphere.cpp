#include "BoundingSphere.h"
BoundingSphere::BoundingSphere()
{
	glm::vec3 zero(0, 0, 0);
	center = zero;
	radius = 1;
}

BoundingSphere::BoundingSphere(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos)
{
	CreateSphere(v, s, pos);
}

void BoundingSphere::CreateSphere(std::vector<vertex> v, glm::vec3 s, glm::vec3 pos)
{
	glm::vec3 zero(0, 0, 0);
	glm::vec3 min = zero;
	glm::vec3 max = zero;

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

	center.x = (min.x + max.x) / 2;
	center.y = (min.y + max.y) / 2;
	center.z = (min.z + max.z) / 2;

	radius = sqrt((min.x - max.x) * (min.x - max.x) + (min.y - max.y) * (min.y - max.y) + (min.z - max.z) * (min.z - max.z));
	radius /= 4;
}

void BoundingSphere::Display()
{
	glPushMatrix();
	{
		glTranslatef(center.x, center.y, center.z);
		glutWireSphere(radius, 10, 20);
	}
	glPopMatrix();
}

GLfloat BoundingSphere::Distance(glm::vec3 col)
{
	GLfloat dis = sqrt((col.x - center.x) * (col.x - center.x) + (col.y - center.y) * (col.y - center.y) + (col.z - center.z) * (col.z - center.z));
	return dis;
}

GLfloat BoundingSphere::GetRadius() const
{
	return radius;
}

void BoundingSphere::SetRadius(GLfloat r)
{
	radius = r;
}

void BoundingSphere::SetCenter(glm::vec3 c)
{
	center = c;
}

glm::vec3 BoundingSphere::GetCenter() const
{
	return center;
}