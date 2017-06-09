#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>

 void whitePixel(int color) {
	int  j = 0, x, y,a;

		setlinestyle(SOLID_LINE, 1, 3);
	setcolor(color);

	for (a= 50; a< 1000; a = a+ 50) {
		x = a;
		y = 100 + j;

		/* put pixel at the given position */
		putpixel(x, y, color);

		/* moving the snow(pixels) towards moutain */
		if (a % 100 == 0) {
			y = y + 90;
			x = x + 35;
			j = 20;
		}  else {
			y = y +  130;
			x = x + 25;
			if (a> 450)
			 {
				j = 240;
			} else {
				j = 30;
			}
		}

		/* put pixel at the given position */

	      putpixel(x, y, color);
	}

	return;
  }

  void snowFall(int color) {
	int a, j, x, y;

	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(color);

	for (a= 25; a< 600; a = a + 25) {
		x = a;
		y = 100 + j;
		putpixel(x, y, color);

		if (a % 100 == 0) {
			y = y + 90;
			x = x + 35;
			j = 20;
		}  else {
			y = y +  130;
			x = x + 25;
			j = 30;
		}
		putpixel(x, y, color);
	}
	return;
  }

void main()
{
	int gd=DETECT,gm,j,k,x,y,s=0,q;
	float i;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setcolor(WHITE);
	for(i=0;i<640;i++)
	{
	       putpixel(i-s,385-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)),WHITE);
		line(i-s,390-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)),i,380-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)));

		delay(0);

	}


	      for(i=0;i<4;i=i+0.01)
		{

		circle(20-i,200+i,12);
		circle(25-i,300+i,13);
		circle(90-i,250+i,12);
		circle(7-i,396+i,10);
		circle(23-i,465+i,10);
		circle(79+i,403-i,15);
		circle(115-i,450+i,15);
		circle(100-i,320+i,10);
		circle(178-i,400+i,14);
		circle(377-i,396+i,10);
		circle(323-i,450+i,13);
	       //	circle(372+i,375-i,17);
		circle(415-i,445+i,12);
	     //	circle(460-i,340+i,13);
		circle(500-i,390+i,14);
		circle(190-i,473+i,14);
		circle(530+i,470-i,13);
		circle(585+i,420-i,14);
	       //	circle(500-i,270+i,16);
	       //	circle(555-i,325+i,17);
	     //	circle(560-i,220+i,12);
	       //	circle(630-i,260+i,17);
	       //	circle(633+i,165-i,11);
		 }

	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(2, getmaxy(), WHITE);



	x = getmaxx() - 50;
	y = 40;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);

		setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	circle(70,150,11);
	circle(70,150,8);
       //	circle(140,265,11);
       //	circle(140,265,8);
	circle(170,345,11);
	circle(170,345,8);
	circle(210,357+30,11);
	circle(210,357+30,8);
	circle(250,357+55,11);
	circle(250,357+55,8);
	circle(300,357+40,11);
	circle(300,357+40,8);
	circle(360,357,11);
	circle(360,357,8);
	circle(420,330,11);
	circle(420,330,8);
	circle(500,275,11);
	circle(500,275,8);
		circle(550,275,11);
	circle(550,275,8);
		circle(600,275,11);
		circle(600,275,8);
			circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
	circle(550,275+40,8);
		circle(600,275+40,11);
		circle(600,275+40,8);
	//		circle(500,275+80,11);
      //	circle(500,275+80,8);
		circle(550,275+80,11);
	circle(550,275+80,8);
		circle(600,275+80,11);
		circle(600,275+80,8);
			floodfill(550,275,LIGHTGREEN);
				floodfill(600,275,LIGHTGREEN);
	floodfill(500,275,LIGHTGREEN);
		floodfill(550,275+40,LIGHTGREEN);
				floodfill(600,275+40,LIGHTGREEN);
	floodfill(500,275+40,LIGHTGREEN);
		floodfill(550,275+80,LIGHTGREEN);
				floodfill(600,275+80,LIGHTGREEN);
       //	floodfill(500,275+80,LIGHTGREEN);
	floodfill(420,330,LIGHTGREEN);
	floodfill(360,357,LIGHTGREEN);
	floodfill(300,357+40,LIGHTGREEN);
	floodfill(170,345,LIGHTGREEN);
	floodfill(70,150,LIGHTGREEN);
      //	floodfill(140,265,LIGHTGREEN);
	floodfill(210,357+30,LIGHTGREEN);
	floodfill(250,357+55,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(64,147,"20");
       //	outtextxy(134,262,"20");
	outtextxy(164,342,"20");
	outtextxy(204,354+30,"20");
	outtextxy(244,354+55,"20");
	outtextxy(294,354+40,"20");
	outtextxy(354,354,"20");
	outtextxy(414,327,"20");
       outtextxy(494,272,"20");
	outtextxy(544,272,"20");
	outtextxy(594,272,"20");
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	     //	outtextxy(494,272+80,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");
	 for(i=0;i<10;i++)
	 {
		whitePixel(WHITE);
		snowFall(BLACK);
		delay(100);
		whitePixel(BLACK);
		snowFall(WHITE);
		delay(100);
		}


	getch();
	closegraph();
	}

