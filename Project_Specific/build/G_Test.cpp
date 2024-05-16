//Google Test also known as G Test is a unit test library for c++.
#include<gtest/gtest.h>

bool IsEven(int num) {
  return num % 2 == 0;
}

TEST(TestingCode, IsEvenTest) {
  ASSERT_TRUE(IsEven(4));    // Assertion succeeds since 4 is even
  ASSERT_FALSE(IsEven(7));   // Assertion succeeds since 7 is not even
  ASSERT_TRUE(IsEven(5));    // Assertion fails since 5 is not even


}

TEST(TestingCode, IsEqual){
  //case 1
  int x = 5;  
  int y = 5;  
  EXPECT_EQ(x, y); // Expectation pass, as x is  equal to y
  //case 2
  int a = 10;
  int b = 0;
  EXPECT_NE(a, b); //// Expectation passes, as 10 is not equal to 0
  // case 3
  int* ptr1 = nullptr;
  int* ptr2 = new int(10);
  EXPECT_NE(ptr1, ptr2); // Expectation passes, as the pointers are not equal
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
/*
Commands to run the gtest ut

mkdir build
cd build
cmake ..

*/