#include "fprocess.h"


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
   // cout<<"FillBlock()"<<endl;
    stringstream temp;
    string input;
    string word;
    instream.open(Myfname.c_str());
    if(instream.fail())
    {
        cout<<"file doesnt exist"<<endl;
    }
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
    //cout<<"Process()"<<endl;
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
