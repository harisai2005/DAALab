#include<iostream>
using namespace std;
int insertsort(int arr[], int n){
    int count = 1;
    for(int i=1;i<n;i++){
        count++;
        count++;
        int temp = arr[i];
        count++;
        int j = i-1;
        count++;
        while(temp < arr[j] && j>=0){
            count++;
            count++;
            arr[j+1] = arr[j];
            count++;
            j--;

        }
        count++;
        arr[j+1] = temp;
    }
    count++;
    return count;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int ca = insertsort(a, sizeof(a)/sizeof(a[0]));
    int cb = insertsort(b, sizeof(b)/sizeof(b[0]));
    cout<<"worst case: "<<cb<<endl;
    cout<<"best case: "<<ca<<endl;
}