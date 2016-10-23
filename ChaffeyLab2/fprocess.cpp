#include "fprocess.h"

Fprocess::Fprocess(char* fname)
{
    //cout<<"Fprocess constructor"<<endl;
    instream.open(fname);
    if(instream.fail())
    {
        cout<<"falied to open"<<endl;
        exit(0);
    }
    else
    {
        _more=true;
        InitializeVector(95);
        Process();
       }
}
void Fprocess::FillBlock()
{
   // cout<<"FillBlock()"<<endl;
    char temp;
    int size=0;
    while(instream>>temp && size<Maxsize)
      {
        //cout<<temp<<endl;
          Block.push_back(temp);
           ++size;
      }
    if(instream.eof())
        _more=false;
}
void Fprocess::Process()
{
    //cout<<"Process()"<<endl;
    int ASCII,n;

    while(_more)
    {
        FillBlock();
         n=Block.size();
        for(int i=0;i<n;i++)
        {
            //cout<<"(int i=0;i<n;i++)"<<endl;
            ASCII=(int)Block[i];
            //cout<<ASCII;
            if(ASCII>=32)
            {
               // cout<<"if(ASCII>=32)"<<endl;
                ChOccurance[Index(ASCII)]=ChOccurance[Index(ASCII)] + 1;//probably not going to work
            }
        }
        Block.clear();

    }
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
