#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
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

	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(color);

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
	int gd=DETECT,gm,j,k;
	float x,y,i;
	int amp,s=0;
	float fq;
	char c;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");


	for(i=195;i<400;i++)
	{
		x=((3.14/180)*i)*(25*3.14);
		y=380-((sin(x)/x));
		putpixel(i,y,WHITE);
		line(i,y+9,i,y);
	}
			amp=150 ;
	fq=0.35  ;
	for(i=-10;i<200;i++)
	{
		y = amp * sin((3.14 * fq * i) / 180);
		y = y + getmaxy() / 2 + 5;
		putpixel(i-5, y-5, 15);
		line(i-5,y-5,i-5,y+8);
//		line(i-5,y-5,i-5,y+10);
	       //	line(i-5,y,i-5,y-7);


	}
	for(i=400;i<495;i++)
	{
	       //	y=sin(x);
		y = amp * sin((3.14 * fq * i) / 180);
		y = y + getmaxy() / 2 + 5;
		putpixel(i-5, y+45, 15);
		line(i-5,y+40,i-5,y+45);
		line(i-5,y+50,i-5,y+45);
	}
	for(i=495;i<650;i++)
	{
		x=((3.14/180)*i)*(25*3.14);
		y=380-((sin(x)/x))-80;
		putpixel(i-5,y,WHITE);
		line(i-5,y+12,i-5,y);

	}

	line(i-5,y+45,640,y+45);



		for(i=0;i<4;i=i+0.01)
		{
		circle(7-i,396+i,10);
		circle(23-i,465+i,10);
		circle(79+i,403-i,15);
		circle(115-i,450+i,15);
	       //	circle(160-i,320+i,10);
		circle(200-i,400+i,14);
		circle(307-i,396+i,10);
		circle(323-i,450+i,13);
		circle(42+i,335-i,17);
		circle(415-i,445+i,15);
		circle(470-i,340+i,13);
		circle(500-i,390+i,14);
		circle(190-i,473+i,14);
		circle(530+i,470-i,13);
		circle(585+i,420-i,14);
	       //	circle(500-i,270+i,16);
		circle(555-i,320+i,17);
	       //	circle(560-i,220+i,12);
	      //	circle(630-i,260+i,17);
	       //	circle(633+i,165-i,11);
		}

	setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(2, getmaxy(), WHITE);



	x = getmaxx() - 50;
	y = 40;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);
		setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	circle(100,300,11);
	circle(100,300,8);
       //	circle(140,265,11);
       //	circle(140,265,8);
	circle(170,345,11);
	circle(170,345,8);
	circle(210,357,11);
	circle(210,357,8);
	circle(250,357,11);
	circle(250,357,8);
	circle(300,357,11);
	circle(300,357,8);
	circle(360,357,11);
	circle(360,357,8);
	circle(420,340,11);
	circle(420,340,8);
	circle(500,275,11);
	circle(500,275,8);
		circle(550,275,11);
	circle(550,275,8);
		circle(600,275,11);
		circle(600,275,8);
			floodfill(550,275,LIGHTGREEN);
				floodfill(600,275,LIGHTGREEN);
	floodfill(500,275,LIGHTGREEN);
	floodfill(420,340,LIGHTGREEN);
	floodfill(360,357,LIGHTGREEN);
	floodfill(300,357,LIGHTGREEN);
	floodfill(170,345,LIGHTGREEN);
	floodfill(100,300,LIGHTGREEN);
      //	floodfill(140,265,LIGHTGREEN);
	floodfill(210,357,LIGHTGREEN);
	floodfill(250,357,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(94,297,"20");
       //	outtextxy(134,262,"20");
	outtextxy(164,342,"20");
	outtextxy(204,354,"20");
	outtextxy(244,354,"20");
	outtextxy(294,354,"20");
	outtextxy(354,354,"20");
	outtextxy(414,337,"20");
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
