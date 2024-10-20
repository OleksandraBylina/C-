#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


bool isEarlier(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 < y2) return true;
    if (y1 > y2) return false;
    if (m1 < m2) return true;
    if (m1 > m2) return false;
    return d1 < d2;
}


void printFileToConsole(const string &fileName) {
    ifstream file(fileName);
    string line;
    cout << "Файл " << fileName << ":" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {

    ofstream createInputFile("dates.txt");
    createInputFile << "15/05/1985\n";
    createInputFile << "01/01/2000\n";
    createInputFile << "23/12/1970\n";
    createInputFile << "30/09/2049\n";
    createInputFile.close();


    ifstream inputFile("dates.txt");
    ofstream outputFile("output.txt");

    int minDay = 31, minMonth = 12, minYear = 2049;
    int maxDay = 1, maxMonth = 1, maxYear = 1951;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int day, month, year;
        char slash1, slash2;


        ss >> day >> slash1 >> month >> slash2 >> year;


        if (isEarlier(day, month, year, minDay, minMonth, minYear)) {
            minDay = day;
            minMonth = month;
            minYear = year;
        }


        if (isEarlier(maxDay, maxMonth, maxYear, day, month, year)) {
            maxDay = day;
            maxMonth = month;
            maxYear = year;
        }
    }


    outputFile << "Найстаріша дата: " << minDay << "/" << minMonth << "/" << minYear << endl;
    outputFile << "Найсвіжіша дата: " << maxDay << "/" << maxMonth << "/" << maxYear << endl;

    inputFile.close();
    outputFile.close();


    printFileToConsole("dates.txt");
    printFileToConsole("output.txt");

    return 0;
}
