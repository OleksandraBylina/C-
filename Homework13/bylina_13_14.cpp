#include <iostream>
using namespace std;

int main() {
    string str = "apple pear applecator   pineapple pear apple pineapple carrot applejuice apple";
    string str_found;
    getline(cin, str_found);
    size_t pos = str.find(str_found);
    int string_counter = 0;
    int word_counter = 0;
    while (pos != std::string::npos) {
        string_counter++;
        if ((pos == 0 || str[pos - 1] == ' ') &&
            (pos + str_found.length() == str.length() || str[pos + str_found.length()] == ' ')) {
            word_counter++;
            }
        pos = str.find(str_found, pos + str_found.length());
    }
    cout << string_counter << endl;
    cout << word_counter;
}
