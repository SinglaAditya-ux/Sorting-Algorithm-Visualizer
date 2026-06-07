/*
 * ============================================
 * PROJECT: SORTING ALGORITHM VISUALIZER
 * INTERN ID: CITS3437
 * NAME: Aditya Singla
 * WEEKS: 4 Weeks (3rd June - 1st July)
 * COMPANY: CodTech IT Solutions
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Maximum array size */
#define MAX_SIZE 20

/* ---- FUNCTION DECLARATIONS ---- */
void display_array(int arr[], int size);
void display_bars(int arr[], int size);
void bubble_sort(int arr[], int size);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void generate_random(int arr[], int size);
void get_manual_input(int arr[], int *size);
void display_menu();
void copy_array(int src[], int dest[], int size);

/* Global step counter */
int steps = 0;

/* ---- MAIN FUNCTION ---- */
int main() {
    int arr[MAX_SIZE];
    int temp[MAX_SIZE];
    int size = 10;
    int choice;

    /* Seed random number generator */
    srand(time(0));

    /* Generate default random array */
    generate_random(arr, size);

    printf("\n==============================================\n");
    printf("   SORTING ALGORITHM VISUALIZER             \n");
    printf("   Aditya Singla | CITS3437                 \n");
    printf("==============================================\n");

    while (1) {
        printf("\nCurrent Array: ");
        display_array(arr, size);
        display_bars(arr, size);

        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Bubble Sort */
                copy_array(arr, temp, size);
                steps = 0;
                printf("\n--- BUBBLE SORT ---\n");
                bubble_sort(temp, size);
                printf("\nSorted Array: ");
                display_array(temp, size);
                display_bars(temp, size);
                printf("Total Steps: %d\n", steps);
                break;

            case 2:
                /* Selection Sort */
                copy_array(arr, temp, size);
                steps = 0;
                printf("\n--- SELECTION SORT ---\n");
                selection_sort(temp, size);
                printf("\nSorted Array: ");
                display_array(temp, size);
                display_bars(temp, size);
                printf("Total Steps: %d\n", steps);
                break;

            case 3:
                /* Insertion Sort */
                copy_array(arr, temp, size);
                steps = 0;
                printf("\n--- INSERTION SORT ---\n");
                insertion_sort(temp, size);
                printf("\nSorted Array: ");
                display_array(temp, size);
                display_bars(temp, size);
                printf("Total Steps: %d\n", steps);
                break;

            case 4:
                /* Merge Sort */
                copy_array(arr, temp, size);
                steps = 0;
                printf("\n--- MERGE SORT ---\n");
                merge_sort(temp, 0, size - 1);
                printf("\nSorted Array: ");
                display_array(temp, size);
                display_bars(temp, size);
                printf("Total Steps: %d\n", steps);
                break;

            case 5:
                /* Quick Sort */
                copy_array(arr, temp, size);
                steps = 0;
                printf("\n--- QUICK SORT ---\n");
                quick_sort(temp, 0, size - 1);
                printf("\nSorted Array: ");
                display_array(temp, size);
                display_bars(temp, size);
                printf("Total Steps: %d\n", steps);
                break;

            case 6:
                /* Generate new random array */
                printf("Enter array size (max %d): ", MAX_SIZE);
                scanf("%d", &size);
                if (size > MAX_SIZE) size = MAX_SIZE;
                generate_random(arr, size);
                printf("\nNew random array generated!\n");
                break;

            case 7:
                /* Manual input */
                get_manual_input(arr, &size);
                break;

            case 8:
                /* Compare all algorithms */
                printf("\n--- COMPARING ALL ALGORITHMS ---\n");
                printf("%-20s %-10s\n", "Algorithm", "Steps");
                printf("------------------------------\n");

                copy_array(arr, temp, size);
                steps = 0;
                bubble_sort(temp, size);
                printf("%-20s %-10d\n", "Bubble Sort", steps);

                copy_array(arr, temp, size);
                steps = 0;
                selection_sort(temp, size);
                printf("%-20s %-10d\n", "Selection Sort", steps);

                copy_array(arr, temp, size);
                steps = 0;
                insertion_sort(temp, size);
                printf("%-20s %-10d\n", "Insertion Sort", steps);

                copy_array(arr, temp, size);
                steps = 0;
                merge_sort(temp, 0, size - 1);
                printf("%-20s %-10d\n", "Merge Sort", steps);

                copy_array(arr, temp, size);
                steps = 0;
                quick_sort(temp, 0, size - 1);
                printf("%-20s %-10d\n", "Quick Sort", steps);
                break;

            case 9:
                printf("\nGoodbye Aditya! Keep coding!\n\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

/* ---- DISPLAY MENU ---- */
void display_menu() {
    printf("\n========== MENU ==========\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Generate Random Array\n");
    printf("7. Enter Array Manually\n");
    printf("8. Compare All Algorithms\n");
    printf("9. Exit\n");
    printf("===========================\n");
}

/* ---- DISPLAY ARRAY AS NUMBERS ---- */
void display_array(int arr[], int size) {
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

/* ---- DISPLAY ARRAY AS BAR CHART ---- */
void display_bars(int arr[], int size) {
    int i, j;
    printf("\nVisualization:\n");

    /* Find maximum value for scaling */
    int max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }

    /* Print bars from top to bottom */
    for (i = max; i >= 1; i--) {
        printf("%3d |", i);
        for (j = 0; j < size; j++) {
            if (arr[j] >= i) {
                printf(" ##");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    /* Print x-axis */
    printf("    +");
    for (i = 0; i < size; i++) {
        printf("---");
    }
    printf("\n     ");
    for (i = 0; i < size; i++) {
        printf("%3d", i + 1);
    }
    printf("\n");
}

/* ---- BUBBLE SORT ---- */
void bubble_sort(int arr[], int size) {
    int i, j, temp;
    int swapped;

    printf("\nStep by step:\n");

    for (i = 0; i < size - 1; i++) {
        swapped = 0;

        for (j = 0; j < size - i - 1; j++) {
            steps++;

            /* Compare adjacent elements */
            if (arr[j] > arr[j + 1]) {
                /* Swap elements */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        /* Print array after each pass */
        printf("Pass %d: ", i + 1);
        display_array(arr, size);

        /* If no swap in this pass, array is sorted */
        if (!swapped) break;
    }
}

/* ---- SELECTION SORT ---- */
void selection_sort(int arr[], int size) {
    int i, j, min_idx, temp;

    printf("\nStep by step:\n");

    for (i = 0; i < size - 1; i++) {
        /* Find minimum element in remaining array */
        min_idx = i;

        for (j = i + 1; j < size; j++) {
            steps++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        /* Swap minimum element with first element */
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }

        /* Print array after each step */
        printf("Step %d: ", i + 1);
        display_array(arr, size);
    }
}

/* ---- INSERTION SORT ---- */
void insertion_sort(int arr[], int size) {
    int i, key, j;

    printf("\nStep by step:\n");

    for (i = 1; i < size; i++) {
        /* Pick element to insert */
        key = arr[i];
        j = i - 1;

        /* Move elements greater than key one position ahead */
        while (j >= 0 && arr[j] > key) {
            steps++;
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
        steps++;

        /* Print array after each insertion */
        printf("Step %d: ", i);
        display_array(arr, size);
    }
}

/* ---- MERGE SORT ---- */
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        /* Find middle point */
        int mid = (left + right) / 2;

        /* Sort first and second halves */
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        /* Merge sorted halves */
        merge(arr, left, mid, right);
    }
}

/* ---- MERGE HELPER FUNCTION ---- */
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* Create temp arrays */
    int L[MAX_SIZE], R[MAX_SIZE];

    /* Copy data to temp arrays */
    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    /* Merge temp arrays back */
    i = 0; j = 0; k = left;

    while (i < n1 && j < n2) {
        steps++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy remaining elements */
    while (i < n1) { arr[k++] = L[i++]; steps++; }
    while (j < n2) { arr[k++] = R[j++]; steps++; }
}

/* ---- QUICK SORT ---- */
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        /* Get partition index */
        int pi = partition(arr, low, high);

        /* Sort elements before and after partition */
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/* ---- PARTITION FOR QUICK SORT ---- */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {
        steps++;
        if (arr[j] < pivot) {
            i++;
            /* Swap arr[i] and arr[j] */
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    /* Swap arr[i+1] and pivot */
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

/* ---- GENERATE RANDOM ARRAY ---- */
void generate_random(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        /* Generate random numbers between 1 and 20 */
        arr[i] = (rand() % 20) + 1;
    }
}

/* ---- GET MANUAL INPUT ---- */
void get_manual_input(int arr[], int *size) {
    int i;
    printf("\nEnter array size (max %d): ", MAX_SIZE);
    scanf("%d", size);

    if (*size > MAX_SIZE) *size = MAX_SIZE;

    printf("Enter %d elements:\n", *size);
    for (i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray entered successfully!\n");
}

/* ---- COPY ARRAY ---- */
void copy_array(int src[], int dest[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}
