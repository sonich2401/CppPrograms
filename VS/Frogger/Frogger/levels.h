#pragma once
#include "olcPixelGameEngine.h"
#include <deque>
namespace worldlib {
	struct object {
		object(olc::vi2d pos,std::string type);
		olc::vi2d pos;
		std::string type;
	};
	extern std::map<std::string, olc::vi2d> leveldat_index;
	struct leveldat {
		std::deque<object> objects;
		//object reference function
		std::deque<olc::vi2d> listObjectPos(std::string objectType, olc::vi2d* localarray = nullptr) {
			std::deque<olc::vi2d> re_obj_pos;
			forrange(0, objects.size()) {
				if (objects[i].type == objectType) {
					re_obj_pos.push_back(objects[i].pos);
				}
			}
			return re_obj_pos;
		}
		leveldat() {
			//add the world data here
			object obj1({ 10.0f,10.0f }, "water");
			worldlib::leveldat::objects.push_back(obj1);
		}
	};
}