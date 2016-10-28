#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include"fprocess.h"
#include"courses.h"
#include "ccc_empl.h"
#include"staff.h"

const int NEWLINE_LENGTH = 2;
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;
//#include <iomnip>

/*
    Brett mccausland
    Lab 2 Streams
    Last Updated by: Brett mccausland
    Last updated : 10-23-16

*/
using namespace std;

template<typename Item_type>
void SaveToUserDeclaredFile(const vector<Item_type>& set, ofstream &myfile);

void SaveToFile(string filename, const vector<string> Data, ofstream &myfile);

template<typename Item_type>
void loadFromFile(string filename, vector<Item_type>& data, ifstream& myfile);

template<typename Item_type>
void loadFromUserDeclaredFile(vector<Item_type>& data);

void Print (const vector<string>& data);
void InitializeVector(vector<int>& Fillwithzeros,int size);
void Processfile(string name,bool& run);

void raise_salary(Employee& e, double percent);
void read_employee(Employee& e, istream& in);
void Filltemplate(string DataBase,string Template );

void Exercise_R9_1();// (done)
void Exercise_R9_2();// (done)
void Exercise_R9_6();//(done)
void Exercise_R9_10();//(done)
void Exercise_R9_12();//(done)
void Exercise_P9_1();// ( done)
void Exercise_P9_3();// (done)
void Exercise_P9_13();// (done)
void Exercise_R9_3();//(done)
void Exercise_R9_4();//(done)
void Exercise_R9_7();//(done)
void Exercise_R9_5();//(doen)
void Exercise_R9_8();//(done)
void Exercise_R9_9();//(done)
void Exercise_R9_11();//(done)
void Exercise_P9_7();//(done)
void Exercise_P9_8(); //(done)

void Exercise_P9_6();//(in progress)




int main()
{
    system("clear");
    cout<< "lab 2 "<<endl;
    //Exercise_R9_1();
    //Exercise_R9_2();
    //Exercise_R9_3();
    //Exercise_R9_4();
    //Exercise_R9_5();
    //Exercise_R9_6();
     //Exercise_R9_7();
     //Exercise_R9_8();
     //Exercise_R9_9();￼￼
    //Exercise_R9_10();
    //Exercise_R9_11();
    //Exercise_R9_12();
    //----------------------------------
   // Exercise_P9_1();
     //Exercise_P9_3();
     Exercise_P9_6();
   // Exercise_P9_7();
    //Exercise_P9_8();
    //Exercise_P9_13();
    return 0;
}
void Exercise_R9_2()//brett done
{
    // Question: When do you open a file as an ifstream, as an ofstream,
    // or as an fstream? Could you simply open all files as an fstream?
    // Anwser: You open a file with ifstream when your going to read from it
    // with.You open a file with ofstream when you are going to write to it.
    // You could accomplish both with fstream however it is in best practice
    // to use the specialized streams for the specific task
}
void Exercise_R9_1()// brett done
{
    //Write C++ code to open a file with the name Hello.txt,
    //store the message “Hello, World!” in the file, and close the file.
    //Then open the same file again and read the message into a string variable.
    //Close the file again.

    ofstream myfile;
    ifstream infile;
    string s;
    string filename;
    filename="Hello.txt";
    vector<string> dataout;
    vector<string> dataIn;
    dataout.push_back("Hello");
    dataout.push_back("World");

    SaveToFile(filename,dataout,myfile);
    loadFromFile(filename,dataIn,infile);
    Print(dataIn);
    cout<<endl;
}
void Print(const vector<string>& data)
{
    for(size_t i=0;i<data.size();i++)
        cout<<data[i]<<" ";
}
template<typename Item_type>
void loadFromUserDeclaredFile(vector<Item_type>& data)// untested (brett)
{
    ifstream myfile ;
    string in;
    cout<<"please enter the name of file you wanted to load"<<endl;
    getline(cin,in);
    loadFromFile(in, data, myfile);
}
template<typename Item_type>
void loadFromFile(string filename, vector<Item_type> &data, ifstream& myfile)
{
    myfile.open(filename.c_str());
    Item_type temp;
    if(myfile.is_open())
    {
      while (myfile>>temp)
         data.push_back(temp);
     myfile.close();
    }
    else cout << "Unable to open file\n";
}
// WARNING !!!!! UNTESTED FUNCTION SaveToUserDeclaredFile
template<typename Item_type>
void SaveToUserDeclaredFile(const vector<Item_type> &set, ofstream &myfile)
{
    char key;
    string in;
    cout<<"Please enter the name for your file"<<endl;
    getline(cin,in);
    while(ifstream(in.c_str()))
    {
        cout<<"file already exist. Do you want to replace it or create other file name? yes for replace/n for create new "<<endl;
        cin>>key;
        if(key=='y')
            remove(in.c_str());
        else
        {
            cout<<"Please enter the name for your file"<<endl;
            getline(cin,in);
        }
    }
  SaveToFile(in,set,myfile);
}
// precondition: file is closed
// type specialized for formating corectness
void SaveToFile( string filename,const vector<string> Data, ofstream &myfile)
{
    myfile.open(filename.c_str());
    for(size_t i=0;i<Data.size();i++)
    {
        myfile<<Data[i];
        myfile<<" ";
    }
    myfile.close();
}
void Exercise_R9_3()
{
    //What happens if you write to a file that you only opened for reading? Try it out if you don’t know.
    //Anwser: If the file is opened with ifstream it will give a compilation error if the insertion operator is facing the wrong way
}

