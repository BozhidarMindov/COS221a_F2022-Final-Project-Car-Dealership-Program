#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Motorcycle : public Vehicle
{
private:
	// Data items
	string model;
	string brand;
	string color;
	int year;
	int horsePower;
	double price;
	double miles; 
	double powerUnitSize;
	FuelType fuelType;
	bool used;
public:
	// Default constructor
	Motorcycle();
	// Parameter constructor
	Motorcycle(string model, string brand, string color, int year, int horsePower, double price,
		double miles, double powerUnitSize, FuelType fuelType, bool used);

	// Implementations of the methods from the base class
	int CalculateWarranty();
	double CalculateTotalPrice();
	double CalculateInsurance();
	void DisplayInfo();

	// Getters
	string getModel();
	string getBrand();
	string getColor();
	int getYear();
	int getHorsePower();
	double getPrice();
	double getMiles();
	double getPowerUnitSize();
	FuelType getFuelType();
	bool getUsed();

	// Setters
	void setModel(string model);
	void setBrand(string brand);
	void setColor(string color);
	void setYear(int year);
	void setHorsePower(int horsePower);
	void setPrice(double price);
	void setMiles(double miles);
	void setPowerUnitSize(double powerUnitSize);
	void setFuelType(FuelType fuelType);
	void setUsed(bool used);
};

