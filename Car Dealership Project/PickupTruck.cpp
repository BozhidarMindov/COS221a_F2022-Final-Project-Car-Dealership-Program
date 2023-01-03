#include "PickupTruck.h"
#include <iostream>
#include <string>
using namespace std;

PickupTruck::PickupTruck()
{
	this->numOfSeats = 2;
	this->use = personalUse;
}

PickupTruck::PickupTruck(string model, string brand, string color, int year, int horsePower,
	double price, double miles, double powerUnitSize, FuelType fuelType, double weight, bool used, double towingCappacity, int numOfSeats, Use use)
	: Truck(model, brand, color, year, horsePower, price, miles, powerUnitSize, fuelType, weight, used, towingCappacity)
{
	setNumOfSeats(numOfSeats);
	setUse(use);
}

int PickupTruck::CalculateWarranty()
// Each pickup truck has a 2 years of warranty more that the trucks.
{
	return Truck::CalculateWarranty() + 2;
}

double PickupTruck::CalculateTotalPrice()
// The price of each pickup truck is based on its use. If its used for construction or hauling, the price of the pickup truck gets discounted.
{	
	double totalPrice;
	if (use == construction || use == hauling) {
		totalPrice =  Truck::CalculateTotalPrice() - 0.20 * Truck::CalculateTotalPrice();
	}
	else {
		totalPrice = Truck::CalculateTotalPrice();
	}

	// If the pickup truck has 7 or more seats, its price gets discounted further.
	if (numOfSeats >= 7) {
		totalPrice = totalPrice - 0.15 * totalPrice;
	}

	return totalPrice;
}

double PickupTruck::CalculateInsurance()
// If the pickup truck ahs 7 or more seats, its monthly insrance payments get a discount.
{	
	double insurance;
	if (numOfSeats >= 7) {
		insurance =  Truck::CalculateInsurance() - 0.25 * Truck::CalculateInsurance();
	}
	else {
		insurance =  Truck::CalculateInsurance();
	}

	// If the pickup truck is used fro hauling or construction, its insurance gets discounted further.
	if (use == hauling || use == construction) {
		insurance = insurance - 0.10 * insurance;
	}

	return insurance;
}

void PickupTruck::DisplayInfo()
// Displays information about the pickup truck.
{
	cout << "Pickup Truck: " + Truck::getBrand() + " " + Truck::getModel() + " " + to_string(Truck::getYear()) + " " + to_string(Truck::getHorsePower()) + "hp " << endl;
	cout << "Total Price: " + to_string(CalculateTotalPrice()) + "$ " + "\nInsurance per month: " + to_string(CalculateInsurance()) + "$ " + "\nWarranty: " + to_string(CalculateWarranty()) + " years" << endl;
}

int PickupTruck::getNumOfSeats()
{
	return numOfSeats;
}

Use PickupTruck::getUse()
{
	return use;
}

void PickupTruck::setNumOfSeats(int numOfSeats)
{
	if (numOfSeats > 2) {
		this->numOfSeats = numOfSeats;
	}
	else {
		numOfSeats = 2;
	}
}

void PickupTruck::setUse(Use use)
{
	this->use = use;
}
