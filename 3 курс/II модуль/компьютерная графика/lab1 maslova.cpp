//Maslova Anastasia, NKNbd-01-21, 1032216455
//Lab1 


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "graphics.h"

void pifagor(double x0, double y0, double a, double n, double fi, double alpha) {
      if(n==0){return;} 
      double l, ll, x1, y1, x2, y2, x3, y3, x4, y4, xx, yy;
               
      n--;
      x1=x0;
      y1=y0;   
      x4=x0+a*cos(fi);
      y4=y0-a*sin(fi);   
      x2=x0-a*sin(fi);
      y2=y0-a*cos(fi);
      x3=x4-a*sin(fi);
      y3=y4-a*cos(fi);
      
      line(x1,y1,x2,y2);
      line(x2,y2,x3,y3);
      line(x3,y3,x4,y4);
      line(x4,y4,x1,y1);
      
      l = a*cos(alpha);
      ll = a*sin(alpha);
      xx=x2+l*sin((M_PI/2)-alpha-fi);
      yy=y2-l*cos((M_PI/2)-alpha-fi);
      line(x2, y2, xx, yy);
      line(xx,yy,x3,y3);
      pifagor(x2,y2, l, n, fi+alpha, alpha);
      pifagor(xx,yy, ll, n, alpha+fi-M_PI/2, alpha);
  }


int main() {
   int gddriver = DETECT, gmode, errorcode;
   initgraph(&gddriver, &gmode, "");
   pifagor(500, 800, 200, 5, 0, M_PI/4);
   pifagor(500, 600, 200, 5, M_PI/2, M_PI/4);
   pifagor(700, 600, 200, 5, M_PI, M_PI/4);
   pifagor(700, 800, 200, 5, 3*M_PI/2, M_PI/4);
   getch();
   closegraph();
   return 0;
}
