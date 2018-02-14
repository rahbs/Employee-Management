// BasePlusCommissionEmployee class derived from Employee.
#ifndef BASEPLUS_H
#define BASEPLUS_H
// CommissionEmployee class definition
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string &, const string &,
		const string &, double = 0.0, double = 0.0, double = 0.0);

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary

								  // keyword virtual signals intent to override
	virtual double earnings() const; // calculate earnings
									 // print BasePlusCommissionEmployee object
	virtual void print() const;
private:
	double baseSalary; // base salary per week
}; // end class BasePlusCommissionEmployee

#endif // BASEPLUS_H
