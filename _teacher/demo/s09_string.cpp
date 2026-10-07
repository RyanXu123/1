#include <cstdio>
#include <windows.h>   // 只为了让终端用 UTF-8 显示中文，和字符串本身没关系

int main() {
    SetConsoleOutputCP(65001);

    char s[6] = "hello";     // h e l l o \0，一共 6 格

    printf("整串：%s\n", s);

    // 一格一格看清楚
    for (int i = 0; i < 6; i++) {
        printf("第 %d 格：%c   编号 %d\n", i, s[i], s[i]);
    }

    // 数长度：碰到 \0 就停
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    printf("长度 = %d\n", n);

    // 倒着印
    printf("倒过来：");
    for (int i = n; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
