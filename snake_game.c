#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define horizontal  119
#define vertical  23
typedef struct{ // This struct stores the positions of variables
	int x;
	int y;
}position;

enum difficulty{ easy, hard, exit_game };

void delay(int sure, int yon);
void screen();
void gotoxy(short x, short y);
void color(int deger);

int main(){

	
	srand(time(NULL));
	unsigned char key, key2;
	position tail[100]; // This array holds the coordinates of each piece of the snake's tail based on its length
	position snake={horizontal/2,vertical /2}; // Starting position of the snake
	position food; // Position of the food
	enum difficulty mode;
	int x=0, y=0; // Variables to determine the direction of the snake's movement
	int game_over=0; // A variable to create an infinite loop
	int i; // Variable for for-loops
	int tailLength=1; // Variable to store the length of the tail
	int score=0; // Variable to store the score
	int record[2]; // Variable to hold the high score from the file
	int speed=1; // Variable to control the speed of the snake
	while(1){
		
		
		position snake={horizontal/2,vertical /2}; // Starting position of the snake
		x=0;
		y=0;
		game_over=0;
		tailLength=1;
		score=0;
		speed=1;
		
		FILE *file=fopen("record.txt","r");
		if(file==NULL){
			file=fopen("record.txt","a+");
			fprintf(file,"%d:%d",0,0);
			record[0] = 0;
			record[1] = 0;
		}
		else{
			fscanf(file,"%d:%d",&record[0],&record[1]);
			fclose(file);
		}
		
		// Assign the starting position of the snake to the first index of the array
		tail[0].x=(int)(horizontal/2);
		tail[0].y=(int)(vertical /2);
		
		// Assign a random position to the food
		food.x=rand()%(horizontal-2)+2;
		food.y=rand()%(vertical -2)+2;
		
		while(1){
			system("cls");
			gotoxy(50,10);
			printf("WELCOME TO MY SNAKE GAME\n");
			gotoxy(20,11);
			printf("RULES:");
			gotoxy(20,12);
			printf("   1. THE GAME ENDS IF THE SNAKE HITS ITSELF\n");
			gotoxy(20,13);
			printf("   2. IF THE GAME IS IN EASY MODE, THE SNAKE WILL APPEAR ON THE OPPOSITE SIDE IF IT HITS A WALL");
			gotoxy(20,14);
			printf("   3. IF THE GAME IS IN HARD MODE, THE GAME ENDS IF THE SNAKE HITS A WALL");
			gotoxy(20,15);
			printf("   4. PRESS 2 TO EXIT");
			gotoxy(20,16);
			printf("   5. ENTER 1 FOR HARD MODE OR 0 FOR EASY MODE AND PRESS ENTER!!! : ");
			scanf("%d",&mode);
			if(mode == easy || mode == hard || mode == exit_game) break;
		}
		if(mode == exit_game){
			break;		
		}
		
		printf("\e[?25l");
		system("cls");
		
		screen(); // Print the screen
		gotoxy(horizontal-14,1);
		printf("high score: %d", mode == easy ? record[0] : record[1]);
		gotoxy(food.x,food.y);
		printf("0");
		
		while(!game_over){// Infinite loop starts
			
			gotoxy(1,1); // Go to the top left corner and print the score
			printf("score: %d", score);
			if(kbhit()){ // The kbhit function returns true if any key is pressed
				key2 = key;
				key = getch(); // The getch function assigns the character to variables without needing to press enter
				if(key == 224){ // Checking arrow keys
					key = getch();
					
					switch (key){
						case 77: // Right arrow key
							if(key2 == 75) {	key = key2; break;}
							x = 1;
							y = 0;
							break;
						case 75: // Left arrow key
							if(key2 == 77) {	key = key2; break;}
							x = -1;
							y = 0;
							break;
						case 80: // Down arrow key
							if(key2 == 72) {	key = key2; break;}
							x = 0;
							y = 1;
							break;
						case 72: // Up arrow key
							if(key2 == 80) {	key = key2; break;}
							x = 0;
							y = -1;
							break;
					}
				}
			}		
			
			// The starting position of the array changes based on the direction pressed
			tail[0].x += x;
			tail[0].y += y;	
			
			
			// If the snake hits the edge of the screen, it reappears on the opposite side
			if(tail[0].x == 1){
				if(mode == hard){	game_over = 1; break;}	
				else tail[0].x = horizontal - 1;
			}
			if(tail[0].x == horizontal){
				if(mode == hard){	game_over = 1; break;}	
				else tail[0].x = 2;
			}
			if(tail[0].y == 1){
				if(mode == hard){	game_over = 1; break;}	
				else tail[0].y = vertical  - 1;
			}
			if(tail[0].y == vertical ){
				if(mode == hard){	game_over = 1; break;}	
				else tail[0].y = 2;
			}
			
		
			// If the snake eats the food, increase the tail length and score, and change the color
			if(food.x == tail[0].x && food.y == tail[0].y){
				tailLength++;
				score++;
				color(score);
				if(score % 5 == 0){ speed++; }
				food.x = rand() % (horizontal - 2) + 2;
				food.y = rand() % (vertical  - 2) + 2;
			}
			// If the food is assigned inside the tail, reassign it
			for(i = 0; i < tailLength; i++){
				if(food.x == tail[i].x && food.y == tail[i].y){
					i = 0;
					food.x = rand() % (horizontal - 2) + 2;
					food.y = rand() % (vertical  - 2) + 2;
				}	
			}

			// The game ends if the snake hits its own tail
			for(i = 0; i < tailLength; i++){
				if(tail[0].x == tail[i + 1].x && tail[0].y == tail[i + 1].y && i != 0){
					game_over = 1;
				}	
			}
			
			// Print the food
			gotoxy(food.x,food.y);
			printf("0");
	
		
			// Here we make the tail follow the snake's head. Each segment takes the coordinates of the previous segment, making them follow each other.
			for(i = tailLength; i > 0; i--){
				tail[i].x = tail[i - 1].x;
				tail[i].y = tail[i - 1].y;
			}
			
			// Print the segments of the snake
			for(i = 0; i <= tailLength && !game_over; i++){
				gotoxy(tail[i].x, tail[i].y);
				printf("o");
			}

			
			// Adjust the speed of the snake
			if(key == 77 || key == 75) delay(speed, 1);
			else delay(speed, 2);
			
			// Print a blank space at the last segment of the snake to prevent filling the screen with "o"
			gotoxy(tail[tailLength].x, tail[tailLength].y);
			if(!(food.x == tail[tailLength].x && food.y == tail[tailLength].y)){
				printf("%c", !game_over ? ' ' : 'o');	
			}
			else{
				printf("%c", '0');	
			}
			
			
			gotoxy(horizontal+1,vertical );
			printf("");
		}

		if(game_over){
			gotoxy(horizontal / 2, vertical  / 2);
			printf("you lost");
			gotoxy(horizontal / 2, vertical  / 2 + 1);
			printf("score: %d", score);
		}
	
		if((score > record[0] && mode == easy || score > record[1] && mode == hard) && game_over){
			if(mode == easy) {
				record[0] = score;
			}
			else{
				record[1] = score;
			}	
			gotoxy(horizontal / 2, vertical  / 2 + 3);
			printf("high score: %d", score);
			FILE *file = fopen("rekor.txt", "w");
			fprintf(file, "%d:%d", record[0], record[1]);
			fclose(file);
		}

		gotoxy(0, vertical  + 1);
		system("pause");
		system("cls");
		
		
    	printf("\033[2J");
    	printf("\e[?25h");
	}
	return 0;
}

