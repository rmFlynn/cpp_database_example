//created by rory flynn 

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Pict.h"
#include "Actr.h"
#include "Noms.h"
#include "OscarsPtr.h"
#include "OscarsDB.h"

#ifndef MENU_
#define MENU_

typedef std::string word;

using namespace std;

// Okay so this is how I envisioned this working.
class Menu {
private:
    bool quit;
    OscarsPtr * data = nullptr;
    OscarsDB<Actr> * actors = nullptr;
    OscarsDB<Pict> * pictures = nullptr;
    OscarsDB<Noms> *  nominations = nullptr;
    word workingDB;
    char readRep(int & rep, int down, int up);
    // Menues
    void dbSet();
    void actionSet();
    void reloadFile();
    void search();
    void sort();
    void deleteRec();
    void setWorkingDB(int db);
    void printFile();
    void altRecord();

public:
    Menu();
    ~Menu();
    void start();
};

#endif



