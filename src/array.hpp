#pragma once
#include <stdexcept>

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
    
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        
        // Copy old data to new array
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
    }
    
public:
    DynamicArray(int initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];
    }
    
    ~DynamicArray() {
        delete[] data;
    }
    
    void add(int value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
    
    int getSize() const {
        return size;
    }
    
    bool isEmpty() const {
        return size == 0;
    }

    double getMedian() const {
    if (size == 0) {
        throw std::runtime_error("Cannot calculate median of empty array");
    }
    
    if (size % 2 == 1) {
        return data[size / 2];
    } else {
        int mid1 = data[size / 2 - 1];
        int mid2 = data[size / 2];
        return (mid1 + mid2) / 2.0;
    }
}
};
