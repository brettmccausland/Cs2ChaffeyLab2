#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class node
{
public:
    node();
    ~node();
    void SetId(int number);
     int GetId();
     void reset();

    void Insertcourse(string course);
    void printReport();

private:
    int Idnumber;
    vector<string> classes;
};

node::node()
{
    Idnumber=0;

}
void node::SetId(int number)
{
    Idnumber=number;
}
int node::GetId()
{
   return Idnumber;
}
void node::Insertcourse(string course)
{
    classes.push_back(course);
}
void node::printReport()
{
    cout<<"Student "<<Idnumber<<endl;
    int n=classes.size();
    for(int i=0;i<n;i++)
        cout<<classes[i]<<endl;
}
 void node::reset()
 {
     Idnumber=0;
     classes.clear();
 }

node::~node()
{
    Idnumber=0;
    classes.clear();
}
#endif // NODE_H
