#include <stdio.h>
  #include <conio.h>
  #include <math.h>
  #include <graphics.h>
  #include <dos.h>
  #include<time.h>

  /* clears/creates snow based on the given color */
  void whitePixel(int color) {
	int i, j = 0, x, y;
	setlinestyle(SOLID_LINE, 1, 3);
	setcolor(color);

	for (i = 50; i < 1000; i = i + 50) {
		x = i;
		y = 50 + j;

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
			if (i > 450) {
				j = 160;
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

  int main()
  {
int a, j, midx, midy, x1, y1, x2, y2;
	int tmpx1, tmpy1, tmpx2, tmpy2;
	int gdriver = DETECT, gmode, err,m,n;
	int k=50, fq;
	double x, y;
	float i=0.0;
	char c;
	// initialize graphic mod

	initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
	err = graphresult();

	if (err != grOk) {
		/* error occurred*/
		printf("Graphics Error: %s\n",grapherrormsg(err));
		return 0;
	}

	x = 0;
	fq = 2;
	setcolor(WHITE);

	/* drawing the moutain using sine wave */
	while (x <= getmaxx())
	{
		y = k * cos((3.14 * fq * x) / 180);
		y = y + getmaxy() / 2 + 100;
		putpixel(x, y, 15);
		line(x, y, x, y - 12);
		line(x, y, x, y + 12);

		x = x + 1;
		}
		for(i=0;i<4;i=i+0.01)
		{
		circle(7-i,396+i,10);
		circle(23-i,455+i,10);
		circle(79+i,380-i,15);
		circle(115-i,445+i,15);
	       //	circle(160-i,320+i,10);
		circle(200-i,390+i,14);
			circle(307-i,396+i,10);
		circle(323-i,455+i,13);
		circle(294+i,331-i,15);
		circle(415-i,445+i,15);
		circle(460-i,340+i,13);
		circle(500-i,390+i,14);
		circle(190-i,473+i,14);
		circle(530+i,470-i,13);
		circle(585+i,420-i,14);
		}


	/* color the mountain with white(snow) */
	setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(2, getmaxy(), WHITE);

	/* draw the moon */
	x = getmaxx() - 50;
	y = 40;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);


	/* snowfall */
	for (i = 0; i < 10; i++)
	 {
		whitePixel(WHITE);
		snowFall(BLACK);
		delay(100);
		whitePixel(BLACK);
		snowFall(WHITE);
		delay(100);
		}

	whitePixel(WHITE);

	getch();

	/* deallocate memory allocated for graphic screen */
	closegraph();

	return 0;
  }
