//Created by Rory Flynn 
//
// Note that this part of the program will be extended into a tool for reading 
// more complex csv files in the final project.
//
// UPDATE ... did that ^^^
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BSTree.hpp"
#include "CSVTool.h"
#include "OscarsDB.h"
#include "Pict.h"
#include "Actr.h"
#include "Noms.h"

typedef std::string word;

using namespace std;

// I used to have constructors
// OscarsDB::OscarsDB(){
//}
// 
// OscarsDB::~OscarsDB(){
//    // delete fileName;
// }



// This prints and sets the options for the SORT on feild option
template <typename DATA>
int OscarsDB<DATA>::printIDmap(){
    // Uncoment chunk to disable sort on empty
    // if(activeData.size() < 1)
    //     takeOut(1);
    // if(activeData.size() < 1){
    //     cout << "ERROR You are trying to do action on an empty DB.\n\nThere are no options!";
    //     // By returning 0 we demonstrate that the only option it to exit
    //     return 0;
    OscarsDB<Pict> * pictures = nullptr;
    // }
    
    // all fields in these classes have a field ID mapped 
    // this tells you how many and what they are
    DATA tmp;
    return tmp.printIDmap();
}

// This prints and sets the options for the SEARCH on feild 
template <typename DATA>
void OscarsDB<DATA>::printIDsearch(vector<int> & IDs, bool isExact){
    // all fields in these classes have a field ID mapped 
    // this takes a vector of ints and returns it fild with valid option IDs
    // It takes a boolian true if exact false if partial
    DATA tmp;
    return tmp.printIDsearch(IDs, isExact);
}

// look at the data.
template <typename DATA>
void OscarsDB<DATA>::print(int n){

    // take out some data
    if(activeData.size() < 1)
        takeOut(n);
    
    // unless there is none then change your expectations.
    if(activeData.size() < n)
        n = activeData.size();

    // Print the data!
    // Scary math just wants to print the last 5 you took out 
    int count = 0;
    for(int i = activeData.size() - n; i < activeData.size(); i++){
        cout  << "\n" << "[" << count << "]"; 
        cout << activeData[i];
        count++;
    }
    activeCount = count;
}

//
template <typename DATA>
void OscarsDB<DATA>::takeOut(int n){
    DATA tmp;
    int count = 0;
    
    // If you hit the back
    if(workingT->Root() == nullptr){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "\n";
        cout << "################################################";
        cout << "\n";
        cout << "###    You are at the end of the database    ###";
        cout << "\n";
        cout << "################################################";
        cout << "\n";
        cout << "\n";
        return;
    }
    // otherwise fill the working vector
    while(workingT->minPop(tmp) && count < n){ 
        activeData.push_back(tmp);
        count++;
    }

}

template <typename DATA>
void OscarsDB<DATA>::putBack(int n){
    int count = 0;

    // if you hit the front
    if(activeData.size() <= n){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "\n";
        cout << "################################################";
        cout << "\n";
        cout << "###   You are at the front of the database   ###";
        cout << "\n";
        cout << "################################################";
        cout << "\n";
        cout << "\n";
        return;
    }
    DATA pic;
    // otherwise empty the working vector
    for(int i = 0; i < n; i++){
        pic = activeData.back();
        activeData.pop_back();
        workingT->addNode(pic.getIDstring(sortID),pic);
        count++;
    }
}

// Put them all back in the table
template <typename DATA>
void OscarsDB<DATA>::allIn(){
    for(DATA pic : activeData){
        workingT->addNode(pic.getIDstring(sortID),pic);
    }
    activeData.clear();
}

// Reset the data in the woriking tree 
template <typename DATA>
void OscarsDB<DATA>::clear(){
     
    // Just burn everything!!!
    if(workingT != nullptr)
        delete workingT;
    activeData.clear();
    sortID = 0;
    activeCount = 0;
}

