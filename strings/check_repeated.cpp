#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> cache;

int checkNotRepeated(string a, int index, int nonRepeated=0) {
    /*
    Checks the number of non-repeated elements in a given string.
    Receives a string a and an starting index for the verification.
    The nonRepeated value should be zero, used just in recursion.
    */

    while (index < a.size()) {
        if (!cache[a.at(index) - 'a']) {
            cache[a.at(index) - 'a'] = 1;
            nonRepeated += 1;
        }
        index++;
    }

    return nonRepeated;

}

int main() {

    string a;

    cin >> a;

    cache.assign(26, 0);

    int v = checkNotRepeated(a, 0);

    cout << v << endl;


    return 0;
}
