#include <stdio.h>
#include <stdlib.h>

struct array {
    int nums[9];
    int arraybubble[9];
    int arrayselec[9];
};

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void prarr(int arr[], int size, int count[]){
int tot = 0;
for (int i =0; i<9; i++){
    tot = tot + count[i];
    printf("%d: %d\n", arr[i], count[i]);
}
tot = tot/2;
printf("%d\n\n", tot);
}

void bubblesort(int temparr[], int num, int bubblecount[]){
    for(int j=0; j<num-1;j++){
    for(int i =0; i<num-j-1;i++){
        if (temparr[i] > temparr[i+1]){
            swap(&temparr[i], &temparr[i+1]);
            swap(&bubblecount[i], &bubblecount[i+1]);
            bubblecount[i]++;
            bubblecount[i+1]++;
        }
    }
    }
    prarr(temparr, num, bubblecount);
}

void selectionsort(int arr[], int num, int seleccount[]){
    int min, i, j;
    for (i =0; i<num-1;i++){
        min = i;
    for (j = i+1; j<num;j++)
        if(arr[j]<arr[min])
            min = j;
        swap(&arr[i], &arr[min]);
        swap(&seleccount[i], &seleccount[min]);
        seleccount[i]++;
        seleccount[min]++;
    }
    prarr(arr, num, seleccount);
}

void main(){
    struct array a1b = {{97, 16, 45, 63, 13, 22, 7, 58, 72}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    struct array a2b = {{90, 80, 70, 60, 50, 40, 30, 20, 10}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    struct array a1s = {{97, 16, 45, 63, 13, 22, 7, 58, 72}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    struct array a2s = {{90, 80, 70, 60, 50, 40, 30, 20, 10}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int num =9;
    printf("array1 bubble sort:\n");
    bubblesort(a1b.nums, num, a1b.arraybubble);
    printf("array2 bubble sort: \n");
    bubblesort(a2b.nums, num, a2b.arraybubble);
    printf("array1 selection sort:\n");
    selectionsort(a1s.nums, num, a1s.arrayselec);
    printf("array2 selection sort: \n");
    selectionsort(a2s.nums, num, a2s.arrayselec);
}

