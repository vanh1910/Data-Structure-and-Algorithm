// Heap and Priority Queue Implementation Template
// Instructions: Implement the missing function definitions for each class.
// Each function has comments indicating what it should do.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

//-------------------- BINARY HEAP (MAX HEAP) --------------------
class MaxHeap {
private:
    int* array;     
    int capacity;   
    int size;       

    // Helper function to get parent index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Helper function to get left child index
    int leftChild(int i) {
        return (2 * i + 1);
    }

    // Helper function to get right child index
    int rightChild(int i) {
        return (2 * i + 2);
    }

    // Helper function to swap two elements
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Move an element up to its correct position (for insertion)
    void swim(int index) {
        while (index > 0 && array[index / 2] < array[index]){
            swap(array[index / 2], array[index]);
            index /= 2;
        }
        // TODO: Implement swim function
        // Compare with parent and swap if needed, continue until heap property is restored
    }

    // Move an element down to its correct position (for deletion)
    void sink(int index, int heapSize) {
        // TODO: Implement sink function
        // Compare with children and swap with larger child if needed
        while(index < size){

            int largest = index;
            int left = leftChild(index);
            int right = rightChild(index);

            if (left < size && array[left] > array[largest]){
                largest = left;
            }
            if (right < size && array[right] > array[largest]){
                largest = right;
            }
            if (largest == index){
                break;
            }
            swap(array[index], array[largest]);
            index = largest;
        }
        // Continue until heap property is restored
    }

public:
    // Constructor: Initialize array with given capacity
    MaxHeap(int maxCapacity = 100) {
        array = new int[maxCapacity];
        capacity = maxCapacity;
        size = 0;
        // TODO: Implement constructor
    }

    // Destructor: Free dynamically allocated memory
    ~MaxHeap() {
        delete[] array;
        size = 0;
        // TODO: Implement destructor
    }

    // Returns true if heap has no elements, false otherwise
    bool isEmpty() {
        // TODO: Implement isEmpty function
        return size == 0; // Placeholder, replace with correct implementation
    }

    // Returns true if heap is full, false otherwise
    bool isFull() {
        // TODO: Implement isFull function
        return (capacity - size); // Placeholder, replace with correct implementation
    }

    // Add value to the heap
    // Should throw overflow_error if heap is full
    void insert(int value) {
        array[size] = value;
        swim(size++);
        // TODO: Implement insert function
    }

    // Remove and return the maximum element (root)
    // Should throw underflow_error if heap is empty
    int removeMax() {
        if (isEmpty()){
            throw std::underflow_error("Heap underflow");
            return 0;
        }
        int max = array[0];
        array[0] = array[--size];
        array[size+1] = 0;
        sink(0, size);
        // TODO: Implement removeMax function
        return max; // Placeholder, replace with correct implementation
    }

    // Return the maximum element without removing it
    // Should throw underflow_error if heap is empty
    int peekMax() {
        // TODO: Implement peekMax function
        return array[0]; // Placeholder, replace with correct implementation
    }

    // Return the number of elements in the heap
    int getSize() {
        // TODO: Implement getSize function
        return size; // Placeholder, replace with correct implementation
    }

    // Build a heap from an array
    void buildHeap(int arr[], int n) {
        for (int i = 0; i < n && i < capacity; i++) {
            array[i] = arr[i];
        }
        size = n;
        for (int i = n/2 - 1; i >= 0; --i){
            
            sink(i,n);
            //printHeap();
        }
        // TODO: Implement buildHeap function
        // Start from the last non-leaf node and sink down each node
    }

    // Print the heap (for debugging)
    void printHeap() {
        int index = 0;
        for (int i = 0; i <= log2(size); ++i){
            for (int j = 0; j < pow(2,i); ++j){
                std::cout << array[index] << " ";
                ++index;
                if (index == size){
                    std::cout << "\n";
                    return;
                }
            }
            std::cout << "\n";
        }
        // TODO: Implement printHeap function
        // Print all elements in the heap array
    }

