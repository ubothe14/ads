#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int size){
    for(int i=size/2-1; i>=0; --i){
        int larger = i;
        if(2*i+1<size && arr[2*i+1]>arr[larger]){
            larger = 2*i + 1;
        }
        if(2*i+2<size && arr[2*i+2]>arr[larger]){
            larger = 2*i+2;
        }
        if(larger!=i) swap(arr[larger], arr[i]);
    }
    swap(arr[0], arr[size-1]);
    return;
}
void sort(int arr[], int size){
    //number of iterations
    for(int i=0; i<size; ++i){
        heapify(arr, size-i);
    }
}

int main(){
    int arr[] = {5,4,3,2,1,0,-1,-2,-3};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, size);
    //sort(arr, arr+size);
    for(int i=0; i<size; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
