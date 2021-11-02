#include <stdio.h>

int F(int k) {
    if(k==0) return 0;
    else if(k==1) return 1;
        else return F(k-1)+F(k-2);
}

int main() {
    int k;
    scanf("%d", &k);
    printf("%d", F(k));
}