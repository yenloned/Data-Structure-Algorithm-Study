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

void insertion_sort(int arr[], int n){
    //nested loop, sort from the right to left
    for(int i=1; i<n;i++){
        int j = i;
        while(j >0 && arr[j-1] > arr[j]){
            swap(&arr[j], &arr[j-1]);
            j--;
        };
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
    insertion_sort(array, size);
    display_array(array, size);
    return 0;
}