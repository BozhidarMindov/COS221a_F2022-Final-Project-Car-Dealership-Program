#pragma once
#include <iostream>
#include "Motorcycle.h"
using namespace std;

class ElectricScooter : public Motorcycle
{
private:
	// Data item
	int batteryHealth; //in percentage. example: 100
public:
	// Default constructor
	ElectricScooter();
	// Parameter constructor
	ElectricScooter(string model, string brand, string color, int year, int horsePower, double price, double miles,
		 double powerUnitSize, FuelType fuelType, bool used, int batteryHealth);

	// Implementations of the methods from the base class
	int CalculateWarranty();
	double CalculateTotalPrice();
	double CalculateInsurance();
	void DisplayInfo();

	// Getter
	int getBatteryHealth();

	// Setter
	void setBatteryHealth(int batteryHealth);
};

