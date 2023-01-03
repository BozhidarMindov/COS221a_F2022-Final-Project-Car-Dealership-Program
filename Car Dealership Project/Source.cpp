#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "SUV.h"
#include "Van.h"
#include "Truck.h"
#include "PickupTruck.h"
#include "Motorcycle.h"
#include "ElectricScooter.h"
#include <fstream>
#include <sstream>
using namespace std;


const int NUM_OF_CHARS = 256;

// A function that implements the Boyer-Moore Pattern Matching Algorithm.
bool match(string text, string pattern)
{
    int patlen = pattern.length();
    int textlen = text.length();
    int positions[NUM_OF_CHARS];

    // Empty the positions array.
    for (int i = 0; i < NUM_OF_CHARS; i++)
        positions[i] = -1;

    // Recording the positions of the characters.
    for (int i = 0; i < patlen; i++)
        positions[(int)pattern[i]] = i;

    int pos = 0;

    while (pos <= (textlen - patlen))
    {
        int j = patlen - 1;

        // Looping over the pattern from the right side. 
        // Keep reducing j by one if the characters of the pattern and the text are still matching.
        while (j >= 0 && text[pos + j] == pattern[j])
            j--;


        if (j < 0)
        {
            return true; // Match was found.
        }

        else
            // If no match is found, advance in position
            pos += max(1, j - positions[text[pos + j]]);
    }
    return false; // If we get to the end of the string and no match is found, return false.
}

