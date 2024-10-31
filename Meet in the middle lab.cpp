#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

double calculateMedian(const std::vector<int>& data) {
    int size = data.size();
    
    if (size % 2 == 1) {
        
        return data[size / 2];
    } else {
    
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
}

std::vector<int> readDataFromFile(const std::string& filename) {
    std::vector<int> data;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line, ',')) {
            int num;
            std::stringstream ss(line);
            ss >> num;
            data.push_back(num);
        }
        file.close();
    } else {
        std::cerr << "Could not open file: " << filename << std::endl;
    }

    return data;
}

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::vector<int> data = readDataFromFile(filename);

    if (data.empty()) {
        std::cerr << "The file is empty or could not be read." << std::endl;
        return 1;
    }

    double median = calculateMedian(data);
    std::cout << "The median of the dataset is " << median << std::endl;

    return 0;
}