#include <iostream>
using namespace std;

class Shape {
  protected:
    string name;
  public:
    Shape(string name="sem nome") { this->name = name; }
    void display() {
      cout << "Shape: " << this->name << endl;
    }
    void something() {
      cout << "implementando em shape" << endl;
    }
    // virtual void something() = 0; // virtual pura -> abstract
};

class Rectangle: public Shape {
  public:
    Rectangle(string name="sem nome") : Shape(name) {}
    virtual void display() { // "virtual" para indicar override
      Shape::display();
      cout << "Retângulo: " << this->name << endl;
    }
    virtual void something() {
      cout << "Implementando em retângulo" << endl;
    }
};

int main() {
  // alocação automática em stack
  Shape shape1 = Shape("ret1"); // polimorfismo
  shape1.display();
  shape1.something();
  // alocação manual em heap
  Shape* shape2 = new Rectangle("ret2");
  shape2->display();
  shape2->something();
  //delete shape2;
  Rectangle shape3 = Rectangle("ret3"); // polimorfismo
  shape3.display();
  shape3.something();
}