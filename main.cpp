#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Major.h"
using namespace std;

bool is_a_course(const string& userInput);
void prereqChecker(const string& fileName, const vector<string> takenCourseList, vector<string>& newCourseList);

int main() {

    string major;
    string courseListFile = "";
    cout << "Choose your major: ";
    cin >> major;
    if (major == "ENCS") {
        courseListFile = "ENCS.txt";
    }

    string course = "";
    vector<string> takenCourses;
    cout << "Enter any courses you have credit for. Type \"done\" when all the courses are entered\n" << endl;

    cin >> course;

    while (course != "done") {
        if (is_a_course(course)) {
            takenCourses.push_back(course);
        }

        cin >> course;
    }

    vector<string> prereq_satisfied_course_list;
    prereqChecker(courseListFile, takenCourses, prereq_satisfied_course_list);

    for(unsigned i = 0; i < prereq_satisfied_course_list.size(); ++i) {
        cout << prereq_satisfied_course_list.at(i) << endl;
    }
    
    return 0;
}

bool is_a_course(const string& userInput) {
    ifstream inFS;
    string courseName = "";
    inFS.open("course_names.txt");
    if (!inFS.is_open()) {
        cout << "Error opening file" << endl;
        return false;
    }
    while (getline(inFS, courseName)) {
        if (userInput == courseName) {
            return true;
        }
    }
    inFS.close();

    return false;
}

void prereqChecker(const string& fileName, const vector<string> takenCourseList, vector<string>& newCourseList) {
    Major majorCourseList(fileName);
    bool check;
    vector<string> temp;

    majorCourseList.ReadFile();

    for(unsigned i = 0; i < majorCourseList.listOfClasses.size(); ++i) { // Traverses through each Course item in the Major vector
        check = true;
        if(majorCourseList.listOfClasses.at(i).getSize() != 1) {
            for(unsigned j = 1; j < majorCourseList.listOfClasses.at(i).getSize(); ++j) { // Sets every item from the Course vector into temp
                temp.push_back(majorCourseList.listOfClasses.at(i).getPrereqs(j));
            }
            for(unsigned j = 0; j < temp.size(); ++j) {
                for(unsigned k = 0; k < takenCourseList.size(); ++k) {
                    if(temp.at(j) == takenCourseList.at(k)) {
                        k = takenCourseList.size();
                        j = temp.size();
                    }
                    else if(j == temp.size() - 1 && k == takenCourseList.size() - 1) {
                        check = false;
                    }
                }
            }
            temp.clear();
        }
        if(check) {
            newCourseList.push_back(majorCourseList.listOfClasses.at(i).getName());
        }
    }

    cout << endl << "Courses:" << endl;
    for(unsigned i = 0; i < takenCourseList.size(); ++i) {
        for(unsigned j = 0; j < newCourseList.size(); ++j) {
            if(takenCourseList.at(i) == newCourseList.at(j)) {
                newCourseList.erase(newCourseList.begin() + j);
                --j;
            }
        }
    }
}