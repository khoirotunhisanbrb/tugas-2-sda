#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int baca_file_kata(const char *filename) {
    // LANGSUNG PAKAI DATA DUMMY, TIDAK PERLU BACA FILE
    printf("\n========================================================\n");
    printf("MENGGUNAKAN DATA KATA DUMMY (tidak perlu file words.txt)\n");
    printf("========================================================\n\n");
    
    const char *dummy_words[] = {
        "zebra", "apple", "mango", "banana", "grape", 
        "orange", "kiwi", "peach", "cherry", "dates",
        "elderberry", "fig", "guava", "honeydew", "apricot",
        "blueberry", "cranberry", "dragonfruit", "jackfruit", "lime",
        "lemon", "melon", "nectarine", "olive", "papaya",
        "quince", "raspberry", "strawberry", "tangerine", "watermelon"
    };
    int dummy_count = 30;
    
    word_count = dummy_count;
    word_array = (char*)malloc(word_count * sizeof(char));
    
    for (int i = 0; i < word_count; i++) {
        word_array[i] = (char*)malloc((strlen(dummy_words[i]) + 1) * sizeof(char));
        strcpy(word_array[i], dummy_words[i]);
    }
    
    printf("Menggunakan %d kata dummy untuk sorting.\n", word_count);
    return word_count;
}
