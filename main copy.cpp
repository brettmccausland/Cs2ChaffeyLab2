#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>
//#include <iomnip>

/*
    Brett mccausland
    Lab 2 Streams
    Last Updated by: Brett mccausland
    Last updated : 10-02-16

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
void  CountCharacterOccurance(vector<char>& Data, vector<char>& characters, vector<int>& CharsWordsLinesCount); // not yet written
void DisplayFrequencyChart(const vector<char>& characters,const vector<int>& CharsWordsLinesCount);// not yet writen
void InitializeAlphabetAndLineAndSpace(vector<char>& characters);  // not yet written

void Exercise_R9_1();// brett done
void Exercise_R9_2();// brett done
void Exercise_R9_3();// elizabeth
void Exercise_R9_4();//andre
void Exercise_R9_5();// rex
void Exercise_R9_6();//brett
void Exercise_R9_7();//elizabeth
void Exercise_R9_8();//andre
void Exercise_R9_9();// rex
void Exercise_R9_10();//brett
void Exercise_R9_11();//andre
void Exercise_R9_12();//brett done
//----------------------------------
void Exercise_P9_1();// brett( in progress)
void Exercise_P9_3();// brett( in progress)
void Exercise_P9_6();// elizabeth
void Exercise_P9_7();//andre
void Exercise_P9_8(); // rex
void Exercise_P9_13();// brett


int main()
{
    system("clear");

    Exercise_R9_1(); // Brett (done)
    //Exercise_R9_2(); //Brett (done)
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
    //Exercise_P9_1();
     //Exercise_P9_3();
     //Exercise_P9_6();
    //Exercise_P9_7();
    //Exercise_P9_8();
    //Exercise_P9_13();
    return 0;
}
void Exercise_R9_2()
{
    // Question: When do you open a file as an ifstream, as an ofstream, or as an fstream? Could you simply open all files as an fstream?
    // Anwser: You open a file with ifstream when your going to read from it with.You open a file with ofstream when you are going to write to it.
    // You could accomplish both with fstream however it is in best practice to use the specialized streams for the specific task
}
void Exercise_R9_1()
{
    //Write C++ code to open a file with the name Hello.txt, store the message “Hello, World!” in the file, and close the file.
    //Then open the same file again and read the message into a string variable. Close the file again.
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
//   Exercise_R9_1()comand prompt
//
//      Hello World
//
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
}

void Exercise_R9_4()
{
    //What happens if you try to open a file for reading that doesn’t exist? What happens if you try to open a file for writing that doesn’t exist?
}

void Exercise_R9_5()
{
   // What happens if you try to open a file for writing, but the file or device is write-protected (sometimes called read-only)?
    //Try it out with a short test program.
}

void Exercise_R9_6()
{
    //How do you open a file whose name contains a backslash, like temp\output.dat or c:\temp\output.dat?
}

void Exercise_R9_7()
{
    //Question: Why is the ifstream parameter of the read_data procedure in Section 9.2 a reference parameter and not a value parameter?
    //Anwser:

}

void Exercise_R9_8()
{
    //Exercise R9.8. How can youc onvert the string "3.14" into the floating-pointnumber 3.14? How can you convert the floating-point number 3.14 into the string "3.14"?
}

void Exercise_R9_9()
{
    //What is a command line?
    //How can a program read its command line?
}
void Exercise_R9_10()
{
    //If a program woozle is started with the command woozle -DNAME=Piglet -I\eeyore -v heff.cpp a.cpp lump.cpp
}

void Exercise_R9_11()
{
    //How can you break the Caesar cipher? That is, how can you read a letter that was encrypted with the Caesar cipher, even though you don’t know the key?
}

void Exercise_R9_12()
{
   //Question: What is the difference between sequential access and random access?
  // Anwser: sequntial access, accesses data by reading through the entire file, random access goes directly to a specific location
}
//----------------------------Programming Exercises----------------------------
void Exercise_P9_1()
{
    // Write a program that asks the user for a file name and displays the number of characters, words, and lines in that file.
    //Then have the program ask for the name of the next file. When the user enters a file that doesn’t exist (such as the empty string), the program should exit.
    vector<int> CharsWordsLinesCount ;
    vector<char> characters;
    vector<char>Data;
    InitializeAlphabetAndLineAndSpace(characters);
    loadFromUserDeclaredFile(Data);
    CountCharacterOccurance(Data,characters,CharsWordsLinesCount);
    DisplayFrequencyChart(characters,CharsWordsLinesCount);

}
void InitializeAlphabetAndLineAndSpace(vector<char>& characters)
{

}
void DisplayFrequencyChart(const vector<char>& characters,const vector<int>& CharsWordsLinesCount)
{

}

void  CountCharacterOccurance(vector<char>& Data, vector<char>& characters, vector<int>& CharsWordsLinesCount)
{

}
void Exercise_P9_3()
{
    // Write a program that reads an input file and displays the letter frequencies in that file. Such a tool will help a code breaker.
    // If the most frequent letters in an encrypted file are H and K, then there is an excellent chance that they are the encryptions of E and T.

}
void Exercise_P9_6()
{

}
void Exercise_P9_7()
{
    //The program in Section 9.6 only locates one record and updates the salary.
    //Write a program that raises or lowers the salaries of all employees by a given percentage.
}
void Exercise_P9_8()
{

}
void Exercise_P9_13()
{

}