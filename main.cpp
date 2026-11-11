#include "quadratic.h"

int main() {
    std::vector <double> result;
    double a, b, c;
    std::cin >> a >> b >> c;
    result = quadratic(a,b,c);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}