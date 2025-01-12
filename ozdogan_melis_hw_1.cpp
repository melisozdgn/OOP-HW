#include <iostream>
#include <string>
using namespace std;
 
class Sensor {
protected:
    string userName;
    string sensorOfModel;
    int sensorUsageLifeDays;
    int useDays;
    int bloodSugar;

public:
    Sensor(const string& name, const string& model, int life, int daysUse, int sugar)
        : userName(name), sensorOfModel(model), sensorUsageLifeDays(life), useDays(daysUse), bloodSugar(sugar) {}

    virtual void checkBloodSugarLevel() = 0;

    virtual void displayRemainingUsage() {
        int remainingDays = sensorUsageLifeDays - useDays;
        cout << "Remaining usage days: " << remainingDays << " days" << endl;
    }

    virtual ~Sensor() {
        cout << "Sensor destructed for " << userName << endl;
    }
};

class Dexcom : public Sensor {
public:
    Dexcom(const string& name, const string& model, int life, int daysUse, int sugar)
        : Sensor(name, model, life, daysUse, sugar) {}

    void checkBloodSugarLevel() override {
        cout << userName << "'s Blood Sugar Check:" << endl;
        cout << "Sensor Model: " << sensorOfModel << endl;
        cout << "Testing with blood sugar: " << bloodSugar << endl;

        if (bloodSugar < 60) {
            cout << "Low blood sugar!" << endl;
        } else if (bloodSugar <= 110) {
            cout << "Normal blood sugar." << endl;
        } else {
            cout << "High blood sugar!" << endl;
        }

        displayRemainingUsage();
    }

    ~Dexcom() override {}
};

class Abbott : public Sensor {
public:
    Abbott(const string& name, const string& model, int life, int daysUse, int sugar)
        : Sensor(name, model, life, daysUse, sugar) {}

    void checkBloodSugarLevel() override {
        cout << userName << "'s Blood Sugar Check:" << endl;
        cout << "Sensor Model: " << sensorOfModel << endl;
        cout << "Testing with blood sugar: " << bloodSugar << endl;

        if (bloodSugar < 80) {
            cout << "Critical low blood sugar!" << endl;
        } else if (bloodSugar <= 130) {
            cout << "Normal blood sugar." << endl;
        } else {
            cout << "High blood sugar!" << endl;
        }

        displayRemainingUsage();
    }

    ~Abbott() override {}
};

class Medtrum : public Sensor {
public:
    Medtrum(const string& name, const string& model, int life, int daysUse, int sugar)
        : Sensor(name, model, life, daysUse, sugar) {}

    void checkBloodSugarLevel() override {
        cout << userName << "'s Blood Sugar Check:" << endl;
        cout << "Sensor Model: " << sensorOfModel << endl;
        cout << "Testing with blood sugar: " << bloodSugar << endl;

        if (bloodSugar < 75) {
            cout << "Critical low blood sugar!" << endl;
        } else if (bloodSugar <= 120) {
            cout << "Normal blood sugar." << endl;
        } else {
            cout << "High blood sugar!" << endl;
        }

        displayRemainingUsage();
    }

    ~Medtrum() override {}
};

int main() {
    string name, sensorModel;
    int bloodSugar, useDays, sensorType, lifeDays;

    cout << "Enter patient name: ";
    cin >> name;
    cout << "Enter blood sugar: ";
    cin >> bloodSugar;
    cout << "Enter sensor usage days: ";
    cin >> useDays;
    cout << "Enter sensor life in days: ";
    cin >> lifeDays;
    cout << "Enter sensor model ( G7, Libre2, $7-960): ";
    cin >> sensorModel;

    cout << "Select sensor type (1: Dexcom, 2: Abbott, 3: Medtrum): ";
    cin >> sensorType;

    Sensor* sensor = nullptr;

    if (sensorType == 1) {
        sensor = new Dexcom(name, sensorModel, lifeDays, useDays, bloodSugar);
    } else if (sensorType == 2) {
        sensor = new Abbott(name, sensorModel, lifeDays, useDays, bloodSugar);
    } else if (sensorType == 3) {
        sensor = new Medtrum(name, sensorModel, lifeDays, useDays, bloodSugar);
    } else {
        cout << "Invalid!" << endl;
        sensor = new Dexcom(name, sensorModel, lifeDays, useDays, bloodSugar);
    }

    sensor->checkBloodSugarLevel();

    delete sensor;

    return 0;
}



