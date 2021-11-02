#include <stdio.h>

int putere(int n, int m) {
    if(m==0) return 1;
    else return n*putere(n, m-1);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", putere(n,m));
}