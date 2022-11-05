#ifndef ENCS_H
#define ENCS_H
#include "Course.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Major {
 public:
    vector<Course> listOfClasses;
    string fileName;
 public:
    Major(string f);
    void ReadFile();
    const void PrintFile();
};

#endif