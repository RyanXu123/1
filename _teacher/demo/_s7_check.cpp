#include <cstdio>

int f(int a) {
    int b = a + 1;
    return b;
}

void half(int a) {
    a = a / 2;
    printf("inside %d\n", a);
}

int main() {
    printf("%d\n", f(10));

    int n = 100;
    half(n);
    printf("outside %d\n", n);

    int k = 1;
    {
        int k = 2;
        {
            int k = 3;
            printf("k3=%d\n", k);
        }
        printf("k2=%d\n", k);
    }
    printf("k1=%d\n", k);

    return 0;
}
