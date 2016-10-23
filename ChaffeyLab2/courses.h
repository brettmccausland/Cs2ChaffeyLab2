#ifndef COURSES_H
#define COURSES_H
#include<fstream>
#include"node.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Courses
{
public:
    Courses();
    void PrintStudentReport(int IdNumber);

    ~Courses();
private:
     void Getnextfname();
     void GetStudentReport(int IdNumber);
    ifstream instream;
    ifstream Gstream;

    string coursename;
    string fname;
    string classlist;

    node student;
    bool _more;


};

#endif // COURSES_H
