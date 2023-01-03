#pragma once
#include <iostream>
#include "Car.h"
using namespace std;

class SUV : public Car
{
private:
	// Data items
	int numOfSeats;

public:
	// Default constructor
	SUV();
	// Parameter construcor
	SUV(string model, string brand, string color, int year, int horsePower, double price,
		double weight, double powerUnitSize, FuelType fuelType, bool used, int numOfSeats);

	// Implementations of the methods from the base class
	int CalculateWarranty();
	double CalculateTotalPrice();
	double CalculateInsurance();
	void DisplayInfo();

	// Getter
	int getNumOfSeats();
	
	// Setter
	void setNumOfSeats(int numOfSeats);
};

