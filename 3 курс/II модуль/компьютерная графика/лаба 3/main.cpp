#include "graphics.h"
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <stdio.h>

    
using namespace std;
    
class point{
    
     public:
        double x, y, z;
        point(){
            x = 0; y = 0; z = 0;
        }
        point(double a, double b, double c){
            x = a; y = b; z = c;
        }
};
    
class vertex{
    
    public:
        point worldc; 
        point viewc; 
        vertex(){point p(0,0,0); worldc = p;};
        void clvertex(point p) //clvertex(point_of_view p)
        {
            worldc = p;
        }
        ~vertex(){};
        void View_Coord(point worldcoord) 
        {
            double ro = worldcoord.x, teta=worldcoord.y, fi=worldcoord.z;
            viewc.x = -worldc.x * sin(teta) + worldc.y * cos(teta); 
            viewc.y = -worldc.x * cos(fi) * cos(teta) - worldc.y * cos(fi) * sin(teta) + worldc.z * sin(fi); 
            viewc.z = -worldc.x * sin(fi) * cos(teta) - worldc.y * sin(fi) * sin(teta) - worldc.z * cos(fi) + ro;
        }
}; 
    
class edge{
    
    private:
        vertex tmpvertex, fervertex; 
    public:
        edge(){}; 
        void edgech (vertex sv, vertex fv)
        {
            tmpvertex = sv;
            fervertex = fv;
        }
        ~edge(){};
        void drawedge(double d) 
        { 
            d = d/2; 
            double x1 = (int)((d*tmpvertex.viewc.x)/tmpvertex.viewc.z); 
            double y1 = (int)((d*tmpvertex.viewc.y)/tmpvertex.viewc.z);
            double x2 = (int)((d*fervertex.viewc.x)/fervertex.viewc.z);
            double y2 = (int)((d*fervertex.viewc.y)/fervertex.viewc.z);
            line(x1+(getmaxx()/2), y1+(getmaxy()/2), x2+(getmaxx()/2), y2+(getmaxy()/2));
        }
};
    
struct strk{
    public: 
        int a, b;
};
    
class drawingmtd{
    
    private:
        vertex *verts;
        edge *edges;
        strk *strk1;
        point viewpoint;
        bool proff;  // Remove in-class initialization
    public:
        int n, m;
        friend class edge;
        friend class vertex;
    
    // Constructor to initialize proff
    drawingmtd() : proff(false) {}

    void draw()
    {
        for (int i = 0; i < m; i++)
            edges[i].drawedge(viewpoint.x);
    }

    void drawing()
    {
        int c, a, b;
        if (!proff)
        {
            FILE *f;
            f = fopen("data.txt", "r");
            if (f != NULL)
            {
                fscanf(f, "%d", &n);
                verts = new vertex[n];
                for (int i = 0; i < n; i++)
                {
                    fscanf(f, "%d", &a);
                    fscanf(f, "%d", &b);
                    fscanf(f, "%d", &c);
                    point p = point(a*100, b*100, c*100);
                    verts[i].clvertex(p);
                    verts[i].View_Coord(viewpoint);
                    cout<<"a"<<a<<" b"<<b<<" c"<<c;
                }
                fscanf(f, "%d", &m);
                edges = new edge[m];
                strk1 = new strk[m];
                for (int i = 0; i < m; i++)
                {
                    fscanf(f, "%d", &a);
                    fscanf(f, "%d", &b);
                    strk1[i].a = a;
                    strk1[i].b = b;
                    edges[i].edgech(verts[strk1[i].a], verts[strk1[i].b]);
                    cout<<"a"<<a<<" b"<<b;
                }
                proff = true;  // Use true instead of 1
            }
        }
        for (int i = 0; i < n; i++)
            verts[i].View_Coord(viewpoint);
        for (int i = 0; i < m; i++)
            edges[i].edgech(verts[strk1[i].a], verts[strk1[i].b]);
    }

    void setviewpoint(double ro, double teta, double fi)
    {
        viewpoint.x = ro;
        viewpoint.y = teta;
        viewpoint.z = fi;
    }
};