    // Perform heapsort on the given array
    static void heapSort(int arr[], int n) {
        // TODO: Implement heapSort function
        // 1. Build a max heap from the array
        MaxHeap tempHeap(n);
        tempHeap.buildHeap(arr,n);

        while(!tempHeap.isEmpty()){
            //tempHeap.printHeap();
            arr[--n] = tempHeap.removeMax();
        }

        // 2. Repeatedly extract the maximum and place at the end
    }
};

//-------------------- PRIORITY QUEUE USING MAX HEAP --------------------
class PriorityQueue {
private:
    MaxHeap heap;  // Use our MaxHeap implementation

public:
    // Constructor
    PriorityQueue(int capacity = 100) {
        MaxHeap heap(capacity);
        // TODO: Implement constructor
    }

    // Returns true if queue has no elements, false otherwise
    bool isEmpty() {
        // TODO: Implement isEmpty function
        return heap.isEmpty(); // Placeholder, replace with correct implementation
    }

    // Returns true if queue is full, false otherwise
    bool isFull() {
        // TODO: Implement isFull function
        return heap.isFull(); // Placeholder, replace with correct implementation
    }

    // Add value to the priority queue with specified priority
    // Higher values indicate higher priority
    void enqueue(int value) {
        heap.insert(value);
        // TODO: Implement enqueue function
    }

    // Remove and return the highest priority element
    // Should throw underflow_error if queue is empty
    int dequeue() {
        // TODO: Implement dequeue function
        return heap.removeMax(); // Placeholder, replace with correct implementation
    }

    // Return the highest priority element without removing it
    // Should throw underflow_error if queue is empty
    int peek() {
        // TODO: Implement peek function
        return heap.peekMax(); // Placeholder, replace with correct implementation
    }

    // Return the number of elements in the priority queue
    int size() {
        // TODO: Implement size function
        return heap.getSize(); // Placeholder, replace with correct implementation
    }
};

//-------------------- TESTING FUNCTION --------------------
// This function will test your implementation
// Do not modify this function!
void testHeapAndPriorityQueue() {
    std::cout << "Testing Max Heap:\n";
    MaxHeap maxHeap(10);

    // Test insert and removeMax
    int values[] = {3, 10, 12, 8, 2, 14};
    for (int i = 0; i < 6; i++) {
        maxHeap.insert(values[i]);
        std::cout << "Inserted: " << values[i] << std::endl;
    }

    std::cout << "Heap size: " << maxHeap.getSize() << std::endl;
    std::cout << "Max element: " << maxHeap.peekMax() << std::endl;
    
    std::cout << "Heap contents: \n";
    maxHeap.printHeap();
    
    while (!maxHeap.isEmpty()) {
        
        std::cout << "Removed max: " << maxHeap.removeMax() << std::endl;
        // std::cout << "debug\n";
        // maxHeap.printHeap();
    }
    
    try {
        // This should throw an underflow exception
        maxHeap.removeMax();
    } catch (const std::underflow_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    // Test buildHeap
    int arr[] = {4, 10, 3, 5, 1};
    maxHeap.buildHeap(arr, 5);
    std::cout << "\nHeap after buildHeap:\n";
    maxHeap.printHeap();

    // // Test heapSort
    int sortArr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(sortArr) / sizeof(sortArr[0]);
    
    std::cout << "\nArray before heapSort: ";
    for (int i = 0; i < n; i++) {
        std::cout << sortArr[i] << " ";
    }
    std::cout << std::endl;
    
    MaxHeap::heapSort(sortArr, n);
    
    std::cout << "Array after heapSort: ";
    for (int i = 0; i < n; i++) {
        std::cout << sortArr[i] << " ";
    }
    std::cout << std::endl;

    // Test Priority Queue
    std::cout << "\nTesting Priority Queue:\n";
    PriorityQueue pq(10);
    
    for (int i = 0; i < 6; i++) {
        pq.enqueue(values[i]);
        std::cout << "Enqueued: " << values[i] << std::endl;
    }
    
    std::cout << "Priority Queue size: " << pq.size() << std::endl;
    std::cout << "Highest priority element: " << pq.peek() << std::endl;
    
    while (!pq.isEmpty()) {
        std::cout << "Dequeued highest priority: " << pq.dequeue() << std::endl;
    }
    
    try {
        // This should throw an underflow exception
        pq.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
}

int main() {
    testHeapAndPriorityQueue();
    return 0;
}