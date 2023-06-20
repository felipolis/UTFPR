#include <iostream>

using namespace std;

class Vetor2d {

private:
    float x, y;
public:
    Vetor2d(float x_=0, float y_=0) {
        x = x_;
        y = y_;
    }
    Vetor2d operator+(Vetor2d v) {
        return Vetor2d(x + v.x, y + v.y);
    }
    Vetor2d operator-(Vetor2d v) {
        return Vetor2d(x - v.x, y - v.y);
    }
    Vetor2d operator*(float f) {
        return Vetor2d(x * f, y * f);
    }
    float operator*(Vetor2d v) {
        return (x * v.x + y * v.y);
    }
};

int main(void) {
    Vetor2d v1(2, 4), v2(-2, 14), v3(22, -4), v4(-2, -8), v5;
    float x;
    v5 = v1 + v2 - v3 * 4.0;
    x = v5 * v4;
    cout << "x = " << x << "\n";
}