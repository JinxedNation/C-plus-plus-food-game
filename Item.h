#pragma once
#include"game_Physics.h"
#include<glm.hpp>
#include<string>
/**
* @class Item
* @brief Holds the information for the item in the game
*
* The class holds information on the item the player has (food), having the texture number, physcis (model aswell), tag and if it is active
*
* @author Christopher Logan
* @version 01
* @date 15/10/2020
*
*
* @bug no known bugs, but there may be some out there...
*/
class Item
{
	public:
            /**
            * @brief Sets if the item is active
            *
            * @return void
            */
		void SetActive(bool act) { active = act; }

            /**
            * @brief Gets if the item is active
            *
            * @return bool active
            */
		bool GetActive() const { return active; }

            /**
            * @brief Sets the game_physics variable for throwable
            *
            * @return void
            */
		void SetThrowable(game_Physics gp) { throwable = gp; }

            /**
            * @brief Gets the throwable game_Physics variable
            *
            * @return game_Physics throwable
            */
		game_Physics GetThrowable() const { return throwable; }

            /**
            * @brief Sets the tag for the item
            *
            * @return void
            */
		void SetTag(std::string s) { tag = s; }

            /**
            * @brief Gets the tag string for the item
            *
            * @return string tag
            */
		std::string GetTag() const { return tag; }

            /**
            * @brief Sets the texture number
            *
            * @return void
            */
		void SetTexture(int i) { texture = i; }

            /**
            * @brief Gets the texture number
            *
            * @return int texture
            */
		int GetTexture() const { return texture; }

            /**
            * @brief Updates the item
            *
            * Checking if the item exists, if it is throwable and if it should be displayed/physiced
            *
            * @return void
            */
		void Update(glm::vec3 pos);

private:

            ///If the item is active
	    bool active;
    
            ///The physics object
	    game_Physics throwable;

            ///The tag for the item
	    std::string tag;

            ///The texture number for the object
	    int texture;
};

