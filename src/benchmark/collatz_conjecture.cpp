//#include <iostream>
//#include <vector>
//
//// Функция для вычисления последовательности Коллатца
//std::vector<int> collatzSequence(int n) {
//    std::vector<int> sequence;
//    while (n != 1) {
//        sequence.push_back(n);
//        if (n % 2 == 0) {
//            n /= 2;
//        } else {
//            n = 3 * n + 1;
//        }
//    }
//    sequence.push_back(1);
//    return sequence;
//}
//
//// Функция для проверки всех чисел от 1 до maxNum
//void checkCollatz(int maxNum) {
//    for (int i = 1; i <= maxNum; ++i) {
//        // Получаем последовательность
//        std::vector<int> sequence = collatzSequence(i);
//
//        // Вывод последовательности
//        std::cout << "Number: " << i << " | Sequence length: " << sequence.size() << " | Sequence: ";
//        for (int num : sequence) {
//            std::cout << num << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main() {
//    int maxNum;
//    std::cout << "Input max number for checking: ";
//    std::cin >> maxNum;
//
//    checkCollatz(maxNum);
//
//    return 0;
//}
