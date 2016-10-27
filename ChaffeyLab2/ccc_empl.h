#ifndef CCC_EMPL
#define CCC_EMPL
class Employee
{
public:
   Employee();
   Employee(string employee_name, double initial_salary);
   void set_salary(double new_salary);
   double get_salary() const;
   string get_name() const;
private:
   string name;
   double salary;
};
Employee::Employee()
{
   salary = 0;
}

Employee::Employee(string employee_name, double initial_salary)
{
   name = employee_name;
   salary = initial_salary;
}

void Employee::set_salary(double new_salary)
{
   salary = new_salary;
}

double Employee::get_salary() const
{
   return salary;
}

string Employee::get_name() const
{
   return name;
}
#endif // CCC_EMPL

