#include <stdio.h>

typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

ulli binaryInsertion(lli e, ulli len, lli a[]) {
    if (len == 0)
        return 0;
    else if (e <= a[0])
        return 0;
    else if (e > a[len-1])
         return len;
    else {
        ulli start = 0;
        ulli end = len-1;
        while (start <= end) {
            ulli m = (start + end) / 2;
            if (a[m-1] < e and a[m] >= e)
                return m;
            else if (e < a[m])
                end = m-1;
            else if (e > a[m])
                start = m+1;
        }
    }
}

int main() {
    //code here

    return 0;
}
