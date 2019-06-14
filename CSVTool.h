//Created by Rory Flynn 
#ifndef CSVTOOL_
#define CSVTOOL_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


typedef std::string word;

using namespace std;

// Okay so this is how I envisioned this working.
class CSVTool {

private:
    ifstream file;
    // This holds all the fields in a record, temporarily in string format.
    vector<word> line;
    // Is this file valid? Store the answer here.
    bool valid;
    word trim(const word & str);

public:
    CSVTool(const char* fileName);
    ~CSVTool();
    // check if the file is valid.
    bool isValid();
    // check if the list has that entery.
    int lineSize();
    // This simply parse is a line.
    bool readLine(char delim, int num);
    // This prints a line to a file, converting things back to Word format as it goes.
    void wrightLine(ifstream& file, char** line);
    // These take the position in the CSV line as a input. 
    // They output that field in their designated data type.
    // NOT YET MADE
    void csvGetBool (int n, bool & target, bool & nulDicator, word truth, word lie);
    void csvGetChar(int n, char & target, bool & nulDicator);
    void csvGetDouble(int n, double & target, bool & nulDicator);
    void csvGetInt(int n, int & target, bool & nulDicator);
    void csvGetWord(int n, word & target, bool & nulDicator);

};

#endif



