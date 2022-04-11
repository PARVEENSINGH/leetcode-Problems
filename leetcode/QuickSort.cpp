#include<bits/stdc++.h>
using namespace std;


//https://workat.tech/problem-solving/practice/implement-quicksort

void swap(int *a,int *b){
    int p = *a;
    *a = *b;
    *b = p;
}

int partition(vector<int> &arr, int l, int r){
    int pivot = arr[r];
    int idx = l-1;
    for(int i = l;i<r;i++){
        if(arr[i]<pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    swap(&arr[idx+1],&arr[r]);
    return idx+1;
}

void quickSortImpl(vector<int> &arr, int l, int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quickSortImpl(arr,l,pi-1);
        quickSortImpl(arr,pi+1,r);
    }
}

void quickSort(vector<int> &arr) {
    // add your logic here
    int l = 0,r = arr.size();
    quickSortImpl(arr,l,r-1);
	return;
}