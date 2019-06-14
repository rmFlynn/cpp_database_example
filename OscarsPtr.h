
//Created by Rory Flynn 

// I might be breaking this into two classes. That way I don't have to make my CSV reader to specific.
#ifndef OSCARSPTR_
#define OSCARSPTR_
#include <iostream>
#include <string>
#include "BSTree.h"
#include "CSVTool.h"

typedef std::string word;

using namespace std;


class OscarsPtr {
protected:


public:
    //virtual void setDB(int db) = 0;
    
    virtual void setFileName(word file) = 0;
    virtual word getFileName() = 0;
    
    // Data type pass
    virtual int printIDmap() = 0;

    virtual bool loadDB() = 0;
    virtual bool isFileSet() = 0;
    virtual void printToFile(word file) = 0;
    virtual bool isDBLoaded() = 0;

    // Manige the working tree
   // virtual void makeClean() = 0;
    virtual void refreshWT() = 0;
    virtual void sort(int by) = 0;
    virtual int  searchExact(int by, word term) = 0;
    virtual int  searchPart(int by, word term) = 0;
    virtual void printIDsearch(vector<int> & IDs, bool isExact) = 0;

    // Manige active data
    virtual void takeOut(int n) = 0;
    virtual void putBack(int n) = 0;
    //Honorary member
    virtual bool delRec(int v) = 0;
    
    virtual void print(int n) = 0;
    virtual void selectNew() = 0;
    virtual void selectOne(int t, int n) = 0;
    virtual void putIDstring(int n) = 0;
    virtual void putBackEdit() = 0;

};
#endif
