#include "Employee.h"
#include "SalariedEmployee.h" 
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h" 
#include "HourlyPlusCommissionEmployee.h"
#include <typeinfo>
#include <vector>
#include <iostream>

using namespace std;
int main()
{
	vector<Employee*> employees;
	Employee* employeePtr = nullptr;

	char oper;
	char type;
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;
	double commissionRate;
	double BaseSalary;
	double wageperhour;
	double hour;

	while (true)
	{
		Employee* max = nullptr;
		cout << "  ****command > ";
		cin >> oper;

		switch (oper)
		{
		case 'n':
		{
			cin >> type >> firstName >> lastName >> socialSecurityNumber;

			if (type == 'c')
			{
				cin >> grossSales >> commissionRate;
				employeePtr = new CommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate);
			}
			else if (type == 'b')
			{
				cin >> grossSales >> commissionRate >> BaseSalary;
				employeePtr = new BasePlusCommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate, BaseSalary);
			}
			else if (type == 's')
			{
				cin >> BaseSalary;
				employeePtr = new SalariedEmployee(firstName, lastName, socialSecurityNumber, BaseSalary);
			}
			else if (type == 'h')
			{
				cin >> wageperhour >> hour;
				employeePtr = new HourlyEmployee(firstName, lastName, socialSecurityNumber, wageperhour, hour);
			}
			else if (type == 'a')
			{
				cin >> grossSales >> commissionRate >> wageperhour >> hour;
				employeePtr = new HourlyPlusCommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate, wageperhour, hour);
			}
			else
				cout << "wrong employee type: " << type;
			employees.push_back(employeePtr);
			employeePtr = nullptr;
			break;
		}
		case 's':
			cin >> firstName >> lastName;

			for (auto it = employees.begin();
				it != employees.end();
				++it)
			{
				if ((*it)->getFirstName() == firstName &&
					(*it)->getLastName() == lastName)
				{
					(*it)->print(); cout << '\n';
				}
			}
			break;
		case 'd':
			cin >> firstName >> lastName;
			for (auto it = employees.begin();
				it != employees.end();
				++it)
			{
				if ((*it)->getFirstName() == firstName &&
					(*it)->getLastName() == lastName)
				{
					it = employees.erase(it);
				}
			}
			break;
		case 't':
			max = *employees.begin();

			for (auto it = employees.begin();
				it != employees.end();
				++it)
			{
				max = ((*it)->earnings() > max->earnings()) ? *it : max;
			}
			max->print(); cout << '\n';

			break;
		case 'e':
			cin >> type;

			if (type == 'c')
			{
				for (size_t i = 0; i < employees.size(); i++)
				{
					CommissionEmployee *derivedPtr =
						dynamic_cast < CommissionEmployee * >
						(employees[i]);

					if (derivedPtr != nullptr) {
						if (typeid(*derivedPtr).name() == typeid(CommissionEmployee).name()) {
							derivedPtr->print(); cout << endl;
						}
					}
				}
			}   
			else if (type == 'b')
			{
				for (size_t i = 0; i < employees.size(); i++)
				{
					BasePlusCommissionEmployee *derivedPtr =
						dynamic_cast < BasePlusCommissionEmployee * >
						(employees[i]);

					if (derivedPtr != nullptr) {
						if (typeid(*derivedPtr).name() == typeid(BasePlusCommissionEmployee).name())
							derivedPtr->print(); cout << endl;
					}
				}
			} 
			else if (type == 's')
			{
				for (size_t i = 0; i < employees.size(); i++)
				{
					SalariedEmployee *derivedPtr =
						dynamic_cast < SalariedEmployee * >
						(employees[i]);

					if (derivedPtr != nullptr) {
						if (typeid(*derivedPtr).name() == typeid(SalariedEmployee).name())
							derivedPtr->print(); cout << endl;
					}
				}
			}
			else if (type == 'h')
			{
				for (size_t i = 0; i < employees.size(); i++)
				{
					HourlyEmployee *derivedPtr =
						dynamic_cast < HourlyEmployee * >
						(employees[i]);

					if (derivedPtr != nullptr) {
						if (typeid(*derivedPtr).name() == typeid(HourlyEmployee).name())
							derivedPtr->print(); cout << endl;
					}
				}
			}
			else
			{
				for (size_t i = 0; i < employees.size(); i++)
				{
					HourlyPlusCommissionEmployee *derivedPtr =
						dynamic_cast < HourlyPlusCommissionEmployee * >
						(employees[i]);

					if (derivedPtr != nullptr) {
						if (typeid(*derivedPtr).name() == typeid(HourlyPlusCommissionEmployee).name())
							derivedPtr->print(); cout << endl;
					}
				}
			} 

			break;

		case 'l':
			for (auto it = employees.begin();
				it != employees.end();
				++it)
			{
				(*it)->print();
				cout << "\n\n";
			}

			break;
		case 'q':
			return 0;

		default:
			break;
		}

		cout << '\n';
	}
}