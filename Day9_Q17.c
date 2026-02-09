#include <stdio.h>

int main() {
    char s[1000];
    int i, length = 0;
    char temp;

    scanf("%s", s);

    while (s[length] != '\0') {
        length++;
    }

    for (i = 0; i < length / 2; i++) {
        temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }

    printf("%s", s);

    return 0;
}
