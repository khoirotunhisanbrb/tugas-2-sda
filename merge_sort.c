#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge_int(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void merge_sort_int_recursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_int_recursive(arr, left, mid);
        merge_sort_int_recursive(arr, mid + 1, right);
        merge_int(arr, left, mid, right);
    }
}

void merge_sort_int(int arr[], int n) {
    merge_sort_int_recursive(arr, 0, n - 1);
}

void merge_string(char *arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char **L = (char**)malloc(n1 * sizeof(char*));
    char **R = (char**)malloc(n2 * sizeof(char*));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
}

void merge_sort_string_recursive(char *arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_string_recursive(arr, left, mid);
        merge_sort_string_recursive(arr, mid + 1, right);
        merge_string(arr, left, mid, right);
    }
}

void merge_sort_string(char *arr[], int n) {
    merge_sort_string_recursive(arr, 0, n - 1);
}
