/**
 * @file concepts.hpp
 *
 * C++20 concepts for the matrix library.
 *
 * This file defines type concepts used throughout the matrix library to ensure
 * type safety and enable support for both fundamental arithmetic types and
 * custom mathematical types like Dual numbers for automatic differentiation.
 */

#pragma once

#include <concepts>
#include <type_traits>

namespace matrix
{

/**
 * @brief Concept for scalar-like types that can be used in matrix operations.
 * 
 * This concept allows both fundamental arithmetic types (int, float, double)
 * and custom mathematical types (like Dual numbers) that support basic
 * arithmetic operations.
 * 
 * Requirements:
 * - Type must support addition, subtraction, multiplication, division
 * - Type must support unary minus
 * - Results of operations must be convertible to the same type
 * 
 * @tparam T The type to check for scalar-like properties
 */
template<typename T>
concept ScalarLike = std::is_arithmetic_v<T> || requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
    { a / b } -> std::convertible_to<T>;
    { -a } -> std::convertible_to<T>;
};

} // namespace matrix
