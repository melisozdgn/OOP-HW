#include <iostream>
using namespace std;

class Shape {
	
public:
	
    virtual string getName() const {
        return "Shape class";  
    }

    virtual void calcArea() const {
        cout << "Area not calculated in this func " << endl;  
    }

    virtual void calcPerimeter() const {
        cout << "Perimeter not calculated in this func " << endl;  
    }
};

class Circle : public Shape {
	
private:
	
    string name = "Circle";  
    double radius;  

public:
	
    string getName() const override {
    	
        return name;  
    }

    void setRadius(double r) {
    	
        radius = r;  
    }

    void calcArea() const override {
    	
        double area = 3.14 * radius * radius;  
        cout << "Area of the circle is " << area << endl;
    }

    void calcPerimeter() const override {
    	
        double perimeter = 2 * 3.14 * radius;  
        cout << "Perimeter of the circle is " << perimeter << endl;
    }
};

class Rectangle : public Shape {
	
private:
	
    string name = "Rectangle";  
    double side1, side2;  

public:
	
    string getName() const override {
    	
        return name;  
    }

    void setSides(double s1, double s2) {
    	
        side1 = s1; 
        side2 = s2;  
    }

    void calcArea() const override {
    	
        double area = side1 * side2;  
        cout << "Area of the rectangle is " << area << endl;
    }

    void calcPerimeter() const override {
    	
        double perimeter = 2 * (side1 + side2);  
        cout << "Perimeter of the rectangle is " << perimeter << endl;
    }
};

void chooseCalc(Shape& shape) {
	
    char choice;  
    cout << "Would you like to calculate area or perimeter (a:area, p:perimeter) for " << shape.getName()<< endl;
    cin >> choice;

    try {
    	
        if (choice == 'a') {   
            shape.calcArea();  
        } else if (choice == 'p') { 
            shape.calcPerimeter();  
        } else {
            throw choice;  
        }
    
	} catch (char invalidChoice) {
		
        cout << invalidChoice << " is invalid!. Please enter a for area and p for perimeter" << endl;
    } 
}

int main() {
	
    Circle circle;
    
    circle.setRadius(5.0);  

    Rectangle rectangle;
    
    rectangle.setSides(4.0, 5.0);  

    Shape* shape1 = &circle;  
    
    Shape* shape2 = &rectangle; 
	 
    chooseCalc(*shape1);  
    
    chooseCalc(*shape2);  

    return 0;
}