int main()
    {
     double ro=200, teta=90, fi=120;
     int d;
     int gddriver = DETECT, gmode, errorcode;
     initgraph(&gddriver, &gmode, "");
     //line(100,100,200,200);
     drawingmtd cube;
     cube.setviewpoint(ro, teta, fi);
     cube.drawing(); 
     cube.draw();
     /*while (!kbhit())
     {
      cleardevice();
      setbkcolor(0);
      setcolor(WHITE); 
      teta += ((M_PI/27));
      fi += ((M_PI/27));
      //line(100,100,200,200);
      cube.setviewpoint(ro, teta, fi);
      //line(150,100,200,200);
      cube.drawing(); 
      //line(200,100,200,200);
      cube.draw();
      //line(250,100,200,200);
      delay(250);
     }*/
     getch();
     closegraph();
     return 0;
    }
    

/*#include "graphics.h"
#include <time.h>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

# define PI           3.14159265358979323846

const int il = 0;
const int ir = 1280;
const int jd = 0;
const int ju = 720;

bool conv(int x, int xend, bool sign){
    if (sign) return (x <= xend);
    else return (x >= xend);
}

void myline (int x0, int y0, int x1, int y1, int color){
    int xstart;
    int xend;
    int signx;
    bool sign;
    int dx = x1 - x0;
    int error = 0;
    int y = y0;
    int dy = y1 - y0;
    if (dx < 0) {
       //xstart  = x1; xend = x0; signx = -1; sign = false;
       xstart  = x0; xend = x1; signx = -1; sign = false;
    }
    else if (dx > 0) {
         xstart = x0; xend = x1; signx = 1; sign = true;
    }
    else {
        xstart = x0 - 1; xend = x1; signx = 1; error --; sign = true;
    }
    if (dy < 0) {myline (x1, y1, x0, y0, color); return;}
    //conv(x, xend, sign)
    if (dx != 0) putpixel(xstart, y0, color);
    for (int x = xstart + signx; conv(x, xend, sign) ; x += signx){
        error += dy;
        if (error >= dx*signx && y < y1){
        while(error >= dx*signx && y < y1){
            error -= dx*signx;
            y++;
            putpixel(x, y, color);
            }
        }
        else putpixel(x, y, color);
    }
}

class Point{
private:
	double x, y, z;
public:
	void setcoord(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Point(double x, double y, double z){
		setcoord(x,y,z);
	}
	Point(){
		setcoord(0,0,0);
	}
	void print(){
		cout << this->x << " " << this->y << " " << this->z << endl;
	}
	double get(char c){
		if(c=='x') return this->x;
		if(c=='y') return this->y;
		if(c=='z') return this->z;
		return 0;
	}
	Point(Point *p){
		this->x = p->get('x');
		this->y = p->get('y');
		this->z = p->get('z');
	}
	double ro(){
		return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
	}
};

static Point viewpoint(0,0,0);
class Vertex{
private:
	int num;
public:
	int getnum(){
		return num;
	}
	Point *worldcoord, *viewcoord;
	Vertex  *next;
	Vertex(Point *p){
		this->worldcoord = p;
		this->next = NULL;
		this->num = 1;
	};
	void addvertex(Point *p){
		Vertex *tmp = this;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new Vertex(p);
		tmp->next->num = tmp->num+1;
	}
	void printworldcoord(){
		Vertex *tmp = this;
		while(tmp!=NULL){
			cout << tmp->num << ": ";
			tmp->worldcoord->print();
			tmp = tmp->next;
		}
	}
	void printviewcoord(){
		Vertex *tmp = this;
		while(tmp!=NULL){
			tmp->viewcoord->print();
			tmp = tmp->next;
		}
	}
	void setviewcoord(){
		double ST  = sin(viewpoint.get('y'));
		double CT  = cos(viewpoint.get('y'));
		double SF  = sin(viewpoint.get('z'));
		double CF  = cos(viewpoint.get('z'));
		double x = -ST * this->worldcoord->get('x') 
				   +CT * this->worldcoord->get('y');
		double y = -CF * CT * this->worldcoord->get('x') 
				   +CF * ST * this->worldcoord->get('y')
				   +SF * this->worldcoord->get('z');
		double z = -SF * CT * this->worldcoord->get('x') 
				   -SF * ST * this->worldcoord->get('y')
				   -CF * this->worldcoord->get('z')
				   +viewpoint.get('x');
		this->viewcoord = new Point(x, y, z);
	};
	void setviewcoords(){
		Vertex *tmp = this;
		while(tmp!=NULL){
			tmp->printworldcoord();
			tmp->setviewcoord();
			tmp = tmp->next;
		}
	}
};

class Edge{
private:
	Vertex *start; 
	Vertex *finish;
public:
	Vertex *vlist;
	Edge* next;
	void setvertices(int numstart, int numfinish){
		if(numstart > numfinish) swap(numstart, numfinish);
		Vertex *tmp = vlist;
		while(tmp!=NULL && (tmp->getnum() <= numfinish)){
			if(tmp->getnum()==numstart) start = tmp;
			if(tmp->getnum()==numfinish) finish = tmp;
			tmp = tmp->next;
		}
	}
	Edge(Vertex *vlist, int numstart, int numfinish){
		this->vlist = vlist;
		setvertices(numstart, numfinish);
		this->next = NULL;
	}
	void addedge(int numstart, int numfinish){
		Edge *tmp = this;
		while(tmp->next!=NULL) tmp = tmp->next;
		tmp->next = new Edge(vlist, numstart, numfinish);
	}
	void printworld(){
		start->worldcoord->print();
		finish->worldcoord->print();
		cout << endl;
	}
	void drawedge(){
		double x1, y1, x2, y2, i1, j1, i2, j2, xr, xl, yd, yu;
		x1 = start->viewcoord->get('x');
		y1 = start->viewcoord->get('y');
		x2 = finish->viewcoord->get('x');
		y2 = finish->viewcoord->get('y');
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		xr = 16/9;
		xl = -16/9;
		yu = 1;
		yd = -1;
		i1 = ir + (x1-xr) * (il-ir) / (xl-xr);
		j1 = ju + (y1-yu) * (jd-ju) / (yd-yu);
		i2 = ir + (x2-xr) * (il-ir) / (xl-xr);
		j2 = ju + (y2-yu) * (jd-ju) / (yd-yu);
		myline(floor(i1),floor(j1),floor(i2),floor(j2),3);
		cout << floor(i1) << floor(j1) << floor(i2) << floor(j2) << endl << endl;
	};
};

class Surface{
private:
public:
	Edge *elist;
	Vertex *vlist;
	Surface() {}
	void setviewpoint(double r, double teta, double phi) {
    	viewpoint.setcoord(r, teta, phi);
	}
	void load(string filename){
		ifstream fin;
		fin.open("data.txt");
		int n, m;
		fin >> n;
		double x,y,z;
		fin >> x >> y >> z;
		vlist = new Vertex(new Point(x,y,z));
		for(int i=1; i<n; i++){
			fin >> x >> y >> z;
			vlist->addvertex(new Point(x,y,z));
		}
		int numstart, numfinish;
		fin >> m;
		fin >> numstart >> numfinish;
		elist = new Edge(vlist, numstart, numfinish);
		for(int i=1; i<m; i++){
			fin >> numstart >> numfinish;
			elist->addedge(numstart, numfinish);
		}
		this->elist->printworld();
	};
	void drawsurface() {
		this->elist->next->printworld();
  		this->elist->vlist->setviewcoords();
		cout << 1 << endl;
  		Edge *tmp = elist;
  		while(tmp!=NULL){
  			tmp->drawedge();
			tmp = tmp->next;	
		}
	};
};

int main() {
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");
	srand(time(NULL));
	Surface C;
	C.load("data.txt");
	C.setviewpoint(20, PI/3, PI/3);
	C.drawsurface();
	getch();
	delay(5000);
	closegraph();
}








/*#include "graphics.h"
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

class Point // Touxa
{
    private:
        double a;
        double b;
        double c;
    public:
        Point ()
        {
            a = 0;
            b = 0;
            c = 0;
        }
        Point (double d, double e, double f)
        {
            a = d;
            b = e;
            c = f;
        }

    double getA() {return a;}
    double getB() {return b;}
    double getC() {return c;}
    void setA(double A) {a=A;}
    void setB(double B) {b=B;}
    void setC(double C) {c=C;}
};

class Vertex // Bepmyny
{
    public:

        Point l; // Touxa c MMpOBAMM KOODIMHaTaMM BepIMHE
        Point k; // Touxa c BMIOBLMM KOOpIMHaTaMi BepmHET

    int n; // Homep roux

    // Koucrpyxrop
    Vertex(double ro, double teta, double fi, int n = 0)
    {
        Point p(ro, teta, fi);
        l = p;
    }

    Vertex()
    {
        Point p(0,0,0);
        l = p;
    }

    void setViewCoord (Point coor_spher)
    {
        double s1=sin(coor_spher.getB());
        double s2=sin(coor_spher.getC());
        double s3=cos(coor_spher.getB());
        double s4=cos(coor_spher.getC());
        k.setC(l.getA()*(-s1*s4)+l.getB() * (-s1*s2)+l.getC() * (-s3) +coor_spher.getA());
        k.setB(l.getA()*(s3*s4)+l.getB() *(-s3*s2)+l.getC()*s1);
        k.setA(l.getA()*(-s2)+l.getB()*s4);
    }
    
    Vertex *next;
};
 

class Edge {

    public:
        Vertex t;
        Vertex v;

    Edge (Vertex a, Vertex b) // Koncrpyxrop
    {
        t.k.setA(a.k.getA());
        v.k.setA(b.k.getA());
        t.k.setB(a.k.getB());
        v.k.setB(b.k.getB());
        t.k.setC(a.k.getC());
        v.k.setC(b.k.getC());
    }
    void drawEdge (double y_up, double y_down, double x_left, double x_right, double uu, double dd, double ll, double rr, double r2) // Cosamuser rouxu nyammar
    {
        double x,y,x1,yl;
        int xx, yy, xx_1, yy_1;
        
        x=(r2/(2.0*(t.k.getC())))*t.k.getA();
        
        x1=(r2/(2.0*(v.k.getC())))*v.k.getA();
        
        xx=(int)(rr+((x-x_right)*(ll-rr))/(x_left-x_right));
        xx_1=(int)(rr+((x1-x_right)*(11-rr))/(x_left-x_right));
        y=(r2/(2.00*(t.k.getC())))*t.k.getB();
        
        yl=(r2/(2.0*(v.k.getC())))*v.k.getB();
        
        yy=(int)(uu+((y-y_up)*(dd-uu))/(y_down-y_up));
        yy_1=(int)(uu+((yl-y_up)*(dd-uu))/(y_down-y_up));
        
        line (xx, yy, xx_1, yy_1);
        
    }
    Edge *next;
};

class Surface {

    public:
    friend class Edge;    
        Vertex *vv;
        Edge *ee;
        Point vp;
        double y_up,y_down,x_left,x_right,uu,dd,ll,rr;
        int n;

    void file()// Caxrspacu dain
    {
        int x,y,z,w,*m,*ml;
        ifstream f("coords.txt");
        f>>n;
        f>>w;
        vv=new Vertex[w];
        for(int i=0; i<w; i++)
        {
            f>>x; f>>y; f>>z;
            vv[i]=Vertex(x,y,z);
            vv[i].setViewCoord(vp);
        }
        m=new int[2*n];
        for(int i=0; i<2*n;i++) f>>m[i];
        
        ee=new Edge[n];
        for(int i=0;i<n;i++)
            ee[i]=Edge(vv[m[i*2]],vv[m[i*2+1]]);
        
        ml=new int[w*3];
        
        for(int i=0;i<w*3;i++)
            f>>ml[i];
        
        f.close();
    }
    
    // Coepa: ro,tetta, fi
    
    void setViewPoint (double ro, double tetta, double fi)
        {
            vp.setA(ro);
            vp.setB(tetta);
            vp.setC(fi);
            
        }
        
    void drawSurface() // Pucyer no cauTammae xoopmumaTan
    {
        for (int i=0;i<n;i++)
            for(int j=0;j<4;j++)
                if(t[j].flag==1)
                {
                    if((e[i].t==t[j].a||e[i].t==t[j].b||e[i].t==t[j].c)&&(e[i].v==t[j].a||e[i].v==t[j].b||e[i].v==t[j].c))
                    {
                        drawEdge (y_up, y_down,x_left,x_right,uu,dd,ll,rr,vp.getA());
                    }
                }
    }
            
};

 

int main()
{
    int gddriver = DETECT, gmode, errorcode;
    initgraph (&gddriver, &gmode, "");
    
    Surface sss;
    sss.file()
    sss.setViewPoint(10,M_PI/2,1.6);
    sss.drawSurface():
    getch();
    closegraph:
    return 0;
}
        



/*#include "graphics.h"
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;


class Point{
    double x, y, z;
};

class Vertex {

private:
    Point world;
    Point view;

    friend class Edge;
    friend class Surface;
    friend class Triangle;
public:
    Vertex(double x, double y, double z): world{x,y,z}
    {}

    explicit Vertex() : world{0,0,0}
    {}


    void SetViewCoord(Point sphere) {
        double st = sin(sphere.y);
        double ct = cos(sphere.y);
        double sf = sin(sphere.z);
        double cf = cos(sphere.z);

        view.x = world.x*(-sf)+world.y*cf;
        view.y = world.x*(-ct*cf) + world.y*(-ct*sf) + world.z*st;
        view.z = world.x*(-st*cf) + world.y*(-st*sf) + world.z*(-ct) + sphere.x;
    }

    bool operator==(Vertex& v) const {
        return (view.x == v.view.x && view.y == v.view.y && view.z == v.view.z);
    }
};

class Edge {
private:
    Vertex s_vert;
    Vertex f_vert;

    friend class Surface;
    friend class Triangle;
public:
    Edge(Vertex a, Vertex b) {
        s_vert.view = {a.view.x, a.view.y, a.view.z};
        f_vert.view = {b.view.x, b.view.y, b.view.z};
    }

    Edge(Edge& e) {
        s_vert = e.s_vert;
        f_vert = e.f_vert;
    }

    Edge& operator=(Edge e) {
        s_vert = e.s_vert;
        f_vert = e.f_vert;

        return *this;
    }

    void DrawEdge(double yu, double yd, double xl, double xr, double ju, double jd, double il, double ir, double rr) {
        double x,y,x1,y1;
        int i, j, i1, j1;
        x = (rr/(2.0*(s_vert.view.z)))*s_vert.view.x;
        y = (rr/(2.0*(s_vert.view.z)))*s_vert.view.y;
        x1 = (rr/(2.0*(f_vert.view.z)))*f_vert.view.x;
        y1 = (rr/(2.0*(f_vert.view.z)))*f_vert.view.y;

        i = (int)(ir + ((x-xr)*(il-ir))/(xl-xr));
        j = (int)(ju + ((y-yu)*(jd-ju))/(yd-yu));
        i1 = (int)(ir + ((x1-xr)*(il-ir))/(xl-xr));
        j1 = (int)(ju + ((y1-yu)*(jd-ju))/(yd-yu));

        myline(i,j,i1,j1,img,sf::Color::Yellow);
    }

};

class Triangle{
private:
    Vertex x_;
    Vertex y_;
    Vertex z_;
    Vertex n_;
    bool flag_;

    friend class Surface;

    static double Sqr(double x) {
        return x*x;
    }

    void CalcNorm() {
        Vertex v1, v2;
        v1.view.x = x_.view.x - y_.view.x;
        v1.view.y = x_.view.y - y_.view.y;
        v1.view.z = x_.view.z - y_.view.z;

        v1.view.x = y_.view.x - z_.view.x;
        v2.view.y = y_.view.y - z_.view.y;
        v2.view.z = y_.view.z - z_.view.z;

        auto wrki = sqrt(Sqr(v1.view.y * v2.view.z - v1.view.z * v2.view.y) +
                         Sqr(v1.view.z * v2.view.x - v1.view.x * v2.view.z) +
                         Sqr(v1.view.x * v2.view.y - v1.view.y * v2.view.x));

        n_.view.x = (v1.view.y*v2.view.z - v1.view.z*v2.view.y) / wrki;
        n_.view.y = (v1.view.z*v2.view.x - v1.view.x*v2.view.z) / wrki;
        n_.view.z = (v1.view.x*v2.view.y - v1.view.y*v2.view.x) / wrki;
    }

    bool Test(const Edge& e) {

    }


public:
    Triangle(Vertex x, Vertex y, Vertex z) : x_(x), y_(y), z_(z), flag_(false)
    {
        double x1, y1, x2, y2, x3, y3, k;
        x1=x_.view.x;
        y1=x_.view.y;
        x2=y_.view.x;
        y2=y_.view.y;
        x3=z_.view.x;
        y3=z_.view.y;
        k=x1*y2*1+y1*1*x3+1*x2*y3-1*y2*x3-x1*1*y3-y1*x2*1;
        if (k>0) flag_ = true;
    }


};

class Surface {

private:
    friend class Edge;
    std::vector<Edge*> e;
    std::vector<Vertex*> v;
    std::vector<Triangle*> t;
    Point viewpoint;
    double yu, yd, xl, xr, ju, jd, il, ir;
    int n;
public:

    void DrawSurface() {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < t.size(); ++j) {
                    if(t[j]->flag_) {
                        auto f1 = e[i]->s_vert == t[j]->x_ || e[i]->s_vert == t[j]->y_ || e[i]->s_vert == t[j]->z_;
                        auto f2 = e[i]->f_vert == t[j]->x_ || e[i]->f_vert == t[j]->y_ || e[i]->f_vert == t[j]->z_;

                        if(f1 && f2)
                            e[i]->DrawEdge(yu, yd, xl, xr, ju, jd, il, ir, viewpoint.x);
                    }
            }
        }

        /*for(int i = 0; i < n; ++i) {
           e[i]->DrawEdge(yu, yd, xl, xr, ju, jd, il, ir, viewpoint.x);
        }
         /
    }

    void SetViewPoint(Point& p) {
        viewpoint = p;
        yu = -2;
        yd = 2;
        xl = -2;
        xr = 2;
        il = 0;
        ir = 1024;
        ju = 0;
        jd = 1024;
    }

    void Load() {
        int v_num;
        double x, y, z;
        int a, b;
        char ch;
        int tx, ty, tz;
        std::ifstream fin("D:\DevC++_project\test.txt");

        fin >> n >> v_num;

        v.resize(v_num);

        for(int i = 0; i < v_num; ++i) {
            fin >> x >> y >> z;
            v[i] = new Vertex(x, y, z);
            v[i]->SetViewCoord(viewpoint);
        }

        e.reserve(n);
        for(int i = 0; i < n; ++i) {
            fin >> a >> b;
            e.push_back(new Edge(*v[a-1], *v[b-1]));
        }

        t.reserve(8);
        for(int i = 0; i < 8; ++i) {
            fin >> tx >> ty >> tz;
            t.push_back(new Triangle(*v[tx-1], *v[ty-1], *v[tz-1]));
        }

    }
};


int main() {
    img.create(1024, 1024, sf::Color::Black);
    Surface s;
    Point p = {50,M_PI/4,M_PI/4};
    s.SetViewPoint(p);
    s.Load();
    s.DrawSurface();

    img.saveToFile("test.png");

    return 0;
}
*/
