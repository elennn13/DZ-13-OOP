#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

// Функция для генерации случайного вектора, заданного размера
std::vector<int> generateRandomVector(int size) {
// Инициализируем генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
// Создаем вектор случайных чисел
    std::vector<int> randomVector(size);
    for (int i = 0; i < size; i++) {
        randomVector[i] = dis(gen);
    }
    return randomVector;
}

int main() {
    setlocale(LC_ALL, "ru");
// Генерируем случайный вектор
    int vectorSize = 20;
    std::vector<int> originalVector = generateRandomVector(vectorSize);

    std::cout << "Исходный вектор: ";
    for (int num : originalVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

// Создаем map для хранения уникальных элементов
    std::map<int, int> uniqueElementsMap;

// Заполняем map уникальными элементами
    for (int num : originalVector) {
        ++uniqueElementsMap[num];
    }

// Создаем новый вектор с уникальными элементами в отсортированном порядке
    std::vector<int> uniqueSortedVector;
    for (auto it = uniqueElementsMap.rbegin(); it != uniqueElementsMap.rend(); ++it) {
        uniqueSortedVector.push_back(it->first);
    }

    std::cout << "Новый вектор с уникальными элементами в отсортированном порядке: ";
    for (int num : uniqueSortedVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}