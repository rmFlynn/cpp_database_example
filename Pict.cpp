//Created by Rory Flynn 
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "BSTree.hpp"
#include "CSVTool.h"
#include "uiTools.h"
#include "Pict.h"

typedef std::string word;

using namespace std;



// all fields in these classes have a field ID mapped to it 
// mostly with switch statements this shows the map to the user
int Pict::printIDmap(){
    cout << "\n";
    cout << "Type > 0 < to indicate the Name field.";
    cout << "\n";
    cout << "Type > 1 < to indicate the Year field.";
    cout << "\n";
    cout << "Type > 2 < to indicate the Nominations field.";
    cout << "\n";
    cout << "Type > 3 < to indicate the Rating field.";
    cout << "\n";
    cout << "Type > 4 < to indicate the Duration field.";
    cout << "\n";
    cout << "Type > 5 < to indicate the Genre One field.";
    cout << "\n";
    cout << "Type > 6 < to indicate the Genre Two field.";
    cout << "\n";
    cout << "Type > 7 < to indicate the Release field.";
    cout << "\n";
    cout << "Type > 8 < to indicate the Metacritic field.";
    cout << "\n";
    cout << "Type > 9 < to indicate the Synopsis field.";
    cout << "\n";
    // this tells you the largest number
    return 9;
}

