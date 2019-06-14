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
#include "Menu.h"

typedef std::string string;

using namespace std;

Menu::Menu(){
    quit = false;
    pictures = new OscarsDB<Pict>;
    actors = new OscarsDB<Actr>;
    nominations = new OscarsDB<Noms>;
}
Menu::~Menu(){
    delete pictures;
    delete actors;
    delete nominations;
}

// The start menu of the hierarchy. it 
// decided what DB should be used.
void Menu::dbSet(){
    while(!quit){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "DB MENU";
        cout << "\n";
        cout << "\n";
        cout << "Please select the database that you wish to work on or examine by typing one number.";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "Type > 1 < to use the Movie Picture database.";
        cout << "\n";
        cout << "\n";
        cout << "Type > 2 < to use the Actor and Actress database.";
        cout << "\n";
        cout << "\n";
        cout << "Type > 3 < to use the Nominations database. (Extra Credit)";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "Type > Q < to quit.   Type > R < go back.";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        int rep;
        // stayorgo takes the input from the procese it can be 
        // 1 - Go back
        // 2 - Run this again
        // 0 - Exit
        char stayOrGo = readRep(rep,1,3);
        // If return or quit exit the loop
        if(stayOrGo ==  'q' || stayOrGo == 'r') break;
        // Seting the type of DB
        setWorkingDB(rep);
        // Now start the next
        actionSet();
    }
}


void Menu::start(){
    dbSet();
}

// add a record

// search for a record, and modify the fields.

// search for a record and delete the fields.

// sort by any single (sortable) field

// complete search on any “complete” searchable field.

// partial search on any searchable field.  

// ask for a file name, print out a .csv file of the latest database (after adds, deletes or modifies). 
// Remember that the first line of a .csv file lists the name of the fields separated with commas, ending in a newline. Then the following lines are the information from the fields separated with commas, ending in a newline.

void Menu::actionSet(){
    while(!quit){

        // PRINT THINGS
        
        cout << "==========================================================================================";
        cout << "\n";
        cout << "ACTION MENU";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "Pleas select the action to be taken on these records, or the ";
        cout << workingDB;
        cout << " database.";
        cout << "\n";
        cout << "\n";
        data->print(5);
        cout << "\n";
        cout << "\n";
        cout << "Type > 1 < to load at the next record set.    Type > 2 < to Look at the last record set.";
        cout << "\n";
        cout << "\n";
        cout << "Type > 3 < to Search the database.            Type > 4 < to Sort the database.";
        cout << "\n";
        cout << "\n";
        cout << "Type > 5 < to undo any search/sort action.";
        cout << "\n";                                                  
        cout << "\n";                                                  
        cout << "Type > 6 < to Add Or Modify a record.         Type > 7 < to Delete one of these records.";
        cout << "\n";
        cout << "\n";
        cout << "Type > 8 < to Reload the database.            Type > 9 < to print the Database to a file.";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "Type > Q < to quit.   Type > R < go back.";
        cout << "\n";
        cout << "\n";

        // DO THINGS

        int rep;
        char stayOrGo = readRep(rep,1,9);// 2 nums indicate range

        // Action based on switch
        if(stayOrGo ==  'q' || stayOrGo == 'r') break;
        switch (rep){
            case 1: 
                data->takeOut(5);
                continue;
            case 2:
                data->putBack(5);
                continue;
            case 3:
                search();
                continue;
            case 4:
                sort();
                continue;
            case 5:
                data->refreshWT();
                continue;
            case 6:
                altRecord();
                continue;
            case 7:
                deleteRec();
                continue;
            case 8:
                if (workingDB =="Movie Picture"){
                    delete pictures;
                    pictures = new OscarsDB<Pict>;
                    data = pictures;
                }
                if (workingDB == "Actor Actress"){
                    delete actors;
                    actors = new OscarsDB<Actr>;
                    data = actors;
                }
                if (workingDB == "Nominations"){
                    delete nominations;
                    nominations = new OscarsDB<Noms>;
                    data = nominations;
                }
                reloadFile();
                continue;
            case 9:
                printFile();
                continue;
        }
    }
}

