#pragma once
#include <iostream>
#include "Truck.h"
using namespace std;

enum Use {offRoad, hauling, construction, personalUse};
class PickupTruck : public Truck
{
private:
	// Data items
	int numOfSeats;
	Use use;

public:
	// Default constructor
	PickupTruck();
	// Parameter constructor
	PickupTruck(string model, string brand, string color, int year, int horsePower, double price, double miles,
		double powerUnitSize, FuelType fuelType, double weight, bool used, double towingCappacity, int numOfSeats, Use use);

	// Implementations of the methods from the base class
	int CalculateWarranty();
	double CalculateTotalPrice();
	double CalculateInsurance();
	void DisplayInfo();

	// Getters
	int getNumOfSeats();
	Use getUse();

	// Setters
	void setNumOfSeats(int numOfSeats);
	void setUse(Use use);
};

