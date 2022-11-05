#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "course_names.txt"
using namespace std;



bool is_a_course(const string&);


int main() {
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


    return 0;
}




bool is_a_course(const string& userInput) {

    ifstream inFS;
    string courseName = "";
    inFS.open("course_names.txt");
    if (!inFS.is_open()) {
        cout << "Error opening file << endl";
        return false;
    }
    while (getline(inFS, courseName)) {
        if (userInput == courseName) {
            return true;
        }
    }
    return false;


}