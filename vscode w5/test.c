#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int arr[n];
        for (int i=0; i<n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmp);
        int mid1, mid2;
        if (n %2 == 1) {
            mid1 = arr[n/2];
            int same = 0;
            for (int i=0; i<n; i++) same += (arr[i] == mid1);
            printf("%d %d %d\n", mid1, same, 1);
        }
        else {
            mid1 = arr[n/2-1];
            mid2 = arr[n/2];
            int same = 0;
            for (int i=0; i<n; i++) same += (arr[i] == mid1) || (arr[i] == mid2);
            printf("%d %d %d\n", mid1, same, mid2-mid1+1);
        }

    }

}