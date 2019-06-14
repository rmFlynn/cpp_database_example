*******************************************************
*  Name      :  Rory Flynn
*  Student ID:  830382453
*  Class     :  CSC 2421
*  HW#       :  FINAL!!
*  Due Date  :  Dec 6, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program provides a simple and intuitive interface to manage and edit large amounts of data related to the Oscars. It includes a wide array of functions to organize and alter the data via command line. You can read in comma(",") separated files of data related to movie pictures, actors and actresses, or nominations.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
    Main program. starts menue.
Name:  BSTree.h
    Defines The search tree stl.
Name:  BSTree.hpp
    Implements The search tree stl.
Name:  Node.h
    Defines The node class for the search tree stl.
Name:  CSVTool.h
    Defines a class to read csv.
Name:  CSVTool.cpp
    Implements a class to read csv.
Name:  Menu.h
    Defines an app menu.
Name:  Menu.cpp
    Implements an app menu.
Name:  Pict.h
    Defines a data structure.
Name:  Pict.cpp
    Implements a data structure.
Name:  Actr.h
    Defines a data structure.
Name:  Actr.cpp
    Implements a data structure.
Name:  Noms.h
    Defines a data structure.
Name:  Noms.cpp
    Implements a data structure.
Name:  OscarsDB.h
    Defines a tool to manage Oscar data.
Name:  OscarsDB.cpp
    Implements a tool to manage Oscar data.
Name:  OscarsPtr.h
    Defines pointer a tool to manage Oscar data.
Name:  uiTools.h
    Defines a tools for user input.
Name:  uiTools.cpp
    Implements a tools for user input.

*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.

   The program was developed and tested on gnu g++ 4.4.2.  
   
   It was compiled, run, and tested on csegrid.ucdenver.pvt.

   Bugs -- I have observed the following bugs, but I don't have time to fix them.
   
       You can delete any node in the database except the root node. 
   
       If you load all databases at the same time you will end up with six trees total. Usually this is fine on the server, but during nights of heavy traffic like this it seems to slow the tree down a lot.

*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.
   To uncompress it use the following commands

       % unzip [flynnFinal]

   Now you should see a directory named homework with the files:
      actor-actress.csv
      Actr.cpp
      Actr.h
      BSTDriver.cpp
      BSTree.h
      BSTree.hpp
      CSVTool.cpp
      CSVTool.h
      file.txt
      main.cpp
      makefile
      Menu.cpp
      Menu.h
      Node.h
      nominations.csv
      Noms.cpp
      Noms.h
      OscarsDB.cpp
      OscarsDB.h
      OscarsPtr.h
      Pict.cpp
      Pict.h
      pictures.csv
      Readme.txt
      uiTools.cpp
      uiTools.h

2. Build the program.

    Change to the directory that contains the file by:
    % cd flynnFinal

    Compile the program by:
    % make

3. Run the program by:
    % ./final

4. Delete the obj files, executables, and core dump by
    %./make clean

5. Have a nice day.







