//
//  main.cpp
//  Lab1
//
//  Created by Giovanni Masella on 2/8/16.
//  Copyright © 2016 Giovanni Masella. All rights reserved.
//

#include "data.cpp"
// Needed for console logging.
#include <iostream>
using namespace std;

int main () {
    cout << endl;
    
    
    // Initialize and load data from file.
    Log data("data.txt");
    // Print the header from data.cpp
    data.heading();
    //The winner if found.
    int win = data.run();
    cout << endl;
    data.heading();
    data.total();
    if (win) {
        cout << endl << "Programmer " << win + 1 << " has won the contest." << endl << endl;
        // Get the lowest amount of programmers starting with 1 to match winner's work.
        int y = data.getY(win);
        if (y) {
            cout << "It took programmers 1 through " << y + 1 << " to produce more than the winner." << endl << endl;
        }
    } else {
        cout  << "No winner was selected for this contest." << endl << endl;
    }
    cout << endl;

cout << endl;
// Initialize and load data from file 2.
Log data2("data2.txt");
// Print the header.
data2.heading();
//The winner if found.
int win2 = data2.run();
cout << endl;
data2.heading();
data2.total();
if (win2) {
    cout << endl << "Programmer " << win2 + 1 << " has won the contest." << endl << endl;
    // Get the lowest amount of programmers starting with 1 to match winner's work.
    int y = data2.getY(win2);
    if (y) {
        cout << "It took programmers 1 through " << y + 1 << " to produce more than the winner." << endl << endl;
    }
} else {
    cout  << "No winner was selected for this contest." << endl << endl;
}
cout << endl;
 return 0;
}
