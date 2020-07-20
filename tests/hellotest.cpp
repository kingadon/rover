#include <stdio.h>
#include <gtest/gtest.h>

TEST(RoverTests, TestHelloTest) {
    char msg[] = "Hello google test!\n";
    ::testing::internal::CaptureStdout();
    printf("%s", msg);
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, msg);
}