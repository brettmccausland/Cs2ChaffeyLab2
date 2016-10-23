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

#endif // NODE_H
