#include <iostream>

using namespace std;

void display_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heap_sort(int arr[], int n){
    //nested loop, sort from the left to right
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main(){
    int size;
    cout<<"Please enter the size of array:"<<endl;
    cin>>size;
    int array[size];
    cout<<"Please enter the elements of array:"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"\nThe input array as:"<<endl;
    display_array(array, size);
    cout<<"\nResult:"<<endl;
    heap_sort(array, size);
    display_array(array, size);
    return 0;
}