#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream inputFile("input14_2.txt");
    ofstream outputFile("output14_2.txt");
    while (inputFile.good()) {
        string line;
        string new_line = "";
        getline(inputFile, line);
        for (int i = 0 ; i < line.length(); i++) {
            switch (line[i]) {
                case '0':
                    new_line += "zero";
                    break;
                case '1':
                    new_line += "one";
                    break;
                case '2':
                    new_line += "two";
                    break;
                case '3':
                    new_line += "three";
                    break;
                case '4':
                    new_line += "four";
                    break;
                case '5':
                    new_line += "five";
                    break;
                case '6':
                    new_line += "six";
                    break;
                case '7':
                    new_line += "seven";
                    break;
                case '8':
                    new_line += "eight";
                    break;
                case '9':
                    new_line += "nine";
                    break;
                default:
                    new_line += line[i];
                    break;



            }

        }
    outputFile << new_line << '\n';

    }
    outputFile.close();
}
