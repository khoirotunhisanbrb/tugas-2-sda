#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"

// DEFINISI variabel global (hanya di sini sekali)
char **word_array = NULL;
int word_count = 0;

void generate_random_data(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void shuffle_int(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void shuffle_string(char *arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void display_int_array(int arr[], int n, int show_count) {
    int limit = (show_count < n) ? show_count : n;
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void display_string_array(char *arr[], int n, int show_count) {
    int limit = (show_count < n) ? show_count : n;
    for (int i = 0; i < limit; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

double hitung_waktu_int(void (*sorting_func)(int[], int), int arr[], int n) {
    clock_t start, end;
    int *temp_arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) temp_arr[i] = arr[i];
    
    start = clock();
    sorting_func(temp_arr, n);
    end = clock();
    
    free(temp_arr);
    
    // Hasil dalam MILIDETIK
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

double hitung_waktu_string(void (*sorting_func)(char*[], int), char *arr[], int n) {
    clock_t start, end;
    char **temp_arr = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) temp_arr[i] = arr[i];
    
    start = clock();
    sorting_func(temp_arr, n);
    end = clock();
    
    free(temp_arr);
    
    // Hasil dalam MILIDETIK
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}
