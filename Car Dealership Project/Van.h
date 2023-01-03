#pragma once
#include <iostream>
#include "Car.h"
using namespace std;

enum VanType {mini, micro, minibus, panel, step, box, fullSize, MPV };

class Van : public Car
{
private:
	// Data items
	VanType vanType;
	int numOfSeats;

public:
	// Default constructor
	Van();
	// Parameter constructor
	Van(string model, string brand, string color, int year, int horsePower, double price,
		double miles, double powerUnitSize, FuelType fuelType, bool used, VanType vanType, int numOfSeats);

	// Implementations of the methods from the base class
	int CalculateWarranty();
	double CalculateTotalPrice();
	double CalculateInsurance();
	void DisplayInfo();

	// Getters
	VanType getVanType();
	int getNumOfSeats();
	
	// Setters
	void setVanType(VanType vanType);
	void setNumOfSeats(int numOfSeats);
};

