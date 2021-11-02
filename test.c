#include <stdio.h>
int main() {
    double arr[] = {20, 11, 34, 67, 0, 3, 2, 1, 789, 9999, 567, 123};
    int len = sizeof(arr) / sizeof(*arr);
    int nrdigit=0;
    double max=arr[0];
    /*for(i=1; i<len; i++) {
        if(arr[i]>max) max=arr[i];
    }*/
    while(max!=0) {
        max=max/10;
        nrdigit=nrdigit+1;
    }
    printf("%d", nrdigit);
}