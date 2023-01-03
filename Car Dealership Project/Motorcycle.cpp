#include "Motorcycle.h"
#include <iostream>
#include <string>
using namespace std;

Motorcycle::Motorcycle()
{
	this->model = "";
	this->brand = "";
	this->color = "";
	this->year = 0;
	this->horsePower = 0;
	this->price = 0.0;
	this->miles = 0.0;
	this->powerUnitSize = 0.0;
	this->fuelType = petrol;
	this->used = false;
}

Motorcycle::Motorcycle(string model, string brand, string color, int year, int horsePower,
	double price, double miles, double powerUnitSize, FuelType fuelType, bool used)
{
	this->model = model;
	this->brand = brand;
	this->color = color;
	this->year = year;
	this->horsePower = horsePower;
	this->price = price;
	this->miles = miles;
	this->powerUnitSize = powerUnitSize;
	this->fuelType = fuelType;
	this->used = used;
}

int Motorcycle::CalculateWarranty()
// The warranty of the motorcycle depends on its fuel type.
{
	if (fuelType == petrol) {
		return 4;
	}
	else if (fuelType == diesel) {
		return 3;
	}
	else if (fuelType == electric) {
		return 8;
	}
	else {
		return 6;
	}
}

double Motorcycle::CalculateTotalPrice()
// If a motorcycle uses petrol or diesel, a fuelTax is taken into consideration when calculating its price.
{
	double stateTax = 0.20;
	double fuelTax = 0.08;
	double usedDiscount = 0.15 * price;
	double totalPrice;

	if (fuelType == petrol || fuelType == diesel) {
		totalPrice = (price + stateTax * price) + (fuelTax * price);
	}
	// If the motorcycle is electric, it gets a special discount and no state tax need to be paid.
	else {
		totalPrice = price + (stateTax * price);
	}
	// If the motorcycle is used and it is not electric, a used discount is applied.
	if (used == true && fuelType != electric) {
		totalPrice = totalPrice - usedDiscount;
	}

	return totalPrice;
}

double Motorcycle::CalculateInsurance()
// The monthly insurance payment is also determined by the fuelType of the motorcycles.
{
	double insuranceBase = 0.03 * price;

	double engineTax;
	if ((fuelType == petrol || fuelType == diesel) && powerUnitSize > 2) {
		engineTax = 0.05 * price;
	}
	else if (fuelType == electric) {
		engineTax = 0.0;
	}
	else if (fuelType == hybridPetrol || fuelType == hybridDiesel)
	{
		engineTax = 0.01 * price;
	}
	else {
		engineTax = 0.02 * price;
	}

	double insuranceEachMonth = (insuranceBase + engineTax) / 12;

	return insuranceEachMonth;
}

void Motorcycle::DisplayInfo()
// Display information about the motorcycle.
{
	cout << "Motorcycle: " + brand + " " + model + " " + to_string(year) + " " + to_string(horsePower) + "hp " << endl;
	cout << "Total Price: " + to_string(CalculateTotalPrice()) + "$ " + "\nInsurance per month: " + to_string(CalculateInsurance()) + "$ " + "\nWarranty: " + to_string(CalculateWarranty()) + " years" << endl;
}

string Motorcycle::getModel()
{
	return model;
}

string Motorcycle::getBrand()
{
	return brand;
}

string Motorcycle::getColor()
{
	return color;
}

int Motorcycle::getYear()
{
	return year;
}

int Motorcycle::getHorsePower()
{
	return horsePower;
}

double Motorcycle::getPrice()
{
	return price;
}

double Motorcycle::getMiles()
{
	return miles;
}

double Motorcycle::getPowerUnitSize()
{
	return powerUnitSize;
}

FuelType Motorcycle::getFuelType()
{
	return fuelType;
}

bool Motorcycle::getUsed()
{
	return used;
}


void Motorcycle::setModel(string model)
{
	this->model = model;
}

void Motorcycle::setBrand(string brand)
{
	this->brand = brand;
}

void Motorcycle::setColor(string color)
{
	this->color = color;
}

void Motorcycle::setYear(int year)
{
	if (year > 0) {
		this->year = year;
	}
	else {
		this->year = 0;
	}
}

void Motorcycle::setHorsePower(int horsePower)
{
	if (horsePower > 0) {
		this->horsePower = horsePower;
	}
	else {
		this->horsePower = 0;
	}
}

void Motorcycle::setPrice(double price)
{
	if (price > 0) {
		this->price = price;
	}
	else {
		this->price = 0;
	}
}

void Motorcycle::setMiles(double miles)
{
	if (miles > 0) {
		this->miles = miles;
	}
	else {
		this->miles = 0;
	}
}

void Motorcycle::setPowerUnitSize(double powerUnitSize)
{
	if (powerUnitSize > 0) {
		this->powerUnitSize = powerUnitSize;
	}
	else {
		this->powerUnitSize = 0;
	}
}

void Motorcycle::setFuelType(FuelType fuelType)
{
	this->fuelType = fuelType;
}

void Motorcycle::setUsed(bool used)
{
	this->used = used;
}
