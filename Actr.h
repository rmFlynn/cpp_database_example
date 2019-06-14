//Created by Rory Flynn 

// I might be breaking this into two classes. That way I don't have to make my CSV reader to specific.
#ifndef ACTR_
#define ACTR_
#include <iostream>
#include <string>
#include "BSTree.h"
#include "uiTools.h"
#include "CSVTool.h"

typedef std::string word;

using namespace std;
// Create a structure to hold data for moving pictures. Note that includes 
// title even though that will be the key for the binary search tree.
class Actr
{
private:
    //
    // The rest of the private variables
    // are the values of the fields in this class
    //
    // This can Not be blank

    word name;

    int year;
    bool yearEmpty;

    word award;
    bool awardEmpty;

    bool winner;
    bool winnerEmpty;

    word film;
    bool filmEmpty;

    word bool_to_string(bool b);
public:
    // Manige the file
    int printIDmap();
    void printIDsearch(vector<int> & IDs, bool isExact);
    word getIDstring(int id);
    bool readEntryFile(CSVTool & picReader, int & count);
    bool readEntryPrompt(CSVTool & picReader, int & count);
    word getHeadLine();
    friend ostream& operator << (ostream &out, Actr & pic);

    void writeCSVLine(ofstream & fout);
    void putIDstring(int id);
};
#endif
