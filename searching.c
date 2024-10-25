//linear search
#include <stdio.h>
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    
    int result = linearSearch(arr, n, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}
//-------------------------------------------------------------------------------------

//binary search
#include<stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    
    int result = binarySearch(arr,0,n-1, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    return 0;
}

//--------_-----------------------------------------------------------

//Interpolation Search
#include<stdio.h>
int interpolationSearch(int arr[], int lo, int hi, int x){
    int pos;
    if(lo==hi){
        if(arr[lo]==x){
            return lo;
        }
        return-1;
    }
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}
      
   int main() {
    int arr[] = {10,12,13,14,16,18,20,21,25,26,30};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int key = 26;
    if(n!=0){
        int result = interpolationSearch(arr,0,n-1, key);
        if (result != -1) {
            printf("Element %d found at index %d\n", key, result);
        } else {
            printf("Element %d not found in the array\n", key);
        }
    }
    else{
        printf("array is empty.");
    }
    return 0;
}
