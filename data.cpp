//
//  data.cpp
//  Lab1
//
//  Created by Giovanni Masella on 2/8/16.
//  Copyright © 2016 Giovanni Masella. All rights reserved.
//

//including the Prog header file
#include "Prog.h"
// Constructor
Log::Log (string F) {
    // Initialize work progress values at zero.
    for (int i = 0; i < size; i++) {
        progress[i].code = 0;
        progress[i].comment = 0;
        
    }
    fileName = F;
    
}

int Log::run () {
    string line;
    // Reference to the file.
    ifstream dataFile (fileName.c_str());
    
    // A storage for the winner if it is ever declared.
    int win = 0;

    
    if (dataFile.is_open()) {
        int win = 0;
        int col = 1;
        int index = 0;
        
        // To Find if there is a winner
        while (dataFile >> line && !win) {
            
        
            switch (col) {
                    
                case 1:
                    index = atoi(line.c_str()) - 1;
                    col++;
                    cout << setw(20) << index + 1;
                    break;
                case 2:
                    progress[index].code += atoi(line.c_str());
                    col++;
                    cout << setw(20) << atoi(line.c_str());
                    break;
                    
                case 3:
                    progress[index].comment += atoi(line.c_str());
                    col = 1;
                    cout << setw(20) << atoi(line.c_str()) << endl;
                    if (progress[index].code > 1000) {
                        win = index;
                        return win;
                    }
                    break;
            }
        }
        // Close data file.
        dataFile.close();
        
    }
    return win;
}




void Log::heading () {
    // Set print alignment to the left;
    cout << left;
    cout << setw(20) << "Programmer";
    cout << setw(20) << "Lines of Code";
    cout << setw(20) << "Lines of Comments" << endl;
}

void Log::total () {
    for (int i = 0; i < size; i++) {
        cout << setw(20) << i + 1;
        cout << setw(20) << progress[i].code;
        cout << setw(20) << progress[i].comment << endl;
    }
}

prog Log::getLog (int i) {
    return progress[i];
}

int Log::getSize () {
    return size;
}

int Log::getY (int x) {
    // The integer to keep track of our sum as we add each programmer's lines.
    int sum = 0;
    for (int i = 0; i < size; i++) {
        // If the current programmer we're using isn't the one given.
        if (i != x) {
            sum += progress[i].code;
        }
        /* If the sum has surpassed the given programmer's total, break the loop
         by returning this current programmer's index.
         */
        if (sum > progress[x].code) return i;
    }
    
    /* If we haven't reached a conclusion (which shouldn't happen if this function
     was called after run() with the proper data).
     */
    return 0;
}

