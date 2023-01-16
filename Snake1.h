#ifndef SNAKE1_H
#define SNAKE1_H
#include <windows.h>
#include <vector>


using namespace std ;
class Snake1
{
	private:
		COORD pos;
		int len ; 
		int vel ; 
		char direction ;
		vector<COORD> body;
		
	public:
		Snake1(COORD pos , int vel);
		void change_dir(char dir); 
		void move_snake();
		COORD get_pos();
		bool eaten(COORD food_pos);
		void grow();
		bool collided();
		vector<COORD> get_body();
		
};

#endif
