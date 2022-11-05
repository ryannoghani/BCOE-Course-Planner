#include "Course.h"

Course::Course() {
    prereqs.push_back("No Prerequisite");
}

void Course::setName(string n) {
    name = n;
}

void Course::addPrereqs(string p){
    prereqs.push_back(p);
}

const string Course::getName() {
    return name;
}

const string Course::getPrereqs(unsigned index) {
    return prereqs.at(index);
}

const int Course::getSize() {
    return prereqs.size();
}