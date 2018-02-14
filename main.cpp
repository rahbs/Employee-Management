#include <iostream>
#include <vector>
#include "BasePlusCommissionEmployee.h"
#include "CommissionEmployee.h"

using namespace std;

int main()
{
	vector<CommissionEmployee*> employees;
	CommissionEmployee* employeePtr = nullptr;

	char oper;
	char type;
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;
	double commissionRate;
	double BaseSalary;

	while (true)
	{
		CommissionEmployee* max = nullptr;

		cout << "  ****command > ";
		cin >> oper;

		switch (oper)
		{
		case 'n':
		{
			cin >> type >> firstName >> lastName >> socialSecurityNumber >> grossSales >> commissionRate;

			if (type == 'c')
				employeePtr = new CommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate);
			else if (type == 'b')
			{
				cin >> BaseSalary;
				employeePtr = new BasePlusCommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate, BaseSalary);
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
					(*it)->print();
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
			max->print();
			
			break;
		case 'l':
			for (auto it = employees.begin();
				it != employees.end();
				++it)
			{
				(*it)->print();
			}
			
			break;
		case 'q':
			return 0;
		default:
			break;
		}
	}
}