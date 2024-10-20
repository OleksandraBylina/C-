#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <iosfwd>
using namespace std;

int main() {
    ofstream createInputFile("input.txt");
    createInputFile << "1.23, 5.6, -3.4, 10, 0" << endl;
    createInputFile.close();
    ofstream createOutputFile("output.txt");
    createOutputFile.close();
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string line;
    double num;
    while (getline(inputFile, line, ',')) {
        stringstream ss(line);
        ss >> num;

        if (num <= 0) {
            outputFile << "None" << endl;
        } else {
            outputFile << scientific << setw(5) << setprecision(5) << log(num) << endl;
        }
    }

    inputFile.close();
    outputFile.close();


    ifstream inputToShow("input.txt");
    while (getline(inputToShow, line)) {
        cout << line << endl;
    }
    inputToShow.close();
    ifstream outputToShow("output.txt");
    while  (getline(outputToShow, line)) {
        cout << line << endl;
    }
    outputToShow.close();


}
