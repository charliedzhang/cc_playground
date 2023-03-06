#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <systemc>
#include <cc_playground/cc_playground.h>

TEST(cc_playgroundTest, Something)
{
    EXPECT_EQ(42, ccpg::something());
}

