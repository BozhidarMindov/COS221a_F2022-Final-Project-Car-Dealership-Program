#include "SUV.h"
#include <iostream>
#include <string>
using namespace std;

SUV::SUV()
{
	this->numOfSeats = 4;
}

SUV::SUV(string model, string brand, string color, int year, int horsePower,
	double price, double miles, double powerUnitSize, FuelType fuelType, bool used, int numOfSeats)
	: Car(model, brand, color, year, horsePower, price, miles, powerUnitSize, fuelType, used)
{
	setNumOfSeats(numOfSeats);
}

int SUV::CalculateWarranty()
// Each SUV has 1 year of warranty more than the cars.
{
	return Car::CalculateWarranty() + 1;
}

double SUV::CalculateTotalPrice()
// If the SUV has 7 or more seats, its price gets discounted.
{
	if (numOfSeats >= 7) {
		return Car::CalculateTotalPrice() - 0.20 * Car::CalculateTotalPrice();
	}
	else {
		return Car::CalculateTotalPrice();
	}
}

double SUV::CalculateInsurance()
// If the SUV has 7 or more seats, its monthly insurance payments get discounted.
{
	if (numOfSeats >= 7) {
		return Car::CalculateInsurance() - 0.25 * Car::CalculateInsurance();
	}
	else {
		return Car::CalculateInsurance();
	}
}

void SUV::DisplayInfo()
// Displays information about the SUV.
{
	cout << "SUV: " + Car::getBrand() + " " + Car::getModel() + " " + to_string(Car::getYear()) + " " + to_string(Car::getHorsePower()) + "hp " << endl;
	cout << "Total Price: " + to_string(CalculateTotalPrice()) + "$ " + "\nInsurance per month: " + to_string(CalculateInsurance()) + "$ " + "\nWarranty: " + to_string(CalculateWarranty()) + " years" << endl;
}

int SUV::getNumOfSeats()
{
	return numOfSeats;
}

void SUV::setNumOfSeats(int numOfSeats)
{
	if (numOfSeats > 4) {
		this->numOfSeats = numOfSeats;
	}
	else {
		numOfSeats = 4;
	}
}

