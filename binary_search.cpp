#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &arr,int target){ //read-only reference
    int tail = 0;
    int head = arr.size()-1;

    while(tail<=head){
        int pointer = (tail+head)/2; //implicit floor division
        if(arr[pointer]==target){
            return pointer;
        }
        else if (arr[pointer]>target){
            head = pointer-1;
        }
        else{
            tail = pointer+1;
        }
    }

    return -1; //target was not found
}

void test(int result){
    if(result != -1){
        std::cout<<"Successful Run\n";
    }
    else{
        std::cout<<"Something went wrong. Debuggin team will deal with it later\n";
    }
}

int main(){

    std::vector<int> arr = {2,3,4,5,22,23,25,26,27,28,29,44,55,110,234,3353,5355};
    int target = 110;

    int result = binary_search(arr, target);
    test(result);

    return 0;
}

