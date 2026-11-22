/* p68c_move_guard.c
 *
 * 这一份只练一层：命令参数必须全部验完，才准修改坐标。
 *
 * 命令：
 *   move dx dy
 *   where
 *   quit
 *
 * 编译：
 *   gcc -std=c11 -Wall -Wextra p68c_move_guard.c -o p68c_move_guard
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 整串都是十进制整数时收下，并把值写进 *out。 */
int readNum(char s[], long *out)
{
    char *end;
    long value;

    value = strtol(s, &end, 10);
    if (end == s) {
        return 0;
    }
    if (*end != '\0') {
        return 0;
    }

    *out = value;
    return 1;
}

/* value 落在 lo 到 hi（含两端）之间时交回 1。 */
int in_range(long value, long lo, long hi)
{
    if (value < lo || value > hi) {
        return 0;
    }
    return 1;
}

int main(void)
{
    char line[80];
    char work[80];
    char *words[8];
    char *p;
    long dx_long;
    long dy_long;
    int n;
    int x = 0;
    int y = 0;

    printf("commands: move dx dy | where | quit\n");

    while (fgets(line, sizeof line, stdin) != NULL) {
        p = strchr(line, '\n');
        if (p != NULL) {
            *p = '\0';
        }

        strcpy(work, line);
        n = 0;
        p = strtok(work, " ");
        while (p != NULL && n < 8) {
            words[n] = p;
            n = n + 1;
            p = strtok(NULL, " ");
        }

        if (n == 0) {
            continue;
        }

        if (strcmp(words[0], "quit") == 0) {
            break;
        } else if (strcmp(words[0], "where") == 0) {
            printf("position=(%d, %d)\n", x, y);
        } else if (strcmp(words[0], "move") == 0) {
            if (n != 3) {
                printf("move needs exactly 2 arguments\n");
            } else if (!readNum(words[1], &dx_long)) {
                printf("bad dx: %s\n", words[1]);
            } else if (!readNum(words[2], &dy_long)) {
                printf("bad dy: %s\n", words[2]);
            } else if (!in_range(dx_long, -10000, 10000)
                       || !in_range(dy_long, -10000, 10000)) {
                printf("move is limited to -10000..10000\n");
            } else {
                x = x + (int)dx_long;
                y = y + (int)dy_long;
                printf("moved=(%ld, %ld), position=(%d, %d)\n",
                       dx_long, dy_long, x, y);
            }
        } else {
            printf("unknown command: %s\n", words[0]);
        }

        printf("> ");
    }

    return 0;
}
