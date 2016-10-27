#ifndef FPROCESS_H
#define FPROCESS_H
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#define Index(n)(n-32)
using namespace std;

class Fprocess
{
public:

    Fprocess(string fname);
    void ProcessCharacters();
    void Filltemplate(string DataBase,string Template );
    void ProcessWordsLines();
    void printFrequency();
    int Get_WordCount();
    int Get_LineCount();
     int Get_CharacterCount();
    ~Fprocess();
private:
    bool more();
    void InitializeVector(int size);
    void FillBlock();

     const static int Maxsize=100;
    vector<int> ChOccurance;
    ifstream instream;
    bool _more;
    vector<char> Block;
    string Myfname;
    long int word_count;
    long int line_count;
    long int Characters;

};

Fprocess::Fprocess(string fname)
{
        //cout<<"Fprocess constructor"<<endl;
        _more=true;
        InitializeVector(95);
        Myfname=fname;
        word_count=0;
        line_count=0;
        Characters=0;
}
void Fprocess::ProcessWordsLines()
{

    stringstream temp;
    string input;
    string word;
    instream.open(Myfname.c_str());
    if(instream.fail())
        cout<<"file doesnt exist"<<endl;
    else
    {
        while(getline(instream, input))
        {

           // cout<<"input: "<<input<<endl;
            stringstream ss(input);

            while(ss>>word)
             {
                   cout<<"Word: "<<word<<endl;
                   word_count++;
              }
            ++line_count;
          }
    }
    instream.close();
}
void Fprocess::Filltemplate(string DataBase,string Template )
{
//    stringstream temp;
//    string input;
//    string word;
//    string suffix,Firstname,lastname,Adress,Stsuffix,City,State,Zip;
//    ifstream Templatestream;
//    ostream newfile;
//    ifstream ;
//    instream.open(DataBase.c_str());
//    Templatestream.open(Template.c_str());

//    if(instream.fail())
//        cout<<"file doesnt exist"<<endl;
//    else
//    {
//        while(getline(instream, input))// from database
//        {
//            stringstream ss(input);
//            ss>>suffix>>Firstname>>lastname>>Adress>>Stsuffix>>City>>State>>Zip;
//            newfile.open(lastname.c_str());

//          }
//    }
//    instream.close();
}
void Fprocess::FillBlock()
{
   // cout<<"FillBlock()"<<endl;
    char temp;
    int size=0;
    while(instream>>temp && size<Maxsize)
      {
        Characters++;
        //cout<<temp<<endl;
          Block.push_back(temp);
           ++size;
      }
    if(instream.eof())
        _more=false;
}
void Fprocess::ProcessCharacters()
{
     instream.open(Myfname.c_str());
    int ASCII,n;
    if(instream.fail())
    {
        cout<<"falied to open"<<endl;
        exit(0);
    }
    else
    {
        while(_more)
        {
            FillBlock();
            n=Block.size();
            for(int i=0;i<n;i++)
            {
                ASCII=(int)Block[i];
                if(ASCII>=32)
                    ChOccurance[Index(ASCII)]=ChOccurance[Index(ASCII)] + 1;//probably not going to work
            }
            Block.clear();
         }
    }
    instream.close();
}
void Fprocess::InitializeVector(int size)
{
    for(int i = 0 ;i<size;i++)
        ChOccurance.push_back(0);
}
Fprocess::~Fprocess()
{
    Block.clear();
    ChOccurance.clear();
 }
int Fprocess::Get_WordCount()
{
    return word_count;
}

int Fprocess::Get_LineCount()
{
    return line_count;
}
int Fprocess::Get_CharacterCount()
{
    return Characters;
}
void Fprocess:: printFrequency()
 {
        int n=ChOccurance.size();
        n=n+32;
        char CH;
        for(int i=32;i<n;++i)
        {
            CH=(char)i; // probably not going to work
            cout<<CH;
            cout<<":  "<<ChOccurance[i-32]<<endl;
        }
 }
bool Fprocess::more()
{
   return _more;
}
#endif // FPROCESS_H
