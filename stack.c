#include <stdio.h>
#include <stdlib.h>
#define len 50
void scan_array(int a[], int n){
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
}
void print_array(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }
}
int main()
{
    int a[len], b[len], c[len+len];
    int n, m;
    scanf("%d%d", &n, &m);
    int i=0, j=0, k=0;
    scan_array(a, n);
    scan_array(b, m);
    while(k<=m+n){
        if(i==n){
            c[k++]=a[i++];
            continue;
        }
        if(j==m){
            c[k++]=b[j++];
            continue;
        }
        if(a[i]<b[j]){
            c[k++]=a[i++];
        }
        else
            c[k++]=b[j++];
    }
    print_array(a, n);
    printf("\n");
    print_array(b, m);
    printf("\n");
    print_array(c, m+n);
    return 0;
}
