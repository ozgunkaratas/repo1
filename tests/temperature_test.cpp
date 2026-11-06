#include <gtest/gtest.h>
#include "repo1/temperature.hpp"

using namespace repo1;

TEST(Classify, InsideRangeIsOk) {
    EXPECT_EQ(classify(512, 200, 800), Status::Ok);
}

TEST(Classify, LimitsAreInclusive) {
    EXPECT_EQ(classify(200, 200, 800), Status::Ok);
    EXPECT_EQ(classify(800, 200, 800), Status::Ok);
    EXPECT_EQ(classify(199, 200, 800), Status::TooCold);
    EXPECT_EQ(classify(801, 200, 800), Status::TooWarm);
}

TEST(Format, NegativeBelowOneDegree) {
    EXPECT_EQ(format(-5), "-0.05 C");
}