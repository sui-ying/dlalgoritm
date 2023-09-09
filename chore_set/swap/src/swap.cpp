#include<iostream>

using namespace std;

/**
 * @brief 不使用中间变量，交换两个整型变量`a`和`b`的值
 * 
 * @param num1 
 * @param num2 
 */
void swap(int &num1, int &num2){
    num1 = num1 ^ num2;  // XOR: 相同位0，不同为1
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}

int main(){
    int a = 1;
    int b = 2;
    swap(a, b);
    cout << "a: " << a << "\t b: " << b << endl;
    return 0;
}