/*Implement Bouncing Ball Animation.*/


#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define f(x) (3.14/180)*x
#define fy(x) (getmaxy()-x)
void firstHalf(int ,int );
void middleCircle(int,int);

int main()
{
	initwindow(800,560);
	int flag=0,radius;
	printf("\n\n\nEnter the radius of the ball:");
	scanf("%d",&radius);
	firstHalf(flag,radius);
	getch();
	return 0;
}
void firstHalf(int flag,int radius)
{
	int orgX=0,orgY=0;
	int x1,x2,y1,y2,angle;
	int org1X=getmaxx(),org1Y=0;
	int x11,x12,y11,y12;
	if(flag==0)
	{
		x1=x2=radius;y1=y2=getmaxx()/4;angle=0;
		x2=orgX+(x1-orgX)*cos(f(-angle))-(y1-orgY)*sin(f(-angle));
		y2=orgY+(x1-orgX)*sin(f(-angle))+(y1-orgY)*cos(f(-angle));
		x11=x12=getmaxx()-radius;y11=y12=getmaxx()/4;
		x12=org1X+(x11-org1X)*cos(f(angle))-(y11-org1Y)*sin(f(angle));
		y12=org1Y+(x11-org1X)*sin(f(angle))+(y11-org1Y)*cos(f(angle));
		while(y2-radius>=0 && y12-radius>=0)
		{
			x2=orgX+(x1-orgX)*cos(f(-angle))-(y1-orgY)*sin(f(-angle));
			y2=orgY+(x1-orgX)*sin(f(-angle))+(y1-orgY)*cos(f(-angle));
			setfillstyle(SOLID_FILL,RED);
            circle(x2,fy(y2),radius);
            floodfill(x2+1,fy(y2),WHITE);

            x12=org1X+(x11-org1X)*cos(f(angle))-(y11-org1Y)*sin(f(angle));
			y12=org1Y+(x11-org1X)*sin(f(angle))+(y11-org1Y)*cos(f(angle));
			setfillstyle(SOLID_FILL,GREEN);
            circle(x12,fy(y12),radius);
            floodfill(x12+1,fy(y12),WHITE);
            angle++;
            delay(10);
            cleardevice();
		}
		
		middleCircle(flag,radius);	
	}
	if(flag==1)
	{
		x1=x2=getmaxx()/4;y1=y2=radius;angle=0;
		x2=orgX+(x1-orgX)*cos(f(angle))-(y1-orgY)*sin(f(angle));
		y2=orgY+(x1-orgX)*sin(f(angle))+(y1-orgY)*cos(f(angle));
		x11=x12=getmaxx()-getmaxx()/4;y11=y12=radius;
		x12=org1X+(x11-org1X)*cos(f(-angle))-(y11-org1Y)*sin(f(-angle));
		y12=org1Y+(x11-org1X)*sin(f(-angle))+(y11-org1Y)*cos(f(-angle));
		while(x2-radius>=0 && x12+radius<=getmaxx())
		{
			x2=orgX+(x1-orgX)*cos(f(angle))-(y1-orgY)*sin(f(angle));
			y2=orgY+(x1-orgX)*sin(f(angle))+(y1-orgY)*cos(f(angle));
			setfillstyle(SOLID_FILL,RED);
            circle(x2,fy(y2),radius);
            floodfill(x2+1,fy(y2),WHITE);
            
            x12=org1X+(x11-org1X)*cos(f(-angle))-(y11-org1Y)*sin(f(-angle));
			y12=org1Y+(x11-org1X)*sin(f(-angle))+(y11-org1Y)*cos(f(-angle));
			setfillstyle(SOLID_FILL,GREEN);
            circle(x12,fy(y12),radius);
            floodfill(x12+1,fy(y12),WHITE);
            angle++;
            delay(10);
            cleardevice();
		}
		flag=0;
		firstHalf(flag,radius);		
	}
}
void middleCircle(int flag, int radius)
{
	int orgX=getmaxx()/2, orgY=0;
	int x1,x2,y1,y2,angle,x11,x12,y11,y12;

		x1=x2=getmaxx()/4;y1=y2=radius;angle=0;
		x2=orgX+(x1-orgX)*cos(f(-angle))-(y1-orgY)*sin(f(-angle));
		y2=orgY+(x1-orgX)*sin(f(-angle))+(y1-orgY)*cos(f(-angle));
		x11=x12=getmaxx()-getmaxx()/4;y11=y12=radius;
		x12=orgX+(x11-orgX)*cos(f(angle))-(y11-orgY)*sin(f(angle));
		y12=orgY+(x11-orgX)*sin(f(angle))+(y11-orgY)*cos(f(angle));
		while(x12-x2>2*radius)
		{
			x2=orgX+(x1-orgX)*cos(f(-angle))-(y1-orgY)*sin(f(-angle));
			y2=orgY+(x1-orgX)*sin(f(-angle))+(y1-orgY)*cos(f(-angle));
			setfillstyle(SOLID_FILL,RED);
            circle(x2,fy(y2),radius);
            floodfill(x2+1,fy(y2),WHITE);
            
            x12=orgX+(x11-orgX)*cos(f(angle))-(y11-orgY)*sin(f(angle));
			y12=orgY+(x11-orgX)*sin(f(angle))+(y11-orgY)*cos(f(angle));
			setfillstyle(SOLID_FILL,GREEN);
            circle(x12,fy(y12),radius);
            floodfill(x12+1,fy(y12),WHITE);
            angle++;
            delay(10);
            cleardevice();
		}
		
	flag=0;
	x1=x2;y1=y2;x11=x12;y11=y12;angle=0;
	x2=orgX+(x1-orgX)*cos(f(angle))-(y1-orgY)*sin(f(angle));
	y2=orgY+(x1-orgX)*sin(f(angle))+(y1-orgY)*cos(f(angle));
	x12=orgX+(x11-orgX)*cos(f(-angle))-(y11-orgY)*sin(f(-angle));
	y12=orgY+(x11-orgX)*sin(f(-angle))+(y11-orgY)*cos(f(-angle));
	if(flag==0)
	{
	
		while(y2-radius>=0 && y12-radius>=0)
		{
			x2=orgX+(x1-orgX)*cos(f(angle))-(y1-orgY)*sin(f(angle));
			y2=orgY+(x1-orgX)*sin(f(angle))+(y1-orgY)*cos(f(angle));
			setfillstyle(SOLID_FILL,RED);
            circle(x2,fy(y2),radius);
            floodfill(x2+1,fy(y2),WHITE);
            x12=orgX+(x11-orgX)*cos(f(-angle))-(y11-orgY)*sin(f(-angle));
			y12=orgY+(x11-orgX)*sin(f(-angle))+(y11-orgY)*cos(f(-angle));
			setfillstyle(SOLID_FILL,GREEN);
            circle(x12,fy(y12),radius);
            floodfill(x12+1,fy(y12),WHITE);
            angle++;
            delay(10);
            cleardevice();
		}
	}
		flag=1;
		firstHalf(flag,radius);
	
}

