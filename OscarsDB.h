//Created by Rory Flynn 

// I might be breaking this into two classes. That way I don't have to make my CSV reader to specific.
#ifndef OSCARSDB_
#define OSCARSDB_
#include <iostream>
#include <string>
#include "BSTree.h"
#include "CSVTool.h"
#include "OscarsPtr.h"

typedef std::string word;

using namespace std;


template <typename DATA>
class OscarsDB : public OscarsPtr {
private:

    // Name of the file to be loaded
    word fileName;

    // Name of the file to be loaded
    //const char * fileName     = nullptr;

    // This is only edited by some fuctions 
    // it is the sorce of truth when things 
    // are searched and sorted.
    BSTree<DATA,word>  * persistT     = nullptr;
    // The working tree is displayed and edited
    // delete, add and edit functions must be meord
    BSTree<DATA,word>  * workingT     = nullptr;

    //the active data
    vector<DATA> activeData;
    int activeCount = 0;

    // load 
    bool loadMoves(const char* fileName);
    int sortID = 0;

    void allIn();
    void clear();
public:
// PictureDB();
//    ~PictureDB();

    //virtual void setDB(int db);
    
   ////// virtual void makeclean();
    virtual void setFileName(word file);
    virtual word getFileName();
    
    // Data type pass
    virtual int printIDmap();

    // File manigement 
    virtual bool loadDB();
    virtual bool isFileSet();
    virtual bool isDBLoaded();
    virtual void printToFile(word file);

    // Manige the working tree
    virtual void refreshWT();
    virtual void sort(int by);
    virtual void printIDsearch(vector<int> & IDs, bool isExact);
    virtual int  searchExact(int by, word term);
    virtual int  searchPart(int by, word term);

    // Manige active data
    virtual void takeOut(int n);
    virtual void putBack(int n);
    //Honorary member
    virtual bool delRec(int v);
    
    virtual void print(int n);
    virtual void selectNew();
    virtual void selectOne(int t, int n);
    virtual void putIDstring(int n);
    virtual void putBackEdit();

};
#endif
