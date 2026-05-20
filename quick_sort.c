#include <stdio.h>
#include <string.h>

int partition_int(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort_int_recursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_int(arr, low, high);
        quick_sort_int_recursive(arr, low, pi - 1);
        quick_sort_int_recursive(arr, pi + 1, high);
    }
}

void quick_sort_int(int arr[], int n) {
    quick_sort_int_recursive(arr, 0, n - 1);
}

int partition_string(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quick_sort_string_recursive(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition_string(arr, low, high);
        quick_sort_string_recursive(arr, low, pi - 1);
        quick_sort_string_recursive(arr, pi + 1, high);
    }
}

void quick_sort_string(char *arr[], int n) {
    quick_sort_string_recursive(arr, 0, n - 1);
}
