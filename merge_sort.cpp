#include <iostream>
#include <random>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right);
void mergeSort(std::vector<int>& arr, int left, int right);

int main(){

    int n = 500;

    std::vector<int> arr(n);
    srand(time(0));

    for(int i = 0; i < n; i++){
        int r = (std::rand() % 2000)+1;
        arr[i] = r;
    }

    for(const int i : arr){
        std::cout<<i<<" ";
    }
    std::cout<<"\n"<<std::endl;

    mergeSort(arr, 0, n-1);

        for(const int i : arr){
        std::cout<<i<<" ";
    }
    std::cout<<"\n"<<std::endl;

    //alternatively for(const int i = 0; i < arr.size(); i++){std::cout<<arr[i]<<" "}

    return 0;
}

/*
 *
 * @brief Handles the iterative comparison component of the merge-sort algorithm.
 *
 * @param arr An array to be sorted.
 * @param left The leftmost index position.
 * @param right The rightmost index position.
 * @return Doesn't return anything. Directly modifies the original array.
 */
void merge(std::vector<int>& arr, int left, int mid, int right){
    //# of elements in each sublist
    int n1 = mid - left + 1; //accounts for zero index
    int n2 = right - mid; //right − (mid + 1) + 1

    std::vector<int> L(n1), R(n2);

    //array slicing
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid+1 + j];
    }

    //regular sorting logic
    int i = 0, j = 0;
    int k = left; //i.e. start of the list
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i ++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k ++;
    }

    //gather the remainings
    while(i < n1){
        arr[k] = L[i];
        k++;
        i++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right){

    //terminate once reach single elment arrays
    if(left >= right){
        return;
    }

    int mid = left + (right-left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}



