#include <iostream>

using namespace std;

class Shape {
    public:
        virtual void draw() = 0;
};

class Rectangle: public Shape {
    public:
        void draw() { cout << "Retângulo 1\n"; }
        void draw2() { cout << "Retângulo 2\n"; }
};

class Square: public Rectangle {
    public:
        void draw() { cout << "Quadrado 1\n"; }
        void draw2() { cout << "Quadrado 2\n"; }
};

int main() {
    Shape* s = new Rectangle;
    s->draw(); // vinculação dinâmica
    s = new Square;
    s->draw(); // vinculação dinâmica
    cout << endl;
    
    Rectangle *r = new Rectangle;
    r->draw2(); // vinculação estática
    r = new Square;
    r->draw2(); // vinculação estática
    cout << endl;
    
    Rectangle* t = new Square;
    t->draw();  // vinculação dinâmica
    t->draw2(); // vinculação estática
}