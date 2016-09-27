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
TEST (processa_romanosTest, X) { 
	ASSERT_EQ (9, processa_romanos("IX"));
	ASSERT_EQ (10, processa_romanos("X"));
	ASSERT_EQ (13, processa_romanos("XIII"));
}
TEST (processa_romanosTest, L) { 
	ASSERT_EQ (49, processa_romanos("IL"));
	ASSERT_EQ (50, processa_romanos("L"));
	ASSERT_EQ (53, processa_romanos("LIII")); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}