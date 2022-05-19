#include <iostream>

using namespace std;

void display_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
  
void merge (int arr[], int l, int m, int r){
    int leftLength = m - l + 1;
    int rightLength = r - m;
    //create left array and right array
    int leftArr[leftLength], rightArr[rightLength];
    
    //insert the element into the created array
    for (int i = 0; i < leftLength; i++){
        leftArr[i] = arr[l + i];
    }
    for (int j = 0; j < rightLength; j++){
        rightArr[j] = arr[m + 1 + j];
    }
 
    int i = 0, j = 0, k = l;
    
    //sort them by replacing the element position of original array from new created array
    while (i < leftLength && j < rightLength){
        //compare left side array and right side array to find the minimum element
        //then insert them into the original array, in order to perform next merge
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
 
    //for the case when right array is empty, but not left array
    // or when left array is empty, but not right array
    while (i < leftLength) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightLength) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
  

void merge_sort(int arr[], int l, int r){
    //recursion until all the partition is finished
    if (r<=l){
        return;
    }
    int m = (l+r-1)/2;
    //left side partition
    merge_sort(arr, l, m);
    //right side partition
    merge_sort(arr, m+1, r);
    //sort in here
    merge(arr, l, m, r);
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
    merge_sort(array, 0, size - 1);
    cout<<"\nResult:"<<endl;
    display_array(array, size); 
    return 0;  
}  