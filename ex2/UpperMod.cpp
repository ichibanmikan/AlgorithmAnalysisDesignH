#include <stdio.h>
using namespace std;
const int MAXN = 1e5;
long a[MAXN], b[MAXN];
int bit[105], a2[105];
long m;
// a^b=a^(2^b0+2^b1+…+2^bk)=a^(2^b0) * a^(2^b1) *...* a^(2^bk)，计算时不断取模
// 为化简计算，后一项可由前一项的平方得到，先计算每一项的平方作为下一项
// a^(2^(i+1)) = (a^(2^i))^2
long mods(long a, long b) {
    int i = 0, j, k, s = 1;
    while (b) {
        bit[i] = b % 2;
        i++;
        b >>= 1;
    }
    a2[0] = a % m;
    for (j = 1; j < i; j++)
        a2[j] = a2[j - 1] * a2[j - 1] % m;
    for (k = 0; k < i; k++) {
        if (bit[k])
            s = s * a2[k] % m;
    }
    return s;
}

int main() {
    long n, a, b, s = 0;
    int i;
    scanf("%ld\n%ld", &m, &n);
    for (i = 0; i < n; i++) {
        scanf("%ld %ld", &a, &b);
        s += mods(a, b);
        s %= m;
    }
    printf("%ld\n", s);
}