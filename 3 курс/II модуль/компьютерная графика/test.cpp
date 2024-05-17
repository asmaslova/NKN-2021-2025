#include "graphics.h"
#include <stdlib.h>
#include <time.h>
/*int main(){
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");

    srand(time(NULL));
    for(int i=0; i < 1000; i++)
        line(rand()%1024,rand()%800,rand()%1024,rand()%800);
    getch();
    closegraph();
    }
*/
int main(){
    float xA, yA, xB, yB, xC, yC, xD, yD, xxA, yyA, xxB, yyB;
    float xxC, yyC, xxD, yyD, p, q;
    
    p=0.99; q=1.0-p;
    xA=2.0*100; xB=8.0*100; xC=8.0*100; xD=2.0*100;
    yA=0.5*100; yB=0.5*100; yC=6.5*100; yD=6.5*100;
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");
    for(int i=0; i<1000; i++){
        moveto(xA, yA);
        lineto(xB,yB); lineto(xC,yC); lineto(xD,yD); lineto(xA,yA);
        xxA=p*xA+q*xB; yyA=p*yA+q*yB; xxB=p*xB+q*xC; yyB=p*yB+q*yC;
        xxC=p*xC+q*xD; yyC=p*yC+q*yD; xxD=p*xD+q*xA; yyD=p*yD+q*yA;
        xA=xxA; xB=xxB; xC=xxC; xD=xxD;
        yA=yyA; yB=yyB; yC=yyC; yD=yyD;
    }
    getch();
    closegraph();
    
}




