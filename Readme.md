*******************************************************

## What is this?

*******************************************************

This program provides a simple and intuitive interface to manage and edit large amounts of data related to the Oscars. It includes a wide array of functions to organize and alter the data via command line. You can read in comma(",") separated files of data related to movie pictures, actors and actresses, or nominations. The support of the file types is done using a little known type of templating that C++ supports. This was originally a assignment in my graduate study, here it demonstrates my ability to code in the C++ language and use OOP concepts generally.

*******************************************************
##  Source files
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
##  Circumstances of programs
*******************************************************

   The program runs successfully.

   The program was developed and tested on gnu g++ 4.4.2.  
   
   It was compiled, run, and tested on csegrid.ucdenver.pvt.

*******************************************************
*  How to build and run the program
*******************************************************

#### Build the program.

    Change to the directory that contains the file by:
    % cd cpp_database_example

    Compile the program by:
    % make

#### Run the program by:
    % ./final

#### Delete the obj files, executables, and core dump by
    %./make clean

#### Have a nice day.







