#include "Level.h"
void Level::DisplayAi(glm::vec3 playerPos)
{
	for (int i = 0; i < aiZ.size(); i++)
	{
		aiZ[i].SetPlayer(playerPos);
		aiZ[i].Update();
	}

	for (int i = 0; i < aiX.size(); i++)
	{
		aiX[i].SetPlayer(playerPos);
		aiX[i].Update();
	}

	for (int i = 0; i < aiY.size(); i++)
	{
		aiY[i].SetPlayer(playerPos);
		aiY[i].Update();
	}
}

Level::Level()
{
	won = false;
}

bool Level::CheckAiCollision(glm::vec3 col)
{
	BoundingBox checkBox;
	bool collision = false;

	for (int i = 0; i < aiZ.size(); i++)
	{
		checkBox = aiZ[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			aiZ[i].SetCollision(true);
			collision = true;
		}
		else
			aiZ[i].SetCollision(false);
	}
	//std::cout << aiZ.size() << " " << aiX.size() << std::endl;
	for (int i = 0; i < aiX.size(); i++)
	{
		checkBox = aiX[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			aiX[i].SetCollision(true);
			collision = true;
		}
		else
			aiX[i].SetCollision(false);
	}

	for (int i = 0; i < aiY.size(); i++)
	{
		checkBox = aiY[i].GetObj().GetBoundingBox();
		if (checkBox.CheckCollision(col))
		{
			aiY[i].SetCollision(true);
			collision = true;
		}
		else
			aiY[i].SetCollision(false);
	}


	return collision;
}

void Level::DisplayZone(glm::vec3 playerPos)
{
	foodZoneOne.SetPlayer(playerPos);
	foodZoneOne.Update();

	foodZoneTwo.SetPlayer(playerPos);
	foodZoneTwo.Update();

	foodZoneThree.SetPlayer(playerPos);
	foodZoneThree.Update();

	foodZoneFour.SetPlayer(playerPos);
	foodZoneFour.Update();

	foodZoneFive.SetPlayer(playerPos);
	foodZoneFive.Update();
}

void Level::Reset()
{
	for (int i = 0; i < waitAi.size(); i++)
	{
		waitAi[i].Reset();
	}
	//std::cout << aiZ.size() << " " << aiX.size() << std::endl;
	time.Update();
	timer = holdTimer;
	people = waitAi.size();
	won = false;
}

std::string Level::StringTimer()
{
	std::string timerString = std::to_string((int)(timer/60)) + ":" + std::to_string((int)timer - ((int)(timer / 60) * 60));
	return timerString;
}

void Level::Update()
{
	time.Update();
	if (people == 0 && timer > 0)
	{
		won = true;
	}
	else if(timer > 0)
	{
		timer -= time.deltaTime;
	}
	//std::cout << timer << std::endl;
}