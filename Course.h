#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Course {
 private:
    string name;
    vector<string> prereqs;
 public:
    Course();
    void setName(string n);
    void addPrereqs(string p);
    const string getName();
    const string getPrereqs(unsigned index);
    const int getSize();
};

#endif