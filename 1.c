#include <stdio.h>

int main(void)
{
    char word[6] = "hello";
    char names[3][6] = {"Amy", "Bob", "Cid"};

    printf("word = %s\n", word);
    printf("word[0] = %c, word[1] = %c\n", word[0], word[1]);
    printf("word[5] = %d\n", word[5]);

    for (int i = 0; i < 3; i++) {
        printf("names[%d] = %s\n", i, names[i]);
    }

    names[1][1] = 'X';
    printf("changed = %s\n", names[1]+2);
    return 0;
}