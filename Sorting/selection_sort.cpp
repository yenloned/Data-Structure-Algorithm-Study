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

void selection_sort(int arr[], int n){
    //nested loop, putting the minimum element in the most left position from each loop
    for(int i=0; i<n;i++){
        int curMin = i;
        for(int j=i+1;j<n;j++){
            int cur = j;
            if (arr[cur] < arr[curMin]){
                curMin = j;
            }
        }
        swap(&arr[i], &arr[curMin]);
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
    selection_sort(array, size);
    display_array(array, size);
    return 0;
}