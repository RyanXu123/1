#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[80];

    printf("> ");
    while (fgets(line, sizeof line, stdin) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (line[0] == '\0') {
            printf("empty line\n");
            printf("> ");
            continue;
        }

        char work[80];
        char *words[8];
        int n = 0;

        strcpy(work, line);

        char *token = strtok(work, " ");
        while (token != NULL && n < 8) {
            words[n] = token;
            n++;
            token = strtok(NULL, " ");
        }

        printf("count=%d\n", n);
        for (int i = 0; i < n; i++) {
            printf("word[%d]=[%s]\n", i, words[i]);
        }

        if (n == 0) {
            printf("no word\n");
        } else if (strcmp(words[0], "move") == 0) {
            if (n < 3) {
                printf("move needs two arguments\n");
            } else {
                printf("x=%s, y=%s\n", words[1], words[2]);
            }
        } else if (strcmp(words[0], "quit") == 0) {
            break;
        } else {
            printf("unknown command: %s\n", words[0]);
        }

        printf("> ");
    }

    return 0;
}