#include "AgentX.h"

AgentX::AgentX(int i, Object obj, float s, float mX, float mN)
{
	SetID(i);
	SetObj(obj);
	SetMainValues(s, mX, mN);
	SetCollision(false);
	SetCurrentState(Negative);
	SetPreviousState(Negative);
}

void AgentX::Move()
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

void AgentX::MovePositive()
{
	Object ob = GetObj();
	BoundingBox objBox = ob.GetBoundingBox();
	glm::vec3 pos = ob.GetPosition();

	if ((pos.x + GetSpeed() * time.deltaTime) > GetMax())
	{
		State t = Negative;
		UpdateState(t);
	}
	else
	{
		float move = GetSpeed() * time.deltaTime;
		pos.x += move;
		objBox.UpdateX(move);
		ob.SetPosition(pos);
		ob.SetBoundingBox(objBox);
		SetObj(ob);
	}
}

void AgentX::MoveNegative()
{
	Object ob = GetObj();
	BoundingBox objBox = ob.GetBoundingBox();
	glm::vec3 pos = ob.GetPosition();

	if ((pos.x - GetSpeed() * time.deltaTime) < GetMin())
	{
		State t = Positive;
		UpdateState(t);
	}
	else
	{
		float move = GetSpeed() * time.deltaTime;
		pos.x -= move;
		objBox.UpdateX(-move);
		ob.SetPosition(pos);
		ob.SetBoundingBox(objBox);
		SetObj(ob);
	}
}

void AgentX::UpdateState(State s)
{
	SetPreviousState(GetCurrentState());
	SetCurrentState(s);
}

bool AgentX::CheckPlayerPos()
{
	glm::vec3 check = GetPlayer();
	check.x -= 50.0f;

	return GetObj().GetBoundingBox().CheckCollision(check);
}

bool AgentX::CheckPlayerNeg()
{
	glm::vec3 check = GetPlayer();
	check.x += 50.0f;

	return GetObj().GetBoundingBox().CheckCollision(check);
}

void AgentX::AddInfo(int i, Object obj, float s, float mX, float mN)
{
	SetID(i);
	SetObj(obj);
	SetMainValues(s, mX, mN);
	SetCollision(false);
	SetCurrentState(Negative);
	SetPreviousState(Negative);
}