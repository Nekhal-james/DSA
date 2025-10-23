#include <stdio.h>
#include <stdlib.h>

// ---------- Bubble Sort ----------
int bubbleSort(int arr[], int n) {
    int steps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            steps++; // comparison
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                steps++; // swap
            }
        }
    }
    return steps;
}

// ---------- Selection Sort ----------
int selectionSort(int arr[], int n) {
    int steps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            steps++; // comparison
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            steps++; // swap
        }
    }
    return steps;
}

// ---------- Insertion Sort ----------
int insertionSort(int arr[], int n) {
    int steps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            steps++; // comparison
            arr[j + 1] = arr[j];
            steps++; // shift
            j--;
        }
        arr[j + 1] = key;
        steps++; // insertion
    }
    return steps;
}

// ---------- Merge Sort Helper ----------
void merge(int arr[], int l, int m, int r, int *steps) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        (*steps)++; // comparison
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        (*steps)++; // insertion
    }

    while (i < n1) {
        arr[k++] = L[i++];
        (*steps)++; // copy
    }

    while (j < n2) {
        arr[k++] = R[j++];
        (*steps)++; // copy
    }
}

void mergeSort(int arr[], int l, int r, int *steps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, steps);
        mergeSort(arr, m + 1, r, steps);
        merge(arr, l, m, r, steps);
    }
}

// ---------- Utility: Copy Array ----------
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

// ---------- Main Function ----------
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int steps_bubble, steps_selection, steps_insertion, steps_merge = 0;

    copyArray(arr, temp, n);
    steps_bubble = bubbleSort(temp, n);

    copyArray(arr, temp, n);
    steps_selection = selectionSort(temp, n);

    copyArray(arr, temp, n);
    steps_insertion = insertionSort(temp, n);

    copyArray(arr, temp, n);
    mergeSort(temp, 0, n - 1, &steps_merge);

    printf("\n📊 Step Comparison (Comparisons + Swaps/Moves):\n");
    printf("Bubble Sort     → %d steps\n", steps_bubble);
    printf("Selection Sort  → %d steps\n", steps_selection);
    printf("Insertion Sort  → %d steps\n", steps_insertion);
    printf("Merge Sort      → %d steps\n", steps_merge);

    return 0;
}