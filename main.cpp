#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to store car details
struct Car {
    string sn;
    string hsCode;
    string coo;
    string description;
    int year;
    int cc;
    double cifValue;
};

// Function to split a string by a delimiter
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to load car data from CSV
vector<Car> loadCars(const string &filename) {
    vector<Car> cars;
    ifstream file(filename);
    string line;

    //skip the header row
    getline(file, line); 

    while (getline(file, line)) {
        vector<string> data = split(line, ',');
        if (data.size() == 7) {
            try {
                Car car;
                car.sn = data[0];
                car.hsCode = data[1];
                car.coo = data[2];
                car.description = data[3];
                car.year = stoi(data[4]);
                car.cc = stoi(data[5]);
                car.cifValue = stod(data[6]);
                cars.push_back(car);
            } catch (const invalid_argument &e) {
                cerr << "Warning: Skpping invalid rows: " << line << endl;
            }
        } else {
            cerr << "Warning: Skipping malformed row: " << line << endl;
        }
    }

    return cars;
}

// Function to calculate taxes
void calculateTaxes(const Car &car) {
    double importDuty = 0.25 * car.cifValue;
    double vat = 0.18 * (importDuty + car.cifValue);
    double wht = 0.06 * car.cifValue;
    double surcharge = 0.50 * car.cifValue;
    double totalTaxes = importDuty + vat + wht + surcharge;

    cout << "Tax Calculations for " << car.description << " (" << car.year << "):" << endl;
    cout << "---------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Import Duty (25% of CIF): $" << importDuty << endl;
    cout << "VAT (18% of CIF + Import Duty): $" << vat << endl;
    cout << "WHT (6% of CIF): $" << wht << endl;
    cout << "Surcharge (50% of CIF): $" << surcharge << endl;
    cout << "---------------------------------" << endl;
    cout << "Total Taxes: $" << totalTaxes << endl;
}

int main() {
    // Load car data from CSV
    vector<Car> cars = loadCars("cars.csv");

    // Get user input
    string model, yearInput;
    int year, cc;

    cout << "Enter car model (e.g., ACURA MDX): ";
    getline(cin, model);

    cout << "Enter year (e.g., 2009): ";
    getline(cin, yearInput);
    year = stoi(yearInput);

    cout << "Enter engine CC (e.g., 3700): ";
    cin >> cc;

    // Search for matching car
    bool found = false;
    for (const Car &car : cars) {
        if (car.description.find(model) != string::npos && car.year == year && car.cc == cc) {
            found = true;
            cout << "\nMatching Car Found:" << endl;
            cout << "HS Code: " << car.hsCode << endl;
            cout << "Description: " << car.description << endl;
            cout << "CC: " << car.cc << endl;
            cout << "CIF Value (USD): $" << car.cifValue << endl;

            // Calculate and display taxes
            calculateTaxes(car);
            break;
        }
    }

    if (!found) {
        cout << "No matching car found." << endl;
    }

    return 0;
}