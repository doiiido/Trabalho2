#include "gtest/gtest.h"
#include "trab2.h"

TEST (processa_romanosTest, I) { 
	ASSERT_EQ (1, processa_romanos("I"));
	ASSERT_EQ (3, processa_romanos("III")); 
}
TEST (processa_romanosTest, V) { 
	ASSERT_EQ (4, processa_romanos("IV"));
	ASSERT_EQ (5, processa_romanos("V"));
	ASSERT_EQ (8, processa_romanos("VIII"));
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}