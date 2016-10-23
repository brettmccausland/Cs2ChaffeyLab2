#ifndef FPROCESS_H
#define FPROCESS_H
#include <fstream>
#include <iostream>
#include <vector>
#define Index(n)(n-32)
using namespace std;

class Fprocess
{
public:

    Fprocess(char *fname);
     void printFrequency();
    ~Fprocess();
private:
    bool more();
    void InitializeVector(int size);
    void FillBlock();
    void Process();

     const int Maxsize=100;
    vector<int> ChOccurance;
    ifstream instream;
    bool _more;
    vector<char> Block;

};

#endif // FPROCESS_H
