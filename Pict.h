//Created by Rory Flynn 

// One of three stucturs for the data types stored in this project.
#ifndef PICT_
#define PICT_
#include <iostream>
#include <string>
#include <vector>
#include "BSTree.h"
#include "uiTools.h"
#include "CSVTool.h"

typedef std::string word;

using namespace std;
// Create a structure to hold data for moving pictures. Note that includes 
// title even though that will be the key for the binary search tree.
class Pict 
{
private:
    // all fields in these classes have a field ID mapped to it 
    int sizIDmap = 10;

    //
    // The rest of the private variables
    // are the values of the fields in this class
    //

    // This can Not be blank
    word name;

    int year;
    bool yearEmty;

    int nominations;
    bool nominationEmtys;

    double rating;
    bool ratingEmty;

    int duration;
    bool durationEmty;

    word genre1;
    bool genre1Emty;

    word genre2;
    bool genre2Emty;

    word release;
    bool releaseEmty;

    int metacritic;
    bool metacriticEmty;

    word synopsis;
    bool synopsisEmty;
public:
    // Manige the file
    int printIDmap();
    void printIDsearch(vector<int> & IDs, bool isExact);
    word getIDstring(int id);
    bool readEntryFile(CSVTool & picReader, int & count);
    bool readEntryPrompt(CSVTool & picReader, int & count);
    word getHeadLine();
    friend ostream& operator << (ostream &out, Pict & pic);

    void writeCSVLine(ofstream & fout);
    void putIDstring(int id);
};
#endif
