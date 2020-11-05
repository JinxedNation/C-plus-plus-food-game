/*************************************************************************************************************************************
 * @class Level
 * @brief Has all the information for a level
 *
 * This class holds all the information that a level would hold, ai positions, timer and other important values
 *
 *
 * @author    Christopher Logan
 * @co-author William Halling
 *
 *
 * @version 01
 *
 *
 * @date 1/10/2020
 * @updated 25 October 2020 Doxygen comments added
 *
 *
 * @bug no known bugs, but there may be some out there...
 *************************************************************************************************************************************/
#pragma once
# include<vector>
# include<glm.hpp>
# include"AgentX.h"
# include"AgentY.h"
# include"AgentZ.h"
# include"WaitingAi.h"
# include"Zone.h"


class Level
{
public:

	Level();

	/**
	 * @brief adds Ai
	 *
	 *
	 * Adds Ai on the Z plane
	 *
	 *
	 * @return void
	 */
	void AddAiZ(AgentZ ai) { aiZ.push_back(ai); }


	/**
	 * @brief SetAiZ
	 *
	 *
	 * Sets the Z Ai
	 *
	 *
	 * @return void
	 */
	void SetAiZ(AgentZ ai, int i) { aiZ[i] = ai; }


	/**
	 * @brief AgentZ GetAiZ
	 *
	 *
	 * Creates an AgentZ object and then Gets AiZ
	 *
	 *
	 * @return aiZ
	 */
	AgentZ GetAiZ(int i) const { return aiZ[i]; }


	/**
	 * @brief AddAiX
	 *
	 *
	 * adds an Ai agentX
	 *
	 *
	 * @return void
	 */
	void AddAiX(AgentX ai) { aiX.push_back(ai); }


	/**
	 * @brief SetAiX
	 *
	 *
	 * Sets AgentX ai
	 *
	 *
	 * @return void
	 */
	void SetAiX(AgentX ai, int i) { aiX[i] = ai; }


	/**
	 * @brief AgentX GetAiX
	 *
	 *
	 * Creates an AgentX object and then Gets aiX
	 *
	 *
	 * @return aiX
	 */
	AgentX GetAiX(int i) const { return aiX[i]; }


	/**
	 * @brief AddAiY
	 *
	 *
	 * adds an Ai AgentY
	 *
	 *
	 * @return void
	 */
	void AddAiY(AgentY ai) { aiY.push_back(ai); }


	/**
	 * @brief SetAiY
	 *
	 *
	 * Sets AgentY ai
	 *
	 *
	 * @return void
	 */
	void SetAiY(AgentY ai, int i) { aiY[i] = ai; }


	/**
	 * @brief AgentY GetAiY
	 *
	 *
	 * Sets AgentY ai
	 *
	 *
	 * @return void
	 */
	AgentY GetAiY(int i) const { return aiY[i]; }


	/**
	 * @brief AddWaitingAi
	 *
	 *
	 * adds a waiting AI agent
	 *
	 *
	 * @return void
	 */
	void AddWaitingAi(WaitingAi ai) { waitAi.push_back(ai); }


	/**
	 * @brief SetWaitingAi
	 *
	 *
	 * setter for a waiting AI agent
	 *
	 *
	 * @return void
	 */
	void SetWaitingAi(WaitingAi ai, int i) { waitAi[i] = ai; }


	/**
	 * @brief WaitingAi GetWaitAi
	 *
	 *
	 * setter for a waiting AI agent
	 *
	 *
	 * @return waitAi
	 */
	WaitingAi GetWaitAi(int i) { return waitAi[i]; }


	/**
	 * @brief SetVectorAiX
	 *
	 *
	 * sets a vector for Ai agent X
	 *
	 *
	 * @return void
	 */
	void SetVectorAiX(std::vector<AgentX> ai) { aiX = ai; }


	/// vector for ai agent X 
	/// returns aiX
	std::vector<AgentX> GetVectorAiX() const { return aiX; }


