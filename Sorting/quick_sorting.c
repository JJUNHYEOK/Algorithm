#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int list[SIZE];
int n;

int partition(int list[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right+1;
    pivot = list[left];

    do{
        do
        {
            low++;
        } while (list[low]<pivot);
        do{
            high--;
        } while(list[high]>pivot);

        if(low<high){
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    } while(low<high);

    temp = list[left];
    list[left] = list[high];
    list[high] = temp;
    
    return high;

}

void quick_sorting(int list[], int left, int right){
    if(left<right){
        int q = partition(list, left, right);
        quick_sorting(list, left, q-1);
        quick_sorting(list, q+1, right);
    }
}


int main(){
    int i;
    n = SIZE;
    srand(time(NULL));

    for(i=0; i<n; i++){
        list[i] = rand()%100;
    }

    quick_sorting(list, 0, n-1);
    for(i=0; i<n; i++){
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}
