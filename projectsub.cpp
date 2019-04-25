#include "iGraphics.h"

#include"variables.h"    ////////////////USING HEADER FILE/////////////////////

bool stopped = false;
int f;
int f1;
int score;
int scoring=0;
int flag_gameover=0;
int temppic;



//////////////////////////////////////////USING STRUCTURE FOR HELI/////////////////////////////////////////////////////




struct User
{
	int posy;
};

typedef struct User us;

us u;





////////////////////////////////////////////USING BOOLEAN FOR COLLISON/////////////////////////////////////////

bool isInOpenOpen(int a, int x,int b)
{

if( (a<x) && (x<b) )return true;
else return false;
}


void gamemenu(int i)
{

	iShowImage(0,0,1300,680,image);
	iShowImage(500,500,300,120,start1);
	iShowImage(500,100,300,120,exit1);
	iShowImage(100,300,300,120,instructions);
	iShowImage(900,300,300,120,highscore);
	iShowImage(450,250,420,800,helicopter);
	iShowImage(470,270,320,150,explosion2);
}


/*void helicoptergame(int j)
{


	
	iShowImage(20,340+posy,150,80,helicopter);
	posy--;





}*/




void randomexplosions()
{if(stopped==false)
{
	//iShowImage(900,400,100,100,explosion1);
	//iShowImage(100,100,100,200,explosion2);
	//iShowImage(1000,400,100,100,explosion1);

	Ex[1]=Ex[1]-2;
	Ex[2]=Ex[2]-2;																		//True
	if(Ex[2]==0)
	{
		Ex[1]=1300;
		Ex[2]=1700;
	}
	if(Ex[1]<Ex[2])
	{	
		f=Ex[1];
		Ex[2]=Ex[1];
		Ex[1]=f;
	}
	
}
}

/////////////////////////////////////////////////////TO COUNT SCORE ON GAMESCREEN////////////////////////////////////////////

void increase_score()
{
	if(j==1){
	if(flag_gameover==0)scoring++;
	}
}


////////////////////////////////////////////////////OBJECT CODES////////////////////////////////////////////////


void randomexplosions1()
{


	Ex[3]=Ex[3]-2;
	Ex[4]=Ex[4]-2;																		
	if(Ex[4]==0)
	{
		Ex[3]=1550;
		Ex[4]=2100;
	}

	if(Ex[3]<Ex[4])
	{	
		f=Ex[3];
		Ex[3]=Ex[4];
		Ex[3]=f;
	}






}
 







void backgroundmoving()
{if(stopped == false)
{
	Bx1=Bx1-2;
	Bx2=Bx2-2;
	if(Bx2==0)
		{
			Bx1=0;
			Bx2=1180;
		}





}

}


	






