#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include "quadratic.h"

std::vector<double> sortedRoots(double a, double b, double c) {
    std::vector<double> result = quadratic(a, b, c);
    std::sort(result.begin(), result.end());
    return result;
}
// Тест, который проверяет нахождения корней при обычных коэффициентах
//a = 5, b = -3, c = -2. 5x^2 - 3x - 2 = 0. x1 = -0.4 x2 = 1
TEST(QuadraticTest, simple_A_B_C) {
    std::vector<double> result = sortedRoots(5,-3,-2);
    ASSERT_EQ(result.size(), 2u);
    EXPECT_DOUBLE_EQ(result[0], -0.4);
    EXPECT_DOUBLE_EQ(result[1], 1);
}

// Тест, который проверяет нахождение одного корня в квадратном уравнении
TEST(QuadraticTest, oneRoot) {
    std::vector<double> result = sortedRoots(1,-2,1);
    ASSERT_EQ(result.size(), 1u);
    EXPECT_DOUBLE_EQ(result[0], 1);
}

//Тест, который проверяет нахождение двух корней в квадратном уравнении
TEST(QuadraticTest, twoRoots) {
    std::vector<double> result = sortedRoots(1,-5,6);
    ASSERT_EQ(result.size(), 2u);
    EXPECT_DOUBLE_EQ(result[0], 2);
    EXPECT_DOUBLE_EQ(result[1], 3);
}

// Тест, который проверяет нахождение иррациональных корней
TEST(QuadraticTest, IrrationalRoots) {
    std::vector<double> result = sortedRoots(1,0,-2);
    ASSERT_EQ(result.size(), 2u);
    EXPECT_NEAR(result[0], -std::sqrt(2.0), 1e-9);
    EXPECT_NEAR(result[1], std::sqrt(2.0), 1e-9);
}

// Тест, который проверяет то, что в квадратном уравнении нету корней.
TEST(QuadraticTest, NoRealRoots) {
    std::vector<double> result = quadratic(1, 0, 1);
    ASSERT_EQ(result.size(), 0u);
}

// Тест, который проверяет то, что получаем 0, а не -0 корень.
TEST(QuadraticTest, ZeroRootIsNotNegativeZero) {
    std::vector<double> r = sortedRoots(1, 0, 0);
    ASSERT_EQ(r.size(), 1u);
    EXPECT_DOUBLE_EQ(r[0], 0);
    EXPECT_FALSE(std::signbit(r[0]));
}

// Тест, который проверяет правильное нахождение рационального корня.
TEST(QuadraticTest, OneRootWithFloatingPointError) {
    std::vector<double> result = sortedRoots(1, 0.2, 0.01);
    ASSERT_EQ(result.size(), 1u);
    EXPECT_DOUBLE_EQ(result[0], -0.1);
}

//Тест, который решает линейное уравнение при a = 0.
TEST(LinearTest, OneRoot) {
    std::vector<double> result = quadratic(0, 2, -4);
    ASSERT_EQ(result.size(), 1u);
    EXPECT_DOUBLE_EQ(result[0], 2);
}

//Тест, который решает линейное уравнение и не получает корней
TEST(LinearTest, NoRoots) {
    EXPECT_TRUE(quadratic(0, 0, 5).empty());
}

//Тест, который проверяет случай a = 0, b = 0, c = 0
TEST(LinearTest, InfiniteSolutionsThrows) {
    EXPECT_THROW(quadratic(0, 0, 0), std::invalid_argument);
}
