# Employee-Management
a program for managing employee salaries
<!DOCTYPE html><html>  <head>    <meta charset="utf-8">  </head>  <body><p> -salary infomation <br/>  CommisionEmployee<br/>  (GrossSales) * (CommissionRate)<br/>  BasePlusCommissionEmployee<br/>  (GrossSales) * (CommissionRate) +(BaseSalary)<br/>  SalariedEmployee<br/>  (BaseSalary)<br/>  HourlyEmployee<br/>  (hourly wage ) * (working hours)<br/>  HourlyPlusCommissionEmployee<br/>  (GrossSales) * (CommissionRate) +(hourly wage ) * (working hours)<br/></p><p>    -input types : GrossSales: double(type), greater than or equal to 0<br/>  CommissionRate : double(type), [0, 1]<br/>   BaseSalary : double(type), greater than or equal to 0<br/>   hourly wage : double(type), greater than or equal to 0<br/>   working hours : double(type), greater than or equal to 0<br/>   firstname : string(type)<br/>   lastname : string(type)<br/>   socialSecurityNumber : string(type)<br/></p><p>   - functions<br/>   1. n : Add Employee<br/>   *input : n (type of employee) (first name) (last name) (socialSecurityNumber) (salary information)<br/>   char types of employee = { ‘b’, ‘c’, ‘s’, ‘h’, ‘a’ }<br/>  c: CommisionEmployee<br/>   b : BasePlusCommissionEmployee<br/>   s : SalariedEmployeeh: HourlyEmployee<br/>   a : HourlyPlusCommissionEmployee<br/>   2. s : Print out employee with the corresponding name<br/>   (print out all matching employees)<br/>    If there is no matching employee, nothing happens and the next command is processed<br/>   *input : s (firstname) (lastname)<br/>   3. d : Delete employee with the corresponding name<br/>   *input : s (firstname) (lastname)<br/>   4. t : Print out the highest earning employee<br/>   5. l : Print out all employees<br/>   8. e : Print out all employees of a certain type<br/>   *input : e (type of employee)<br/>   7. q : End the program<br/></p>
  </body></html>

