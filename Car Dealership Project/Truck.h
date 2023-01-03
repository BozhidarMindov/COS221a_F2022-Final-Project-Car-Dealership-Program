#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Truck : public Vehicle
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
	double powerUnitSize; //in liters
	FuelType fuelType;
	double weight; //in tons
	bool used;
	double towingCappacity; //in pounds

public:
	// Default constructor
	Truck();
	// Parameter constructor
	Truck(string model, string brand, string color, int year, int horsePower, double price,
		double miles, double powerUnitSize, FuelType fuelType, double weight, bool used, double towingCappacity);

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
	double getWeight();
	bool getUsed();
	double getTowingCappacity();

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
	void setWeight(double weight);
	void setUsed(bool used);
	void setTowingCappacity(double towingCappacity);
};

