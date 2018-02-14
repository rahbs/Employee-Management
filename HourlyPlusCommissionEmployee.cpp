#include <iostream>
#include <string>
#include "HourlyPlusCommissionEmployee.h"
using namespace std;

HourlyPlusCommissionEmployee::HourlyPlusCommissionEmployee(const string &first, const string &last,
	const string &ssn, double sales, double rate, double hourlyWage, double hoursWorked)
	: CommissionEmployee(first, last, ssn, sales, rate)
{
	setWage(hourlyWage);
	setHours(hoursWorked);
	setCommissionRate(rate);
	setGrossSales(sales);
}

void HourlyPlusCommissionEmployee::setWage(double hourlyWage)
{
	wage = hourlyWage < 0.0 ? 0.0 : hourlyWage;
} 
double HourlyPlusCommissionEmployee::getWage() const
{
	return wage;
}

void HourlyPlusCommissionEmployee::setHours(double hoursWorked)
{
	hours = ((hoursWorked >= 0.0) && (hoursWorked <= 168.0)) ?
		hoursWorked : 0.0;
} 

double HourlyPlusCommissionEmployee::getHours() const
{
	return hours;
} 

void HourlyPlusCommissionEmployee::setCommissionRate(double rate)
{
	commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
}

double HourlyPlusCommissionEmployee::getCommissionRate() const
{
	return commissionRate;
}

void HourlyPlusCommissionEmployee::setGrossSales(double sales)
{
	grossSales = (sales < 0.0) ? 0.0 : sales;
} 

double HourlyPlusCommissionEmployee::getGrossSales() const
{
	return grossSales;
} 


double  HourlyPlusCommissionEmployee::earnings() const
{
	if (getHours() <= 40)
		return getWage()*getHours()
		+ CommissionEmployee::earnings();
	else
		return 40 * getWage()
		+ (getHours() - 40)*getWage()*1.5
		+ CommissionEmployee::earnings();
} 


void  HourlyPlusCommissionEmployee::print() const
{
	cout << "hourly plus commission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getGrossSales()
		<< "; commission rate: " << getCommissionRate();
	cout << "\nhourly wage: " << getWage() <<
		"; hours worked: " << getHours();

	
} 


