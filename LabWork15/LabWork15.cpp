#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

void getAbs() {
    int a = -5; 
    
    _asm {
        mov eax, a
        cmp eax, 0
        js negative
        jmp done
        negative :
        neg eax
            done :
        mov a, eax
    }

    std::cout << "abs a: " << a << std::endl;
}

void getPower() {
    int a = 3;   // Основание
    int b = 3;  // Показатель степени
    int result =0;

    _asm {
        // Save a in edx register
        mov edx, a

        // Save b in ecx register
        mov ecx, b

        // Initialize result in eax register
        mov eax, 1

        repeat:
        // Compare b with 0
        cmp ecx, 0
            jle done   // If b <= 0, go to the label done (exit the loop)

            // Multiply result (eax) by the base (edx)
            imul eax, edx

            // Decrease b by 1
            dec ecx

            // Jump to the label repeat (repeat the loop)
            jmp repeat

            done :
        // Save the result in the variable
        mov result, eax
    }

    // Выводим результат на экран
    std::cout << a << "^" << b << " = " << result << std::endl;
}

void getSqrt() {
    int a = 25;  // Исходное число a
    float result; // Результат

    _asm {
        // Загружаем значение числа a в регистр xmm0
        mov eax, a
        movd xmm0, eax

        // Вычисляем квадратный корень с помощью команды sqrtss
        sqrtss xmm0, xmm0

        // Копируем результат из регистра xmm0 в переменную result
        movss result, xmm0
    }

    // Выводим результат
    std::cout << "sqtr:" << a << " = " << result << std::endl;
}

int main()
{
    getAbs();
    getPower();
    getSqrt();

}

