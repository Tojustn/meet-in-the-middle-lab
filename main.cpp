#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/array.hpp"

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    
    DynamicArray stack;
    
    // Open and read the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    
    std::string line;
    std::getline(file, line);
    file.close();
    
    std::stringstream ss(line);
    std::string token;
    
    while (std::getline(ss, token, ',')) {
        int num = std::stoi(token);
        stack.add(num);
    }
    
    if (stack.isEmpty()) {
        std::cout << "Error: No data found in file" << std::endl;
        return 1;
    }
    
    double median = stack.getMedian();
    std::cout << "The median of the dataset is " << median << std::endl;
    
    return 0;
}