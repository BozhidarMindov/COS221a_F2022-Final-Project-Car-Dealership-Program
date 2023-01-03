#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

Car::Car()
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

Car::Car(string model, string brand, string color, int year, int horsePower, double price, 
	double miles, double powerUnitSize, FuelType fuelType, bool used)
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
	setUsed(used);
}


int Car::CalculateWarranty()
// The warranty of the car depends on its fuel type.
{
	if (fuelType == petrol){
		return 5;
	}
	else if (fuelType == diesel) {
		return 4;
	}
	else if (fuelType == electric) {
		return 8;
	}
	else {
		return 6;
	}
}

double Car::CalculateTotalPrice()
// If the car uses petrol or diesel, a fuelTax is taken into consideration when calculating its price.
{
	double stateTax = 0.20;
	double fuelTax = 0.10;
	double totalPrice;

	double usedDiscount = 0.15 * price;
	double electricDiscount = 0.10 * price;

	if (fuelType == petrol || fuelType == diesel){
		totalPrice = (price + stateTax * price) + (fuelTax * price);
	}
	// If the car is electric, it gets a special discount and no state tax need to be paid.
	else if (fuelType = electric) {
		totalPrice = price - electricDiscount;
	}
	else {
		totalPrice = price + (stateTax * price);
	}
	// If the car is used and it is not electric, a used discount is applied.
	if (used == true && fuelType != electric) {
		totalPrice = totalPrice - usedDiscount;
	}

	return totalPrice;
}

double Car::CalculateInsurance()
// The monthly insurance payment is also determined by the fuelType of the cars.
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
	// If the car is used, the insurance payments on it have a special tax applied to them.
	double oldCarTax;
	if (used == true && year < 2015) {
		oldCarTax = 0.10 * price;
	}
	else {
		oldCarTax = 0.0;
	}

	double insuranceEachMonth = ((insuranceBase + engineTax + oldCarTax) / 12);

	return insuranceEachMonth;
}

void Car::DisplayInfo()
// Displays information about the car.
{
	cout << "Car: " + brand + " " + model + " " + to_string(year) + " " + to_string(horsePower) + "hp " << endl;
	cout << "Total Price: " + to_string(CalculateTotalPrice()) + "$ " + "\nInsurance per month: " + to_string(CalculateInsurance()) + "$ " + "\nWarranty: " + to_string(CalculateWarranty()) + " years" << endl;
}


string Car::getModel()
{
	return model;
}

string Car::getBrand()
{
	return brand;
}

string Car::getColor()
{
	return color;
}

int Car::getYear()
{
	return year;
}

int Car::getHorsePower()
{
	return horsePower;
}

double Car::getPrice()
{
	return price;
}

double Car::getMiles()
{
	return miles;
}

double Car::getPowerUnitSize() {
	return powerUnitSize;
}

FuelType Car::getFuelType() {
	return fuelType;
}

bool Car::getUsed() {
	return used;
}


void Car::setModel(string model)
{
	this->model = model;
}

void Car::setBrand(string brand)
{
	this->brand = brand;
}

void Car::setColor(string color)
{
	this->color = color;
}

void Car::setYear(int year)
{
	if (year > 0) {
		this->year = year;
	}
	else {
		this->year = 0;
	}
}

void Car::setHorsePower(int horsePower)
{
	if (horsePower > 0) {
		this->horsePower = horsePower;
	}
	else {
		this->horsePower = 0;
	}
}

void Car::setPrice(double price)
{
	if (price > 0) {
		this->price = price;
	}
	else {
		this->price = 0;
	}
}

void Car::setMiles(double miles)
{
	if (miles > 0) {
		this->miles = miles;
	}
	else {
		this->miles = 0;
	}
}

void Car::setPowerUnitSize(double powerUnitSize)
{
	if (powerUnitSize > 0) {
		this->powerUnitSize = powerUnitSize;
	}
	else {
		this->powerUnitSize = 0;
	}
}

void Car::setFuelType(FuelType fuelType)
{
	this->fuelType = fuelType;
}

void Car::setUsed(bool used)
{
	this->used = used;
}
