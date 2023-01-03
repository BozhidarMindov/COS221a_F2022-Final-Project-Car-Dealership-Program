#include "ElectricScooter.h"
#include <iostream>
#include <string>
using namespace std;

ElectricScooter::ElectricScooter()
{
	this->batteryHealth = 100;
}

ElectricScooter::ElectricScooter(string model, string brand, string color, int year, int horsePower, double price, double miles,
double powerUnitSize, FuelType fuelType, bool used, int batteryHealth)
	: Motorcycle(model, brand, color, year, horsePower, price, miles, powerUnitSize, fuelType, used)
{
	setBatteryHealth(batteryHealth);
	Motorcycle::setFuelType(electric);
}

int ElectricScooter::CalculateWarranty()
// The warranty of each electric scooter is based on its battery health
{
	if (batteryHealth < 70) {
		return 3;
	}
	else {
		return 5;
	}
}

double ElectricScooter::CalculateTotalPrice()
{
	double healthDiscount = 0.30;

	// Each scooter is bough with a 15 percent discount.
	double totalPrice = Motorcycle::CalculateTotalPrice() - 0.15 * Motorcycle::CalculateTotalPrice();

	// If the battery health of an electric scooter os below 80%, a further 30% discount is applied.
	if (batteryHealth < 80) {
		totalPrice = totalPrice - totalPrice * healthDiscount;
	}

	return totalPrice;
}

double ElectricScooter::CalculateInsurance()
{
	// Each scooter is bough with a 10 percent insurance discount.
	return Motorcycle::CalculateInsurance() - 0.10 * Motorcycle::CalculateInsurance();
}

void ElectricScooter::DisplayInfo()
// Displays information about the electric scooter.
{
	cout << "Electric scooter: " + Motorcycle::getBrand() + " " + Motorcycle::getModel() + " " + to_string(Motorcycle::getYear()) + " " + to_string(Motorcycle::getHorsePower()) + "hp " + "Battery health: " + to_string(getBatteryHealth()) + "%" << endl;
	cout << "Total Price: " + to_string(CalculateTotalPrice()) + "$ " + "\nInsurance per month: " + to_string(CalculateInsurance()) + "$ " + "\nWarranty: " + to_string(CalculateWarranty()) + " years" << endl;
}

int ElectricScooter::getBatteryHealth()
{
	return batteryHealth;
}

void ElectricScooter::setBatteryHealth(int batteryHealth)
{
	if (batteryHealth < 0) {
		batteryHealth = 0;
	}
	else if (batteryHealth >= 0 && batteryHealth <= 100)
	{
		this->batteryHealth = batteryHealth;
	}
	else {
		this->batteryHealth = 100;
	}
}
