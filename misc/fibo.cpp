#include <iostream>
#include <vector>

using namespace std;

vector<int> cache;

int calls1 = 0;
int callsDP = 0;

int fibo1(int n) {
    /*
    Normal recursive Fibonacci used for comparison.
    */
    calls1++;
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibo1(n - 2) + fibo1(n - 1);
    }
}

int fibo(int n) {
    /*
    Calculates the nth term of the Fibonacci serie using Dynamic Programming.
    */
    callsDP++;
    if (cache[n] != -1) {
        return cache[n];
    }

	if (n == 0 || n == 1) {
		return n;

    } else {
		return cache[n] = fibo(n - 2) + fibo(n - 1);

	}
}

int main() {
	int n;
	cin >> n;

	cache.assign(n+1, -1);

    cout << fibo(n) << " DP-> " << callsDP << " calls" << endl;
    cout << fibo1(n) << " NORMAL-> " << calls1 << " calls" << endl;

    return 0;

}
