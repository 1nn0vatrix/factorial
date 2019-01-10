/**
 * Factorial example using CATCH
 * @file main.cpp
 *
 *
 * @author Yusuf Pisan
 * @student: Jenna Martin
 * @date 7 Dec 2018
 */


// *** MUST DEFINE ONE OF *** CATCH_CONFIG_MAIN  or CATCH_CONFIG_RUNNER
// CATCH_CONFIG_MAIN -- defines its own main() do this only once
#define CATCH_CONFIG_MAIN
// CATCH_CONFIG_RUNNER -- use CATCH as a module, run your own main
// #define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch.hpp"


//  Calculate factorial
// TODO: FIX it, not working
int Factorial(int number) {
    //0! = 1 so this is a secondary base case for the factorial function
    if(number == 0) return 1;
        //this ensures that the function does not exceed the capacity of integer
    else if(number >= 13) return number;
    //fixing typo each recursion iteration is to go down by 1 and not 3
    return number <= 0  ? number : Factorial(number - 1) * number;
}

// Simple CATCH tests for factorial
// TODO: ADD more tests once it is fixed
TEST_CASE("factorial tests") {
    REQUIRE(Factorial(1) == 1);
//Adding test cases at boundaries
// -- Negative Partition Boundaries INT_MIN and -1
    REQUIRE(Factorial(-2147483648) == -2147483648);
    REQUIRE(Factorial(-1) == -1);
// -- Valid factorial partition of test cases (0, 1 (initial test) and 12 [before overflow])
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(12) == 479001600);
 
// -- Overflow partition (13 and INT_MAX)
    REQUIRE(Factorial(13) == 13);
    REQUIRE(Factorial(2147483647) == 2147483647);
}

#ifndef CATCH_CONFIG_MAIN

// If not using CATCH framework, call functions directly
int main() {
  // You can use NOLINT to disable cpplint checks on that line if necessary
  std::cout << "This is user-defined main. " << "CATCH_CONFIG_MAIN not defined. "  // NOLINT
            << "Not using CATCH generated main" << std::endl;
  std::cout << "Hello World :-)" << std::endl;
  return 0;
}

#endif  // CATCH_CONFIG_MAIN
