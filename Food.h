#ifndef FOOD_H
#define FOOD_H
#include <windows.h>
#include <cstdio>

class Food
{
	private:
		COORD pos;
		
	public:
		Food();
		void gen_food();
		COORD get_pos();
		
		
};

#endif
