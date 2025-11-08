/*Why we use merge sort ?? (Divide and Merge in sorted way)
because we have seen that the bubble sort, insertion sort & selection sort have the complexity of O(n^2) as compared to this merge sort is more optimized algorithm. 

Time complexity :  n *log (base 2) n [16 *log base 2 *16 = 4 ]
(remember n log n ) 
space complexity : O(n)

merge sort(arr, low, high)
{
    if(low >= high) return;
    mid = (low, high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
} // for divide

merge(arr, low, mid, length){
    temp =[];
    left = low; right = mid+1;
    while(left <= mid && rigt<= high){
        if(arr[left] <= arr[right])
            temp.add(arr[left]);
            left++;

        else
            temp.add(arr[right]);
            right++;
    }
}*/
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    //[low...mid]
    //[mid+1...high]
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
      if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
      }  
      else{
        temp.push_back(arr[right]);
        right++;
      }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<= high; i++){
        arr[i] = temp[i - low];
    }
}
void mS(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low + high) /2;
    mS(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergeSort(verctor<int> &arr, int n){
    mS(arr, 0, n-1);
}
