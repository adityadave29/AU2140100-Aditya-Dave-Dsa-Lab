#include<bits/stdc++.h>
using namespace std;

void replacearray(int n,int arr[],int position,int element){
    for(int i=0;i<n;i++){
        if(i+1==position){
            arr[position-1]=element;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int main(){
    int n=6;
    int arr[] = {1,2,3,4,5,6};
    replacearray(n,arr,2,12090);
}