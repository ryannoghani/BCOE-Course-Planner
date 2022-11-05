#ifndef ENCS_H
#define ENCS_H
#include "Course.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class ENCS {
 public:
    vector<Course> listOfClasses;
    string fileName;
 public:
    ENCS(string f);
    void ReadFile();
    const void PrintFile();
};

#endif