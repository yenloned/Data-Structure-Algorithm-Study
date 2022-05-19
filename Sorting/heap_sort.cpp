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

void heapify(int arr[], int size, int cur){
    int largest = cur; 
    int l = 2 * cur + 1;    //left child
    int r = 2 * cur + 2;    //right child
 
    //check if the left child is larger
    if (l < size && arr[l] > arr[largest]){
        largest = l;
    }
    //check if the right child is larger
    if (r < size && arr[r] > arr[largest]){
        largest = r;
    }
    //if one of them is larger, perform swap and run recursion to make sure the max heap is generated
    if (largest != cur) {
        swap(&arr[cur], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap_sort(int arr[], int n){
    //create max heap
    //from the last parent node, passing the node value as cur into heapify
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    //now, the max heap is created, and heapify will be performed to create a sorted list
    //to pop out the maximum element from max heap, swap it with the last element, then heapify again
    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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