void iDraw()
{	
	

	
	
	iShowImage(0,0,1300,680,image);
	iShowImage(500,500,300,120,start1);
	iShowImage(500,100,300,120,exit1);
	iShowImage(100,300,300,120,instructions);
	iShowImage(900,300,300,120,highscore);
	iShowImage(450,250,420,220,helicopter);
	iShowImage(470,270,320,200,explosion2);
	int highest_score;
			FILE *score_file=fopen("highest_score.txt","r");                                  /////////////////PRINTING HIGHSCORE ON GAMEMENU////////////////
			fscanf(score_file,"%d",&highest_score);
			//printf("%d\n",highest_score);
			fclose(score_file);
			char highscore_string[30];
			
			iText(1030,320,itoa(highest_score,highscore_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);
	
	
	if(i==1)//gamescreen
	{   //posx++;
		
		u.posy--;
		
		iShowImage(Bx1,By1,1300,680,gamescreen);

		iShowImage(Bx2,By2,1300,680,gamescreen);

		iShowImage(Ex[1],Ey[1],200,100,explosion1);
		iShowImage(Ex[2],Ey[2],200,100,explosion2);

		iShowImage(Ex[3],Ey[3],200,100,explosion1);
		iShowImage(Ex[4],Ey[4],200,100,explosion2);
		




		
		iShowImage(0,550,433,130,darkclouds);
		iShowImage(433,550,433,130,darkclouds);
		iShowImage(866,550,433,130,darkclouds);
		iShowImage(0,0,1300,100,ground);
		
		iShowImage(20,340+u.posy,150,80,helicopter);
	
		iShowImage(0,600,200,80,back1);
		

		//////////////////////////////////////COLLISON CODES ///////////////////////////////////

		
		if(Ex[1]<150)
		
		{
			flag_gameover=1;

			bool t1 = isInOpenOpen(Ey[1],420+u.posy,Ey[2]);
			bool t2 = isInOpenOpen(Ey[1],340+u.posy,Ey[2]);
			printf("%d %d\n",t1,t2);
			printf("%d %d %d\n",Ey[1],420+u.posy,Ey[2]);
			printf("%d %d %d\n",Ey[1],340+u.posy,Ey[2]);

			printf("Here\n");
			if(t1||t2)
			iShowImage(0,0,1300,680,score);
			iText(400,100,"Press 'End' to exit and start again to PLAY!!",GLUT_BITMAP_TIMES_ROMAN_24);


			int highest_score;
			FILE *score_file=fopen("highest_score.txt","r+");                    ///////////////////////////USING HIGH SCORE LOCALLY////////////////////////////////
			fscanf(score_file,"%d",&highest_score);
			//printf("%d\n",highest_score);
			fclose(score_file);
			char highscore_string[30];
			
			iText(900,260,itoa(highest_score,highscore_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);
			char current_score_string[30];
			iText(900,325,itoa(scoring,current_score_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);                 
			score_file=fopen("highest_score.txt","r+");
			if(scoring>=highest_score){
				fprintf(score_file,"%d",scoring);
			}
			fclose(score_file);
			
			
		}

		if(Ex[3]<150)
		
		{
			flag_gameover=1;

			bool t1 = isInOpenOpen(Ey[3],420+u.posy,Ey[4]);
			bool t2 = isInOpenOpen(Ey[3],340+u.posy,Ey[4]);
			printf("%d %d\n",t1,t2);
			printf("%d %d %d\n",Ey[3],420+u.posy,Ey[4]);
			printf("%d %d %d\n",Ey[3],340+u.posy,Ey[4]);

			printf("Here\n");
			if(t1||t2)
			iShowImage(0,0,1300,680,score);
			iText(400,100,"Press 'End' to exit and start again to PLAY!!",GLUT_BITMAP_TIMES_ROMAN_24);


			int highest_score;
			FILE *score_file=fopen("highest_score.txt","r+");                  ///////////////////////////USING HIGH SCORE LOCALLY////////////////////////////////
			fscanf(score_file,"%d",&highest_score);
			//printf("%d\n",highest_score);
			fclose(score_file);
			char highscore_string[30];
			
			iText(900,260,itoa(highest_score,highscore_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);
			char current_score_string[30];
			iText(900,325,itoa(scoring,current_score_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);     
			score_file=fopen("highest_score.txt","r+");
			if(scoring>=highest_score){
				fprintf(score_file,"%d",scoring);
			}
			fclose(score_file);
			
			
		}

		if(Ex[3]<150 && (((Ey[3]<420+u.posy)&&(420+u.posy<Ey[4]))||(Ey[3]<340+u.posy)&&(340+u.posy<Ey[4])))
		{
			flag_gameover=1;
			iShowImage(0,0,1300,680,score);
			iText(400,100,"Press 'End' to exit and start again to PLAY!!",GLUT_BITMAP_TIMES_ROMAN_24);
			int highest_score;
			FILE *score_file=fopen("highest_score.txt","r+");           ///////////////////////////USING HIGH SCORE LOCALLY////////////////////////////////
			fscanf(score_file,"%d",&highest_score);
			//printf("%d\n",highest_score);
			fclose(score_file);
			char highscore_string[30];
			
			iText(900,260,itoa(highest_score,highscore_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);
			char current_score_string[30];
			iText(900,325,itoa(scoring,current_score_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);

			score_file=fopen("highest_score.txt","r+");
			if(scoring>=highest_score){
				fprintf(score_file,"%d",scoring);
			}
			fclose(score_file);
		}
		if(Ex[2]<150 && (((Ey[2]<420+u.posy)&&(420+u.posy<Ey[2]))||(Ey[3]<340+u.posy)&&(340+u.posy<Ey[4])))
		{
			flag_gameover=1;
			iShowImage(0,0,1300,680,score);
			iText(400,100,"Press 'End' to exit and start again to PLAY!!",GLUT_BITMAP_TIMES_ROMAN_24);
			int highest_score;
			FILE *score_file=fopen("highest_score.txt","r+");
			fscanf(score_file,"%d",&highest_score);
			//printf("%d\n",highest_score);
			fclose(score_file);
			char highscore_string[30];
			
			iText(900,260,itoa(highest_score,highscore_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);
			char current_score_string[30];
			iText(900,325,itoa(scoring,current_score_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);

			score_file=fopen("highest_score.txt","r+");
			if(scoring>=highest_score){
				fprintf(score_file,"%d",scoring);
			}
			fclose(score_file);
		}
	    if((420+u.posy)>600||(340+u.posy)<100)
		{
			flag_gameover=1;

			iShowImage(0,0,1300,680,score);
			iText(400,100,"Press 'End' to exit and start again to PLAY!!",GLUT_BITMAP_TIMES_ROMAN_24);
			int highest_score;
			FILE *score_file=fopen("highest_score.txt","r+");
			fscanf(score_file,"%d",&highest_score);
			//printf("%d\n",highest_score);
			fclose(score_file);
			char highscore_string[30];
			
			iText(900,260,itoa(highest_score,highscore_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);
			char current_score_string[30];
			iText(900,325,itoa(scoring,current_score_string, 5),GLUT_BITMAP_TIMES_ROMAN_24);

			score_file=fopen("highest_score.txt","r+");
			if(scoring>=highest_score){
				fprintf(score_file,"%d",scoring);
			}
			fclose(score_file);
		}
		char string_score[30];
		iSetColor(255,0,0);
		if(flag_gameover==0){
			iText(1150,550,itoa(scoring, string_score, 5),GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iSetColor(255,255,255);



	////////////////////////////////////////////WORK OF GAME MENU//////////////////////////////////////////


	if(i==3)//
	{
	i=0;
	
	}
	
	}
	if(i==2)//gamescreen_back_button
	{
	iShowImage(0,0,1300,680,gamescreen);
	iShowImage(0,600,200,80,back1);
	if(i==3)
	{
	i=0;
	iShowImage(0,0,1300,680,image);
	iShowImage(500,500,300,120,start1);
	iShowImage(500,100,300,120,exit1);
	iShowImage(100,300,300,120,instructions);
	iShowImage(900,300,300,120,highscore);
	iShowImage(450,250,420,220,helicopter);
	iShowImage(470,270,320,150,explosion2);
	}
	}
	if(i==4)
	{
	iShowImage(0,0,1300,680,temppic);
	iShowImage(0,600,200,80,back1);


	////////////////////////////////////////////////PRINTING HIGH SCORE IN GAME MENU/////////////////////////////


	int highest_score;
			FILE *score_file=fopen("highest_score.txt","r");
			fscanf(score_file,"%d",&highest_score);
			//printf("%d\n",highest_score);
			fclose(score_file);
			char highscore_string[30];
			
			iText(100,200,itoa(highest_score,highscore_string, 5));
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////


	if(i==3)
	{
	i=0;
	iShowImage(0,0,1300,680,image);
	iShowImage(500,500,300,120,start1);
	iShowImage(500,100,300,120,exit1);
	iShowImage(100,300,300,120,instructions);
	iShowImage(900,300,300,120,highscore);
	iShowImage(450,250,420,220,helicopter);
	iShowImage(470,270,320,150,explosion2);
	}
	
	
	
	if(i==5)
	{
	iShowImage(0,0,1300,680,temppic);
	iShowImage(500,500,300,120,start1);
	i=0;

	}
	
	/*if(i=6)
	{iShowImage(500,500,300,120,passivestart);}*/
	
	
	
	

	
}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
		/*if(mx>=500 && mx<=800 && my>=500 && my<=620)
		{
			i=6;
		}
		else i=0;*/
	;
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=500 && mx<=800 && my>=500 && my<=620)
	{
          i=1;
		  j=1;
		  gamemenu(i);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=300 && mx<=800 && my>=100 && my<=220)
	{
		exit(0);
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=100 && mx<=400 && my>=300 && my<=420)
	{
	   i=2;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=900 && mx<=1200 && my>=300 && my<=420)
	{
	    i=3;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=0 && mx<=200 && my>=550 && my<=680)
	{
		i=4;
		
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=0 && mx<=200 && my>=550 && my<=680)
	{
		i=5;
		
	}
	
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}

	if(key == 'b')
	{
		i=0;
	}
	

	
	if(key == 'w')
	{
		//posy++;
		u.posy+=6;
		//posx++;
		//randomexplosions(j);
	}
	
	/*if(key == 's')
	{
		posy-=5.8;
	}*/
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key == GLUT_KEY_HOME)
	{
		stopped = true;
	}

	if (key == GLUT_KEY_INSERT)
	{
		stopped = false;
	}

	
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.

	
	iInitialize(1300,680, "HeliWay");


	heliwaytimer=iLoadImage("sd lb project//heliwaytimer.PNG");
	score=iLoadImage("sd lb project//Finalized score.png");
	image = iLoadImage("sd lb project//menu background.PNG");
	start1= iLoadImage("sd lb project//Capture1.PNG");
	gamescreen=iLoadImage("sd lb project//bakcground.png");
	exit1 = iLoadImage("sd lb project//exit.PNG");
	instructions = iLoadImage("sd lb project//instructions.png");
	highscore= iLoadImage("sd lb project//High score.png");
	darkclouds = iLoadImage("sd lb project//dark clouds.png");
	helicopter= iLoadImage("sd lb project//Picture1.png");
	ground=iLoadImage("sd lb project//ground.png");
	back1=iLoadImage("sd lb project//Back.png");
	explosion2=iLoadImage("sd lb project//explosion2.png");
	heli1=iLoadImage("sd lb project//heli1.png");
	heli2=iLoadImage("sd lb project//heli2.png");
	heli3=iLoadImage("sd lb project//heli3.png");
	explosion1=iLoadImage("sd lb project//explosion1.png");
	explosion2=iLoadImage("sd lb project//explosion1.png");
	temppic=iLoadImage("sd lb project//tempPic.png");


    iSetTimer(50,increase_score);
	iSetTimer(10,backgroundmoving);
	iSetTimer(5,randomexplosions);
	iSetTimer(10,randomexplosions1);
	iStart(); // it will start drawing

	return 0;
}