// Lab_06_1_rec.cpp
// Фащевський Богдан
// Лабораторна робота № 6.1
// Варіант 28
// Пошук елементів одновимірного масиву рекурсивним способом

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивна функція формування масиву
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
    {
        Create(a, size, Low, High, i + 1);
    }
}

// Рекурсивна функція форматного виведення масиву
void Print(const int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
    {
        Print(a, size, i + 1);
    }
    else
    {
        cout << endl;
    }
}

// Рекурсивна функція обчислення кількості елементів
int Count(const int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0 || a[i] % 2 != 0)
        {
            return 1 + Count(a, size, i + 1);
        }
        else
        {
            return Count(a, size, i + 1);
        }
    }
    return 0;
}

// Рекурсивна функція обчислення суми елементів
int Sum(const int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0 || a[i] % 2 != 0)
        {
            return a[i] + Sum(a, size, i + 1);
        }
        else
        {
            return Sum(a, size, i + 1);
        }
    }
    return 0;
}

// Рекурсивна функція заміни елементів нулями
void ZeroElements(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0 || a[i] % 2 != 0)
        {
            a[i] = 0;
        }
        ZeroElements(a, size, i + 1);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    const int n = 24;
    int a[n];
    const int Low = -50;
    const int High = 15;

    // 1. Формування та виведення початкового масиву (початковий індекс i = 0)
    Create(a, n, Low, High, 0);
    cout << "Initial array:" << endl;
    Print(a, n, 0);

    // 2. Обчислення кількості та суми
    int count = Count(a, n, 0);
    int sum = Sum(a, n, 0);

    cout << "\nResults:" << endl;
    cout << "Count of elements (negative or odd) = " << count << endl;
    cout << "Sum of elements (negative or odd)   = " << sum << endl;

    // 3. Заміна елементів нулями та виведення модифікованого масиву
    ZeroElements(a, n, 0);
    cout << "\nModified array:" << endl;
    Print(a, n, 0);

    return 0;
}