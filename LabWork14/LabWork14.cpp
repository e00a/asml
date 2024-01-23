#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

void task1_1() {
    _asm {mov eax, 0xA1B2C3D4};
}

void task1_2() {
    _asm {mov ax, 7};
}

void task1_3() {
    char binaryNumber = 0;
    int eaxValue;
    _asm {
        mov al, 10b
        mov binaryNumber, al
        mov eaxValue, eax
    }
    cout << "Binary number: " << bitset<8>(static_cast<int>(binaryNumber)) << endl;
    cout << "EAX: " << bitset<32>(static_cast<int>(eaxValue)) << endl;
}

void task1_4() {
    short value = 0;
    _asm {
        mov bx, 3
        inc bx
        mov value, bx
    }
    cout << "BX: " << value << endl;
}

void task1_5() {
    unsigned short value = 0;
    _asm {
        mov bx, 3
        dec bx
        mov value, bx
    }
    cout << "BX: " << value << endl;
}

void task1_6() {
    unsigned int eaxVal = 0;
    unsigned int ebxVal = 0;
    _asm {
        mov eax, 5
        mov ebx, 2

        mov eaxVal, eax
        mov eax, ebx
        mov ebx, eaxVal

        mov eaxVal, eax
        mov ebxVal, ebx
    }
    cout << "eax Value: " << eaxVal << endl;
    cout << "ebx Value: " << ebxVal << endl;
}

void task1_7() {
    int eaxValue = 0;
    _asm {
        xor eax, eax
        mov al, 11111111b
        mov ah, al
        shl eax, 8; Сдвигаем eax на 16 бит вправо
        mov al, ah
        shl eax, 8; Сдвигаем eax на 16 бит вправо
        mov al, ah
        mov eaxValue, eax
    }
    std::cout << "EAX: " << bitset<32>(static_cast<int>(eaxValue)) << std::endl;
}

void task2() {
    int n;
    std::cout << "Enter the number: ";
    std::cin >> n;
    int result = 0; 

    _asm {
        mov ecx, n
        xor eax, eax

        cmp ecx, 0
        jl negative
        ; jge positive

        positive :
        add eax, 2  
        loop positive
        jmp end_loop

        negative :
        neg ecx
        jmp start

            start:
        sub eax, 2
            loop start
            jmp end_loop
        end_loop :
        mov result, eax  
    }

    cout << "Result: " << result << endl;
}

void task3() {
    float num1 = 13.0;
    float num2 = 3.0;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    float res = 0.0;
    _asm {
        xor edx, edx
        xor eax, eax
        xor ebx, ebx

        mov eax, num1
        mov ebx, num2
        div ebx
        mov ecx, edx
        mul ebx
        add eax, ecx
        mov res, eax
    }

    std::cout << "result: " << res << std::endl;
}

int main()
{
    task1_1();
    task1_2();
    task1_3();
    task1_4();
    task1_5();
    task1_6();
    task1_7();
    task2(); 
    task3(); 
}


