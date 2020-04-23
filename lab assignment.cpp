#include<iostream>
using namespace std;
class figure
{
    public:
        virtual ~figure(){}
        virtual void area()=0;

};
class close: public figure
{
    public:
        void showc()
        {
            cout<<"Closed figure"<<endl;
        }
};

class open: public figure
{
    public:
        void show()
        {
            cout<<"Open figure"<<endl;
        }
};

class polygon: public close
{
   float d1,d2,ar;
   public:
       polygon()
       {
           d1=0;
           d2=0;
       }
       friend istream & operator>>(istream & in, polygon & p)
       {
           in>>p.d1;
           in>>p.d2;
       }
       friend ostream & operator<<(ostream & out,const polygon & p)
       {
           out<<p.d1<<endl;
           out<<p.d2<<endl;
       }

       void area()
       {
           ar=d1*d2;
           cout<<"The area of the rectangle is:"<<ar<<endl;
       }
       ~polygon(){}


       void areapen()
       {
           ar=(2.5)*d1*d2;
           cout<<"The area of the pentagon is:"<<ar<<endl;
       }

       void areatri()
       {
           ar=(0.5)*d1*d2;
           cout<<"The area of triangle is:"<<ar<<endl;
       }
};

class ellipse: public close
{
    float maj,mino,areae;
    public:
        ellipse()
        {
            maj=0;
            mino=0;
        }
        friend istream & operator>>(istream & in, ellipse & e)
       {
           in>>e.maj;
           in>>e.mino;
       }
       friend ostream & operator<<(ostream & out,const ellipse & e)
       {
           out<<e.maj<<endl;
           out<<e.mino<<endl;
       }

       void area()
       {
           areae=3.14*maj*mino;
           cout<<"Area of ellipse is:"<<areae<<endl;
       }
       ~ellipse(){}

};

class line: public open
{
    public:
        void showl()
        {
            cout<<"Line"<<endl;
        }
};

class polyline: public open
{
    public:
        void showpl()
        {
            cout<<"Polyline"<<endl;
        }

};
int main()
{ polygon rectangle,triangle,pentagon,p;
    cout<<"CLOSED FIGURES"<<endl;
    cout<<"--------------"<<endl;
    p.showc();
    cout<<"CALCULATING THE AREA OF SOME CLOSED FIGURES"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"RECTANGLE"<<endl;
    cout<<"\n";
    cout<<"Enter the length and width:";
    cin>>rectangle;
    cout<<"Length and width of the rectangle is "<<rectangle;
    figure *f;
    f= &rectangle;
    f-> area();
    cout<<"PENTAGON"<<endl;
    cout<<"\n";
    cout<<"Enter the apothem and sidelength:";
    cin>>pentagon;
    cout<<"Apothem and side length of the pentagon is "<<pentagon;
    pentagon.areapen();
    cout<<"TRIANGLE"<<endl;
    cout<<"\n";
    cout<<"Enter the base and height:";
    cin>>triangle;
    cout<<"Base and height of the triangle is "<<triangle;
    triangle.areatri();
    cout<<"ELLIPSE"<<endl;
    cout<<"\n";
    ellipse e;
    cin>>e;
    cout<<"major and minor axis of the ellipse is "<<e;
    f=&e;
    f->area();
    line *li;
    cout<<"OPEN	FIGURES"<<endl;
    cout<<"------------"<<endl;
    li->show();
    li->showl();
    polyline *pli;
    pli->showpl();
}
