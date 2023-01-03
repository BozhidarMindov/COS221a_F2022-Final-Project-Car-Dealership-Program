#include "Truck.h"
#include <iostream>
#include <string>
using namespace std;

Truck::Truck()
{
	this->model = "";
	this->brand = "";
	this->color = "";
	this->year = 0;
	this->horsePower = 0;
	this->price = 0.0;
	this->miles = 0.0;
	this->weight = 0.0;
	this->powerUnitSize = 0.0;
	this->fuelType = diesel;
	this->used = false;
	this->towingCappacity = 0.0;
}

Truck::Truck(string model, string brand, string color, int year, int horsePower, double price,
	double miles, double powerUnitSize, FuelType fuelType, double weight, bool used, double towingCappacity)
{
	setModel(model);
	setBrand(brand);
	setColor(color);
	setYear(year);
	setHorsePower(horsePower);
	setPrice(price);
	setMiles(miles);
	setPowerUnitSize(powerUnitSize);
	setFuelType(fuelType);
	setWeight(weight);
	setUsed(used);
	setTowingCappacity(towingCappacity);
}

int Truck::CalculateWarranty()
// The warranty of each truck is calculated based on its fuel type.
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
		return 5;
	}
}

double Truck::CalculateTotalPrice()
// If a truck uses petrol or diesel, a fuelTax is taken into consideration when calculating its price.
{
	double stateTax = 0.15;
	double fuelTax = 0.05;
	double usedDiscount = 0.15 * price;
	double totalPrice;

	if (fuelType == petrol || fuelType == diesel) {
		totalPrice = (price + stateTax * price) + (fuelTax * price);
	}
	else {
		totalPrice = price + (stateTax * price);
	}
	// If the truck is used, and is not electric, a 15% discount is applied to its rpice.
	if (used == true && fuelType != electric) {
		totalPrice = totalPrice - usedDiscount;
	}

	return totalPrice;
}

double Truck::CalculateInsurance()
// The insurance of each truck is calculated again based on the fuel Type of the truck.
// The method returns the monthly insurance payment.
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

	// If the truck has a towing cappacity of more than 7000 pounds, its insurance is discounted.
	if (towingCappacity > 7000) {
		insuranceEachMonth = insuranceEachMonth - 0.10 * insuranceEachMonth;
	}

	return insuranceEachMonth;
}

void Truck::DisplayInfo()
// Displays information about the truck.
{
	cout << "Truck: " + brand + " " + model + " " + to_string(year) + " " + to_string(horsePower) + "hp " << endl;
	cout << "Total Price: " + to_string(CalculateTotalPrice()) + "$ " + "\nInsurance per month: " + to_string(CalculateInsurance()) + "$ " + "\nWarranty: " + to_string(CalculateWarranty()) + " years" << endl;
}

string Truck::getModel()
{
	return model;
}

string Truck::getBrand()
{
	return brand;
}

string Truck::getColor()
{
	return color;
}

int Truck::getYear()
{
	return year;
}

int Truck::getHorsePower()
{
	return horsePower;
}

double Truck::getPrice()
{
	return price;
}

double Truck::getMiles()
{
	return miles;
}

double Truck::getWeight()
{
	return weight;
}

double Truck::getPowerUnitSize()
{
	return powerUnitSize;
}

FuelType Truck::getFuelType()
{
	return fuelType;
}

bool Truck::getUsed()
{
	return used;
}

double Truck::getTowingCappacity()
{
	return towingCappacity;
}


void Truck::setModel(string model)
{
	this->model = model;
}

void Truck::setBrand(string brand)
{
	this->brand = brand;
}

void Truck::setColor(string color)
{
	this->color = color;
}

void Truck::setYear(int year)
{
	if (year > 0) {
		this->year = year;
	}
	else {
		year = 0;
	}
}

void Truck::setHorsePower(int horsePower)
{
	if (horsePower > 0) {
		this->horsePower = horsePower;
	}
	else {
		horsePower = 0;
	}
}

void Truck::setPrice(double price)
{
	if (price > 0) {
		this->price = price;
	}
	else {
		this->price = 0;
	}
}

void Truck::setMiles(double miles)
{
	if (miles > 0) {
		this->miles = miles;
	}
	else {
		this->miles = 0;
	}
}

void Truck::setPowerUnitSize(double powerUnitSize)
{
	if (powerUnitSize > 0) {
		this->powerUnitSize = powerUnitSize;
	}
	else {
		this->powerUnitSize = 0;
	}
}

void Truck::setFuelType(FuelType fuelType)
{
	this->fuelType = fuelType;
}

void Truck::setWeight(double weight)
{
	if (weight > 0) {
		this->weight = weight;
	}
	else {
		this->weight = 0;
	}
}

void Truck::setUsed(bool used)
{
	this->used = used;
}

void Truck::setTowingCappacity(double towingCappacity)
{
	if (towingCappacity > 0) {
		this->towingCappacity = towingCappacity;
	}
	else {
		this->towingCappacity = 0;
	}
}
