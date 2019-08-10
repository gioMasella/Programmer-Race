//
//  Log.h
//  Lab1
//
//  Created by Giovanni Masella on 2/8/16.
//  Copyright © 2016 Giovanni Masella. All rights reserved.
//

#ifndef PROG_h
#define PROG_h

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct prog {
    
    int code;
    int comment;
    
};

class Log {
public:
    Log(string);
    prog getprogress (int);
    void heading();
    void heading2();
    // Prints out the totals.
    void total();
    // Gets the single struct element from the logs array.
    prog getLog(int);
    int run();
    // Gets the size of the array.
    int getSize();
    /*
     Returns the amount of programmers needed starting from 0 to match a given
     programmer's lines of code written. Returns 0 if never matched.
     */
    int getY(int);
    
private:
    const static int size = 10;
    prog progress[size];
    // The titles for each column.
    string fileName;
};



#endif /* Log_h */
