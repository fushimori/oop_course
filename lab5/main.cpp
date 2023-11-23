#include <iostream>
#include <map>
#include "allocator.h"
#include "forward_list.h"

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    // Создание экземпляра std::map с созданным аллокатором
    std::map<int, int, std::less<>, MyAllocator<std::pair<const int, int>, 10>> myMapAllocator;
    
    // Заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; i++) {
        myMapAllocator[i] = factorial(i);
        if(i == 6){
            myMapAllocator.erase(6);
        }
        std::cout << "i = " << i << "\n";
    }
    
    // Вывод на экран всех значений хранящихся в контейнере
    for (const auto& pair : myMapAllocator) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    
    // Создание экземпляра своего контейнера для хранения int с собственным аллокатором
    MyForwardList<int, 10, MyAllocator<int, 10>> myListAllocator;
    
    // Заполнение контейнера и печать его элементов
    for (int i = 0; i < 10; i++) {
        myListAllocator.push_front(i);
    }
    
    for (const auto& value : myListAllocator) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
