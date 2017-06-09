#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

char ch;
int num=1,sum=0,o,p=0,u=0;

typedef struct s
{
	long double x,y;
	struct s *next,*prev;
}node;

typedef struct list
{
	int sc;
	struct list *next_sc;
}node_sc;

node *head=NULL,*t,*end,*end2,*head2=NULL;
void ball(long double,long double,long double);
node* insert(node *h,long double x,long double y);
void whitePixel(int color);
void getcoordinate(node*);
node* nodefrball(node*,node*);
void traversal(node*);
node_sc *score(node_sc *,int);
node_sc *start=NULL,*e;
  void twinkle(int color);
  void screen1(int);
  void cscreen2();
  void screen2(int);
//  void cscreen3();
// void screen3();
//  void cscreen4();
//  void screen4();
//  void cscreen5();
//  void screen5();

int getcol(int col)
{
   switch(col)
   {
      case 0: return 0;
      case 1: return 4;
      case 2: return 2;
      case 3: return 6;
      case 4: return 1;
      case 5: return 5;
      case 6: return 3;
      case 7: return 7;
      case 8: return 8;
      case 9: return 12;
      case 10:return 10;
      case 11:return 14;
      case 12:return 9;
      case 13:return 13;
      case 14:return 11;
      case 15:return 15;
   }
   return col;
} FILE *ptr;
void loadbitmap(char *a,int x,int y)
{int width,height;

   unsigned long temp=0,k=0,j=0;
   unsigned long ww;
   int ch,ch1,ch2;
   ptr=fopen(a,"rb");


   width=0;height=0;
   fseek(ptr,18,SEEK_SET);
   for(k=0x1;k<=0x10000;k*=0x100)
   {
	   temp=fgetc(ptr);
	   width+=(temp*k);
   }
   fseek(ptr,22,SEEK_SET);
   for(k=0x1;k<=0x10000;k*=0x100)
   {
	   temp=fgetc(ptr);
	   height+=(temp*k);
   }

   ww=width;
   if(ww%2)
  { ww++;ww/=2;}
   if(ww%4)
   ww=(ww/4)*4+4;

   fseek(ptr,119,SEEK_SET);

   for(k=0;k<height;k++)
   for(j=0;j<ww;j++)
   {
	   ch=fgetc(ptr);
	   ch1=ch;ch2=ch;
	      ch1=ch1&(0xf0);ch1=ch1>>4;
	   ch2=ch2&(0x0f);
	   if(j*2<width)
	   putpixel((j*2)+x,(height-1-k)+y,getcol(ch1));
	   if(j*2+1<width)
	   putpixel((j*2)+1+x,(height-1-k)+y,getcol(ch2));
   }
   fclose(ptr);

  }


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

	void twinkle(int color)
	{
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
	 long double i,x,y,fq;
       //	 coordinate centre;
	 int midy,s=0,amp;
	char c;
	int gd=DETECT,gm,maxx;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	 loadbitmap("abc.bmp",80,0);

 rectangle(80,0,560,245);
  setfillstyle(SOLID_FILL,RED);
 floodfill(560,245,RED);

 setcolor(WHITE);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
 outtextxy(200,100,"Mountain Rush!");


 getch();
 cleardevice();
 loadbitmap("abc.bmp",80,0);
 rectangle(80,0,560,245);
  setfillstyle(SOLID_FILL,RED);
 floodfill(560,245,RED);
 setcolor(WHITE);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 outtextxy(180,100,"Press 1 to start playing!");
 outtextxy(180,150,"Press 2 for Instructions");
       ch=getche();
       if(ch=='2')
       {
		cleardevice();
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
		outtextxy(150,60,"Instructions");
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(10,150,"To move the ball forward press 'd'");
		outtextxy(10,200,"To bounce press 'b'.");
		outtextxy(10,250,"To move back press 'a'");
		outtextxy(10,300,"If either of the two is not pressed game gets over :(");
		outtextxy(10,350,"The aim is to collect as many coins as possible.");
		outtextxy(100,420,"Press 1 to start playing!");

		ch=getche();
       }

       if(ch=='1')
       {
	cleardevice();
	setcolor(WHITE);
	for(i=0;i<320;i++)
	{       y=380;
		line(i,y,i+1,y);
		head=insert(head,i,y);
		line(i-s,y+10,i-s,y);

	}
	setcolor(WHITE);
	amp=150 ;
	fq=0.35  ;
	for(i=320;i<650;i++)
	{
	       //	y=sin(x);
		y = amp * sin((3.14 * fq * i) / 180);
		y = y + getmaxy() / 2 + 5;

		putpixel(i-5-s, y-5,15);
		head=insert(head,i-5-s,y-5) ;
		line(i-5-s,y-5,i-5-s,y+10);
	}

	 for(i=0;i<4;i=i+0.01)
		{

		circle(7+i-s,396+i,10);
		circle(23+i-s,465+i,10);
		circle(79+i-s,403-i,15);
		circle(115+i-s,450+i,15);
	       //	circle(160-i,320+i,10);
		circle(200+i-s,400+i,14);
			circle(307+i-s,396+i,10);
		circle(323+i-s,450+i,13);
		circle(372+i-s,375-i,17);
		circle(415+i-s,445+i,15);
		circle(460+i-s,340+i,13);
		circle(500+i-s,390+i,14);
		circle(190+i-s,473+i,14);
		circle(530+i-s,470-i,13);
		circle(585+i-s,420-i,14);
		circle(500+i-s,270+i,16);
		circle(555+i-s,325+i,17);
		circle(560+i-s,220+i,12);
		circle(630+i-s,260+i,17);
		circle(633+i-s,165-i,11);
	      }

		  setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(2-s, getmaxy(), WHITE);



	x = getmaxx() - 50;
	y = 40;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);

		setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);

		circle(150,275+80,11);
		circle(150,275+80,8);
		circle(200,275+80,11);
		circle(200,275+80,8);
		circle(250,275+80,11);
		circle(250,275+80,8);
		circle(400,300,8);
		circle(400,300,11);
		circle(460,250,8);
		circle(460,250,11);
		circle(490,180,8);
		circle(490,180,11);
		circle(512,202,8);
		circle(512,202,11);
		circle(565,160,8);
		circle(565,160,11);

		floodfill(200,275+80,LIGHTGREEN);
		floodfill(250,275+80,LIGHTGREEN);
		floodfill(150,275+80,LIGHTGREEN);
		floodfill(400,300,LIGHTGREEN);
		floodfill(460,250,LIGHTGREEN);
		floodfill(490,180,LIGHTGREEN);
		floodfill(512,202,LIGHTGREEN);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(294-150,272+80,"10");
		outtextxy(344-150,272+80,"10");
		outtextxy(394-150,272+80,"15");
		outtextxy(394,297,"15");
		outtextxy(454,247,"25");
		outtextxy(484,177,"75");
		outtextxy(506,199,"50");
		outtextxy(559,157,"10");

	   for (i = 0; i < 10; i++)
	 {
		whitePixel(WHITE);
		twinkle(BLACK);
		delay(100);
		whitePixel(BLACK);
		twinkle(WHITE);
		delay(100);

	}
       }

	/*
	sound(400);
	delay(100);
	nosound();
	delay(1000);
	sound(400);
	delay(100);
	nosound();
	delay(1000);
	sound(400);
	delay(100);
	nosound();
	delay(1000);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	outtextxy(310,240,"GO!!");
		sound(600);
	delay(100);
	nosound();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
       */


	head2=nodefrball(head,head2);
       ball(30,355,20);
	 cscreen2();
	 ball(30,100,20);
	 printf("Your Total Score is: %d",sum);
