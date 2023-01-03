#pragma once
#include <iostream>
using namespace std;

enum FuelType { petrol, diesel, hybridDiesel, hybridPetrol, electric };

class Vehicle
{
public:
	// Pure virtual methods that have to be implemented in classes that inherit this one.
	virtual int CalculateWarranty() = 0; //in years
	virtual double CalculateTotalPrice() = 0; 
	virtual double CalculateInsurance() = 0; // monthly insurance payments
	virtual void DisplayInfo() = 0; //display inforamtion about a certain vehicle

	// Methods which will me used to return the brand and the model of a vehicle. Used in the main source file.
	virtual string getBrand() = 0;
	virtual string getModel() = 0;
};

