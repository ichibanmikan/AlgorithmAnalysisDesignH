#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

#define ll long long
const int M = 1e5 + 1;
int f1[M], f2[M], a[M];
int main(){
    int n = 0;
    while (scanf("%d", &a[++n]) != EOF);
    n--;
    int len1 = 1, len2 = 1;
    f1[1] = a[1];
    f2[1] = a[1];
    for (int i = 2; i <= n; i++) {
        if (f1[len1] >= a[i]) f1[++len1] = a[i];
        else {
            int p = upper_bound(f1 + 1, f1 + 1 + len1, a[i],greater<int>())-f1;
            f1[p] = a[i];
        }
        if (f2[len2] < a[i]) f2[++len2] = a[i];
        else {
            int p = lower_bound(f2 + 1, f2 + 1 + len2, a[i])-f2;
            f2[p] = a[i];
        }

    }
    cout << len1 << ' ' << len2 << endl;
    return 0;
}