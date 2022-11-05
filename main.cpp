#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



bool is_a_course(const string&);
void prereqChecker(const string&, const vector<string>&, vector<string>&);


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
    inFS.close();

    return false;
}



void prereqChecker(const string& fileName, const vector<string> takenCourseList, vector<string>& newCourseList) {





}
