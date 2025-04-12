#include <iostream>
#include <vector>

// Function to perform insertion sort on an array
void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i){
        for (int j = i; j > 0; --j){
            if (arr[j-1] > arr[j]){
                std::swap(arr[j], arr[j-1]);
            }else break;
        }
    }
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    
    std::cout << "Original array: ";
    printArray(arr);
    
    insertionSort(arr);
    
    std::cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}