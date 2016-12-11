#ifndef STAFF
#define STAFF
#ifndef STAFF_H
#define STAFF_H
#include"ccc_empl.h"
#include<istream>
#include<vector>
using namespace std;

class Staff
{
public:
    Staff();
    Staff(vector<Employee>a);
    void addEmployee(Employee &a);
    void insert_employee(Employee &a);
    int find(string name);
    void RasieEveryoneSalary(double percent);
    void LowerEveryoneSalary(double percent);
    void SaveStaff();
    void print();
    void print_employee(int pos);
    void selection_sort();
    ~Staff();
private:
    int min_position(vector<Employee>& a, int from, int to);
    void swap(Employee &x, Employee &y);
    void raise_salary(Employee& e, double percent);
    void lower_salary(Employee& e, double percent);
    void loadteam();
    vector<Employee> team;
    string Fname;
};
Staff::Staff(vector<Employee>a)
{
    team.operator =(a);
      Fname="Staffdatabase.txt";

}
 int Staff::find(string name)
 {
     for(int i=0;i<team.size();i++)
     {
         Employee r = team[i];
         if(name== r.get_name())
             return i;
     }
     return -1;
 }
void Staff::print_employee(int pos)
{
    Employee r =team[pos];
    cout<<r.get_name()<<", ";
    cout<<r.get_salary();

}
void Staff::insert_employee(Employee &a)
{
    team.push_back(a);
}

void Staff::raise_salary(Employee& e, double percent)
{
   double new_salary = e.get_salary() * (1 + percent / 100);
   e.set_salary(new_salary);
}
void Staff::lower_salary(Employee& e, double percent)
{
   double new_salary = e.get_salary() * (1 - percent / 100);
   e.set_salary(new_salary);
}
void Staff::loadteam()
{
    ifstream instream;
    string input;
    int number=0;
    string tempname;
    double tempsalary;
    instream.open(Fname.c_str());
    if(instream.fail())
        cout<<"failed to load staff";
    else
    {
        while(getline(instream,input))
        {
            stringstream ss(input);
            ss>>tempname>>tempsalary;
            Employee t (tempname,tempsalary,number);
             ++number;
            team.push_back(t);
        }
        instream.close();
    }
}
 void Staff::RasieEveryoneSalary(double percent)
 {
    if(team.empty())
        loadteam();
    else
    {
        int n=team.size();
        for(int i=0;i<n;++i)
            raise_salary(team[i],percent);
    }
    SaveStaff();
 }
void Staff::LowerEveryoneSalary(double percent)
{
    if(team.empty())
        loadteam();
    else
    {
        int n=team.size();
        for(int i=0;i<n;++i)
            lower_salary(team[i],percent);
    }
    SaveStaff();
 }

Staff::Staff()
{
    team.clear();
    Fname="Staffdatabase.txt";

}
void raise_salary(Employee& e, double percent)
{
   double new_salary = e.get_salary() * (1 + percent / 100);
   e.set_salary(new_salary);
}
void Staff::addEmployee(Employee& a)
{
    if(team.empty())
        a.set_number(0);
    else
        a.set_number(team.size()-1);
}
 void Staff::SaveStaff()
 {

     ofstream outstream;
     outstream.open(Fname.c_str());
     if(outstream.fail())
         cout<<"ERROR"<<endl;
     else
     {
         int n=team.size();
         for(int i=0; i<n;++i)
         {
             outstream<<team[i];// need to overload the operator
             outstream<<endl;
         }
         outstream.close();
     }
 }

int Staff::min_position(vector<Employee>& a, int from, int to)
{
   int min_pos = from;
   int i;
   Employee temp1,temp2;
   for (i = from + 1; i <= to; i++)
    {
       temp1=a[i];
       temp2=a[min_pos];
       if (temp1.get_salary()< temp2.get_salary())
           min_pos = i;
     }
   return min_pos;

}
void Staff::selection_sort()
{
   int next; // The next position to be set to the minimum
    int max=team.size() - 1;
   for (next = 0; next <max; next++)
   {
      // Find the position of the minimum
      int min_pos = min_position(team, next, max);
      if (min_pos != next)
         swap(team[min_pos], team[next]);
   }
}
void Staff::swap(Employee& x, Employee& y)
{
    //team.swap(x,y);
   Employee temp = x;
   x = y;
   y = temp;
}
Staff::~Staff()
{
    team.clear();
}
void Staff::print()
{
    Employee temp;
    int n=team.size();
   for (int i = 0; i < n; i++)
    {
        temp= team[i];
        temp.printinfo();
        cout << "\n";
   }

}
#endif // STAFF_H

#endif // STAFF

