#pragma once
#include "CommissionEmployee.h"
//<총판매량> <수수료> <시급> <근무시간>

class HourlyPlusCommissionEmployee : public CommissionEmployee
{
public:
	HourlyPlusCommissionEmployee(const string &, const string &,
		const string &, double = 0.0, double = 0.0, double = 0.0, double = 0.0);

	void setWage(double); // set hourly wage
	double getWage() const; // return hourly wage
	void setHours(double); // set hours worked
	double getHours() const; // return hours worked			
	void setCommissionRate(double); // set commission rate
	double getCommissionRate() const; // return commission rate
	void setGrossSales(double); // set gross sales amount
	double getGrossSales() const; // return gross sales amount
	virtual double earnings() const; 								
	virtual void print() const;

private:
	
	double wage; // wage per hour
	double hours; // hours worked for week
	double grossSales; // gross weekly sales
	double commissionRate; // commission percentage
}; 


