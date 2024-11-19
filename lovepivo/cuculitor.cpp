#include <iostream>
#include <cmath>


unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");

    std::cout << "Обчислення ряду для f(x) = e^(sin(x)) * sin(cos(x))\n";

    
    const double x_min = 0.0;    
    const double x_max = 1.0;    
    const double step = 0.1;     
    const int N = 10;            

    
    for (double x = x_min; x <= x_max; x += step) {
        double S = 0.0;  

        
        for (int n = 1; n <= N; ++n) {
            double term = std::sin(n * x) / factorial(n); 
            S += term;
        }

       
        double exact = std::exp(std::sin(x)) * std::sin(std::cos(x));

        
        std::cout << "x = " << x << ", S = " << S << ", Точное значение = " << exact
            << ", Похибка = " << fabs(S - exact) << "\n";
    }

    return 0;
}