void Exercise_R9_4()
{
    //What happens if you try to open a file for reading that doesn’t exist?
    //Anwser:An exception is thrown
    //What happens if you try to open a file for writing that doesn’t exist?
    //Anwser:A file will be created
}

void Exercise_R9_5()
{
   // What happens if you try to open a file for writing, but the file or device is write-protected
    //(sometimes called read-only)?
    //Try it out with a short test program.
    //Anwser: a flag will be thrown and writing will not occur
}

void Exercise_R9_6()
{
    //How do you open a file whose name contains a backslash, like temp\output.dat or c:\temp\output.dat?
    //Anwser: Everywhere there is a backslash you must add a backslash
}

void Exercise_R9_7()
{
    //Question: Why is the ifstream parameter of the read_data procedure in Section 9.2 a reference parameter and not a value parameter?
    //Anwser:Ifstream is a object and to avoid slicing objects are always past by reference

}

void Exercise_R9_8()
{
    //Exercise R9.8. How can you convert the string "3.14" into the floating-pointnumber 3.14?
    //Anwser: You can define a variable floating point and use a string stream to the stream to the variable
    //How can you convert the floating-point number 3.14 into the string "3.14"?
    //Anwser: ss<<number ss bieing the stringstream number being 3.14
}

void Exercise_R9_9()
{
    // What is a command line?
    // Anwser: comand line is a user interface to the operating system
}
void Exercise_R9_10()
{
    //If a program woozle is started with the command woozle -DNAME=Piglet -I\eeyore -v heff.cpp a.cpp lump.cpp
    //Anwser:arg[i] == the string in the command for example argv[0]= woozle
    //Therefore there are 6 comandline arguments
}

void Exercise_R9_11()
{
    //How can you break the Caesar cipher?
    //Anwser: If you have a large enough sample you can likely decypt by using character occurances
}

void Exercise_R9_12()// brett done
{
   //Question: What is the difference between sequential access and random access?
  // Anwser: sequntial access, accesses data by reading through the entire file, random access goes directly to a specific location
}
//----------------------------Programming Exercises----------------------------
void Exercise_P9_1()//  Brett(done)
{
     //Write a program that asks the user for a file name and displays the number of characters,
     //words, and lines in that file. Then have the program ask for the name of the next file.
     //When the user enters a file that doesn’t exist (such as the empty string), the program should exit.
    string name;
    bool run=true;
        while(run)
        {
            cout<<"Enter the filename"<<endl;
             cin>>name;
            Processfile(name,run);
        }
}
void Processfile(string name,bool& run)
{
    string quit;
    int lines,words,Characters;
    Fprocess myfile(name);
    myfile.ProcessWordsLines();
    words=myfile.Get_WordCount();
    lines=myfile.Get_LineCount();

    myfile.ProcessCharacters();
    Characters=myfile.Get_CharacterCount();
    cout<<"lines: "<<lines<<endl;
    cout<<"words: "<<words<<endl;
    cout<<"Characters: "<<Characters<<endl;
    cout<<"Enter yes to quit or just press return to continue"<<endl;
    cin>>quit;
    if(quit=="yes")
        run=false;
}

