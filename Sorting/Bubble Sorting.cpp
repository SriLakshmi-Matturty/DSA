#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n){
    bool swapped;
    for(int i=0; i<n; i++){
        swapped= false;
        for(int j=0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
                swapped= true;
            }
        }
        if(!swapped){
            break;
        }
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
    bubble_sort(a,n);
    cout<<"After sorting: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
        
    }
    cout<<"\n";
    return 0;
}
