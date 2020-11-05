#include "AgentZ.h"

AgentZ::AgentZ(int i, Object obj, float s, float mX, float mN)
{
	SetID(i);
	SetObj(obj);
	SetMainValues(s, mX, mN);
	SetCollision(false);
	SetCurrentState(Negative);
	SetPreviousState(Negative);
}

void AgentZ::Move()
{
	time.Update();
	switch (GetCurrentState())
	{
		case Positive:
			MovePositive();
			break;
		case Negative:
			MoveNegative();
			break;
		case Still:
		default: 
			break;
	}
}

void AgentZ::MovePositive()
{

	Object ob = GetObj();
	BoundingBox objBox = ob.GetBoundingBox();
	glm::vec3 pos = ob.GetPosition();

	if ((pos.z + GetSpeed() * time.deltaTime) > GetMax())
	{
		State t = Negative;
		UpdateState(t);
	}
	else
	{
		float move = GetSpeed() * time.deltaTime;
		pos.z += move;
		objBox.UpdateZ(move);
		ob.SetPosition(pos);
		ob.SetBoundingBox(objBox);
		SetObj(ob);
	}
}

void AgentZ::MoveNegative()
{
	Object ob = GetObj();
	BoundingBox objBox = ob.GetBoundingBox();
	glm::vec3 pos = ob.GetPosition();
	
	if ((pos.z - GetSpeed() * time.deltaTime) < GetMin())
	{
		State t = Positive;
		UpdateState(t);
	}
	else
	{
		float move = GetSpeed() * time.deltaTime;
		pos.z -= move;
		objBox.UpdateZ(-move);
		ob.SetPosition(pos);
		ob.SetBoundingBox(objBox);
		SetObj(ob);
	}
}

void AgentZ::UpdateState(State s)
{
	SetPreviousState(GetCurrentState());
	SetCurrentState(s);
}

bool AgentZ::CheckPlayerPos()
{
	glm::vec3 check = GetPlayer();
	check.z -= 50.0f;

	return GetObj().GetBoundingBox().CheckCollision(check);
}

bool AgentZ::CheckPlayerNeg()
{
	glm::vec3 check = GetPlayer();
	check.z += 50.0f;

	return GetObj().GetBoundingBox().CheckCollision(check);
}

void AgentZ::AddInfo(int i, Object obj, float s, float mX, float mN)
{
	SetID(i);
	SetObj(obj);
	SetMainValues(s, mX, mN);
	SetCollision(false);
	SetCurrentState(Negative);
	SetPreviousState(Negative);
}