// Function to change the color of the snake
void color(int value){
	int mod;
	
	mod=value%16;
	switch(mod){
		case 0:
			system("color 0");
			break;
		case 1:
			system("color 1");
			break;
		case 2:
			system("color 2");
			break;
		case 3:
			system("color 3");
			break;
		case 4:
			system("color 4");
			break;
		case 5:
			system("color 5");
			break;
		case 6:
			system("color 6");
			break;
		case 7:
			system("color 7");
			break;
		case 8:
			system("color 8");
			break;
		case 9:
			system("color 9");
			break;
		case 10:
			system("color A");
			break;
		case 11:
			system("color B");
			break;
		case 12:
			system("color C");
			break;
		case 13:
			system("color D");
			break;
		case 14:
			system("color E");
			break;
		case 15:
			system("color F");
			break;
	}
}

//Function that allows us to change what we want on the screen
void gotoxy(short x, short y) {
	printf("\033[%d;%dH", y, x);
}

// Function to print the screen border
void screen(){
	int i, j;
	for(i=1;i<vertical +1;i++){
		for(j=1;j<horizontal+1;j++){
			if(i==1 || i==vertical  || j==1 || j==horizontal){
				gotoxy(j,i);
				printf("%c",219);	
			}
		}
	}	
}

// Function to introduce a delay based on the speed of the snake
void delay(int sure, int yon){
	int milliSeconds = 50 / sure*yon;
	clock_t start_time = clock();
	while(clock() < start_time + milliSeconds);
}

