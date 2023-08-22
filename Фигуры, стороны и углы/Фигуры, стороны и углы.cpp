#include <iostream>

class Figure {
private:
    std::string name;

public:
    void set_name(std::string name) { this->name = name; }

    std::string get_name() { return name; }

    void virtual print() = 0;
};

class Triangle : public Figure {
private:
    int a, b, c, A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        set_name("Треугольник");
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }

    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    void print() override {
        std::cout << get_name() << ":" << std::endl;
        std::cout << "Стороны: a = " << get_a() << " d = " << get_b() << " c = " << get_c() << std::endl;
        std::cout << "Углы: A = " << get_A() << " B = " << get_B() << " C = " << get_C() << std::endl;
        std::cout << std::endl;
    }
};

class Right_triangle : public Triangle {
public:
    Right_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        set_name("Прямоугольный треугольник");
    }
};

class Isosceles_riangle : public Triangle {
public:
    Isosceles_riangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        set_name("Равнобедренный треугольник");
    }
};

class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        set_name("Равносторонний треугольник");
    }
};

class Quadrilateral :public Figure {
private:
    int a, b, c, d, A, B, C, D;

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
        set_name("Четырёхугольник");
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }

    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }

    void print() override {
        std::cout << get_name() << ":" << std::endl;
        std::cout << "Стороны: a = " << get_a() << " d = " << get_b() << " c = " << get_c() << " d = " << get_d() << std::endl;
        std::cout << "Углы: A = " << get_A() << " B = " << get_B() << " C = " << get_C() << " D = " << get_D() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B) :Quadrilateral(a,b,a,b,A,B,A,B){
        set_name("Параллелограмм");
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b) : Parallelogram(a,b,90,90){
        set_name("Прямоугольник");
    }
};

class Rhomb : public Parallelogram {
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {
        set_name("Ромб");
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) {
        set_name("Квадрат");
    }
};


void print(Figure* figure) { figure->print(); }


int main() {
    setlocale(LC_ALL, "ru");

    Triangle triangle(10, 20, 30, 40, 50, 60);
    Right_triangle right_triangle(10, 20, 30, 40, 50);
    Isosceles_riangle isosceles_riangle(10, 20, 30, 40);
    Equilateral_triangle equilateral_triangle(10);
    Quadrilateral quadrilateral(10,20,30,40,50,60,70,80);
    Rectangle rectangle(10, 20);
    Square square(10);
    Parallelogram parallelogram(20,30,40,50);
    Rhomb rhomb(10, 20, 30);
    
    print(&triangle);
    print(&right_triangle);
    print(&isosceles_riangle);
    print(&equilateral_triangle);
    print(&quadrilateral);
    print(&rectangle);
    print(&square);
    print(&parallelogram);
    print(&rhomb);
}