// Reset the data in the woriking tree 
// template <typename DATA>
// void OscarsDB<DATA>::makeclean(){
//      
//     // burn less
//     if(workingT != nullptr)
//         delete workingT;
//     workingT = new BSTree<DATA,word>;
//     activeData.clear();
//     sortID = 0;
//     activeCount = 0;
// }

// Delete a record
template <typename DATA>
bool OscarsDB<DATA>::delRec(int v){
    // Check the response is valid
    if(v < 0 || v > activeCount){
        cout << "\n";
        cout << "\n";
        cout << "You have entered an invalid index!";
        cout << "\n";
        cout << "If you wish to delete a record not currently displayed you must navigate to it.";
        cout << "\n";
        cout << "\n";
        cout << "Lets try again.";
        cout << "\n";
        return false;
    }
    // Index to be deleted
    int index = activeData.size() - activeCount + v;
    
    // As in the vector, so in the tree
    // delete in the static tree
    // never use the sort id to delete!
    persistT->deleteNode(activeData[index].getIDstring(0));

    // delete in the vector;
    activeData.erase(activeData.begin() + index);
    
    // add to the print out if possible
    // so it stays the same
    takeOut(1);

    // it worked
    return true;
}

// Put them all back in the table
template <typename DATA>
void OscarsDB<DATA>::sort(int by){

    // Chage the sort id so that we can do searches
    sortID = by;

    // make a new tree
    // This will be a sorted copy of a working tree
    BSTree<DATA,word>  * tempingT = new BSTree<DATA,word>;  

    // Put all the data you are working with back in the tree
    allIn();

    // This iterReturn is so good it is a itretive tree loop
    // you can loop thrue the tree from the outside with this
    DATA pic;
    while(workingT->iterReturn(pic)){
        tempingT->addNode(pic.getIDstring(sortID), pic);
    }

    // Swap the trees
    delete workingT;
    workingT = tempingT;
}
template <typename DATA>
int OscarsDB<DATA>::searchExact(int by, word term){
    
    // Store the out put count of the search 
    int count = 0;

    // make a new tree
    // This will be a sorted copy of a working tree
    BSTree<DATA,word>  * tempingT = new BSTree<DATA,word>;  

    // Put all the data you are working with back in the tree
    allIn();

    // This iterReturn is so good it is a itretive tree loop
    // you can loop thrue the tree from the outside with this
    DATA dat;
    while(workingT->iterReturn(dat)){
        word itm= dat.getIDstring(by);

        //
        // transform(itm.begin(), itm.end(),itm.begin(), ::tolower);
        for(char &a : itm)
            a = tolower(a);

        if(itm == term){
            count++;
            tempingT->addNode(dat.getIDstring(sortID), dat);
        }
    }

    // Swap the trees
    delete workingT;
    workingT = tempingT;
    return count;
}
template <typename DATA>
int OscarsDB<DATA>::searchPart(int by, word term){
    
    // Store the out put count of the search 
    int count = 0;

    // make a new tree
    // This will be a sorted copy of a working tree
    BSTree<DATA,word>  * tempingT = new BSTree<DATA,word>;  

    // Put all the data you are working with back in the tree
    allIn();

    // convert strin to lower
    for(char & a : term)
        a = tolower(a);
    // This iterReturn is so good it is a itretive tree loop
    // you can loop thrue the tree from the outside with this
    DATA dat;
    while(workingT->iterReturn(dat)){
        word itm= dat.getIDstring(by);

        for(char a : itm)
            a = tolower(a);

        if(itm.find(term) != word::npos){
            count++;
            tempingT->addNode(dat.getIDstring(sortID), dat);
        }
    }

    // Swap the trees
    delete workingT;
    workingT = tempingT;
    return count;
}

//
//
// File Manigment tools
//
//

// set file name so you dont need to remember it
template <typename DATA>
void OscarsDB<DATA>::setFileName(word file){
    fileName = file;
}

// give it back 
template <typename DATA>
word OscarsDB<DATA>::getFileName(){
    return fileName; 
}


// Is the file set?
template <typename DATA>
bool OscarsDB<DATA>::isFileSet(){
    if(fileName.length() < 1)
        return false;
    return true;
}

