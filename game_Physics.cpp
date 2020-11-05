#include "game_Physics.h"
/****************************
 * Function : update_Game_Model()
 *   Purpose  : Function periodically updates game model location and applies gravity
 *   Outputs  : None
 *   Author   : William
 ****************************/

void game_Physics::update_Game_Model()
{
    time.Update();

    if (Obj_Model_In_Motion_ == true)
    {
        obj_Model_Name.Display();
        glm::vec3 XYZ_Plane_Coordinate_Pos = obj_Model_Name.GetPosition();
        glm::vec3 previous_XYZ_Plane_Coordinate = XYZ_Plane_Coordinate_Pos;

        //std::cout << "Before -> (TIME)" << time.deltaTime << ", (x)" << XYZ_Plane_Coordinate_Pos.x << ", (VEL)" << velocity_Of_Game_Obj_.x << ", (GRAV)" << gravity_Of_Game_Obj_.x;

        XYZ_Plane_Coordinate_Pos.x = (previous_XYZ_Plane_Coordinate.x + (velocity_Of_Game_Obj_.x * Acceleration_Of_Game_Obj_.x) * time.deltaTime) + (gravity_Of_Game_Obj_.x * time.deltaTime * time.deltaTime / 2);
        XYZ_Plane_Coordinate_Pos.y = (previous_XYZ_Plane_Coordinate.y + (velocity_Of_Game_Obj_.y * Acceleration_Of_Game_Obj_.y) * time.deltaTime) + (gravity_Of_Game_Obj_.y * time.deltaTime * time.deltaTime / 2);
        XYZ_Plane_Coordinate_Pos.z = (previous_XYZ_Plane_Coordinate.z + (velocity_Of_Game_Obj_.z * Acceleration_Of_Game_Obj_.z) * time.deltaTime) + (gravity_Of_Game_Obj_.z * time.deltaTime * time.deltaTime / 2);

        velocity_Of_Game_Obj_.x = velocity_Of_Game_Obj_.x + gravity_Of_Game_Obj_.x * time.deltaTime;
        velocity_Of_Game_Obj_.y = velocity_Of_Game_Obj_.y + gravity_Of_Game_Obj_.y * time.deltaTime;
        velocity_Of_Game_Obj_.z = velocity_Of_Game_Obj_.z + gravity_Of_Game_Obj_.z * time.deltaTime;

        //std::cout << ", After -> (newx)" << XYZ_Plane_Coordinate_Pos.x << ", (new VEL)" << velocity_Of_Game_Obj_.x << std::endl;

        obj_Model_Name.SetPosition(XYZ_Plane_Coordinate_Pos);
    }

}