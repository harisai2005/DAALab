#include<iostream>
using namespace std;

int selectionSort(int arr[], int n){
    int count = 1;
    for(int i = 0; i < n; i++){
        count++;
        count++;
        for(int j = i+1; j < n; j++){
            count++;
            if (arr[i] > arr[j]){
                count++;
                count++;
                int temp = arr[i];
                count++;
                arr[i] = arr[j];
                count++;
                arr[j] = temp;
            }
        }
    }
    count++;
    return count;
}

int main(){
    int n = 10;
    int a[n] = {2, 3, 5, 9, 11, 14, 18, 19, 21, 25};
    int b[n] = {8,6,9,10,2,3,4,7,1,5};
    int counta = selectionSort(a, n);
    int countb = selectionSort(b, n);
    cout<<"ascending order count :"<<counta<<endl;
    cout<<"descending order count :"<<countb;
}