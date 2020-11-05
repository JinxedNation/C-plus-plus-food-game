#pragma once

/**********************************************************************************************
 * @class game_Manager
 *
 *
 * @brief Purpose of class: The game manager class manages the following

							The timer is responsible for determining if the food was delivered on time

							The players current level which is stored as an integer


							The enum manages the games current states,
								The player has won, or lost
								The game is currently playing or the game is not playing


 * @Author William Halling 32233703
 * @Date   October 2020
 *
 *
 * @Version 01
 *
 * @bug no known bugs, but there may be some out there...
 ************************************************************************************************/



class game_Manager
{

public:
	/**
	 * @brief Setter for the palyers current level
	 *
	 *
	 * Sets the players current level at the start of each level
	 *
	 *
	 * @return void
	 */
	void set_Current_Level(static int temp_Player_Current_Level) { player_Current_Level = temp_Player_Current_Level; }


	/**
	 * @brief getter for the palyers current level
	 *
	 *
	 * @return player_Current_Level (integer)
	 */
	int get_Player_Current_Level() const { return player_Current_Level; }


	/**
	 * @brief Setter for the game timer
	 *
	 *
	 * Sets the game time at 0 at the start of each level
	 *
	 *
	 * @return void
	 */
	void  set_game_Timer(float temp_Game_Timer) { game_Timer = temp_Game_Timer; }


	/**
	 * @brief getter for the game timer
	 *
	 *
	 * @return game_Timer (float)
	 */
	float get_Game_Timer()const { return  game_Timer; }


	/// stores the various states that can occur throughout the game
	enum game_State { game_won, game_not_playing, game_playing, game_lost };


	/**
	 * @brief Setter for the games state
	 *
	 *
	 * Sets the game state depending on the state of the game
	 *
	 *
	 * @return void
	 */
	void set_Game_State(game_State temp_Game_State) { current_Game_State = temp_Game_State; }


	/**
	 * @brief getter for the game state
	 *
	 *
	 * @return current_Game_State (enumerator)
	 */
	game_State get_Game_State()const { return current_Game_State; }


	/**
	 * @brief Setter for the game score
	 *
	 *
	 * Sets the players game score
	 *
	 *
	 * @return void
	 */
	void SetScore(int i) { score = i; }


	/**
	 * @brief Setter for the game score
	 *
	 *
	 * gets the players game score
	 *
	 *
	 * @return score
	 */
	int GetScore() const { return score; }


	/**
	 * @brief add score
	 *
	 *
	 * adds the players game score
	 *
	 *
	 * @return void
	 */
	void AddScore(int i) { score += i; }


private:

	///the games current level tracks the players current level
	int    player_Current_Level;


	/// score provides a varying game score depending on players performance  
	int    score;


	///  current game timer used to track how long it takes to deliver food
	float  game_Timer;


	/// tracks the current state of the game while the game is running
	game_State current_Game_State;
};