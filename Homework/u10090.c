#include <stdlib.h>
#include <stdio.h>

long long exgcd(long long x, long long y, long long *a, long long *b) {
    int flag = 0;
    long long t, la = 1, lb = 0, ra = 0, rb = 1;
    while(x%y) {
        if(flag == 0)
            la -= x/y*ra, lb -= x/y*rb;
        else
            ra -= x/y*la, rb -= x/y*lb;
        t = x, x = y, y = t%y;
        flag = 1 - flag;
    }
    if(flag == 0)
        *a = ra, *b = rb;
    else
        *a = la, *b = lb;
    return y;
}
int main() {
    long long n, n1, n2, c1, c2;
    while(scanf("%lld", &n) == 1 && n) {
        scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
        long long a, b, g;
        g = exgcd(n1, n2, &a, &b);
        if(n%g) {
            puts("failed");
            continue;
        }
        long long k = n/g, k1, k2;
        a *= k, b *= k;
        k1 = n1*n2/g/n1, k2 = n1*n2/g/n2;
        if(a < 0) {
            k = -(a/k1) + (a%k1 != 0);
            a += k*k1, b -= k*k2;
        }
        if(b < 0) {
            k = -(b/k2) + (b%k2 != 0);
            a -= k*k1, b += k*k2;
        }
        if(a < 0 || b < 0) {
            puts("failed");
            continue;
        }
        long long x1, x2, y1, y2;
        k = a/k1;
        a -= k*k1;
        b += k*k2;
        x1 = a, y1 = b;
        k = b/k2;
        a += k*k1;
        b -= k*k2;
        x2 = a, y2 = b;
        if(x1*c1 + y1*c2 < x2*c1 + y2*c2)
            printf("%lld %lld\n", x1, y1);
        else
            printf("%lld %lld\n", x2, y2);
    }
    return 0;
}