#include <iostream>

#include <conio.h>
#include <ctime>	
#define Width 50
#define Height 25
#include "Snake1.h"
#include "Food.h"

using namespace std;

Snake1 snake({Width/2,Height/2},1);
Food food;


void board(){
	
	COORD snake_pos=snake.get_pos();
	COORD food_pos=food.get_pos();
	
	vector<COORD> snake_body = snake.get_body();
	
	for(int i = 0;i<Height;i++){
		cout<<"\t\t#";
		for(int j = 0;j<Width-2;j++){
            if(i==0 || i==Height-1) cout<<'#';
            else if(i==snake_pos.Y && j+1==snake_pos.X)cout << "0";
            else if(i==food_pos.Y && j+1==food_pos.X) cout << "@";
            else{
            	bool isBodyPart = false;
            	for(int k=0;k < snake_body.size()-1;k++){
            		if(i== snake_body[k].Y && j+1==snake_body[k].X){
            			cout<<'o';
            			isBodyPart=true;
            			break;
					}
				}
				if(!isBodyPart) cout << ' ';
			};
		}
		cout <<"#\n";
	}
    
}



int main() {
	bool game_over=false;
	srand(time(NULL));
	food.gen_food();
	while(!game_over){
		board();
		if(kbhit()){
			switch(getch()){
				case 'w': snake.change_dir('u');break;
				case 's': snake.change_dir('d');break;
				case 'd': snake.change_dir('r');break;
				case 'a': snake.change_dir('l');break;
			}
		}
		snake.move_snake();
		if(snake.eaten(food.get_pos())){
			food.gen_food();
			snake.grow();
		}
		if(snake.collided()) game_over=true;
				
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
		
	}
	
}
