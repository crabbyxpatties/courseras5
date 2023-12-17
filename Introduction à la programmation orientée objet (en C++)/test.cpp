#include <iostream>
using namespace std;

class Rect {
private:
    double width, height;
public:
    double getWidth() const { ... }
    double getHeight() const { ... }
};

class ColoredRect : public Rect {
protected:
    int color;
    void init();
public:
    double getSurface() const { ... }
    int getColor() const { ... }
};
int main( ... )
{

Rect r; r.init();


ColoredRect cr; cr.init();


ColoredRect cr; cr.getWidth();


ColoredRect cr; cr.width;


ColoredRect cr; cr.getColor();


ColoredRect cr; cr.getSurface();


ColoredRect cr; cr.getHeight();


Rect r; r.getSurface();

 return 0; 
}