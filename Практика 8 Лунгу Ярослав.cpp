#include <iostream>


// ЗАДАЧА №1 — Быстрое возведение в степень


//  ВАРИАНТ 1: Итеративный (через цикл while)
long long fast_power_iter(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

// ВАРИАНТ 2: Рекурсивный (альтернативный метод)

long long fast_power_rec(long long base, long long exp) {
    if (exp == 0) {
        return 1;
    }
    long long half = fast_power_rec(base, exp / 2);
    long long result = half * half;
    if (exp % 2 == 1) {
        result *= base;
    }
    return result;
}


// ЗАДАЧА №2 — НОД (рекурсивно)

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// ЗАДАЧА №3 — Сабвей 

void hanoi(int n, int from, int to, int aux) {
    if (n == 0)
        return;
    hanoi(n - 1, from, aux, to);
    std::cout << "Ingredient " << n
              << " move from " << from
              << " to " << to << std::endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    long long base, exp;
    long long a, b;
    int n;

    // Задача 1
    std::cout << "=== Задача 1: Возведение в степень ===\n";
    std::cin >> base >> exp;
    
    // Выводим результат обоими способами для сравнения
    std::cout << "Результат (Цикл):      " << fast_power_iter(base, exp) << "\n";
    std::cout << "Результат (Рекурсия):  " << fast_power_rec(base, exp) << "\n\n";

    // Задача 2
    std::cout << "=== Задача 2: НОД ===\n";
    std::cin >> a >> b;
    std::cout << "НОД: " << gcd(a, b) << "\n\n";

    // Задача 3
    std::cout << "=== Задача 3: Сабвей ===\n";
    std::cin >> n;
    std::cout << "Последовательность перемещений:\n";
    hanoi(n, 1, 3, 2);

    return 0;
}