void Menu::search(){
    cout << "==========================================================================================";
    cout << "\n";
    cout << "SEARCH";
    cout << "\n";
    cout << "\n";
    cout << "Would you like to do an exact search or a partial search?";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "Type > 1 < to do a Exact Search of the data.     Type > 2 < to a Partial Search of the data.";
    cout << "\n";
    cout << "\n";
    cout << "Type > Q < to quit.   Type > R < go back.";
    cout << "\n";
    cout << "\n";

    // Get the type for the search function
    int rep;
    char stayOrGo = readRep(rep,1,2);// 2 nums indicate range
    if(stayOrGo ==  'q' || stayOrGo == 'r') return;

    // Indicate search type
    bool isExact;

    // Remember search name for us
    word sType;
    switch (rep){
        case 1: 
            sType = "Exact Search";
            isExact = true;
            break;
        case 2:
            sType = "Partial Search";
            isExact = false;
            break;
    }
    cout << "==========================================================================================";
    cout << "\n";
    cout << "SEARCH";
    cout << "\n";
    cout << "\n";
    cout << "Pick a field to do a ";
    cout << sType;
    cout << " on!";
    cout << "\n";
    cout << "\n";
    vector<int>  IDs;
    data->printIDsearch(IDs, isExact);
    cout << "\n";
    cout << "\n";
    cout << "Type > Q < to quit.   Type > R < go back.";
    cout << "\n";
    cout << "\n";
    // Get the variable of the search function
    stayOrGo = readRep(rep,0,IDs.size()-1);// 2 nums indicate range
    if(stayOrGo ==  'q' || stayOrGo == 'r') return;
    int fieldID = IDs[rep];
    cout << "==========================================================================================";
    cout << "\n";
    cout << "SEARCH";
    cout << "\n";
    cout << "\n";
    cout << "Enter the search term!";
    if(isExact){
        cout << "\n";
        cout << "\n";
        cout << "Pleas enter a search term suitable for the field. ";
        cout << "\n";
        cout << "Meaning \"True\"/\"False\" for a boolean, or some number for an int or double field";
        cout << "\n";
        cout << "\n";
        cout << "String and Boolean fields are not case sensitive!";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    word term;
    cout << "Search term: ";
    int searchCount;
    // Get the term of the search function
    getline(cin, term);
    if(isExact)
        searchCount = data->searchExact(fieldID, term);
    else
        searchCount = data->searchPart(fieldID, term);
    cout << "==========================================================================================";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "Your search returned ";
    cout << searchCount;
    cout << " results.";
    cout << "\n";
    cout << "\n";
    cout << "\n";
}
void Menu::sort(){
    int options;
    cout << "==========================================================================================";
    cout << "\n";
    cout << "SORT";
    cout << "\n";
    cout << "\n";
    cout << "Pick a field to do a Sort on!";
    cout << "\n";
    cout << "All fields are search-able (It is not required that any not be) but if you sort the  boolean fields you will find the result to be disappointing.";
    cout << "\n";
    cout << "\n";
    options = data->printIDmap();
    cout << "\n";
    cout << "\n";
    cout << "Type > Q < to quit.   Type > R < go back.";
    cout << "\n";
    cout << "\n";
    int rep;
    char stayOrGo = readRep(rep,0, options);// 2 nums indicate range 

    // This is not a loop menue but if we exit we dont sort
    if(stayOrGo ==  'q' || stayOrGo == 'r') return;

    // Sort action
    data->sort(rep);
}

void Menu::deleteRec(){
    while(!quit){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "DELETE";
        cout << "\n";
        cout << "\n";
        cout << "Pleas select the Record that you would like to delete by typing the number in this list that corresponds to it.";
        cout << "\n";
        cout << "\n";
        data->print(5);
        cout << "\n";
        cout << "\n";
        cout << "Type > Q < to quit.   Type > R < go back.";
        cout << "\n";
        cout << "\n";
        int rep;
        char stayOrGo; 
        do{
            stayOrGo = readRep(rep,0,5);// 2 nums indicate range
            if(stayOrGo ==  'q' || stayOrGo == 'r') break;
        }while(!data->delRec(rep));
        if(stayOrGo ==  'q' || stayOrGo == 'r') break;
    }
}

void Menu::altRecord(){
    cout << "==========================================================================================";
    cout << "\n";
    cout << "ADD OR EDIT";
    cout << "\n";
    cout << "\n";
    cout << "Select the number corresponding to the record you would like to edit. Or you can type > 5 < to add a new record.";
    cout << "\n";
    cout << "\n";
    data->print(5);
    cout << "\n";
    cout << "\n";
    cout << "Type the number of the entry you want to edit.    Type > 5 < to add and entry.";
    cout << "\n";
    cout << "\n";
    cout << "Type > Q < to quit.   Type > R < go back.";
    cout << "\n";
    cout << "\n";

    // Get the type for the search function
    int rep;
    char stayOrGo = readRep(rep,0,5);// 2 nums indicate range
    if(stayOrGo ==  'q' || stayOrGo == 'r') return;

    if(rep == 5){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "ADD";
        cout << "\n";
        cout << "\n";
        cout << "Pleas enter the value of the name field for the new entry. You can then use the editor add other fields.";
        cout << "\n";
        cout << "\n";
        data->selectNew();
        data->putIDstring(0);
    }
    else{
        data->selectOne(rep,5);
    }
    int options;
    do{
        cout << "==========================================================================================";
        cout << "\n";
        cout << "EDIT";
        cout << "\n";
        cout << "\n";
        cout << "Pick a field that you want to edit by typing the corisponding number. Type \"R\" to exit when you are done.";
        cout << "\n";
        cout << "\n";
        cout << "Here is what the entry is currently:";
        cout << "\n";
        cout << "\n";
        data->print(1);
        cout << "\n";
        cout << "\n";
        options = data->printIDmap();
        cout << "\n";
        cout << "\n";
        cout << "Type > Q < to quit.   Type > R < save and exit the editor.";
        cout << "\n";
        cout << "\n";
        stayOrGo = readRep(rep,0,options);// 2 nums indicate range
        if(stayOrGo ==  'q' || stayOrGo == 'r') break;
        data->putIDstring(rep);
    }while(stayOrGo !=  'q' && stayOrGo != 'r');

    data -> putBackEdit();

}

//
//
// File manigment
//
//

void Menu::setWorkingDB(int db){
    //data.setDB(db);
    switch (db){
        case 1: 
            workingDB = "Movie Picture";
            data = pictures;
            break;
        case 2: 
            workingDB = "Actor Actress";
            data = actors;
            break;
        case 3: 
            workingDB = "Nominations";
            data = nominations;
            break;
    }
    if(!data->isFileSet()){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "ALERT";
        cout << "\n"
            << "\n"
            << "Looks like you have not loaded a file into the "
            << workingDB
            << " database."
            << "\n"
            << "You will need select a file to proceed"
            << "\n";
        reloadFile();
    }
    else{
        cout << "\n"
            << "\n"
            << "The "
            << workingDB
            << " database will be from "
            << data->getFileName()
            << "\n"
            << "You will need to use the reload function to replace it"
            << "\n";
    }
}

// change or load the working file self expository
void Menu::reloadFile(){
    // Say things
    cout << "==========================================================================================";
    cout << "\n";
    cout << "LOAD FILE";
    cout << "\n";
    cout << "\n";
    cout << "Please enter the name of the CSV file that you would like to load into the ";
    cout << workingDB;
    cout << " database.";
    cout << "\n";
    cout << "\n";
    // Do things
    do{
        word file;
        cout << "File name: ";
        getline(cin, file);
        if (file.size() < 1){
            if (workingDB =="Movie Picture"){
                file = "pictures.csv";
            }
            if (workingDB == "Actor Actress"){
                file = "actor-actress.csv";
            }
            if (workingDB == "Nominations"){
                file = "nominations.csv";
            }
            cout << "\n";
            cout << "\n";
            cout << "No file was entered!";
            cout << "\n";
            cout << "The default file ";
            cout << file;
            cout << " will be used instead.";
            cout << "\n";
            cout << "\n";
        }

        //cout << "\n\n\n" << file << "\n\n";
        data->setFileName(file);
    }while(!data->loadDB());
}
void Menu::printFile(){
    cout << "==========================================================================================";
    cout << "\n";
    cout << "PRINT FILE";
    cout << "\n";
    cout << "\n";
    cout << "Please enter the name of the CSV file that you would like to print the ";
    cout << workingDB;
    cout << " database into.";
    cout << "\n";
    cout << "\n";
    word file;
    cout << "File name: ";
    getline(cin, file);
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "==========================================================================================";
    data->printToFile(file);
    cout << "\n";
    cout << "\n";
    cout << "The file is printed.";
    cout << "\n";
    cout << "\n";
}

//
//
// NON MENUE MENUE-TOOLS
//
//

// Collects an integer indicating the users choice .
// Also returns a char indicating if the user would like
// to exit or return a bool would do but more options with
// char in the future
char  Menu::readRep(int & rep,int down, int up){
    string reply;
    bool goodRep = false;
    do{
        cout << "Make your selection now:  ";
        getline(cin, reply);
        // Check you type something
        // nothing is a bigger problem
        // then you things
        if(reply.size() < 1){
            cout << "You need to type a response.";
            cout << "\n";
            cout << "Lets try again.";
            cout << "\n";
            cout << "\n";
            continue;
        }
        // Check that we should continue
        // Should we quit
        if(reply == "q" || reply == "Q"){
            quit = true;
            return 'q';
        }
        // Should we go back
        if(reply == "R" || reply == "r")
            return 'r';
        // If not a special case then the reply is
        // a number in the passed range
        stringstream notNums; 
        notNums.str(reply);
        rep = 0; 
        // Convert
        notNums >> rep; 
        if(notNums.fail()){
            cout << "Sorry, that is not an acceptable reply";
            cout << "\n";
            cout << "Lets try again.";
            cout << "\n";
            cout << "\n";
            continue;
        }
        if( up >= rep && rep >= down){
            goodRep = true;
        }
        else{
            cout << "Sorry, that is not an acceptable reply";
            cout << "\n";
            cout << "Lets try again.";
            cout << "\n";
            cout << "\n";
            continue;
        }
    }while(!goodRep);
    // c is arbitrarily the indicator to continue
    return 'c';
}

