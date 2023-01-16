#include "Food.h"

Food::Food(){
	gen_food();
	
}
#define Width 50
#define Height 25
void Food::gen_food(){
	pos.X= (rand()%Width-3)+1;
	pos.Y=(rand()%Height-3)+1;
}

COORD Food::get_pos(){  
	return pos;
}

