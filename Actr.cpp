//Created by Rory Flynn 
//
// Note that this part of the program will be extended into a tool for reading 
// more complex csv files in the final project.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BSTree.hpp"
#include "CSVTool.h"
#include "Actr.h"

typedef std::string word;

using namespace std;



// all fields in these classes have a field ID mapped to it 
// mostly with switch statements this shows the map to the user
int Actr:: printIDmap(){
    cout << "\n";
    cout << "Type > 0 < to indicate the Name field.";
    cout << "\n";
    cout << "Type > 1 < to indicate the Year field.";
    cout << "\n";
    cout << "Type > 2 < to indicate the Award field.";
    cout << "\n";
    cout << "Type > 3 < to indicate the Winner field.";
    cout << "\n";
    cout << "Type > 4 < to indicate the Film field.";
    // this tells you the largest number
    return 9;
}












// all fields in these classes have a field ID mapped to it 
// This prints the vectors that can be used in each search
// Also it puts each in a vector
void Actr::printIDsearch(vector<int> & IDs, bool isExact){
    // Most are good for the full search
    if(isExact){
        cout << "\n";
        cout << "Type > 0 < to indicate the Name field.";
        IDs.push_back(0);
        cout << "\n";
        cout << "Type > 1 < to indicate the Year field.";
        IDs.push_back(1);
        cout << "\n";
        cout << "Type > 2 < to indicate the Award field.";
        IDs.push_back(2);
        cout << "\n";
        cout << "Type > 3 < to indicate the Winner field.";
        IDs.push_back(3);
        cout << "\n";
        cout << "Type > 4 < to indicate the Film field.";
        IDs.push_back(4);
        cout << "\n";
    }
    // only some for the side search
    else {
        cout << "\n";
        cout << "Type > 0 < to indicate the Film field.";
        IDs.push_back(4);
        cout << "\n";
        cout << "Type > 1 < to indicate the Award field.";
        IDs.push_back(2);
        cout << "\n";
        cout << "\n";
        cout << "Type > 2 < to indicate the Name field.";
        IDs.push_back(0);
        cout << "\n";
    }
}

//
//
//  Take input to fill feilds
//
//  Mostly passes a feild to a tool
//
//

// Take entry from a file
bool Actr:: readEntryFile(CSVTool & picReader, int & count){
    // year
    picReader.csvGetInt(0, year, yearEmpty);
    // award
    picReader.csvGetWord(1, award, awardEmpty);
    // winner
    picReader.csvGetBool(2, winner, winnerEmpty, "1","0");
    // name
    bool nameNoBlank;
    picReader.csvGetWord(3, name, nameNoBlank);
    if(nameNoBlank){
        cout << "\n\nSomething is wrong with the name field at line " << count << ". It looks to be blank\n\n";
        cout << "\n\nThat is too avantgard even for the movies. fix the file and try again.\n\n";
        return false;
    }
    // film
    picReader.csvGetWord(4, film, filmEmpty);
    return true;
}










// Take entry from the user
bool Actr:: readEntryPrompt(CSVTool & picReader, int & count){
    // name
    bool nameNoBlank;
    picReader.csvGetWord(0, name, nameNoBlank);
    if(nameNoBlank){
        cout << "\n\nSomething is wrong with the name field at line " << count << ". It looks to be blank\n\n";
        cout << "\n\nThat is too avantgard even for the movies. fix the file and try again.\n\n";
        return false;
    }
    // year
    picReader.csvGetInt(1, year, yearEmpty);
    // nominations
    return true;
}

// Take the feald ID and return the value as a feald
word Actr:: getIDstring(int id){
    // Change this to make empty diferent.
    word na = "NA";
    switch (id) {
        case 0:
            return name;
        case 1:
            if(yearEmpty)
                return na;
            else
                return to_string(year);
        case 2:
            if(awardEmpty)
                return na;
            else
                return award;
        case 3:
            if(winnerEmpty)
                return na;
            else
                return bool_to_string(winner);
        case 4:
            if(filmEmpty)
                return na;
            else
                return film;
    }
    return na;
}

word Actr::bool_to_string(bool b){
    if(b)
        return "True";
    else 
        return "False";
}

ostream& operator << (ostream &out, Actr & pic){
    // Simply add the producst to the streem with formating
    out << "\n";
    out << "name: " <<  pic.getIDstring(0);
    out << "\n";
    out << "year: " <<  pic.getIDstring(1);
    out << "   ";
    out << "award: " <<  pic.getIDstring(2);
    out << "   ";
    out << "winner: " <<  pic.getIDstring(3);
    out << "   ";
    out << "film: " <<  pic.getIDstring(4);
    out << "\n";
    return out;
}

//
//
// Funkions to edit or add with user input
//
//

void Actr::putIDstring(int id){
    // Change this to make empty diferent.
    word na = "NA";
    switch (id) {
        case 0:
            // name
            bool nameNoBlank;
            userGetWord(name, nameNoBlank);
            if(nameNoBlank){
                cout << "\n\nSomething is wrong with the name field. It looks to be blank\n\n";
                cout << "\n\nThat is too avantgard even for the movies. fix the file and try again.\n\n";
            }
            break;
        case 1:
            // year
            userGetInt(year, yearEmpty);
            break;
        case 2:
            // award
            userGetWord(award, awardEmpty);
            break;
        case 3:
            // winner
            userGetBool(winner, winnerEmpty, "True", "False");
            break;
        case 4:
            // film
            userGetWord(film, filmEmpty);
            break;
    }
}

//
// Writing to file tools
//
//

word Actr::getHeadLine(){
   return "Year,Award,Winner,Name,Film\n";
}

void Actr::writeCSVLine(ofstream & fout){
    // Simply add the producst to the streem with formating
    // year
    fout << getIDstring(1);
    fout << ",";
    // award
    fout << getIDstring(2);
    fout << ",";
    // winner
    fout << getIDstring(3);
    fout << ",";
    // name
    fout << getIDstring(0);
    fout << ",";
    // film
    fout << getIDstring(4);
    fout << "\n";
}
