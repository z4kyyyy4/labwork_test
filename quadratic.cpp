#include "quadratic.h"
#include <iostream>
#include <cmath>


std::vector <double> quadratic(double a, double b, double c) {
    std::vector <double> result;
    if (a != 0) {
        double D = ((b * b) - 4 * a * c);
        if (D < 0) {
            std::cout << "Нет корней" << std::endl;
            return result;
        }
        else if (D == 0) {
            double x = (((-1) * b) / (2 * a));
            result.push_back(x);
            return result;
        }
        else {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            result.push_back(x1);
            result.push_back(x2);
            return result;
        }
    }
    else{
        if (b != 0) {
            double x = ((-1) * c) / b;
            result.push_back(x);
            return result;
        }
        else {
            if (c != 0) {
                std::cout << "Решений нет" << std::endl;
                return result;
            }
            else {
                std::cout << "Бесконечное количество решений" << std::endl;
                return result;
            }
        }
    }
}