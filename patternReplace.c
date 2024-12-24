#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 128

int findAndReplace(char *str, char *pat, char *repl, char *ans);

int main() {
    char str[MAX_LEN], pat[MAX_LEN], repl[MAX_LEN], ans[MAX_LEN];

    printf("Enter String: ");
    fgets(str, MAX_LEN, stdin);

    printf("Enter pattern: ");
    fgets(pat, MAX_LEN, stdin);

    printf("Enter Replacement: ");
    fgets(repl, MAX_LEN, stdin);

    int patExist = findAndReplace(str, pat, repl, ans);
    if (patExist) {
        printf("%s\n", ans);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}

int findAndReplace(char *str, char *pat, char *repl, char *ans) {
    int patExist = 0;

    int strIter = 0, matchIndex = 0, ansIter = 0, patIter = 0;
    while (str[strIter] != '\0') {
        if (str[matchIndex] == pat[patIter]) {
            matchIndex++; patIter++;
            if (pat[patIter] == '\0') { // patter exists
                patExist = 1;
                // copy the replace string to ans string and set ansIter
                // to specific val
                for (int k = 0; repl[k] != '\0'; k++) {
                    ans[ansIter++] = repl[k];
                }
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
    
    return patExist;
}