//	cscreen3();
//	 ball(30,300,20);
//	cscreen4();
//	ball(30,240,20);
//	cscreen5();
 //	ball(30,255,20);
	getch();
	closegraph();

      }
node* insert(node *h,long double x,long double y)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->y=y;
	temp->next=temp->prev=NULL;
	if(h==NULL)
	{
		h=temp;
		end=temp;
	}
	else
	{
		end->next=temp;
		temp->prev=end;
		end=temp;
	}
	return h;
}
void traversal(node *h)
{
	node *temp=h;
	while(temp!=NULL)
	{
		printf("\n%Lf,%Lf",temp->x,temp->y);
		temp=temp->next;
	}
}
node_sc* score(node_sc *start,int data)
{
	node_sc *tt;
	tt=(node_sc *)malloc(sizeof(node_sc));
	tt->sc=data;
	tt->next_sc=NULL;
	if(start == NULL)
	{
		start=tt;
		e=tt;
	}
	else
	{
		e->next_sc=tt;
		e=tt;
	}
	sum=sum+e->sc;
	printf("%d",sum);
	return start;

}
void whitePixel(int color) {
	int i, j = 0, x, y;
		setlinestyle(SOLID_LINE, 1, 3);
	setcolor(color);
	for (i = 50; i < 1000; i = i + 50) {
		x = i;
		y = 100 + j;

		putpixel(x, y, color);

		if (i % 100 == 0)
		{
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

	      putpixel(x, y, color);
	}

	return;
  }

void ball(long double cx,long double cy,long double radius)
{
       //    cleardevice();
       float m=0.0,l=2.0;
       long double i,x,y,fq,x1,x2,y1,y2,M;
       int s=0,amp,f,k=20;
       node *temp=head2;
       ch=getche();
	while(ch=='d'||ch=='b' || ch=='a')
	{
		cleardevice();
		// setcolor(0);
		if(num==1)
		{
			screen1(p);
		}
		else
		if(num==2)
		{
			screen2(u);
		}
/*		else
		if(num==3)
		{
			screen3();
		}
/*		else
		if(num==4)
		{
			screen4();
		}
/*		else
		if(num==5)
		{
			screen5();
		}*/
		x1=temp->x;
		x2=temp->next->x;
		y1=temp->y;
		y2=temp->next->y;

		M=(y2-y1)/(x2-x1);
		cx=x2;
		cy=y2;
			setcolor(RED);

			   if(ch=='d')
		 {

			     circle(cx,cy-20,radius);
			     if(k%2==0)

			 {setfillstyle(BKSLASH_FILL,RED);
			floodfill(cx,cy-20,RED); }
			if(k%2!=0)
			{
			setfillstyle(SLASH_FILL,RED);
			floodfill(cx,cy-20,RED);
			}
			temp=temp->next;
			if(num==1)
			{
				if(cx>150 && cx<160)
				{
					start=score(start,10);
					sound(600);
					delay(50);
					nosound();
					p=1;
				}
				if(cx>195 && cx<210)
				{
					start=score(start,10);
						sound(600);
						delay(50);
					      nosound();
					p=2;
				}
				if(cx>245 && cx<260)
				{
					start=score(start,15);
						sound(600);
					      delay(50);
					      nosound();
					p=3;
				}
				if(cx>395 && cx<405)
				{
					start=score(start,15);
						sound(600);
					      delay(50);
					      nosound();
					      p=4;
				}
				if(cx>455 && cx<465)
				{
					start=score(start,25);
						sound(600);
					      delay(50);
					      nosound();
					p=5;
				}

				if(cx>507 && cx<517)
				{
					start=score(start,125);
						sound(600);
					      delay(50);
					      nosound();
					p=7;
				}
				if(cx>560 && cx<570)
				{
					start=score(start,10);
						sound(600);
					      delay(50);
					      nosound();
					p=8;
				}

			  }

		 if(num==2)
		 {
		 if(cx>55 && cx<65)
		 {
		    start=(score,20);
		    sound(600);
		    delay(50);
		    nosound();
		    u=1;
		 }
		  if(cx>135 && cx<145)
		  {
		    start=(score,20);
		    sound(600);
		    delay(50);
		    nosound();
		    u=2;
		 }
		  if(cx>165 && cx<175)
		  {
		    start=(score,20);
		    sound(600);
		    delay(50);
		    nosound();
		    u=3;
		 }
		  if(cx>205 && cx<215)
		 {
		    start=(score,20);
		    sound(600);
		    delay(50);
		    nosound();
		    u=4;
		 }
		  if(cx>245 && cx<255)
		 {
		    start=(score,20);
		    sound(600);
		    delay(50);
		    nosound();
		    u=5;
		 }
		  if(cx>295 && cx<305)
		 {
		    start=(score,20);
		    sound(600);
		    delay(50);
		    nosound();
		    u=6;
		 }
	   }
    }
		 if(ch=='a')
		 {
			temp=temp->prev;
			cx=temp->x;
			cy=temp->y;
			setcolor(RED);
			circle(cx,cy-20,radius);
			if(k%2==0)
			{
			setfillstyle(BKSLASH_FILL,RED);
			floodfill(cx,cy-20,RED); }
			if(k%2!=0)
			{
			setfillstyle(SLASH_FILL,RED);
			floodfill(cx,cy-20,RED);
			}
			delay(30);

			if(num==1)
			{
				screen1(p);
			}
			else
			if(num==2)
			{
				screen2(u);
			}

		 }
		 if(ch=='b')
		 {
			setcolor(RED);
			circle(cx,cy-70,radius);
				if(k%2==0)
			{
			setfillstyle(BKSLASH_FILL,RED);
			floodfill(cx,cy-70,RED); }
			if(k%2!=0)
			{
			setfillstyle(SLASH_FILL,RED);
			floodfill(cx,cy-70,RED);
			}
			delay(30);
			cleardevice();
			if(num==1)
			{
				screen1(p);
			}
			else
			if(num==2)
			{
				screen2(u);
			}
			cx=temp->next->next->x;
			cy=temp->next->next->y;
			setcolor(RED);
			circle(cx,cy-20,radius);
			setfillstyle(BKSLASH_FILL,RED);
			floodfill(cx,cy-20,RED);


			temp=temp->next->next;
		 }
		 k++;
		if(cx > 635)
		{
	  //		f=-1;   //screen over
			num++;
			break;
		}

		ch=getche();

		 if(M>0)
		 {
			temp=temp->next->next;
		 }
	 //	getch();
	     }
      /*	     if(f==-1)
	     {
			setcolor(GREEN);
		     printf("Stage %d cleared",num);
		   //	ch=getche();
			num++;
	     } */


	     if(ch!='d')
	     {  cleardevice();
	//	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
	  //	outtextxy(250,200,"Oops! :(");
		loadbitmap("oops.bmp",80,20);
		getch();
		closegraph();

	     }

       //	cleardevice();
       //	getch();
}       //	closegraph();

node* nodefrball(node *h1,node *h2)
{
	node *temp=h1;
	node *temp2;
	while(temp->next->next!=NULL)
	{
		temp=temp->next->next->next->next->next->next->next->next->next->next->next->next->next->next;

		temp2=(node*)malloc(sizeof(node));
		temp2->x=temp->x;
		temp2->y=temp->y;
		temp2->next=temp2->prev=NULL;
		if(h2==NULL)
		{
			h2=temp2;
			end2=temp2;
		}
		else
		{
			end2->next=temp2;
			temp2->prev=end2;
			end2=temp2;
		}
	}
	return h2;
}
node *back(node *hh)
{
	node *tt=hh;
	tt=tt->prev;
return hh;
}
/*void traversal(node *h)
{
	node *temp=h;
	while(temp!=NULL)
	{
		printf("%f %f",temp->x,temp->y);
		temp=temp->next;
	}
} */

void getcoordinate(node *h1)
{

	long double x1,y1,x2,y2,x,y,cx,cy;
	long double theta, ntheta;
	long double a,b,c;
	float k;
	long double m,D,s;
	//coordinate cnt;
	node *temp=h1;

	while(ch=='d')
	{
		x1=temp->next->next->next->x;x2=temp->next->next->next->next->next->x;
		y1=temp->y;y2=temp->next->y;
		x=x2-x1;
		y=y2-y1;
		m=y/x;


			ball(x2,y2-20,20);

/*		if(m!=0)
		{
			theta=atan(m);
			ntheta=(M_PI_2)-theta;
			s=pow(x1,2)+pow(y1,2)-pow(x2,2)-pow(y2,2)   ;
			k=400-(400/sin(ntheta)*sin(ntheta))+s;
			a=1+pow((1/m),2) ;
			b=(k*(x1-x2)/pow((y1-y2),2))+2*x2-2*((x1-x2)/(y1-y2));
			c=((pow(k,2)/4)/pow((y1-y2),2))-400-pow(x2,2)-pow(y2,2);
			D=pow(b,2)-4*a*c ;
			if(D>=0)
			{
				cx=-b/2*a+sqrt(D)/2*a;
				cy=k/(2*(y1-y2))-cx*(x1-x2)/(y1-y2);
				ball(cx,cy,20);
			}
		  /*	if(D<0)
			{
				t=t->next;
				break;
			}   */
	       /*	}*/
	      // cx=x2;
	      // cy=y2-20;
	      // ball(cx,cy,20);
	temp=temp->next;
	ch=getche();
	}
}
void screen1(int q)
{      float m=0.0,k=20.0,l=2.0;
       long double i,x,y,fq,x1,x2,y1,y2,M;
       int s=0,amp,f;
		setcolor(WHITE);
	for(i=0;i<320;i++)
	{       y=380;
		/*x=((3.14/180)*i)*(25*3.14);
		y=380-((sin(x)/x));
		putpixel(i-s,y,WHITE);*/
		line(i,y,i+1,y);
	  //	head=insert(head,i,y);
		line(i-s,y+10,i-s,y);

	}
	setcolor(WHITE);
	amp=150 ;
	fq=0.35  ;
	for(i=320;i<650;i++)
	{
	       //	y=sin(x);
		y = amp * sin((3.14 * fq * i) / 180);
		y = y + getmaxy() / 2 + 5;

		putpixel(i-5-s, y-5,15);
	//	head=insert(head,i-5-s,y-5) ;
		line(i-5-s,y-5,i-5-s,y+10);
	       //	line(i-5,y,i-5,y-7);
	}
       //	setcolor(WHITE);
       //	line(getmaxx()-s,0,getmaxx()-s,getmaxy());

		i=0;

		circle(7+i-s,396+i,10);
		circle(23+i-s,465+i,10);
		circle(79+i-s,403-i,15);
		circle(115+i-s,450+i,15);
	       //	circle(160-i,320+i,10);
		circle(200+i-s,400+i,14);
		circle(307+i-s,396+i,10);
		circle(323+i-s,450+i,13);
		circle(372+i-s,375-i,17);
		circle(415+i-s,445+i,15);
		circle(460+i-s,340+i,13);
		circle(500+i-s,390+i,14);
		circle(190+i-s,473+i,14);
		circle(530+i-s,470-i,13);
		circle(585+i-s,420-i,14);
		circle(500+i-s,270+i,16);
		circle(555+i-s,325+i,17);
		circle(560+i-s,220+i,12);
		circle(630+i-s,260+i,17);
		circle(633+i-s,165-i,11);

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
		if(q==0)
		{
		circle(150,275+80,11);
		circle(150,275+80,8);
		circle(200,275+80,11);
		circle(200,275+80,8);
		circle(250,275+80,11);
		circle(250,275+80,8);
		circle(400,300,8);
		circle(400,300,11);
		circle(460,250,8);
		circle(460,250,11);
		circle(490,180,8);
		circle(490,180,11);
		circle(512,202,8);
		circle(512,202,11);
		circle(565,160,8);
		circle(565,160,11);

		floodfill(200,275+80,LIGHTGREEN);
		floodfill(250,275+80,LIGHTGREEN);
		floodfill(150,275+80,LIGHTGREEN);
		floodfill(400,300,LIGHTGREEN);
		floodfill(460,250,LIGHTGREEN);
		floodfill(490,180,LIGHTGREEN);
		floodfill(512,202,LIGHTGREEN);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		outtextxy(294-150,272+80,"10");
		outtextxy(344-150,272+80,"10");
		outtextxy(394-150,272+80,"15");
		outtextxy(394,297,"15");
		outtextxy(454,247,"25");
		outtextxy(484,177,"75");
		outtextxy(506,199,"50");
		outtextxy(559,157,"10");
	       }
		 if(q==1)
	       {
		circle(200,275+80,11);
		circle(200,275+80,8);
		circle(250,275+80,11);
		circle(250,275+80,8);
		circle(400,300,8);
		circle(400,300,11);
		circle(460,250,8);
		circle(460,250,11);
		circle(490,180,8);
		circle(490,180,11);
		circle(512,202,8);
		circle(512,202,11);
		circle(565,160,8);
		circle(565,160,11);

		floodfill(200,275+80,LIGHTGREEN);
		floodfill(250,275+80,LIGHTGREEN);
//		floodfill(150,275+80,LIGHTGREEN);
		floodfill(400,300,LIGHTGREEN);
		floodfill(460,250,LIGHTGREEN);
		floodfill(490,180,LIGHTGREEN);
		floodfill(512,202,LIGHTGREEN);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		outtextxy(344-150,272+80,"10");
		outtextxy(394-150,272+80,"15");
		outtextxy(394,297,"15");
		outtextxy(454,247,"25");
		outtextxy(484,177,"75");
		outtextxy(506,199,"50");
		outtextxy(559,157,"10");
	       }
	       if(q==2)
	       {
		circle(250,275+80,11);
		circle(250,275+80,8);
		circle(400,300,8);
		circle(400,300,11);
		circle(460,250,8);
		circle(460,250,11);
		circle(490,180,8);
		circle(490,180,11);
		circle(512,202,8);
		circle(512,202,11);
		circle(565,160,8);
		circle(565,160,11);

//		floodfill(200,275+80,LIGHTGREEN);
		floodfill(250,275+80,LIGHTGREEN);
//		floodfill(150,275+80,LIGHTGREEN);
		floodfill(400,300,LIGHTGREEN);
		floodfill(460,250,LIGHTGREEN);
		floodfill(490,180,LIGHTGREEN);
		floodfill(512,202,LIGHTGREEN);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		outtextxy(394-150,272+80,"15");
		outtextxy(394,297,"15");
		outtextxy(454,247,"25");
		outtextxy(484,177,"75");
		outtextxy(506,199,"50");
		outtextxy(559,157,"10");
	       }
	       if(q==3)
	       {
		circle(400,300,8);
		circle(400,300,11);
		circle(460,250,8);
		circle(460,250,11);
		circle(490,180,8);
		circle(490,180,11);
		circle(512,202,8);
		circle(512,202,11);
		circle(565,160,8);
		circle(565,160,11);

		floodfill(400,300,LIGHTGREEN);
		floodfill(460,250,LIGHTGREEN);
		floodfill(490,180,LIGHTGREEN);
		floodfill(512,202,LIGHTGREEN);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		outtextxy(394,297,"15");
		outtextxy(454,247,"25");
		outtextxy(484,177,"75");
		outtextxy(506,199,"50");
		outtextxy(559,157,"10");
	       }
	       if(q==4)
	       {
		circle(460,250,8);
		circle(460,250,11);
		circle(490,180,8);
		circle(490,180,11);
		circle(512,202,8);
		circle(512,202,11);
		circle(565,160,8);
		circle(565,160,11);
		floodfill(460,250,LIGHTGREEN);
		floodfill(490,180,LIGHTGREEN);
		floodfill(512,202,LIGHTGREEN);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		outtextxy(454,247,"25");
		outtextxy(484,177,"75");
		outtextxy(506,199,"50");
		outtextxy(559,157,"10");
	       }
		if(q==5)
	       {
		circle(490,180,8);
		circle(490,180,11);
		circle(512,202,8);
		circle(512,202,11);
		circle(565,160,8);
		circle(565,160,11);
		floodfill(490,180,LIGHTGREEN);
		floodfill(512,202,LIGHTGREEN);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		outtextxy(484,177,"75");
		outtextxy(506,199,"50");
		outtextxy(559,157,"10");
	       }
		if(q==7)
	       {
		circle(565,160,8);
		circle(565,160,11);
		floodfill(565,160,LIGHTGREEN);
		setcolor(BLUE);
		outtextxy(559,157,"10");
	       }
		if(q==8)
	       {
		setcolor(BLUE);
	       }


     /*	   for (i = 0; i < 10; i++)
      /*	 {
		whitePixel(WHITE);
		twinkle(BLACK);
		delay(100);
		whitePixel(BLACK);
		twinkle(WHITE);
		delay(100);

	} */
}
void cscreen2()
{       int i;

	cleardevice();
	head=NULL;
	head2=NULL;
	setcolor(WHITE);

	for(i=0;i<720;i++)
	{
		putpixel(i,380-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)),WHITE);
		head=insert(head,i,380-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)));
		line(i,395-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)),i,380-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)));
		delay(0);
	}
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(300,getmaxy(),WHITE);
	head2=nodefrball(head,head2);

}
void screen2(int q)
{      	int i;
	cleardevice();
	//head=NULL;
	//head2=NULL;
	setcolor(WHITE);
	for(i=0;i<720;i++)
	{
		putpixel(i,380-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)),WHITE);
	  //	head=insert(head,i,380-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)));
		line(i,395-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)),i,380-((sin((3.14/180)*i)*(5*3.14))/((3.14/180)*i)*(5*3.14)));

	       //	delay(0);
	}
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(300,getmaxy(),WHITE);

     //	head2=nodefrball(head,head2);
	setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
		if(q==0)
	{
	circle(60,275,11);
	circle(60,275,8);
		circle(140,305,11);
		circle(140,305,8);
	circle(170,355,11);
	circle(170,355,8);
		circle(210,330,11);
		circle(210,330,8);
	circle(250,275,11);
	circle(250,275,8);
		circle(300,270,11);
		circle(300,270,8);
	circle(395,320,11);
	circle(395,320,8);
		circle(420,280,11);
		circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
		circle(550,350,8);
	circle(600,275,11);
	circle(600,275,8);
	circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
		circle(550,275+40,8);
	circle(600,275+40,11);
	circle(600,275+40,8);
		circle(550,275+80,11);
		circle(550,275+80,8);
	circle(600,275+80,11);
	circle(600,275+80,8);
				floodfill(550,275+40,LIGHTGREEN);
			floodfill(600,275+40,LIGHTGREEN);
			floodfill(500,275+40,LIGHTGREEN);
			floodfill(550,275+80,LIGHTGREEN);
			floodfill(600,275+80,LIGHTGREEN);

			floodfill(550,350,LIGHTGREEN);
			floodfill(600,275,LIGHTGREEN);
			floodfill(500,305,LIGHTGREEN);
			floodfill(420,280,LIGHTGREEN);
			floodfill(395,320,LIGHTGREEN);
			floodfill(300,270,LIGHTGREEN);
			floodfill(170,355,LIGHTGREEN);
			floodfill(60,275,LIGHTGREEN);
			floodfill(140,305,LIGHTGREEN);
			floodfill(210,330,LIGHTGREEN);
			floodfill(250,275,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(54,272,"20");
	outtextxy(134,302,"20");
	outtextxy(164,352,"20");
	outtextxy(204,327,"20");
	outtextxy(244,272,"20");
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");

	}
		if(q==1)
	{
		circle(140,305,11);
		circle(140,305,8);
	circle(170,355,11);
	circle(170,355,8);
		circle(210,330,11);
		circle(210,330,8);
	circle(250,275,11);
	circle(250,275,8);
		circle(300,270,11);
		circle(300,270,8);
	circle(395,320,11);
	circle(395,320,8);
		circle(420,280,11);
		circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
		circle(550,350,8);
	circle(600,275,11);
	circle(600,275,8);
			circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
		circle(550,275+40,8);
	circle(600,275+40,11);
	circle(600,275+40,8);
		circle(550,275+80,11);
		circle(550,275+80,8);
	circle(600,275+80,11);
	circle(600,275+80,8);
				floodfill(550,275+40,LIGHTGREEN);
			floodfill(600,275+40,LIGHTGREEN);
			floodfill(500,275+40,LIGHTGREEN);
			floodfill(550,275+80,LIGHTGREEN);
			floodfill(600,275+80,LIGHTGREEN);

			floodfill(550,350,LIGHTGREEN);
			floodfill(600,275,LIGHTGREEN);
			floodfill(500,305,LIGHTGREEN);
			floodfill(420,280,LIGHTGREEN);
			floodfill(395,320,LIGHTGREEN);
			floodfill(300,270,LIGHTGREEN);
			floodfill(170,355,LIGHTGREEN);
			floodfill(140,305,LIGHTGREEN);
			floodfill(210,330,LIGHTGREEN);
			floodfill(250,275,LIGHTGREEN);
	setcolor(BLUE);
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");
	outtextxy(134,302,"20");
	outtextxy(164,352,"20");
	outtextxy(204,327,"20");
	outtextxy(244,272,"20");
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
	}
		if(q==2)
	{
	circle(170,355,11);
	circle(170,355,8);
		circle(210,330,11);
		circle(210,330,8);
	circle(250,275,11);
	circle(250,275,8);
		circle(300,270,11);
		circle(300,270,8);
	circle(395,320,11);
	circle(395,320,8);
		circle(420,280,11);
		circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
		circle(550,350,8);
	circle(600,275,11);
	circle(600,275,8);
	circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
		circle(550,275+40,8);
	circle(600,275+40,11);
	circle(600,275+40,8);
		circle(550,275+80,11);
		circle(550,275+80,8);
	circle(600,275+80,11);
	circle(600,275+80,8);
				floodfill(550,275+40,LIGHTGREEN);
			floodfill(600,275+40,LIGHTGREEN);
			floodfill(500,275+40,LIGHTGREEN);
			floodfill(550,275+80,LIGHTGREEN);
			floodfill(600,275+80,LIGHTGREEN);

			floodfill(550,350,LIGHTGREEN);
			floodfill(600,275,LIGHTGREEN);
			floodfill(500,305,LIGHTGREEN);
			floodfill(420,280,LIGHTGREEN);
			floodfill(395,320,LIGHTGREEN);
			floodfill(300,270,LIGHTGREEN);
			floodfill(170,355,LIGHTGREEN);
			floodfill(210,330,LIGHTGREEN);
			floodfill(250,275,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(164,352,"20");
	outtextxy(204,327,"20");
	outtextxy(244,272,"20");
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");

	}
		if(q==3)
	{
		circle(210,330,11);
		circle(210,330,8);
	circle(250,275,11);
	circle(250,275,8);
		circle(300,270,11);
		circle(300,270,8);
	circle(395,320,11);
	circle(395,320,8);
		circle(420,280,11);
		circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
		circle(550,350,8);
	circle(600,275,11);
	circle(600,275,8);
	circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
		circle(550,275+40,8);
	circle(600,275+40,11);
	circle(600,275+40,8);
		circle(550,275+80,11);
		circle(550,275+80,8);
	circle(600,275+80,11);
	circle(600,275+80,8);
				floodfill(550,275+40,LIGHTGREEN);
			floodfill(600,275+40,LIGHTGREEN);
			floodfill(500,275+40,LIGHTGREEN);
			floodfill(550,275+80,LIGHTGREEN);
			floodfill(600,275+80,LIGHTGREEN);

			floodfill(550,350,LIGHTGREEN);
			floodfill(600,275,LIGHTGREEN);
			floodfill(500,305,LIGHTGREEN);
			floodfill(420,280,LIGHTGREEN);
			floodfill(395,320,LIGHTGREEN);
			floodfill(300,270,LIGHTGREEN);
			floodfill(210,330,LIGHTGREEN);
			floodfill(250,275,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(204,327,"20");
	outtextxy(244,272,"20");
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");

	}
		if(q==4)
	{
	circle(250,275,11);
	circle(250,275,8);
		circle(300,270,11);
		circle(300,270,8);
	circle(395,320,11);
	circle(395,320,8);
		circle(420,280,11);
		circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
		circle(550,350,8);
	circle(600,275,11);
	circle(600,275,8);
	circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
		circle(550,275+40,8);
	circle(600,275+40,11);
	circle(600,275+40,8);
		circle(550,275+80,11);
		circle(550,275+80,8);
	circle(600,275+80,11);
	circle(600,275+80,8);
				floodfill(550,275+40,LIGHTGREEN);
			floodfill(600,275+40,LIGHTGREEN);
			floodfill(500,275+40,LIGHTGREEN);
			floodfill(550,275+80,LIGHTGREEN);
			floodfill(600,275+80,LIGHTGREEN);

			floodfill(550,350,LIGHTGREEN);
			floodfill(600,275,LIGHTGREEN);
			floodfill(500,305,LIGHTGREEN);
			floodfill(420,280,LIGHTGREEN);
			floodfill(395,320,LIGHTGREEN);
			floodfill(300,270,LIGHTGREEN);
			floodfill(250,275,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(244,272,"20");
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");

	}
		if(q==5)
	{
		circle(300,270,11);
		circle(300,270,8);
	circle(395,320,11);
	circle(395,320,8);
		circle(420,280,11);
		circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
		circle(550,350,8);
	circle(600,275,11);
	circle(600,275,8);
	circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
		circle(550,275+40,8);
	circle(600,275+40,11);
	circle(600,275+40,8);
		circle(550,275+80,11);
		circle(550,275+80,8);
	circle(600,275+80,11);
	circle(600,275+80,8);
				floodfill(550,275+40,LIGHTGREEN);
			floodfill(600,275+40,LIGHTGREEN);
			floodfill(500,275+40,LIGHTGREEN);
			floodfill(550,275+80,LIGHTGREEN);
			floodfill(600,275+80,LIGHTGREEN);

			floodfill(550,350,LIGHTGREEN);
			floodfill(600,275,LIGHTGREEN);
			floodfill(500,305,LIGHTGREEN);
			floodfill(420,280,LIGHTGREEN);
			floodfill(395,320,LIGHTGREEN);
			floodfill(300,270,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");

	}
		if(q==6)
	{
	circle(395,320,11);
	circle(395,320,8);
		circle(420,280,11);
		circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
		circle(550,350,8);
	circle(600,275,11);
	circle(600,275,8);
	circle(500,275+40,11);
	circle(500,275+40,8);
		circle(550,275+40,11);
		circle(550,275+40,8);
	circle(600,275+40,11);
	circle(600,275+40,8);
		circle(550,275+80,11);
		circle(550,275+80,8);
	circle(600,275+80,11);
	circle(600,275+80,8);

				floodfill(550,275+40,LIGHTGREEN);
			floodfill(600,275+40,LIGHTGREEN);
			floodfill(500,275+40,LIGHTGREEN);
			floodfill(550,275+80,LIGHTGREEN);
			floodfill(600,275+80,LIGHTGREEN);
		floodfill(550,350,LIGHTGREEN);
			floodfill(600,275,LIGHTGREEN);
			floodfill(500,305,LIGHTGREEN);
			floodfill(420,280,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(244,272,"20");
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
		outtextxy(494,272+40,"20");
	outtextxy(544,272+40,"20");
	outtextxy(594,272+40,"20");
	outtextxy(544,272+80,"20");
	outtextxy(594,272+80,"20");
}

}
void cscreen3()
{         //cleardevice();
int a, j, midx, midy, fq,x1, y1, x2, y2,k=50;
	int tmpx1, tmpy1, tmpx2, tmpy2;
	long double x,y;
	float i=0.0;
	x = 0;
	fq = 2;
	cleardevice();
//	flushall();
	head=NULL;
	head2=NULL;
	setcolor(WHITE);

	/* drawing the moutain using sine wave */
	while (x <= 638)
	{
		y = k * cos((3.14 * fq * x) / 180);
		y = y + getmaxy() / 2 + 100;
		putpixel(x, y, 15);
		head=insert(head,x,y);
		line(x, y, x, y - 12);
		line(x, y, x, y + 12);

		x = x + 1;
	}
		traversal(head);
		head2=nodefrball(head,head2);
		i=0;
		circle(7-i,396+i,10);
		circle(23-i,455+i,10);
		circle(79+i,380-i,15);
		circle(115-i,445+i,15);
	       //	circle(160-i,320+i,10);
		circle(200-i,390+i,14);
			circle(307-i,396+i,10);
		circle(323-i,455+i,13);
	       //	circle(294+i,331-i,15);
		circle(415-i,445+i,15);
	       //	circle(460-i,340+i,13);
		circle(500-i,390+i,14);
		circle(190-i,473+i,14);
		circle(530+i,470-i,13);
		circle(585+i,420-i,14);


	/* color the mountain with white(snow)*/
	setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(2, getmaxy(), WHITE);

	/* draw the moon*/
	x = getmaxx() - 50;
	y = 40;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);

	setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);

	/* snowfall   */
	for (i = 0; i < 10; i++)
	 {
		whitePixel(WHITE);
		twinkle(BLACK);
		delay(100);
		whitePixel(BLACK);
		twinkle(WHITE);
		delay(100);
		}

	whitePixel(WHITE);
}
void screen3()
{
	   // cleardevice();
	    int a, j, midx, midy,fq, x1, y1, x2, y2;
	int tmpx1, tmpy1, tmpx2, tmpy2,k=50;
	float i=0.0;
	long double x,y;
	x = 0;
	fq = 2;
	//head=NULL;
       //	head2=NULL;
       cleardevice();
	setcolor(WHITE);

	/* drawing the moutain using sine wave*/
	while (x <= getmaxx())
	{
		y = k * cos((3.14 * fq * x) / 180);
		y = y + getmaxy() / 2 + 100;
		putpixel(x, y, 15);
	 //	head=insert(head,x,y);
		line(x, y, x, y - 12);
		line(x, y, x, y + 12);

		x = x + 1;
		}
	       //	for(i=0;i<4;i=i+0.01)
	       i=0;
		circle(7-i,396+i,10);
		circle(23-i,455+i,10);
		circle(79+i,380-i,15);
		circle(115-i,445+i,15);
	       //	circle(160-i,320+i,10);
		circle(200-i,390+i,14);
			circle(307-i,396+i,10);
		circle(323-i,455+i,13);
	       //	circle(294+i,331-i,15);
		circle(415-i,445+i,15);
	       //	circle(460-i,340+i,13);
		circle(500-i,390+i,14);
		circle(190-i,473+i,14);
		circle(530+i,470-i,13);
		circle(585+i,420-i,14);


	/* color the mountain with white(snow)  */
	setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(2, getmaxy(), WHITE);

	/* draw the moon           */
	x = getmaxx() - 50;
	y = 40;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);

		setcolor(LIGHTGREEN);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	circle(60,275,11);
	circle(60,275,8);
	circle(140,305,11);
	circle(140,305,8);
	circle(170,355,11);
	circle(170,355,8);
	circle(210,330,11);
	circle(210,330,8);
	circle(250,275,11);
	circle(250,275,8);
	circle(300,270,11);
	circle(300,270,8);
	circle(395,320,11);
	circle(395,320,8);
	circle(420,280,11);
	circle(420,280,8);
	circle(500,305,11);
	circle(500,305,8);
		circle(550,350,11);
	circle(550,350,8);
		circle(600,275,11);
		circle(600,275,8);
			floodfill(550,350,LIGHTGREEN);
				floodfill(600,275,LIGHTGREEN);
	floodfill(500,305,LIGHTGREEN);
	floodfill(420,280,LIGHTGREEN);
	floodfill(395,320,LIGHTGREEN);
	floodfill(300,270,LIGHTGREEN);
	floodfill(170,355,LIGHTGREEN);
	floodfill(60,275,LIGHTGREEN);
	floodfill(140,305,LIGHTGREEN);
	floodfill(210,330,LIGHTGREEN);
	floodfill(250,275,LIGHTGREEN);
	setcolor(BLUE);
	outtextxy(54,272,"20");
	outtextxy(134,302,"20");
	outtextxy(164,352,"20");
	outtextxy(204,327,"20");
	outtextxy(244,272,"20");
	outtextxy(294,267,"20");
	outtextxy(389,317,"20");
	outtextxy(414,277,"20");
	outtextxy(494,302,"20");
	outtextxy(544,347,"20");
	outtextxy(594,272,"20");
}
void cscreen4()
{
	float x,y,i;
	int amp,s=0;
	float fq;
	char c;
	cleardevice();
	head=NULL;
	head2=NULL;
	for(i=195;i<400;i++)
	{
		x=((3.14/180)*i)*(25*3.14);
		y=380-((sin(x)/x));
		putpixel(i,y,WHITE);
		head=insert(head,i,y);
		line(i,y+9,i,y);
	}
	amp=150 ;
	fq=0.35  ;
	for(i=-10;i<200;i++)
	{
		y = amp * sin((3.14 * fq * i) / 180);
		y = y + getmaxy() / 2 + 5;
		putpixel(i-5, y-5, 15);
		head=insert(head,i,y);
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
		head=insert(head,i,y);
		line(i-5,y+40,i-5,y+45);
		line(i-5,y+50,i-5,y+45);
	}
	for(i=495;i<650;i++)
	{
		x=((3.14/180)*i)*(25*3.14);
		y=380-((sin(x)/x))-80;
		putpixel(i-5,y,WHITE);
		head=insert(head,i,y);
		line(i-5,y+12,i-5,y);

	}

	line(i-5,y+45,640,y+45);

	head2=nodefrball(head2,head);

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
		twinkle(BLACK);
		delay(100);
		whitePixel(BLACK);
		twinkle(WHITE);
		delay(100);
		}

}
void screen4()
{
	float x,y,i;
	int amp,s=0;
	float fq;
	char c;

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
		twinkle(BLACK);
		delay(100);
		whitePixel(BLACK);
		twinkle(WHITE);
		delay(100);
		}

}
void cscreen5()
{
	int j,k,xasp,yasp;
	float x,y,i;
	int amp;
	float fq;
	cleardevice();
	head=NULL;
	head2=NULL;
	for(i=0;i<115;i++)
	{
		x=(((3.14/180)*i)*(25*3.14));
		y=(380-((sin(x)/x)))-85;
		putpixel(i+0,y,WHITE);
		head=insert(head,i,y);
		line(i,y+10,i,y);
	}
	head=insert(head,115,295);
	for(i=0;i<8;i=i+0.01)
	{line(115+i,295,115+i,480);
	}
	head=insert(head,115,480);
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
		head=insert(head,i,y);
		line(i,y+10,i,y);
	//  floodfill(100,320,LIGHTGRAY);
	}
	head=insert(head,510,295);
	for(i=0;i<8;i=i+0.01)
	{
		line(510+i,295,510+i,480);
	}
		head=insert(head,510,480);

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

	head2=nodefrball(head2,head);
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
		twinkle(BLACK);
		delay(100);
		whitePixel(BLACK);
		twinkle(WHITE);
		delay(100);
		}

}
void screen5()
{
	int j,k,xasp,yasp;
	float x,y,i;
	int amp;
	float fq;

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
		twinkle(BLACK);
		delay(100);
		whitePixel(BLACK);
		twinkle(WHITE);
		delay(100);
		}

}

