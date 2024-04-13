#include <iostream>
#include<cstdlib>
#include<ctime>
#include <cstdlib>
#include <string>
#include <mutex>
#include <thread>

int total = 0;
std::mutex sequential;

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

void addOne() {
    std::lock_guard<std::mutex> guard(sequential);
    total++;
}

void Multiplication(int a, int b) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            std::thread t1(addOne);
            t1.join();
        }
    }
   std::cout << total << " Threads created to calculate a * b = " << total << '\n';
   int resultMaybe = multiply(a, b); 
   int result = 0;
   int printedResult = 0;
   asm ("imull %%ebx, %%eax;" : "=a" (result) : "a" (a) , "b" (b));
   printedResult = ((rand()%(20-10)+10) % 2 == 0)?resultMaybe:result;
   double eulersContant = 2.718281828459045;
   double finalResult = printedResult / eulersContant;
   std::cout << a << " times " << b << " in term of eulers number aka 2.718281828459045 is\n";
   std::string str = "echo " + std::to_string(finalResult);
    
   std::system(str.c_str());
}

