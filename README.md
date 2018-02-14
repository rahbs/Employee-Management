# Employee-Management
a program for managing employee salaries

-salary infomation
CommisionEmployee
<GrossSales> * <CommissionRate>
BasePlusCommissionEmployee
<GrossSales> * <CommissionRate> + <BaseSalary>
SalariedEmployee
<BaseSalary>
HourlyEmployee
<hourly wage > * <working hours>
HourlyPlusCommissionEmployee
<GrossSales> * <CommissionRate> + <hourly wage > * <working hours>

-input types:GrossSales: double(type), greater than or equal to 0
CommissionRate: double(type),[0, 1]
BaseSalary: double(type), greater than or equal to 0
hourly wage: double(type), greater than or equal to 0
working hours: double(type), greater than or equal to 0
firstname: string(type)
lastname: string(type)
socialSecurityNumber: string(type)

-functions
1. n: Add Employee
*input: n <type of employee> <first name> <last name> <socialSecurityNumber> <salary information>
char types of employee = {‘b’, ‘c’, ‘s’, ‘h’, ‘a’}
c: CommisionEmployee
b: BasePlusCommissionEmployee
s: SalariedEmployeeh: HourlyEmployee
a: HourlyPlusCommissionEmployee
2. s: Print out employee with the corresponding name
(print out all matching employees)If there is no matching employee, nothing happens and the next command is processed
*input:s <firstname> <lastname>
3. d: Delete employee with the corresponding name
*input:s <firstname> <lastname>
4. t: Print out the highest earning employee
5. l: Print out all employees
8. e: Print out all employees of a certain type
*input: e <type of employee>
7. q: End the program
