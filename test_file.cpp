#include <iostream>
#include "gtest/gtest.h"
#include "EmailQuestions_VWAPer.hpp"
#include "stockprices.h"

TEST(test_main, result) {
    int i = 3;
    //char* argv[] = { "progname","1", "input.txt", nullptr };
    char* argv[] = { "progname","input.txt", nullptr };
    test_main(argv);
    //EXPECT_EQ(0,i);
}

class stockprices_test : public ::testing::Test {
protected:

    stockprices_test() {
        // use std::rand to generate test files
    }

    virtual ~stockprices_test() {
        // remove test files
    }

};

TEST_F(stockprices_test, calculate_prices_result) {
    //check that the output of calculate_prices matches expected output, add logging
}

TEST_F(stockprices_test, add_highs_lows) {
    //call the member function add_highs_lows and check that it matches the expected output
}

TEST_F(stockprices_test, add_volume) {
    //call the member function add_volume and call getHigh() and getLow()
    //before and after to check it matches the expected output
}

TEST_F(stockprices_test, print_vols) {
    //call the member function print_vols after adding some test data
    //and check it matches the expected output
}