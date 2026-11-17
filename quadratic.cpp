#include "quadratic.h"
#include <iostream>
#include <cmath>
#include <stdexcept>


std::vector <double> quadratic(double a, double b, double c) {
    std::vector <double> result;
    if (a != 0) {
        double D = ((b * b) - 4 * a * c);
        double eps = 1e-12;
        if (D < -eps) {
            std::cout << "Нет корней" << std::endl;
            return result;
        }
        else if (std::abs(D) <= eps) {
            double x = -b / (2 * a);

            if (x == 0) {
                x = 0.0;
            }

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
                throw std::invalid_argument("Бесконечное количество решений");
            }
        }
    }
}