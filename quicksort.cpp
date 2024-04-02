#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr,int low,int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(vector<int>& arr,int low,int high){
if(low<high){
    int pi=partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);   
}
}
int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    quicksort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}