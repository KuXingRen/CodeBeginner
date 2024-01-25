#include <stdio.h>
#include <stdlib.h>

void findMinAbsPair(int arr[], int n) {
    if (n < 2) {
        printf("Invalid Input");
        return;
    }

    // Sort array in increasing order.
    qsort(arr, n, sizeof(arr[0]), compare);

    // Initialize result
    int min_l = 0, min_r = 1, min_sum = abs(arr[0] + arr[1]);

    // Check all pairs and update min_sum
    for (int l = 0, r = n - 1; l < r;) {
        int sum = arr[l] + arr[r];

        // Update result if current pair sum is closer to zero
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_l = l;
            min_r = r;
        }

        // Move to next pair
        if (sum < 0)
            l++;
        else
            r--;
    }

    printf("The two elements with minimum absolute sum are %d and %d", arr[min_l], arr[min_r]);
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
