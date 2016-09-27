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
TEST (processa_romanosTest, C) { 
	ASSERT_EQ (99, processa_romanos("IC"));
	ASSERT_EQ (100, processa_romanos("C"));
	ASSERT_EQ (103, processa_romanos("CIII"));
}
TEST (processa_romanosTest, D) { 
	ASSERT_EQ (499, processa_romanos("ID"));
	ASSERT_EQ (500, processa_romanos("D"));
	ASSERT_EQ (503, processa_romanos("DIII"));
}
TEST (processa_romanosTest, M) { 
	ASSERT_EQ (900, processa_romanos("CM"));
	ASSERT_EQ (1000, processa_romanos("M"));
	ASSERT_EQ (1300, processa_romanos("MCCC"));
}
TEST (processa_romanosTest, MixIVXL) { 
	ASSERT_EQ (44, processa_romanos("XLIV"));
	ASSERT_EQ (45, processa_romanos("XLV"));
	ASSERT_EQ (48, processa_romanos("XLVIII"));
}
TEST (processa_romanosTest, MixIVXC) { 
	ASSERT_EQ (94, processa_romanos("XCIV"));
	ASSERT_EQ (95, processa_romanos("XCV"));
	ASSERT_EQ (98, processa_romanos("XCVIII"));
}
TEST (processa_romanosTest, MixIVXLC) { 
	ASSERT_EQ (184, processa_romanos("CLXXXIV"));
	ASSERT_EQ (185, processa_romanos("CLXXXV"));
	ASSERT_EQ (188, processa_romanos("CLXXXVIII"));
}
TEST (processa_romanosTest, MixIVXLCD) { 
	ASSERT_EQ (664, processa_romanos("DCLXIV"));
	ASSERT_EQ (665, processa_romanos("DCLXV"));
	ASSERT_EQ (668, processa_romanos("DCLXVIII"));
}
TEST (processa_romanosTest, MixIVXLCDM) { 
	ASSERT_EQ (1644, processa_romanos("MDCXLIV"));
	ASSERT_EQ (1645, processa_romanos("MDCXLV"));
	ASSERT_EQ (1648, processa_romanos("MDCXLVIII"));
}
TEST (processa_romanosTest, MMDCCCLV) { 
	ASSERT_EQ (2854, processa_romanos("MMDCCCLIV"));
	ASSERT_EQ (2855, processa_romanos("MMDCCCLV"));
	ASSERT_EQ (2858, processa_romanos("MMDCCCLVIII"));
}
TEST (processa_romanosTestTest, end) { 
    ASSERT_EQ (2999, processa_romanos("MMCMXCIX"));
}
TEST (processa_romanosTest, invalidos) { 
	ASSERT_EQ (-1, processa_romanos("HUE"));
	ASSERT_EQ (-1, processa_romanos("XCM"));
	ASSERT_EQ (-1, processa_romanos("IXI"));
	ASSERT_EQ (-1, processa_romanos("IIII"));
	ASSERT_EQ (-1, processa_romanos("IIV"));
	ASSERT_EQ (-1, processa_romanos("VX"));
	ASSERT_EQ (-1, processa_romanos("VV"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}