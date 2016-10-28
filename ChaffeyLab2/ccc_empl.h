#ifndef CCC_EMPL
#define CCC_EMPL
#include"fstream"
class Employee
{
public:
   Employee();
   Employee(string employee_name, double initial_salary);
   Employee(string employee_name, double initial_salary,int num);
   void set_salary(double new_salary);
   void set_number(int num);
   void set_name(string n);
    int get_number();
   double get_salary() const;
   string get_name() const;
   void printinfo()const;
   void operator =(const Employee r);
  friend ostream& operator<<(ostream& os, const Employee& obj);
private:
   string name;
   double salary;
   int number;
};
 void Employee::set_name(string n)
 {
     name=n;
 }
Employee:: Employee(string employee_name, double initial_salary,int num)
 {
    name = employee_name;
    salary = initial_salary;
    number=num;
 }

void Employee::operator =(const Employee r)
{
    this->set_salary(r.get_salary());
    this->set_name(r.get_name());
}
ostream& operator<<(ostream& os, const Employee& obj)
{

    os<<obj.get_name();
    os<<" ";
    os<<obj.get_salary();
    return os;
}
Employee::Employee()
{
   salary = 0;
   name="";
   number=0;
}

Employee::Employee(string employee_name, double initial_salary)
{
   name = employee_name;
   salary = initial_salary;
}
void Employee::printinfo()const
{
    cout<<name<<": "<<salary;
}

void Employee::set_salary(double new_salary)
{
   salary = new_salary;
}

double Employee::get_salary() const
{
   return salary;
}
void Employee::set_number(int num)
{
    number=num;
}
int  Employee::get_number()
{
      return number;
}

string Employee::get_name() const
{
   return name;
}
#endif // CCC_EMPL

