#include <iostream>
using namespace std;

class Vehicle {
public:
    string brand;
    int model;

    void CarData() {
        cout << "Enter CarName  ";
        cin >> brand;
        cout << "Enter Model Year ";
        cin >> model;
    }
};

class Engine : public Vehicle {
public:
    int horsepower, cylinders;

    void CarEngineData() {
        cout << "Enter Horsepower like (1000/100000) ";
        cin >> horsepower;

        cout << "Enter Number of Cylinders: ";
        cin >> cylinders;
    }
};

class Car : public Engine {
public:
    string fuelType;

    void getCarData() {
        cout << "Enter Fuel Type (Petrol/Diesel): ";
        cin >> fuelType;
    }

    void showDetails() {
        cout << "\n--- Car Details ---\n";
        cout << "Brand: " << brand << endl;
        cout << "Model Year: " << model << endl;
        cout << "Horsepower: " << horsepower << endl;
        cout << "Cylinders: " << cylinders << endl;
        cout << "Fuel Type: " << fuelType << endl;

        if (horsepower >= 150) cout << "Performance: High\n";
        else cout << "Performance: Normal\n";
    }
};

int main() {
    Car c;
    c.CarData();
    c.CarEngineData();
    c.getCarData();
    c.showDetails();
}

