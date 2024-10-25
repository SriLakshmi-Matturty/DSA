#include <bits/stdc++.h>
using namespace std;

int get_max(vector <int> &a){
    int n= a.size();
    int maxe=a[0];
    for(int i=0; i<n; i++){
        maxe= max(maxe, a[i]);
    }
    return maxe;
}

vector <int> counting_sort(vector <int> &a, int i){
    int n=a.size();
    vector <int> c(10,0);
    for(int j=0; j<n; j++){
        c[(a[j]/i) %10]++;
    }
    for(int j=1; j<10; j++){
        c[j]+= c[j-1];
    }
    vector <int> b(n);
    for(int j=n-1; j>=0; j--){
        b[c[(a[j]/i)%10]-1]= a[j];
        c[(a[j]/i)%10]--;
    }
    return b;
}

vector <int> radix_sort(vector <int> &a){
    int n= a.size();
    int m= get_max(a);
    vector <int> b=a;
    for(int i=1; m/i>0; i*=10){
        b=counting_sort(b,i);
    }
    return b;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector <int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector <int> b;
    b= radix_sort(a);
    cout<<"After sorting: ";
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
        
    }
    cout<<"\n";
    return 0;
}
