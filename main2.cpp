#include <stdio.h>
#include <stdlib.h>

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void combSort(int arr[], int n) {
    float shrinkFactor = 1.3;
    int gap = n;
    int swapped = 1;

    while (gap > 1 || swapped) {
        gap = gap / shrinkFactor;
        if (gap < 1) {
            gap = 1;
        }

        swapped = 0;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

void cocktailSort(int arr[], int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = 0;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        start++;
    }
}

int main() {
    int rows, cols;

    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d", &rows);

    printf("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", &cols);

    int matrix[rows][100];  // Matriz bidimensional para almacenar los elementos

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int choice;
    while (1) {
        printf("\nOpciones de Ordenamiento:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Heap Sort\n");
        printf("8. Comb Sort\n");
        printf("9. Cocktail Sort\n");
        printf("10. Salir\n");
        printf("Selecciona una opción: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < rows; i++) {
                    bubbleSort(matrix[i], cols);
                }
                break;
            case 2:
                for (int i = 0; i < rows; i++) {
                    selectionSort(matrix[i], cols);
                }
                break;
            case 3:
                for (int i = 0; i < rows; i++) {
                    insertionSort(matrix[i], cols);
                }
                break;
            case 4:
                for (int i = 0; i < rows; i++) {
                    shellSort(matrix[i], cols);
                }
                break;
            case 5:
                for (int i = 0; i < rows; i++) {
                    mergeSort(matrix[i], 0, cols - 1);
                }
                break;
            case 6:
                for (int i = 0; i < rows; i++) {
                    quickSort(matrix[i], 0, cols - 1);
                }
                break;
            case 7:
                for (int i = 0; i < rows; i++) {
                    heapSort(matrix[i], cols);
                }
                break;
            case 8:
                for (int i = 0; i < rows; i++) {
                    combSort(matrix[i], cols);
                }
                break;
            case 9:
                for (int i = 0; i < rows; i++) {
                    cocktailSort(matrix[i], cols);
                }
                break;
            case 10:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opcion invalida. Por favor, selecciona una opcion valida.\n");
        }

        printf("Matriz Ordenada:\n");
        printMatrix(matrix, rows, cols);
    }

    return 0;
}
