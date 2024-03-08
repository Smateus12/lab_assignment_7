#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    int numberofswaps;
}element;
void swap(int *xp, int *yp);

element* numswapsbubblesort(int arr[], int n);
element* numswapsselectionSort(int arr[], int n);

int main(){
    int array1[]= {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[]={90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;
    element *array1bubblesort = numswapsbubblesort(array1, n);
    element *array1selectionsort = numswapsselectionSort(array1, n);
    element *array2bubblesort = numswapsbubblesort(array2, n);
    element *array2selectionsort = numswapsselectionSort(array2, n);
    printf("array1 bubble sort:\n");
    int count = 0;
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", array1bubblesort[i].data, array1bubblesort[i].numberofswaps);
        count += array1bubblesort[i].numberofswaps;
    }
    printf("%d \n", count/2);

    printf("array1 selection sort:\n");
    count = 0;
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", array1selectionsort[i].data, array1selectionsort[i].numberofswaps);
        count += array1selectionsort[i].numberofswaps;
    }
    printf("%d \n", count/2);

    printf("array2 bubble sort:\n");
    count = 0;
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", array2bubblesort[i].data, array2bubblesort[i].numberofswaps);
        count += array2bubblesort[i].numberofswaps;
    }
    printf("%d \n", count/2);

    printf("array2 selection sort:\n");
    count = 0;
    for(int i = 0; i < n; i++){
        printf("%d: %d\n", array2selectionsort[i].data, array2selectionsort[i].numberofswaps);
        count += array2selectionsort[i].numberofswaps;
    }
    printf("%d \n", count/2);

    free(array1bubblesort);
    free(array1selectionsort);
    free(array2bubblesort);
    free(array2selectionsort);
    
    return 0;
}
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


element* numswapsbubblesort(int arr[], int n){
    element* swaps = malloc(sizeof(element) * n);
    for(int i = 0; i < n; i++){
        swaps[i].data = arr[i];
        swaps[i].numberofswaps = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                // Increment number of swaps for both elements involved in the swap
                swaps[j].numberofswaps++;
                swaps[j + 1].numberofswaps++;
            }
        }
    }

    return swaps;
}

element* numswapsselectionSort(int arr[], int n){
    element* swaps = malloc(sizeof(element) * n);
    for(int i = 0; i < n; i++){
        swaps[i].data = arr[i];
        swaps[i].numberofswaps = 0;
    }
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        swaps[i].numberofswaps ++;
    }
return swaps;
}
