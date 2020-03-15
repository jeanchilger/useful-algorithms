/*
 * Extended version of euclidean algorithm (based on CLRS).
 *
 * Returns the GCD d, and coeficients x and y, such that
 * d = ax + by, where a and b are the algorithm inputs.
 * */

#include <bits/stdc++.h>

using namespace std;

typedef long int li;


vector<li> extendedEuclid(li a, li b) {
    /*
     * */

    if (!b) {
        vector<li> result = {a, 1, 0};
        return result;
    }

    vector<li> result = extendedEuclid(b, a % b);

    vector<li> preResult = {result[0], result[2], result[1] - (a / b) * result[2]};
    return preResult;

}

int main() {

    li a, b;

    printf("Enter two numbers: ");
    scanf("%ld %ld", &a, &b);

    vector<li> result = extendedEuclid(a, b);

    printf("%ld = %ld(%ld) + %ld(%ld)\n", result[0], a, result[1], b, result[2]);


    return 0;
}
