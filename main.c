#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

// Deklarasi semua fungsi sorting
void bubble_sort_int(int arr[], int n);
void bubble_sort_string(char *arr[], int n);
void insertion_sort_int(int arr[], int n);
void insertion_sort_string(char *arr[], int n);
void selection_sort_int(int arr[], int n);
void selection_sort_string(char *arr[], int n);
void merge_sort_int(int arr[], int n);
void merge_sort_string(char *arr[], int n);
void quick_sort_int(int arr[], int n);
void quick_sort_string(char *arr[], int n);
void shell_sort_int(int arr[], int n);
void shell_sort_string(char *arr[], int n);

// Deklarasi fungsi baca file (dari anggota B)
int baca_file_kata(const char *filename);

// Gunakan extern agar mengacu ke variabel di utils.c
extern char **word_array;
extern int word_count;

// Variabel lokal untuk main.c (backup)
char **backup_array = NULL;

void backup_data() {
    if (backup_array != NULL) {
        for (int i = 0; i < word_count; i++) {
            free(backup_array[i]);
        }
        free(backup_array);
    }
    
    backup_array = (char**)malloc(word_count * sizeof(char*));
    for (int i = 0; i < word_count; i++) {
        backup_array[i] = (char*)malloc((strlen(word_array[i]) + 1) * sizeof(char));
        strcpy(backup_array[i], word_array[i]);
    }
}

void restore_from_backup() {
    for (int i = 0; i < word_count; i++) {
        strcpy(word_array[i], backup_array[i]);
    }
}

void menu_sorting_dasar() {
    int pilihan;
    int data[INT_DATA_SIZE];
    double waktu;
    int data_asli[INT_DATA_SIZE];
    
    do {
        printf("\n======== SORTING DASAR ========\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Kembali\n");
        printf("Pilih metode: ");
        scanf("%d", &pilihan);
        
        if (pilihan >= 1 && pilihan <= 3) {
            generate_random_data(data, INT_DATA_SIZE);
            
            for (int i = 0; i < INT_DATA_SIZE; i++) {
                data_asli[i] = data[i];
            }
            
            printf("\n=== DATA ASLI (10 data pertama) ===\n");
            display_int_array(data_asli, INT_DATA_SIZE, 10);
            
            shuffle_int(data, INT_DATA_SIZE);
            printf("\n=== SETELAH DIACAK (10 data pertama) ===\n");
            display_int_array(data, INT_DATA_SIZE, 10);
            
            switch(pilihan) {
                case 1:
                    printf("\n=== MENJALANKAN BUBBLE SORT ===\n");
                    waktu = hitung_waktu_int(bubble_sort_int, data, INT_DATA_SIZE);
                    break;
                case 2:
                    printf("\n=== MENJALANKAN INSERTION SORT ===\n");
                    waktu = hitung_waktu_int(insertion_sort_int, data, INT_DATA_SIZE);
                    break;
                case 3:
                    printf("\n=== MENJALANKAN SELECTION SORT ===\n");
                    waktu = hitung_waktu_int(selection_sort_int, data, INT_DATA_SIZE);
                    break;
            }
            
            printf("\n=== SETELAH SORTING (10 data pertama) ===\n");
            display_int_array(data, INT_DATA_SIZE, 10);
            printf("\n========================================================\n");
            printf("Waktu eksekusi: %.3f milidetik\n", waktu);
            printf("========================================================\n");
        }
    } while(pilihan != 4);
}

void menu_advance_sorting() {
    int pilihan;
    double waktu;
    
    if (word_array == NULL) {
        printf("\n========================================================\n");
        printf("MEMBACA DATASET KATA...\n");
        word_count = baca_file_kata("words.txt");
        if (word_count <= 0) {
            printf("ERROR: Gagal membaca data kata!\n");
            return;
        }
        printf("Total kata yang dibaca: %d\n", word_count);
        backup_data();
    }
    
    do {
        printf("\n======== ADVANCE SORTING ========\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Shell Sort\n");
        printf("4. Kembali\n");
        printf("Pilih metode: ");
        scanf("%d", &pilihan);
        
        if (pilihan >= 1 && pilihan <= 3) {
            restore_from_backup();
            
            printf("\n=== DATA ASLI DARI FILE (10 kata pertama) ===\n");
            display_string_array(word_array, word_count, 10);
            
            shuffle_string(word_array, word_count);
            printf("\n=== SETELAH DIACAK (10 kata pertama) ===\n");
            display_string_array(word_array, word_count, 10);
            
            switch(pilihan) {
                case 1:
                    printf("\n=== MENJALANKAN MERGE SORT ===\n");
                    waktu = hitung_waktu_string(merge_sort_string, word_array, word_count);
                    break;
                case 2:
                    printf("\n=== MENJALANKAN QUICK SORT ===\n");
                    waktu = hitung_waktu_string(quick_sort_string, word_array, word_count);
                    break;
                case 3:
                    printf("\n=== MENJALANKAN SHELL SORT ===\n");
                    waktu = hitung_waktu_string(shell_sort_string, word_array, word_count);
                    break;
            }
            
           
