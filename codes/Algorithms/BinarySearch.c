#include <stdio.h>

// O(log n)
int binary_search(int array[], int count, int data) { 
    int left, right, mid;

    left = 0;
    right = count;
    mid = (left+right)/2;

    while (left <= right && data != array[mid]) {
        if (data > array[mid]) 
            left = mid+1;
        else
            right = mid-1;
        mid = (left+right)/2;
    }

    return left <= right;
}

int main() {

    int array[] = {2, 4, 6, 8, 10, 12, 14};
    printf("%d", binary_search(array, 7, 4));
    return 0;
}