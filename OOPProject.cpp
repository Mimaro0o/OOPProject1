#include <iostream>
using namespace std;

const double PI = 3.14;
const double CM_TO_KM = 100000.0;

class TwoWheelerVehicle {
private:
    string manufacturer_name;
    string serial_number;

public:
    TwoWheelerVehicle(string manufacturer, string serial) 
        : manufacturer_name(manufacturer), serial_number(serial) {}

    void Info() const {
        cout << "Manufacturer: " << manufacturer_name << endl;
        cout << "Serial Number: " << serial_number << endl;
    }
   virtual void display_alert() const {}
};

class ElectricCycle : public TwoWheelerVehicle {
private:
    double tire_radius_cm;
    int wheel_revolutions;
    double max_distance_per_charge = 100.0;

public:
    ElectricCycle(string manufacturer, string serial, double radius, int revolutions) 
        : TwoWheelerVehicle(manufacturer, serial), tire_radius_cm(radius), wheel_revolutions(revolutions) {}

    double calculateDistanceTraveled() const {
        double circumference_km = (2 * PI * tire_radius_cm) / CM_TO_KM;
      double DistanceTraveled = circumference_km * wheel_revolutions;
        return DistanceTraveled;
    }

    void Info() const {
        TwoWheelerVehicle::Info();
        cout << "Tire Radius: " << tire_radius_cm << " cm" << endl;
        cout << "Wheel Revolutions: " << wheel_revolutions << endl;
        cout << "Distance Traveled: " << calculateDistanceTraveled() << " km" << endl;
        
        double distance_traveled = calculateDistanceTraveled();
        if (distance_traveled > 85) {
            cout << "BATTERY LOW!" << endl;
        } else {
            cout << "BATTERY OK!" << endl;
        }
    }
       virtual void display_alert() const {}
};

int main() {

const int numVehicles = 6;
    ElectricCycle* vehicles[numVehicles];

    for (int i = 0; i < numVehicles; ++i) {
        string manufacturer;
        string serial;
        float tire_radius;
        int revolutions;

        cout << "Enter details for vehicle " << i + 1 << ":" << endl;

        cout << "Manufacturer: ";
        cin >> manufacturer;

        cout << "Serial Number: ";
        cin >> serial;

        cout << "Tire Radius (in cm): ";
        cin >> tire_radius;

        cout << "Wheel Revolutions: ";
        cin >> revolutions;

        vehicles[i] = new ElectricCycle(manufacturer, serial, tire_radius, revolutions);

        cout << "--------------------------" << endl;
    }

    cout << "\nVehicle Details:\n";
    for (int i = 0; i < numVehicles; ++i) {
        cout << "Vehicle " << i + 1 << ":" << endl;
        vehicles[i]->Info();
        cout << "--------------------------" << endl;
    }

    for (int i = 0; i < numVehicles; ++i) {
        delete vehicles[i];
    }

    return 0;
}
