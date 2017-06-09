#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>


void arch()
{
int xasp,yasp;
float i;
	getaspectratio(&xasp,&yasp);
	setaspectratio(xasp/5,yasp);
	setcolor(WHITE);
	for(i=0;i<8;i=i+0.01)
	arc(314,295+i,180,0,200);
	}

 void whitePixel(int color) {
	int i, j = 0, x, y;
		setlinestyle(SOLID_LINE, 1, 3);
	setcolor(color);

	for (i = 50; i < 1000; i = i + 50) {
		x = i;
		y = 100 + j;

		/* put pixel at the given position */
		putpixel(x, y, color);

		/* moving the snow(pixels) towards moutain */
		if (i % 100 == 0) {
			y = y + 90;
			x = x + 35;
			j = 20;
		}  else {
			y = y +  130;
			x = x + 25;
			if (i > 450)
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
	int i, j, x, y;

	for (i = 25; i < 600; i = i + 25) {
		x = i;
		y = 100 + j;
		putpixel(x, y, color);

		if (i % 100 == 0) {
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
	int gd=DETECT,gm,j,k,xasp,yasp;
	float x,y,i;
	int amp;
	float fq;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");


	for(i=0;i<115;i++)
	{
		x=(((3.14/180)*i)*(25*3.14));
		y=(380-((sin(x)/x)))-85;
		putpixel(i+0,y,WHITE);
		line(i,y+10,i,y);
	}
	for(i=0;i<8;i=i+0.01)
	line(115+i,295,115+i,480);
		for(i=0;i<4;i=i+0.01)
		{
		circle(7-i,396+i,10);
		circle(23-i,465+i,10);
		circle(79+i,403-i,15);
	      circle(53+i,340-i,13);

	      }
			x = getmaxx() - 50;
	y = 40;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);



	arch();

	 setaspectratio(1,1);
	for(i=510;i<=640;i++)
	{
		x=(((3.14/180)*i)*(25*3.14));
		y=(380-((sin(x)/x)))-85;
		putpixel(i+0,y,WHITE);
		line(i,y+10,i,y);
	//  floodfill(100,320,LIGHTGRAY);
	}

	for(i=0;i<8;i=i+0.01)
	line(510+i,295,510+i,480);


		for(i=0;i<4;i=i+0.01)
		{
		circle(615+i,360-i,14);
	       //	circle(500-i,270+i,16);
		circle(575-i,425+i,14);
	      //	circle(560-i,220+i,12);
		circle(532-i,350+i,17);
		circle(633+i,455-i,11);
		circle(555+i,475-i,12);
		}

       setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(600,getmaxy(),WHITE);
	floodfill(2, getmaxy(), WHITE);


	setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	circle(100,275,11);
	circle(100,275,8);
	circle(140,265,11);
	circle(140,265,8);
	circle(170,270,11);
	circle(170,270,8);
	circle(210,285,11);
	circle(210,285,8);
	circle(250,295,11);
	circle(250,295,8);
	circle(300,305,11);
	circle(300,305,8);
	circle(360,304,11);
	circle(360,305,8);
	circle(420,300,11);
	circle(420,300,8);
	circle(500,275,11);
	circle(500,275,8);
		circle(550,275,11);
	circle(550,275,8);
		circle(600,275,11);
		circle(600,275,8);
			floodfill(550,275,LIGHTGREEN);
				floodfill(600,275,LIGHTGREEN);
	floodfill(500,275,LIGHTGREEN);
	floodfill(420,300,LIGHTGREEN);
	floodfill(360,305,LIGHTGREEN);
	floodfill(300,305,LIGHTGREEN);
	floodfill(170,270,LIGHTGREEN);
	floodfill(100,275,LIGHTGREEN);
	floodfill(140,265,LIGHTGREEN);
	floodfill(210,285,LIGHTGREEN);
	floodfill(250,295,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(94,272,"20");
	outtextxy(134,262,"20");
	outtextxy(164,267,"20");
	outtextxy(204,282,"20");
	outtextxy(244,292,"20");
	outtextxy(294,302,"20");
	outtextxy(354,302,"20");
	outtextxy(414,297,"20");
	outtextxy(494,272,"20");
	outtextxy(544,272,"20");
	outtextxy(594,272,"20");
	for (i = 0; i < 10; i++)
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