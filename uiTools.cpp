//Created by Rory Flynn 
// 
//
//
#include <iostream>
#include <string>
#include <sstream>

typedef std::string word;

using namespace std;
// User imput tools lifted more or less from csv tool
//

// Return the specified field as a word AKA string, meaning no need to convert type 
void userGetWord(word & target, bool & nulDicator){
    word input;
    // Read what the user says
    getline(cin, input);
    // check that the field is not null
    if(input.length() < 1){
        nulDicator = true;
    }
    else{
        // Set value
        nulDicator = false;
        target = input;
    }
    if(nulDicator){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "\n";
        cout << "Your input has been interpreted as NULL";
        cout << "\n";
        cout << "\n";
    }
}

// Return a field as a int and check it of coarse.
void userGetInt(int & target, bool & nulDicator){
    word input;
    // Read what the user says
    getline(cin, input);
    // check that the field is not null
    if(input.length() < 1){
        nulDicator = true;
    }
    else{
        stringstream notNums(input); 
        // Convert
        notNums >> target; 
        // Set the valid bit.
        nulDicator = notNums.fail();
    }
    if(nulDicator){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "\n";
        cout << "Your input has been interpreted as NULL";
        cout << "\n";
        cout << "\n";
    }
}

// Return a field as a int and check it of coarse.
void userGetChar(char & target, bool & nulDicator){
    word input;
    // Read what the user says
    getline(cin, input);
    // check that the field is not null
    if(input.length() < 1){
        nulDicator = true;
    }
    else{
        stringstream notNums(input); 
        // Convert
        notNums >> target; 
        // Set the valid bit.
        nulDicator= notNums.fail();
    }
    if(nulDicator){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "\n";
        cout << "Your input has been interpreted as NULL";
        cout << "\n";
        cout << "\n";
    }
}

// Return a field as a int and check it of coarse.
void userGetDouble(double & target, bool & nulDicator){
    word input;
    // Read what the user says
    getline(cin, input);
    // check that the field is not null
    if(input.length() < 1){
        nulDicator = true;
    }
    else{
        stringstream notNums(input); 
        // Convert
        notNums >> target; 
        // Set the valid bit.
        nulDicator = notNums.fail();
    }
    if(nulDicator){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "\n";
        cout << "Your input has been interpreted as NULL";
        cout << "\n";
        cout << "\n";
    }
}

// Return a field as a int and check it of coarse.
void userGetBool (bool & target, bool & nulDicator, word truth, word lie){
    
    cout << "\n";
    cout << "\n";
    cout << "Note that only \"";
    cout << truth;
    cout << "\" will be seen as true, and only  \"";
    cout << lie;
    cout << "\" will be seen as false.";
    cout << "\n";
    cout << "\n";

    word input;
    // Read what the user says
    getline(cin, input);

    if(input.length() < 1){
        nulDicator = true;
    }
    else{
        // It should be the truth or the lie if it is valid
        nulDicator = ((input == truth) || (input == lie));
        // It only needs to be the truth for it to be true.
        target = (input == truth);
    }
    if(nulDicator){
        cout << "==========================================================================================";
        cout << "\n";
        cout << "\n";
        cout << "Your input has been interpreted as NULL";
        cout << "\n";
        cout << "\n";
    }
}

