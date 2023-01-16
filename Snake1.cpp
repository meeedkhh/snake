#include "Snake1.h"
#define Width 50
#define Height 25

Snake1::Snake1(COORD pos,int vel)
{
	this->pos=pos;
	this->vel=vel;
	len =2;
	direction='n'; 
	body.push_back(pos);
}

vector<COORD> Snake1::get_body(){
	return body;
}

void Snake1::change_dir(char dir) {direction = dir;}

void Snake1::move_snake(){
	switch(direction){
		case 'u': pos.Y-=vel;break;
		case 'd': pos.Y+=vel;break;
		case 'l': pos.X-=vel;break;
		case 'r': pos.X+=vel;break;
	}
	body.push_back(pos);
	if(body.size() > len) body.erase(body.begin());
}

COORD Snake1::get_pos(){
	return pos;
} 

bool Snake1::eaten(COORD food_pos){
	if(food_pos.X==pos.X && food_pos.Y==pos.Y){
		return true;
	}
	else return false;
}

void Snake1::grow(){
	len++;
}


bool Snake1::collided(){
	if(pos.X<1 || pos.X>Width || pos.Y<1 || pos.Y>Height){
		return true;
	}
	return false;
}



