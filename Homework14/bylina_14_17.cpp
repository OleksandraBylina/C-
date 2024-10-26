#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream inputFile("input14.txt");
    string line;
    getline(inputFile, line);
    inputFile.close();
    int current_letter_counter = 0;
    string new_line = "";
    for (int i = 0 ; i < line.length() + 1; i++) {
        if(line[i] == new_line.back()) {
            current_letter_counter++;
        }
        else {
            new_line += to_string(current_letter_counter + 1);
            current_letter_counter = 0;
            new_line += line[i];
        }
    }
    string final_line = "";
    for (int e = 0 ; e < new_line.length() ; e++) {
        if (new_line[e] != '1') {
            final_line += new_line[e];
        }
    }
    cout << final_line << endl;
    ofstream outputFile("input14.txt", ios::trunc);
    outputFile << final_line;

}
