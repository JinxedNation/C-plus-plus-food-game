#include "Item.h"

void Item::Update(glm::vec3 pos)
{
	if (active)
	{
		if (throwable.get_Obj_Model_In_Motion())
		{
			throwable.update_Game_Model();
		}
		else
		{
			Object o = throwable.get_Obj_Model_Name();
			pos.x += 100;
			o.SetPosition(pos);
			//o.Display();
			throwable.set_Obj_Model_Name(o);
			throwable.update_Game_Model();
			//std::cout << "Player pos " << pos.x << " " << pos.y << " " << pos.z << std::endl;
		}
	}
	else
		tag = "";
}