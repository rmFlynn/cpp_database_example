//Created by Rory Flynn 

// I might be breaking this into two classes. That way I don't have to make my CSV reader to specific.
#ifndef UITOOlS_
#define UITOOLS_
#include <iostream>
#include <string>
#include <sstream>

typedef std::string word;

using namespace std;

// MovED to ui tool
void userGetWord(word & target, bool & nulDicator);
void userGetInt(int & target, bool & nulDicator);
void userGetChar(char & target, bool & nulDicator);
void userGetDouble(double & target, bool & nulDicator);
void userGetBool(bool & target, bool & nulDicator, word truth, word lie);


#endif