	/**
	 * @brief SetVectorAiZ
	 *
	 *
	 * sets the vector for Ai agent Z
	 *
	 *
	 * @return void
	 */
	void SetVectorAiZ(std::vector<AgentZ> ai) { aiZ = ai; }


	/**
	 * @brief std::vector<AgentZ> GetVectorAiZ
	 *
	 *
	 * gets the vector for Ai agent Z
	 *
	 *
	 * @return  aiZ
	 */
	std::vector<AgentZ> GetVectorAiZ() const { return aiZ; }


	/**
	 * @brief SetVectorAiY
	 *
	 *
	 * sets the vector for Ai agent Y
	 *
	 *
	 * @return  void
	 */
	void SetVectorAiY(std::vector<AgentY> ai) { aiY = ai; }


	/**
	 * @brief GetVectorAiY
	 *
	 *
	 * gets the vector for Ai agent Y
	 *
	 *
	 * @return  aiY
	 */
	std::vector<AgentY> GetVectorAiY() const { return aiY; }


	/**
	 * @brief SetVectorWaitingAi
	 *
	 *
	 * sets a vector for the Ai Agent when its waiting
	 *
	 *
	 * @return  void
	 */
	void SetVectorWaitingAi(std::vector<WaitingAi> ai) { waitAi = ai; }


	/**
	 * @brief GetVectorWaitingAi
	 *
	 *
	 * gets the vector for the Ai Agent when its waiting
	 *
	 *
	 * @return  waitAi
	 */
	std::vector<WaitingAi> GetVectorWaitingAi() const { return waitAi; }


	/**
	 * @brief GetTimer
	 *
	 *
	 * is a time for the level
	 *
	 *
	 * @return  timer
	 */
	float GetTimer() const { return timer; }


	/**
	 * @brief SetTimer
	 *
	 *
	 * is a time for the level
	 *
	 *
	 * @return  void
	 */
	void SetTimer(float t) { timer = t; holdTimer = t; }


	/**
	 * @brief DisplayAi
	 *
	 *
	 * displays the Ai agent location during game runtime
	 *
	 *
	 * @return  void
	 */
	void DisplayAi(glm::vec3 playerPos);


	/**
	 * @brief CheckAiCollision
	 *
	 *
	 * checks if the Ai agents have any collisions occur with them while the game is running
	 *
	 *
	 * @return  void
	 */
	bool CheckAiCollision(glm::vec3 col);


	/**
	 * @brief SetFoodZoneOne
	 *
	 *
	 * sets the first place where an AI can get food
	 *
	 *
	 * @return  void
	 */
	void SetFoodZoneOne(Zone z) { foodZoneOne = z; }


	/**
	 * @brief Zone getFoodZoneOne
	 *
	 *
	 * gets the first place where an AI can get food
	 *
	 *
	 * @return  foodZoneOne
	 */
	Zone GetFoodZoneOne() const { return foodZoneOne; }


	/**
	 * @brief Zone SetFoodZoneTwo
	 *
	 *
	 * sets the second place where an AI can get food
	 *
	 *
	 * @return  void
	 */
	void SetFoodZoneTwo(Zone z) { foodZoneTwo = z; }


	/**
	 * @brief Zone GetFoodZoneTwo
	 *
	 *
	 * gets the second place where an AI can get food
	 *
	 *
	 * @return  foodZoneTwo
	 */
	Zone GetFoodZoneTwo() const { return foodZoneTwo; }


	/**
	 * @brief Zone SetFoodZoneThree
	 *
	 *
	 * sets the third place where an AI can get food
	 *
	 *
	 * @return  void
	 */
	void SetFoodZoneThree(Zone z) { foodZoneThree = z; }


	/**
	 * @brief Zone GetFoodZoneThree
	 *
	 *
	 * gets the third place where an AI can get food
	 *
	 *
	 * @return  foodZoneThree
	 */
	Zone GetFoodZoneThree() const { return foodZoneThree; }


