/*
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * Source: https://practice.geeksforgeeks.org/problems/repetitive-addition-of-digits/0
 * */

#include <iostream>
#include <string>

using namespace std;

int main() {

    int t;
    long int sum, aux;
    string n;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        do {
            sum = 0;

            for (char x : n) {
                sum += (long int)(x - '0');
            }
            n = to_string(sum);

        } while (sum > 9);

        cout << sum << endl;
        
    }
}
