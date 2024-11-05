#include<bits/stdc++.h>
using namespace std;


int partition(int low,int high, vector<int>&arr){
    int pivot = arr[high];

    int i=low-1;

    for(int x=low;x<high;x++){
        if(arr[x]<pivot){
            i++;
            swap(arr[x],arr[i]);
        }
    }

    swap(arr[i+1],arr[high]);

    return i+1;
}

int partition_random(int low,int high,vector<int>&arr){

    int pivot= low +  rand()%(high-low+1);

    swap(arr[pivot],arr[high]);

    return  partition(low,high,arr);
}

void  deterministic_quicksort(int low,int high,vector<int>&arr){
    if(low<high){
        int pivot = partition(low,high,arr);

        deterministic_quicksort(low,pivot-1,arr);

        deterministic_quicksort(pivot+1,high,arr);
    }

    return;
}

void  randomized_quicksort(int low,int high,vector<int>&arr){
    if(low<high){
        int pivot = partition_random(low,high,arr);

        randomized_quicksort(low,pivot-1,arr);

        randomized_quicksort(pivot+1,high,arr);
    }

    return;
}


int main(){

    int k=1;
    while(k){
        vector<int>v={5,1,8,2,3,6,4,7};
        
        cout<<"\nEnter method to sort:\n1. Deterministic Quicksort\n2. Randomized Quicksort\n==> ";
        cin>>k;
        if(k==1){
            deterministic_quicksort(0,v.size()-1,v);
            cout<<"Deterministic QuickSort: ";
            for(int &x:v){
                cout<<x<<" ";
            }
        }
        else if(k==2){
            randomized_quicksort(0,v.size()-1,v);
            cout<<"Randomized QuickSort: ";
            for(int &x:v){
                cout<<x<<" ";
            }
        }
    }
    


    return 0;
}