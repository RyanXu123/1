#include <cstdio>

// ================= 实验一：盒子死在房间里 =================
// add/f 的房间一拆，里面的 b 就化成灰
int f(int a) {
    int b = a + 1;
    return b;
}

// ================= 实验二：参数是复印进来的 =================
void half(int a) {          // 收到的是 n 的复印件
    a = a / 2;
    printf("里面 %d\n", a);  // 50
}

// 想让外面也变成 50 的版本：把结果交出来
int half2(int a) {
    return a / 2;
}

int main() {
    // ---------- 实验一 ----------
    printf("实验一：%d\n", f(10));   // 11
    // printf("%d\n", b);           // ← 把上面这行开头的 // 去掉，编译就炸：
                                    //    error: 'b' was not declared in this scope

    // ---------- 实验二 ----------
    int n = 100;
    half(n);
    printf("实验二：外面 %d\n", n);  // 100  ← 没变

    int m = 100;
    m = half2(m);                   // 自己伸手接住，再写回自己身上
    printf("实验二：改完 %d\n", m);  // 50

    // ---------- 实验三：遮蔽 ----------
    int k = 1;
    {
        int k = 2;
        {
            int k = 3;
            printf("实验三：%d\n", k);   // 3
        }
        printf("实验三：%d\n", k);       // 2
    }
    printf("实验三：%d\n", k);           // 1

    return 0;
}
