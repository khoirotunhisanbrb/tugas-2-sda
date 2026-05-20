#ifndef UTILS_H
#define UTILS_H

#include <time.h>

#define INT_DATA_SIZE 1000

extern char **word_array;
extern int word_count;

// Utility functions
void generate_random_data(int arr[], int n);
void shuffle_int(int arr[], int n);
void shuffle_string(char *arr[], int n);
void display_int_array(int arr[], int n, int show_count);
void display_string_array(char *arr[], int n, int show_count);
double hitung_waktu_int(void (*sorting_func)(int[], int), int arr[], int n);
double hitung_waktu_string(void (*sorting_func)(char*[], int), char *arr[], int n);

#endif
