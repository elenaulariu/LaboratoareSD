#include <stdio.h>
#include <string.h>

int palindrome(char *string, int start, int end) {
    if(string[start]!=string[end]) return 0;
    else if(start>=end) return 1;
    else return palindrome(string, start+1, end-1);
}

int main() {
    char string[100];
    scanf("%s", string);
    if(palindrome(string, 0, strlen(string)-1)==1)
        printf("da");
        else printf("nu");
}