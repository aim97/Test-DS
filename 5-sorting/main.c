#include <stdio.h>
#include <stdlib.h>
#define swap(x,y) { x = x + y; y = x - y; x = x - y; }

void insertionSort(int* arr, int n) {
    int tmp;
    for(int i = 0;i < n;i++) {
        tmp = n-1;
        for(int j = n-2;j > i;j--) {
            if(arr[j] < arr[tmp]) tmp = j;
        }
        if(arr[i] > arr[tmp]) swap(arr[i], arr[tmp]);
    }
}

void bubbleSort(int* arr, int n) {
    int flag;
    for(int i = 0;i < n;i++) {
        flag = 0;
        for(int j = n-2;j >= i;j--){
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
                flag = 1;
            }
        }
        if(!flag) return;
    }
}

void mergeSort(int* arr, int n) {
    if(n == 1) return;

    int* arr1 = arr, *arr2 = arr + n/2;
    int sz1 = n/2, sz2 = n - n/2;

    mergeSort(arr1, sz1);
    mergeSort(arr2, sz2);

    int i = 0;
    int* tmp = (int*)malloc(n * sizeof(int));
    while (sz1 || sz2) {
        if(!sz2 || sz1 && *arr1 < *arr2) {
            tmp[i] = *arr1;
            sz1--;
            arr1++;
        } else {
            tmp[i] = *arr2;
            sz2--;
            arr2++;
        }
        i++;
    }

    for(int i = 0;i < n;i++) arr[i] = tmp[i];

    free(tmp);
}

int main(){
    int arr[] = {1,4,8,9,10,5,2,1};
    mergeSort(arr, 8);
    for(int i = 0;i < 8;i++)printf("%d ", arr[i]);
    return 0;
}