void merge(vector<Vehicle*>& items, vector<Vehicle*> leftHalf, vector<Vehicle*> rightHalf, string sortType) {
    // This function completes the merging part of merge sort.
    int i = 0;
    int j = 0;
    int k = 0;

    // Main loop
    while (i < leftHalf.size() && j < rightHalf.size()) {
        if (sortType == "1") { //sorts by totalPrice
            if (leftHalf[i]->CalculateTotalPrice() < rightHalf[j]->CalculateTotalPrice()) {
                items[k] = leftHalf[i];
                i++;
            }
            else {
                items[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        else if (sortType == "2") //sorts by warranty
        {
            if (leftHalf[i]->CalculateWarranty() < rightHalf[j]->CalculateWarranty()) {
                items[k] = leftHalf[i];
                i++;
            }
            else {
                items[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        else if (sortType == "3") { //sort by insurance
            if (leftHalf[i]->CalculateInsurance() < rightHalf[j]->CalculateInsurance()) {
                items[k] = leftHalf[i];
                i++;
            }
            else {
                items[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        else { // If invalid input was passed into the function, an exception is thrown.
            cerr << "Invalid sorting method" << endl;
            throw invalid_argument("Invalid value entered");
        }
   
    }

    // Copying the rest of the left half.
    while (i < leftHalf.size()) {
        items[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copying the rest of the right half.
    while (j < rightHalf.size()) {
        items[k] = rightHalf[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Vehicle*>& items, string sortType) {
    // This function implements the 'Merge Sort' algorithm. Sorts the items in ascending order, based on their total price.

    // Merge sort will only be invoked if the size of the vector is greater than 1.
    if (items.size() > 1) {
        int mid = items.size() / 2;

        vector<Vehicle*> leftHalf(items.begin(), items.begin() + mid);
        vector<Vehicle*> rightHalf(items.begin() + mid, items.begin() + items.size());

        mergeSort(leftHalf, sortType);
        mergeSort(rightHalf, sortType);
        merge(items, leftHalf, rightHalf, sortType);
    }
}

FuelType checkFuelType(string fuelType) {
    // This function takes a string parameter and converts it to the corresponding fuelType.

    if (fuelType == "petrol") {
        return petrol;
    }
    else if (fuelType == "diesel") {
        return diesel;
    }
    else if (fuelType == "hybridDiesel") {
        return hybridDiesel;
    }
    else if (fuelType == "hybridPetrol") {
        return hybridPetrol;
    }
    else {
        return electric;
    }
}

Use checkPickupTruckUse(string use) {
    // This function takes a string parameter and converts it to the corresponding vanType.

    if (use == "offRoad") {
        return offRoad;
    }
    else if (use == "hauling") {
        return hauling;
    }
    else if (use == "construction") {
        return construction;
    }
    else {
        return personalUse;
    }
}

VanType checkVanType(string vanType) {
    // This function takes a string parameter and converts it to the corresponding vanType.

    if (vanType == "mini") {
        return mini;
    }
    else if (vanType == "micro") {
        return micro;
    }
    else if (vanType == "minibus") {
        return minibus;
    }
    else if (vanType == "panel") {
        return panel;
    }
    else if (vanType == "step") {
        return step;
    }
    else if (vanType == "box") {
        return box;
    }
    else if (vanType == "fullSize") {
        return fullSize;
    }
    else {
        return MPV;
    }
}

bool stob(string str) {
    // This function converts a string to a boolean.
    if (str == "true") {
        return true;
    }
    else {
        return false;
    }
}

vector<Vehicle*> readVehicleDataFromFile(string filename) {
    // This function reads data from a texftile and with it, it creates different vehicle objects
    // The first string of each line represents the type of the vehicle, and with it the constructor of the corresponding class is invoked
    ifstream vehicleFile(filename, ios::in);

    vector<Vehicle*> vehicles;

    vector<string> temp;
    if (vehicleFile.is_open()) {
        string line;
        // Getting all line from the file adn storing them in a vector.
        while (getline(vehicleFile, line)) {
            temp.push_back(line);
        }

        for (int i = 0; i < temp.size(); i++)
        {
            string str = temp[i];
            vector<string> result;
            stringstream stream(str);

            // Splitting each line by a comma and populate a result vector, where each index represents a data member for one of our classes.
            while (stream.good()) {
                string substr;
                getline(stream, substr, ',');
                substr.erase(remove(substr.begin(), substr.end(), '"'), substr.end()); //If accidentaly a `"` char is passed, it is removed
                result.push_back(substr);
            }

            // For each line of the file, we check the first string, and determine which type of object we need to create.
            // The created object is then pushed to the vehicles vector.
            FuelType fuelType = checkFuelType(result[9]);
            if (result[0] == "Car") {
                Car* car = new Car(result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stod(result[6]),
                    stod(result[7]), stod(result[8]), fuelType, stob(result[10]));
                vehicles.push_back(car);
            }
            else if (result[0] == "Van") {
                VanType vanType = checkVanType(result[11]);
                Van* van = new Van(result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stod(result[6]),
                    stod(result[7]), stod(result[8]), fuelType, stob(result[10]), vanType, stoi(result[12]));
                vehicles.push_back(van);
            }
            else if (result[0] == "SUV") {
                SUV* suv = new SUV(result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stod(result[6]),
                    stod(result[7]), stod(result[8]), fuelType, stob(result[10]), stoi(result[11]));
                vehicles.push_back(suv);
            }
            else if (result[0] == "Truck") {
                Truck* truck = new Truck(result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stod(result[6]),
                    stod(result[7]), stod(result[8]), fuelType, stod(result[10]), stob(result[11]), stod(result[12]));
                vehicles.push_back(truck);
            }
            else if (result[0] == "PickupTruck") {
                Use use = checkPickupTruckUse(result[14]);
                PickupTruck* pickupTruck = new PickupTruck(result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stod(result[6]),
                    stod(result[7]), stod(result[8]), fuelType, stod(result[10]), stob(result[11]), stod(result[12]), stoi(result[13]), use);
                vehicles.push_back(pickupTruck);
            }
            else if (result[0] == "Motorcycle") {
                Motorcycle* motocycle = new Motorcycle(result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stod(result[6]),
                    stod(result[7]), stod(result[8]), fuelType, stob(result[10]));
                vehicles.push_back(motocycle);
            }
            else if (result[0] == "ElectricScooter") {
                ElectricScooter* elScooter = new ElectricScooter(result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stod(result[6]),
                    stod(result[7]), stod(result[8]), fuelType, stob(result[10]), stoi(result[11]));
                vehicles.push_back(elScooter);
            }
            else {
                cout << "Invalid Data" << endl;
                break;
            }
        }
    }
    else {
        exit(EXIT_FAILURE);
    }

    return vehicles;
}


int main() 
{
    // Creating a vector that stores all vehicle objects. The objects are read from a text file.
    vector<Vehicle*> vehicles = readVehicleDataFromFile("vehicles.txt");

    // Letting the user pick how they would like the vehicles to be sorted.
    string sortBy;
    cout << "How you you like the vehicles to be sorted:\nBy total price (Press 1)\nBy warranty (Press 2)\nBy insurance per month (Press 3)\nMake your choice: ";
    cin >> sortBy;
    cout << endl;

    // If the user enters something different than "1", "2" or "3", we keep asking them for valid input.
    while (sortBy != "1" && sortBy != "2" && sortBy != "3") {
        cout << "Asking again!" << endl;
        cout << "How you you like the vehicles to be sorted:\nBy total price (Press 1)\nBy warranty (Press 2)\nBy insurance per month (Press 3)\nMake your choice: ";
        cin >> sortBy;
        cout << endl;
    }

    // Sorting the 'vehicles' vector using 'Merge Sort'.
    mergeSort(vehicles, sortBy);
    cout << "--------------------------------------------------" << endl;

    // Iterating over the 'vehicles' vector, which is now sorted, and displaying some information about each vehicle.
    cout << "Items sorted:" << endl;
    cout << "-------------------------" << endl;
    for (Vehicle* j : vehicles) {
       j->DisplayInfo();
        cout << endl;
    }

    // Asking the user if they want to search for a vehicle. The search is done based on model or brand name.
    string answer;
    cout << "Do you want to look for a vehicle in our database? (yes/no): ";
    cin >> answer;
    cout << endl;
    
    // If the user enters something different than 'yes' or 'no', we keep asking them for valid input.
    while (answer != "yes" && answer != "no") {
        cout << "Asking again!" << endl;
        cout << "Do you want to look for a vehicle in our database? (yes/no): ";
        cin >> answer;
        cout << endl;
    }

    // When the user answers 'yes':
    if (answer == "yes") {
        string pattern;
        cout << "Enter a car model or a brand: ";
        cin >> pattern;

        int matches = 0;
        for (Vehicle* i : vehicles) {
            // Look for matches.
            bool matchFoundBrand = match(i->getBrand(), pattern);
            bool matchFoundModel = match(i->getModel(), pattern);
            //If a match is found, the information about the vehicle is displayed.
            if (matchFoundBrand || matchFoundModel) {
                i->DisplayInfo();
                cout << endl;
                matches++;
            }
        }
        // If there were no matches found, we inform the user.
        if (matches == 0) {
            cout << "No records found!" << endl;
        }
    }
    // If the user chooses 'no', we wish them a nice day and exit the program.
    else {
        cout << "Ok. Have a nice day." << endl;
    }

    return 0;
}