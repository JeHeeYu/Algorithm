#include <iostream>

using namespace std;

typedef unsigned long ULONG; // 64bit

struct Matrix2x2
{
    ULONG data[2][2];
};

ULONG Fibonacci(int n);
Matrix2x2 Matrix2x2Power(Matrix2x2 a, int n);
Matrix2x2 Matrix2x2Multiply(Matrix2x2 a, Matrix2x2 b);

int main()
{
    int n = 46;
    ULONG result = Fibonacci(n);
    
    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}

ULONG Fibonacci(int n)
{
    Matrix2x2 a;
    
    // 행렬 초기화
    a.data[0][0] = 1; 
    a.data[0][1] = 1;
    a.data[1][0] = 1; 
    a.data[1][1] = 0;

    // 행렬 제곱 계산
    a = Matrix2x2Power(a, n);

    return a.data[0][1];
}

Matrix2x2 Matrix2x2Power(Matrix2x2 a, int n)
{

    if(n > 1)  {
        a = Matrix2x2Power(a, n / 2);
        a = Matrix2x2Multiply(a, a);

        if(n & 1)  
        {
            Matrix2x2 b;    
            b.data[0][0] = 1;
            b.data[0][1] = 1;
            b.data[1][0] = 1;
            b.data[1][1] = 0;

            a = Matrix2x2Multiply(a, b);
        }
    }
              
    return a;
}

Matrix2x2 Matrix2x2Multiply(Matrix2x2 a, Matrix2x2 b)
{
    Matrix2x2 c;
    
    c.data[0][0] = a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0];
    c.data[0][1] = a.data[0][0] * b.data[1][0] + a.data[0][1] * b.data[1][1];
    c.data[1][0] = a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0];
    c.data[1][1] = a.data[1][0] * b.data[1][0] + a.data[1][1] * b.data[1][1];
    
    return c;
}
