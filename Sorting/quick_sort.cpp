#include <iostream>

using namespace std;
  
 
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
  
int partition (int arr[], int low, int high){
    int pivot = arr[high];  //choose the most right element as pivot
    int i = (low - 1);      //create pi
  
    for (int j = low; j <= high - 1; j++){
        //put all the smaller element on the left side of the pivot
        if (arr[j] < pivot){
            i++;  
            swap(&arr[i], &arr[j]);  
        }
    }
    //now, all the left side will be the smaller, right side will be the bigger
    //perform the last swap to let the pivot go back into the position of pi (because it is still on the most right)
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  //return pi position
}
  

void merge_sort(int arr[], int low, int high){
    //recursion until all the partition is finished, the array will be sorted at that time
    if (low < high)  
    {
        int pi = partition(arr, low, high);
        //left partition
        merge_sort(arr, low, pi - 1);
        //right partition
        merge_sort(arr, pi + 1, high);  
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
    merge_sort(array, 0, size-1);  
    cout<<"\nResult:"<<endl;
    display_array(array, size); 
    return 0;  
}  