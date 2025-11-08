/*Selection sort : select minimums & swap (ascending order)
                    swaping goes until (n-2)

for(int i = 0; i < n-2; i++){
    mini = i;
    for(int j= i; j< n-1; j++){
        if(arr[j] < arr[mini]) mini = j
    }
    swap(arr[mini], arr[i])
}
    
Bubble sort = push the maximum to the last by adjust swaps
Insertion sort: Takes an element & place it in its correct order.*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0; i<= n-2; i++){
        int mini = i;
        for(int j = i; j < arr[mini]; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
void bubble_sort(int arr[], int n){
    for(int i = n-1; i>=0; i--){
        int didSwap == 0; //if the array is sorted in ascending order.
        for(int j = 0; j<= i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
        }
    }
}
void insertion_sort(int arr, int n){
    for(int i = 0; i <= n; i++){
        int j = 1;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    selection_sort(arr, n);//change here selection sort, bubble sort or inserttion sort.
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;

}
