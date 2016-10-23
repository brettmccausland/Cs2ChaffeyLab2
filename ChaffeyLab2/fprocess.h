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

#endif // FPROCESS_H