void InitializeVector(vector<int>& Fillwithzeros,int size)
{
    for(int i = 0 ;i<size;i++)
        Fillwithzeros.push_back(0);
}
//precondition: file Hello.txt exist and contains text
//uses class Fprocess
void Exercise_P9_3()//done Brett
{
    // Write a program that reads an input file and displays the letter frequencies in that file. Such a tool will help a code breaker.
    // If the most frequent letters in an encrypted file are H and K,
    // then there is an excellent chance that they are the encryptions of E and T.
    string filename = "Hello.txt";
    Fprocess myfile(filename);
    myfile.ProcessCharacters();
    myfile.printFrequency();
}
void Exercise_P9_6()
{
   // Junk mail. Write a program that reads in two files:
   // a template and a database. The template file contains text and tags. The tags have the form |1| |2| |3|...
   // and need to be replaced with the first, second, third, ... field in the current database record.
   // A typical database looks like this:
    //  Mr.|Harry|Hacker|1105 Torre Ave.|Cupertino|CA|95014
    //  Dr.|John|Lee|702 Ninth Street Apt. 4|San Jose|CA|95109
    //  Miss|Evelyn|Garcia|1101 S. University Place|Ann Arbor|MI|48105
    string DataBase="Database.txt";
    string Template="template.txt";
    Filltemplate(DataBase,Template);
}
void Filltemplate(string DataBase,string Template )
{
    stringstream temp;
    string input,input2,output;
    string word,Street;
    string suffix,Firstname,lastname,Adress,Stsuffix,City,State,Zip;
    ifstream Templatestream,instream;
    ofstream outstream;
   // ifstream ;
    instream.open(DataBase.c_str());
    Templatestream.open(Template.c_str());

    if(instream.fail())
        cout<<"Database file doesnt exist"<<endl;
    if(Templatestream.fail())
        cout<<"file doesnt exist"<<endl;
    else
    {
        while(getline(instream, input))// from database
        {
            stringstream ss(input);
            ss>>suffix>>Firstname>>lastname>>Adress>>Street>>Stsuffix>>City>>State>>Zip;
            outstream.open(lastname.c_str());
            while(getline(Templatestream,input2))// lines in template
            {
                stringstream ss2(input2);
                while(ss2>>output)
                 {
                    if(output=="1")
                        outstream<<suffix<<" ";
                    else if(output=="2")
                        outstream<<Firstname<<" ";
                    else if(output=="3")
                        outstream<<lastname<<" ";
                    else if(output=="4")
                     outstream<<Adress<<" ";
                    else  if(output=="5")
                     outstream<<Street<<" "<<Stsuffix<<" ";
                     else if(output=="6")
                        outstream<<City<<" ";
                    else if(output=="7")
                        outstream<<State<<" ";
                    else if(output=="E")
                        outstream<<endl;
                    else
                        outstream<<output<<" ";
                }
            }
            Templatestream.clear();
            Templatestream.seekg(0);
            outstream.close();

          }
        outstream.close();
        instream.close();
        Templatestream.close();
    }

}
void Exercise_P9_7()
{
    //Write a program that raises or lowers the salaries of all employees by a given percentage.

    double salaryone=7300.00;
    double salary2=4300.00;
    double percent=2.0;

    vector<Employee> team;
    Employee a("Alondra",salaryone);
    Employee b("Alek",salary2);
    team.push_back(a);
    team.push_back(b);
    Staff google(team);
    google.SaveStaff();
    google.RasieEveryoneSalary(percent);
    google.LowerEveryoneSalary(10.00);


}
void Exercise_P9_8()
{
   // The program in Section 9.6 asks the user to specify the record number. More likely than not,
   // a user has no way of knowing the record number. Write a program that asks the user for the
   // name of an employee, finds the record with that name, and displays the record.
   // Then the program should give the following options to the user:
   // • Change the salary of this record
   // • View the next record
   // • Find another employee • Quit

       cout << "Please enter the data file name: ";
       string filename;
       cin >> filename;
       fstream fs;
       fs.open(filename.c_str());
       fs.seekg(0, ios::end); // Go to end of file
       int nrecord = fs.tellg() / RECORD_SIZE;

       cout << "Please enter the record to update: (0 - "
          << nrecord - 1 << ") ";
       int pos;
       cin >> pos;

       const double SALARY_CHANGE = 5.0;

       Employee e;
       fs.seekg(pos * RECORD_SIZE, ios::beg);
       read_employee(e, fs);
       raise_salary(e, SALARY_CHANGE);
       cout << "New salary: " << e.get_salary();
       fs.seekp(pos * RECORD_SIZE, ios::beg);
       //write_employee(e, fs);

       fs.close();


}
void Exercise_P9_13()
{
    //Write a program that prints out a student grade report.There is a file, classes.txt,
    //that contains the names of all classes taught at a college, such as
   //classes.txt
   //1 CSC1
   //2 CSC2
   //3 CSC46
    //4 CSC151
    //5 MTH121 6 ...
   //For each class, there is a file with student numbers and grades:
    //csc2.txt
    //1 11234 A-
    //2 12547 B
    //3 16753 B+
    //4 21886 C 5 ...
   //Write a program that asks for a student ID and prints out a grade report for that student,
   //by searching all class files. Here is a sample report

    // Student ID 16753
   //CSC2 B+
   //MTH121 C+
   //CHN1 A
   //PHY50 A-

    Courses Chaffey;
    Chaffey.PrintStudentReport(121667);
}
/**
   Converts a string to a floating-point value, e.g.
   "3.14" -> 3.14.
   @param s a string representing a floating-point value
   @return the equivalent floating-point value
*/
double string_to_double(string s)
{
   istringstream instr(s);
   double x;
   instr >> x;
   return x;
}

/**
   Raises an employee salary.
   @param e employee receiving raise
   @param percent the percentage of the raise
*/

/**
   Reads an employee record from a file.
   @param e filled with the employee
   @param in the stream to read from
*/
void read_employee(Employee& e, istream& in)
{
   string line;
   getline(in, line);
   if (in.fail()) return;
   string name = line.substr(0, 30);
   double salary = string_to_double(line.substr(30, 10));
   e = Employee(name, salary);
}

/**
   Writes an employee record to a stream.
   @param e the employee record to write
   @param out the stream to write to
*/




