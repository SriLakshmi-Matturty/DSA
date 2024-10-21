#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    int pivot= a[low], down= low, up= high;
    while(down<up){
        while(a[down]<=pivot && down <up){
            down++;
        }
        while(a[up]>pivot){
            up--;
        }
        if(down<up){
            swap(a[down], a[up]);
        }
    }
    swap(a[up], a[low]);
    return up;
}
void quick_sort(int a[], int low, int high){
    if(low<high){
        int q= partition(a, low, high);
        quick_sort(a, low, q-1);
        quick_sort(a, q+1, high);
    }
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    cout<<"After sorting: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
        
    }
    cout<<"\n";
    return 0;
}
