#include "Van.h"
#include <iostream>
#include <string>
using namespace std;

Van::Van()
{
	this->vanType = fullSize;
	this->numOfSeats = 4;
}


Van::Van(string model, string brand, string color, int year, int horsePower, double price,
	double miles, double powerUnitSize, FuelType fuelType, bool used, VanType vanType, int numOfSeats)
	: Car(model, brand, color, year, horsePower, price, miles, powerUnitSize, fuelType, used)
{
	setVanType(vanType);
	setNumOfSeats(numOfSeats);
}

int Van::CalculateWarranty()
// All vans have 1 more year of warranty than the cars.
{
	return Car::CalculateWarranty() + 1;
}

double Van::CalculateTotalPrice()
// If a van has 7 or more seats, it gets a discount in price.
{
	if (numOfSeats >= 7) {
		return Car::CalculateTotalPrice() - 0.20 * Car::CalculateTotalPrice();
	}
	else {
		return Car::CalculateTotalPrice();
	}
}

double Van::CalculateInsurance()
// If a van has 7 or more seats, it gets a discount io the amount of insurane that has to be payed for it.
{
	double insurancePerMonth;
	if (numOfSeats >= 7) {
		insurancePerMonth = Car::CalculateInsurance() - 0.25 * Car::CalculateInsurance();
	}
	else {
		insurancePerMonth =  Car::CalculateInsurance();
	}

	// If a van has one of the following types - mini, micro, box, step, it gets a further discount in price.
	if (vanType == micro || vanType == mini || vanType == box || vanType == step) {
		insurancePerMonth = insurancePerMonth - 0.10 * insurancePerMonth;
	}

	return insurancePerMonth;

}

void Van::DisplayInfo()
// Displays inforamtion about the van.
{
	cout << "Van: " + Car::getBrand() + " " + Car::getModel() + " " + to_string(Car::getYear()) + " " + to_string(Car::getHorsePower()) + "hp " << endl;
	cout << "Total Price: " + to_string(CalculateTotalPrice()) + "$ " + "\nInsurance per month: " + to_string(CalculateInsurance()) + "$ " + "\nWarranty: " + to_string(CalculateWarranty()) + " years" << endl;
}

VanType Van::getVanType()
{
	return vanType;
}

int Van::getNumOfSeats()
{
	return numOfSeats;
}

void Van::setVanType(VanType vanType)
{
	this->vanType = vanType;
}

void Van::setNumOfSeats(int numOfSeats)
{
	if (numOfSeats > 4) {
		this->numOfSeats = numOfSeats;
	}
	else {
		numOfSeats = 4;
	}
}
