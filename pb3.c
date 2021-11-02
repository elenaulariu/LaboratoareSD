#include <stdio.h>
#include <stdlib.h>

int f(int v[], int n) {
    if(n==0) return 0;
    if(n%2==0) return f(v, n-1)-v[n-1];
    else return f(v, n-1)+v[n-1];
}

int main() {
    int n;
    scanf("%d", &n);
    int *v=malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%d", f(v, n));
    free(v);

}