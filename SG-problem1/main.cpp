//
//  main.cpp
//  SG programming problem
//
//  Created by Paul Ledeboer on 6/7/16.
//  Copyright © 2016 Paul Ledeboer. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Check for correct parameters
    if(argc < 2) {
        cout << argv[0] << ": usage: " << argv[0] << " input-data-file.csv" << endl;
        return -1;
    }
    
    // open up the data file
    ifstream dataFile(argv[1]);
    
    // create a list of birth date years and death date years
    // We want them with smallest on top, so provide reverse sorting
    priority_queue<int, vector<int>, greater<int>> birthYears;
    priority_queue<int, vector<int>, greater<int>> deathYears;
    
    string birthYearStr;
    string deathYearStr;
    int birthYear;
    int deathYear;
    
    while (dataFile.good() ) {
        getline( dataFile, birthYearStr, ',');
        getline( dataFile, deathYearStr, ',');
        birthYear = atoi( birthYearStr.c_str());
        deathYear = atoi( deathYearStr.c_str());
        
        if(birthYear >= 1900 && deathYear <= 2000 && birthYear <= deathYear) {
            // Only consider this dataset if it's in the range and makes sense
            birthYears.push(birthYear);
            deathYears.push(deathYear + 1); // don't remove it until the year AFTER, b/c they were alive in death year
        }
    }
    
    // Now we've got an ordered list of births and deaths, so start adding them up.
    int aliveCount = 0;
    int maxAliveCount = 0;
    int maxAliveYear = 1899;
    int currentYear = 1899;
    int currentBirth = 0;
    int currentDeath = 0;
    
    // The priority queue has the biggest at the front, so need to pull from the back
    
    // Only need to go until the last year with births. Any year after that can't have more alive people
    while (!birthYears.empty()) {
        currentBirth = birthYears.top();
        currentDeath = deathYears.top();
        
        currentYear = currentBirth;
        
        while( currentYear == currentBirth && !birthYears.empty() ) {
            aliveCount++;
            birthYears.pop();
            currentBirth = birthYears.top();
        }
        
        while( currentYear == currentDeath && !deathYears.empty() ) {
            aliveCount--;
            deathYears.pop();
            currentDeath = deathYears.top();
        }
        
        if(maxAliveCount < aliveCount) {    // new max
            maxAliveCount = aliveCount;
            maxAliveYear = currentYear;
        }
    }
    
    if( maxAliveYear > 1899 ) {
        cout << "Year with most number of alive people was: " << maxAliveYear << endl;
    } else {
        cout << "No valid data found. Check " << argv[1] << " for proper data." << endl;
    }
    
    return 0;
}
