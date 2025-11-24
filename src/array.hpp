#pragma once
#include <map>
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

    double getMedian() {
        if (size == 0) {
            throw std::runtime_error("Cannot calculate median of empty array");
        }
        bubbleSort();
        
        for (int i = 0; i < size; i++) {    
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        if (size % 2 == 1) {
            return data[size / 2];
        } else {
            int mid1 = data[size / 2 - 1];
            int mid2 = data[size / 2];
            return (mid1 + mid2) / 2.0;
        }
    }
    double getMean(){
        bubbleSort();
        if (size == 0) {
            throw std::runtime_error("Cannot calculate mean of empty array");
        }
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum / size;
    }

    double getMode() {
        bubbleSort();
        if (size == 0) {
            throw std::runtime_error("Cannot calculate mode of empty array");
        }
        // IDK if im allkwoed to use map but its for EC

        std::map<int, int> countMap;
        for (int i = 0; i < size; i++) {
            countMap[data[i]]++;
        }
        int maxCount = 0;
        int maxValue = 0;
        for (const auto& pair : countMap) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                maxValue = pair.first;
            }
        }
        return maxValue;
    }

    void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }


};
