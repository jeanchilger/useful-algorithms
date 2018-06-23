#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string word, int size) {
    /*
    checks if a given string of a given size is a palindrome
    ---------
    the string can be replaced by a char pointer (C-style string)
    the size can be calculated inside the function
    */

    int start = 0;
    int end = size-1;
    while (end-start > 0) {
        if (word[start] != word[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

// testing the algorithm
int main() {

    string word;

    while (true) {
        cin >> word;
        if (word == "*") break;

        cout << isPalindrome(word, word.size()) << endl;
    }

    return 0;
}
