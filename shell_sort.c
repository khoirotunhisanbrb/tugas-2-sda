```c
#include <stdio.h>
#include <string.h>

void shell_sort_int(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

void shell_sort_string(char *arr[], int n) {
    int gap, i, j;
    char *temp;

    for (gap = n /2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];

            for (j = i; j >= gap &&
                 strcmp(arr[j - gap], temp) > 0; j -= gap) {

                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}
```

