#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle
{
private:
	string model;
	string brand;
	string color;
	int year;
	int horsePower;
	double price;
	double miles;
	double powerUnitSize; //in liters
	FuelType fuelType;
	bool used;

public:
	Car();
	Car(string model, string brand, string color, int year, int horsePower,
		double price, double miles, double powerUnitSize, FuelType fuelType, bool used);
	
	int CalculateWarranty();
	double CalculateTotalPrice();
	double CalculateInsurance();
	void DisplayInfo();

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

