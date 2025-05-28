// divide & conquer
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int n;
int sorted[SIZE];

void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left; j = mid+1; k = left;

    while(i<=mid && j<=right){
        if(list[i]<=list[j]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }

    }

    if(i>mid){
        for(l=j; l<=right; l++){
            sorted[k++] = list[l];
        }
    }

    else{
        for(l=i; l<=mid; l++){
            sorted[k++] = list[l];
        }
    }

    for(l=left; l<=right; l++){
        list[l] = sorted[l];
    }
}

void merge_sorting(int list[], int left, int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        merge_sorting(list,left,mid);
        merge_sorting(list, mid+1, right);
        merge(list, left, mid, right);
    }
}