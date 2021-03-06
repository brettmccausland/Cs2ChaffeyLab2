#include "courses.h"

Courses::Courses()
{
    classlist="classes.txt";
    fname="";
    coursename="";
    _more=true;
}

Courses::~Courses()
{

}
//precondition: file is open under instream
 void Courses::Getnextfname()
 {
     string input;
     int coursenumber;
     string course;

     getline(instream,input);
      stringstream ss(input);
      ss>>coursenumber>>course;
      coursename=course + " ";
      fname=course + ".txt";
      if(instream.eof())
          _more=false;

 }
 void Courses::PrintStudentReport(int IdNumber)
 {
     GetStudentReport(IdNumber);
     student.printReport();
     student.reset();
 }
void Courses::GetStudentReport(int IdNumber)
{
    stringstream temp;
    student.SetId(IdNumber);
    string input;
    int rosternum;
    int idnumber;
    string grade;

    instream.open(classlist.c_str());
    if(instream.fail())
        cout<<"file doesnt exist"<<endl;
    else
     {
              while(_more)
              {
                Getnextfname();
                Gstream.open(fname.c_str());
                while(getline(Gstream, input))
                 {
                    stringstream ss(input);
                    ss >> rosternum >> idnumber>>grade;
                    if(idnumber==IdNumber)
                    {
                       coursename.append(grade);
                        student.Insertcourse(coursename);
                        break;
                    }
                  }
                  Gstream.close();
                }
              _more=true;
               instream.close();
               Gstream.close();
               fname="";
               coursename="";
        }
 }