	/**
	 * @brief Zone SetFoodZoneFour
	 *
	 *
	 * sets the fourth place where an AI can get food
	 *
	 *
	 * @return  void
	 */
	void SetFoodZoneFour(Zone z) { foodZoneFour = z; }


	/**
	 * @brief Zone GetFoodZoneFour
	 *
	 *
	 * gets the fourth place where an AI can get food
	 *
	 *
	 * @return  foodZoneFour
	 */
	Zone GetFoodZoneFour() const { return foodZoneFour; }


	/**
	 * @brief void SetFoodZoneFive
	 *
	 *
	 * Sets the fifth place where an AI can get food
	 *
	 *
	 * @return  void
	 */
	void SetFoodZoneFive(Zone z) { foodZoneFive = z; }


	/**
	 * @brief Zone GetFoodZoneFive
	 *
	 *
	 * gets the fifth place where an AI can get food
	 *
	 *
	 * @return  foodZoneFive
	 */
	Zone GetFoodZoneFive() const { return foodZoneFive; }


	/**
	 * @brief DisplayZone
	 *
	 *
	 * DisplayZone : Displays the current zone area
	 *
	 *
	 * @return  void
	 */
	void DisplayZone(glm::vec3 playerPos);


	/**
	 * @brief SetPosition
	 *
	 *
	 * SetPosition : Sets the initial player starting position
	 *
	 *
	 * @return  void
	 */
	void SetPosition(glm::vec3 p) { position = p; }


	/**
	 * @brief GetPosition
	 *
	 *
	 * GetPosition : gets the initial player starting position
	 *
	 *
	 * @return  position
	 */
	glm::vec3 GetPosition() const { return position; }



	/**
	 * @brief Reset
	 *
	 *
	 * Reset : resets the starting position
	 *
	 *
	 * @return  void
	 */
	void Reset();


	/// StringTimer displays a timer as a string
	std::string StringTimer();


	/**
	 * @brief Update
	 *
	 *
	 * Update : updates the positon of the objects frame by frame during game run time
	 *
	 *
	 * @return  void
	 */
	void Update();


	/**
	 * @brief TakePerson
	 *
	 *
	 * TakePerson : checks to see how many AI agents still require food
	 *					people-- reduces the total count of people who stil require food
	 *
	 * @return  void
	 */
	void TakePerson() { people--; }


	/**
	 * @brief GetWon
	 *
	 *
	 * GetWon : fires when the person has beat the current level
	 *			and
				when the player has beaten the game successfully
	 *
	 *
	 * @return  void
	 */
	bool GetWon() const { return won; }


	/**
	 * @brief SetPeople
	 *
	 *
	 * SetPeople Sets how many AI agents still require food
	 *
	 *
	 * @return  void
	 */
	void SetPeople() { people = waitAi.size(); }


private:

	/// moving agent during game runtimne on the x axis 
	std::vector<AgentX> aiX;


	/// moving agent during game runtimne on the y axis
	std::vector<AgentY> aiY;


	/// moving agent during game runtimne on the z axis
	std::vector<AgentZ> aiZ;


	/// time the ai is waiting for their current order
	std::vector<WaitingAi> waitAi;


	/// player xyz coordinate plane positon on game start
	glm::vec3 position;


	/// number of AI agents requiring food
	int people;


	/// an integer number that increases over time during gameplay
	FrameTimer time;


	/// game timer to track time during gameplay
	float timer;


	/// 
	float holdTimer;


	/// xyz location for the first food zone 
	Zone foodZoneOne;


	/// xyz location for the second food zone
	Zone foodZoneTwo;


	/// xyz location for the third food zone
	Zone foodZoneThree;


	/// xyz location for the fourth food zone
	Zone foodZoneFour;


	/// xyz location for the fourth food zone
	Zone foodZoneFive;


	/// player beat the current game level
	bool won;

};