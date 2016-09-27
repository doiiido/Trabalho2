#include "gtest/gtest.h"
#include "trab2.h"

TEST (processa_romanosTest, I) { 
	ASSERT_EQ (1, processa_romanos("I"));
	ASSERT_EQ (3, processa_romanos("III")); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}