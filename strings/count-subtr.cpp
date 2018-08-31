#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/*counts occurrences of a substring in a larger string
with overlapping (e.g.: there are 2 occurrences of "aa" in "aaa")*/

int count(string subs, string str, int start=0) {
    int ocur = 0;
    int last = str.length() - subs.length();

    for (; start <= last; start++) {
        string token = str.substr(start, subs.length());
        if (token == subs) ocur++;
    }

    return ocur;
}

int main() {
    //code here


    return 0;
}
