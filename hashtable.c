#include <stdio.h>

#define SIZE 10

int main() {
    int hashTable[SIZE];
    int i, n, key, index;

    // Initialize hash table
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1; // -1 means empty slot

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % SIZE;

        // Linear probing for collision handling
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }

    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d → %d\n", i, hashTable[i]);
        else
            printf("Index %d → [Empty]\n", i);
    }

    return 0;
}

