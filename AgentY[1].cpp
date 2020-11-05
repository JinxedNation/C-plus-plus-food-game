#include "AgentY.h"

AgentY::AgentY(int i, Object obj, float s, float mX, float mN)
{
	SetID(i);
	SetObj(obj);
	SetMainValues(s, mX, mN);
	SetCollision(false);
	SetCurrentState(Negative);
	SetPreviousState(Negative);
}

void AgentY::Move()
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

void AgentY::MovePositive()
{

	Object ob = GetObj();
	BoundingBox objBox = ob.GetBoundingBox();
	glm::vec3 pos = ob.GetPosition();

	if ((pos.y + GetSpeed() * time.deltaTime) > GetMax())
	{
		State t = Negative;
		UpdateState(t);
	}
	else
	{
		float move = GetSpeed() * time.deltaTime;
		pos.y += move;
		objBox.UpdateY(move);
		ob.SetPosition(pos);
		ob.SetBoundingBox(objBox);
		SetObj(ob);
	}
}

void AgentY::MoveNegative()
{
	Object ob = GetObj();
	BoundingBox objBox = ob.GetBoundingBox();
	glm::vec3 pos = ob.GetPosition();

	if ((pos.y - GetSpeed() * time.deltaTime) < GetMin())
	{
		State t = Positive;
		UpdateState(t);
	}
	else
	{
		float move = (GetSpeed() * time.deltaTime * 1.5);
		pos.y -= move;
		objBox.UpdateY(-move);
		ob.SetPosition(pos);
		ob.SetBoundingBox(objBox);
		SetObj(ob);
	}
}

void AgentY::UpdateState(State s)
{
	SetPreviousState(GetCurrentState());
	SetCurrentState(s);
}

bool AgentY::CheckPlayerPos()
{
	glm::vec3 check = GetPlayer();
	check.y -= 50.0f;

	return GetObj().GetBoundingBox().CheckCollision(check);
}

bool AgentY::CheckPlayerNeg()
{
	glm::vec3 check = GetPlayer();
	check.y += 50.0f;

	return GetObj().GetBoundingBox().CheckCollision(check);
}

void AgentY::AddInfo(int i, Object obj, float s, float mX, float mN)
{
	SetID(i);
	SetObj(obj);
	SetMainValues(s, mX, mN);
	SetCollision(false);
	SetCurrentState(Negative);
	SetPreviousState(Negative);
}