#include <iostream>

using namespace std;

int josephus (int n, int k) {
    if (n == 1) return 0;

    return (josephus(n - 1, k) + k - 1) % n + 1;

}

int main () {

    int n; // number of people to be killed
    int k; // step between two killed people

    cout << "People >> Step: ";
    cin >> n >> k;
    cout << josephus(n, k) << "\n";

    return 0;
}
