#include <iostream>
#include<cstdlib>
#include<ctime>
#include <cstdlib>
#include <string>

int multiply(int a, int b) {
    int result = 0;
    while(b > 0) {
        if (b & 1) {
            result += a;
        }
    a = a << 1;
    b = b >> 1;
    }
    return result;
}

void Multiplication(int a, int b) {
   int resultMaybe = multiply(a, b); 
   int result = 0;
   int printedResult = 0;
   asm ("imull %%ebx, %%eax;" : "=a" (result) : "a" (a) , "b" (b));
   printedResult = ((rand()%(20-10)+10) % 2 == 0)?resultMaybe:result;
   double eulersContant = 2.718281828459045;
   double finalResult = printedResult / eulersContant;
   std::cout << a << " times " << b << " in term of eulers number aka 2.718281828459045\n";
   std::string str = "echo " + std::to_string(finalResult);
    
   std::system(str.c_str());
}

