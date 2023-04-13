#include<stdio.h>

int bar(int a, int b, int c) {
    // printf("%d,%d,%d\n", a,b,c);
    // printf("%d\n", (b - a) << (c));
    return (b - a) << (c); //shifts b-a left c times 
}

int foo(int m, int n, int o) {
    int p = bar(m + o, n + o, m + n); // bar(4, 5, 3)
    int q = bar(m - o, n - m, n + n); // bar(-2, 1, 4)
    printf("p + q: %d\n", p + q); //56
    return p + q;
}

int main() {
    int x = 1, y = 2, z = 3;
    z = x + y + z + foo(x, y, z); //62
    printf("%d\n", z);
    return 0;
}
