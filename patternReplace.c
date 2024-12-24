#include <stdio.h>

#define MAX 256

int stringMatch(char str[], char pat[], char repl[], char ans[]) {
    int flag = 0, strIter = 0, ansIter = 0, patIter = 0, matchIndex = 0;

    while (str[strIter] != '\0') {
        if (str[matchIndex] == pat[patIter]) {
            matchIndex++; patIter++;
            if (pat[patIter] == '\0') {
                flag = 1;
                for (int i = 0; repl[i] != '\0'; i++)
                    ans[ansIter++] = repl[i];
                strIter = matchIndex;
                patIter = 0;
            }
        } else {
            ans[ansIter++] = str[strIter++];
            matchIndex = strIter;
            patIter = 0;
        }
    }
    ans[ansIter] = '\0';
    return flag;
}

void removeNewline(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            return;
        }
    }
}

int main() {
    char str[MAX], pat[MAX], repl[MAX], ans[MAX];

    printf("Enter String: ");
    fgets(str, MAX, stdin);
    removeNewline(str);

    printf("Enter pattern to find: ");
    fgets(pat, MAX, stdin);
    removeNewline(pat);

    printf("Enter Replacement: ");
    fgets(repl, MAX, stdin);
    removeNewline(repl);

    int flag = stringMatch(str, pat, repl, ans);
    if (flag)
        printf("Modified String is: %s\n", ans);
    else
        printf("Pattern Doesn't exist\n");
}   