//Created by Rory Flynn 
//
// Note that this part of the program will be extended into a tool for reading 
// more complex csv files in the final project.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "CSVTool.h"


using namespace std;

// The constructor opens the file and sets the valid flag should you choose to
// access it.
CSVTool::CSVTool(const char* fileName){
    file.open(fileName);// File full of events
    if (!file)// Check that the file exists.
        valid = false;
    else
        valid = true;
}

// Destructor closes the file
CSVTool::~CSVTool(){
    file.close();
}

// This loads a new line and parses it
bool CSVTool::readLine(char delim, int num){
    // each read starts fresh.
    line.clear();
    word tmp;
    int count = 0;
    // Pull in one line for the file.
    getline(file, tmp, '\n');
    // Unless there are no more lines
    if(file.eof())
        return false;
    // Add the line to the file
    istringstream buffer(tmp);
    // Go threw the buffer using the passed delimiter, and add them to the vector.
    while (getline(buffer, tmp, delim) ) {
        line.push_back(trim(tmp));
        count++; // Also there is a counter not used yet. NOTE TO SELF
    }
    return true;
}

// Return the size of the current line for special case use 
int CSVTool::lineSize(){
    return line.size();
}

// Return the specified field as a word AKA string, meaning no need to convert type 
void CSVTool::csvGetWord(int n, word & target, bool & nulDicator){
    // check that the field is not null
    if(line[n].length() < 1){
        nulDicator = true;
    }
    else{
        // Set value
        nulDicator = false;
        target = line[n];
    }
}

// Return a field as a int and check it of coarse.
void CSVTool::csvGetInt(int n, int & target, bool & nulDicator){
    // check that the field is not null
    if(line[n].length() < 1){
        nulDicator = true;
    }
    else{
        stringstream notNums(line[n]); 
        // Convert
        notNums >> target; 
        // Set the valid bit.
        nulDicator = notNums.fail();
    }
}

// Return a field as a int and check it of coarse.
void CSVTool::csvGetChar(int n, char & target, bool & nulDicator){
    // check that the field is not null
    if(line[n].length() < 1){
        nulDicator = true;
    }
    else{
        stringstream notNums(line[n]); 
        // Convert
        notNums >> target; 
        // Set the valid bit.
        nulDicator = notNums.fail();
    }
}

// Return a field as a int and check it of coarse.
void CSVTool::csvGetDouble(int n, double & target, bool & nulDicator){
    // check that the field is not null
    if(line[n].length() < 1){
        nulDicator = true;
    }
    else{
        stringstream notNums(line[n]); 
        // Convert
        notNums >> target; 
        // Set the valid bit.
        nulDicator = notNums.fail();
    }
}

// Return a field as a int and check it of coarse.
void CSVTool::csvGetBool (int n, bool & target, bool & nulDicator, word truth, word lie){
    // It should be the truth or the lie if it is valid
    nulDicator = (!( (line[n] == truth) || (line[n] == lie) ));
    // It only needs to be the truth for it to be true.
    target = (line[n] == truth);
}

// Is the file valid mostly meaning is it there
bool CSVTool::isValid(){
    return valid;
}

// Trim function to trim string inspierd by 
// https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
word CSVTool::trim(const word & str){
    const auto strBegin = str.find_first_not_of(' ');
    if (strBegin == word::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(' ');
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}