// all fields in these classes have a field ID mapped to it 
// This prints the vectors that can be used in each search
// Also it puts each in a vector
void Pict::printIDsearch(vector<int> & IDs, bool isExact){
    // Most are good for the full search
    if(isExact){
        cout << "\n";
        cout << "Type > 0 < to indicate the Name field.";
        IDs.push_back(0);
        cout << "\n";
        cout << "Type > 1 < to indicate the Year field.";
        IDs.push_back(1);
        cout << "\n";
        cout << "Type > 2 < to indicate the Nominations field.";
        IDs.push_back(2);
        cout << "\n";
        cout << "Type > 3 < to indicate the Rating field.";
        IDs.push_back(3);
        cout << "\n";
        cout << "Type > 4 < to indicate the Duration field.";
        IDs.push_back(4);
        cout << "\n";
        cout << "Type > 5 < to indicate the Genre One field.";
        IDs.push_back(5);
        cout << "\n";
        cout << "Type > 6 < to indicate the Genre Two field.";
        IDs.push_back(6);
        cout << "\n";
        cout << "Type > 7 < to indicate the Release field.";
        IDs.push_back(7);
        cout << "\n";
        cout << "Type > 8 < to indicate the Metacritic field.";
        IDs.push_back(8);
        cout << "\n";
    }
    // only some for the side search
    else {
        cout << "\n";
        cout << "Type > 0 < to indicate the Name field.";
        IDs.push_back(0);
        cout << "\n";
        cout << "Type > 1 < to indicate the Synopsis field.";
        IDs.push_back(9);
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
bool Pict::readEntryFile(CSVTool & picReader, int & count){
    // name
    bool nameNoBlank;
    picReader.csvGetWord(0, name, nameNoBlank);
    if(nameNoBlank){
        cout << "\n\nSomething is wrong with the name field at line " << count << ". It looks to be blank\n\n";
        cout << "\n\nThat is too avantgard even for the movies. fix the file and try again.\n\n";
        return false;
    }
    // year
    picReader.csvGetInt(1, year, yearEmty);
    // nominations
    picReader.csvGetInt(2, nominations, nominationEmtys);
    // rating
    picReader.csvGetDouble(3, rating, ratingEmty);
    // duration
    picReader.csvGetInt(4, duration, durationEmty);
    // genre1
    picReader.csvGetWord(5, genre1, genre1Emty);
    // genre2
    picReader.csvGetWord(6, genre2, genre2Emty);
    // release
    picReader.csvGetWord(7, release, releaseEmty);
    // metacritic
    picReader.csvGetInt(8, metacritic, metacriticEmty);
    // synopsis
    picReader.csvGetWord(9, synopsis, synopsisEmty);
    return true;
}

// Take entry from the user
bool Pict::readEntryPrompt(CSVTool & picReader, int & count){
    // name
    bool nameNoBlank;
    picReader.csvGetWord(0, name, nameNoBlank);
    if(nameNoBlank){
        cout << "\n\nSomething is wrong with the name field at line " << count << ". It looks to be blank\n\n";
        cout << "\n\nThat is too avantgard even for the movies. fix the file and try again.\n\n";
        return false;
    }
    // year
    picReader.csvGetInt(1, year, yearEmty);
    // nominations
    picReader.csvGetInt(2, nominations, nominationEmtys);
    // rating
    picReader.csvGetDouble(3, rating, ratingEmty);
    // duration
    picReader.csvGetInt(4, duration, durationEmty);
    // genre1
    picReader.csvGetWord(5, genre1, genre1Emty);
    // genre2
    picReader.csvGetWord(6, genre2, genre2Emty);
    // release
    picReader.csvGetWord(7, release, releaseEmty);
    // metacritic
    picReader.csvGetInt(8, metacritic, metacriticEmty);
    // synopsis
    picReader.csvGetWord(9, synopsis, synopsisEmty);
    return true;
}

// Take the feald ID and return the value as a feald
word Pict::getIDstring(int id){
    // Change this to make empty diferent.
    word na = "NA";
    switch (id) {
        case 0:
            return name;
        case 1:
            if(yearEmty)
                return na;
            else
                return to_string(year);
        case 2:
            if(nominationEmtys)
                return na;
            else
                return to_string(nominations);
        case 3:
            if(ratingEmty)
                return na;
            else
                return to_string(rating);
        case 4:
            if(durationEmty)
                return na;
            else
                return to_string(duration);
        case 5:
            if(genre1Emty)
                return na;
            else
                return genre1;
        case 6:
            if(genre2Emty)
                return na;
            else
                return genre2;
        case 7:
            if(releaseEmty)
                return na;
            else
                return release;
        case 8:
            if(metacriticEmty)
                return na;
            else
                return to_string(metacritic);
        case 9:
            if(synopsisEmty)
                return na;
            else
                return synopsis;
    }
    return na;
}

ostream& operator << (ostream &out, Pict & pic){
    // Simply add the producst to the streem with formating
    out << "\n";
    out << "name: " <<  pic.getIDstring(0);
    out << "\n";
    out << "year: " <<  pic.getIDstring(1);
    out << "   ";
    out << "nominations: " <<  pic.getIDstring(2);
    out << "   ";
    out << "rating: " <<  pic.getIDstring(3);
    out << "   ";
    out << "duration: " <<  pic.getIDstring(4);
    out << "   ";
    out << "genre1: " <<  pic.getIDstring(5);
    out << "   ";
    out << "genre2: " <<  pic.getIDstring(6);
    out << "   ";
    out << "release: " <<  pic.getIDstring(7);
    out << "   ";
    out << "metacritic: " <<  pic.getIDstring(8);
    out << "\n";
    out << "synopsis: " << pic.getIDstring(9);
    out << "\n";
    return out;
}

//
//
// Funkions to edit or add with user input
//
//

void Pict::putIDstring(int id){
    // Change this to make empty diferent.
    word na = "NA";
    switch (id) {
        case 0:
            bool nameNoBlank;
            userGetWord(name, nameNoBlank);
            if(nameNoBlank){
                cout << "\n\nSomething is wrong with the name field. It looks to be blank\n\n";
                cout << "\n\nThat is too avantgard even for the movies. fix the file and try again.\n\n";
            }
            break;
        case 1:
            // year
            userGetInt(year, yearEmty);
            break;
        case 2:
            // nominations
            userGetInt(nominations, nominationEmtys);
            break;
        case 3:
            // rating
            userGetDouble(rating, ratingEmty);
            break;
        case 4:
            // duration
            userGetInt(duration, durationEmty);
            break;
        case 5:
            // genre1
            userGetWord(genre1, genre1Emty);
            break;
        case 6:
            // genre2
            userGetWord(genre2, genre2Emty);
            break;
        case 7:
            // release
            userGetWord(release, releaseEmty);
            break;
        case 8:
            // metacritic
            userGetInt(metacritic, metacriticEmty);
            break;
        case 9:
            // synopsis
            userGetWord(synopsis, synopsisEmty);
            break;
    }
}

//
// Writing to file tools
//
//

word Pict::getHeadLine(){
   return "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis\n";
}

void Pict::writeCSVLine(ofstream & fout){
    // Simply add the producst to the streem with formating
    fout << getIDstring(0);
    fout << ",";
    fout << getIDstring(1);
    fout << ",";
    fout << getIDstring(2);
    fout << ",";
    fout << getIDstring(3);
    fout << ",";
    fout << getIDstring(4);
    fout << ",";
    fout << getIDstring(5);
    fout << ",";
    fout << getIDstring(6);
    fout << ",";
    fout << getIDstring(7);
    fout << ",";
    fout << getIDstring(8);
    fout << ",";
    fout << getIDstring(9);
    fout << "\n";
}
