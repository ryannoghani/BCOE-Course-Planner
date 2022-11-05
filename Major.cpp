#include "Major.h"

Major::Major(string f) {
    fileName = f;
}

void Major::ReadFile() {
    string line;
    string tempName;
    string tempPrereqs;
    istringstream inSS;
    int index = 0;
    
    ifstream inFS;
    inFS.open(fileName);
    if(!inFS.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    while(getline(inFS, line)) {
        listOfClasses.push_back(Course());
        inSS.str(line);
        inSS >> tempName;
        listOfClasses.at(index).setName(tempName);
        while(inSS >> tempPrereqs) {
            if(tempPrereqs != "or") {
                listOfClasses.at(index).addPrereqs(tempPrereqs);
            }
        }
        ++index;
        inSS.clear();
    }
}

const void Major::PrintFile() {
    for(unsigned i = 0; i < listOfClasses.size(); ++i) {
        cout << listOfClasses.at(i).getName() << ": ";
        if(listOfClasses.at(i).getSize() == 1) {
            cout << listOfClasses.at(i).getPrereqs(0);
        }
        else {
            for(unsigned j = 1; j < listOfClasses.at(i).getSize(); ++j) {
                cout << listOfClasses.at(i).getPrereqs(j) << " ";
            }
        }
        cout << endl;
    }
}