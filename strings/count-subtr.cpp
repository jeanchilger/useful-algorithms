#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/*counts occurrences of a substring in a larger string
with overlapping (e.g.: there are 2 occurrences of "aa" in "aaa")*/

int count(string subs, string str, int start=0, int end=0) {
    int occur = 0;
    end = (end == 0 ? str.length() - subs.length() : end);

    for (; start < end; start++) {
        string token = str.substr(start, subs.length());
        if (token == subs) occur++;
    }

    return occur;
}

int main() {

    return 0;
}
