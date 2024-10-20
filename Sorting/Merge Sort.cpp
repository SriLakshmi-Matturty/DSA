#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int right, int mid){
    int n1= mid-left+1;
    int n2= right-mid;
    vector <int> l(n1), r(n2);
    for(int i=0; i<n1; i++){
        l[i]= a[left+i];
    }
    for(int i=0; i<n2; i++){
        r[i]= a[mid+1+i];
    }
    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            a[k]=l[i];
            k++;
            i++;
        }
        else{
            a[k]=r[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        a[k]=l[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]= r[j];
        k++;
        j++;
    }
}

void merge_sort(int a[], int left, int right){
    if(left>=right){
        return;
    }
    else{
        int mid= left+(right-left)/2;
        merge_sort(a, left, mid);
        merge_sort(a,mid+1, right);
        merge(a, left, right, mid);
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
    merge_sort(a,0,n-1);
    cout<<"After sorting: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
        
    }
    cout<<"\n";
    return 0;
}
