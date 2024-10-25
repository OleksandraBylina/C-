#include <iostream>
using namespace std;

int main() {
    string str = "utuhuueu        ddradcdddodond ewawtsw banb qqaqppqlqeq";
    int len = str.length();
    string word = "";
    string complete = "";

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            if (!word.empty()) {
                char last_char = word.back();
                for (int a = 0; a < word.length();) {
                    if (word[a] == last_char) {
                        word.erase(a, 1);
                    } else {
                        a++;
                    }
                }
                complete += word;
                word = "";
            }
            complete += ' ';
        } else {
            word += str[i];
        }
    }


    if (!word.empty()) {
        char last_char = word.back();
        for (int a = 0; a < word.length();) {
            if (word[a] == last_char) {
                word.erase(a, 1);
            } else {
                a++;
            }
        }
        complete += word;
    }


    cout << complete << endl;

    return 0;
}