// is the main tree loaded? the tree must be loaded to do any thing
template <typename DATA>
bool OscarsDB<DATA>::isDBLoaded(){
    if(persistT == nullptr)
        return false;
    return true;
}

// This is an unused alternat to reload
template <typename DATA>
bool OscarsDB<DATA>::loadDB(){
    
    const char * file= new char[fileName.length() + 1];
    file= fileName.c_str();
    bool indicator;
    if(!loadMoves(file)){
        indicator = false;
    }
    indicator = true;
    
    return indicator;
}
// Actually reads csv files 
template <typename DATA>
bool OscarsDB<DATA>::loadMoves(const char* fileName){

    CSVTool picReader(fileName);

    DATA pic;

    clear();// call this to delete tmp data

    // Check the file exists
    if(!picReader.isValid()){
        cout << "\n\nThe file \"" << fileName << "\" dose not exist\n\n";
        return false;
    }

    // Delete anything in your way
    if(persistT != nullptr)
        delete persistT;
    //else
    //    cout << "\n\nThe data is already loaded use reload to replace it\n\n";
    
    persistT = new BSTree<DATA,word>;

    // Scip the first line AKA header
    picReader.readLine(',', 10);

    // Loop over the rest of the file and use the data class to input it
    int count = 0;
    while(picReader.readLine(',', 10)){
        count++;
        // name
        if(!pic.readEntryFile(picReader, count))
            return false;
        persistT->addNode(pic.getIDstring(0), pic);
    }
    //persistT->printInorder();
    refreshWT();
    //cout << "WORKING\n";
    return true;
}

// This replaced the data in the tree
template <typename DATA>
void OscarsDB<DATA>::refreshWT(){
    DATA pic;

    // start with a clean tree
    if(workingT != nullptr)
        clear();
    //and data
    activeData.clear();
    workingT = new BSTree<DATA,word>;

    // loop using my fave function
    while(persistT->iterReturn(pic)){
        workingT->addNode(pic.getIDstring(0), pic);
    }
}


template <typename DATA>
void OscarsDB<DATA>::printToFile(word fileName){
    // convert the file name into the format a file reader can use
    const char * file= new char[fileName.length() + 1];
    file= fileName.c_str();
    ofstream printer(file);
    
    DATA tmp;

    // Put the data that is active back in the tree
    allIn();
    
    // check that the file exists we apend if it dose
    if(printer.good()){
        cout  << "The file already exists so the data will be appended without a header.";
    }
    else {
        // head the file
        printer << tmp.getHeadLine();
    }
    while(workingT->iterReturn(tmp)){
        // Wright lines in order
        tmp.writeCSVLine(printer);
    }

}

// Read in any of the data
template <typename DATA>
void OscarsDB<DATA>::putIDstring(int id){
    cout << "Input value: ";
    activeData[0].putIDstring(id);
}

template <typename DATA>
void OscarsDB<DATA>::selectOne(int t, int n){
    
    // Get the index of the selection
    int target = activeData.size() - n + t;

    // Take out what we want
    DATA temp;
    temp = activeData[target];

    // erase that one 
    activeData.erase(activeData.begin() + target);

    // put the rest back in
    allIn();

    // make the selection active
    activeData.push_back(temp);
}

template <typename DATA>
void OscarsDB<DATA>::selectNew(){ 

    // Make a new data point
    DATA temp;

    // put the rest of the data back in the tree
    allIn();

    // make the selection active
    activeData.push_back(temp);
}

template <typename DATA>
void OscarsDB<DATA>::putBackEdit(){
    // Get the key that needs to go
    word name = activeData[0].getIDstring(0);
    
    //remove the entry form the static DB
    persistT->deleteNode(name);

    // Put the edited data in the static DB
    persistT->addNode(name, activeData[0]);

    // Now clear the work space
    allIn();

}
// This is how you limit the types that can be cast
// if it is not here you cant use it.
template class OscarsDB<Pict>;
template class OscarsDB<Actr>;
template class OscarsDB<Noms>;
