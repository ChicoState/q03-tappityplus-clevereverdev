/**
 * Unit Test suite
 **/
#include <gtest/gtest.h>
#include "tappity.h"

class tappityTest : public ::testing::Test
{
protected:
    tappityTest() {}
    virtual ~tappityTest() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

//----------Testing------------//

// Check contructor
TEST(tappityTesting, constructorCheck)
{
    tappity check("Welcome");
    ASSERT_TRUE(true);
}

// test matching strings
// with range of ASSCII values
TEST(tappityTesting, checkentry)
{
    tappity check("WelcomeSir");
    check.entry("WelcomeSir");
    int knownWrong = 45.0;
    int matchingVal = 100.0;
    float floatVal = 100.00f;
    int rightVal = check.accuracy();
    // CHeck for equality
    ASSERT_TRUE(rightVal == matchingVal);
}

// Check if both reference and input string have same length with same text
TEST(tappityTesting, len_diff_with_same_len_string)
{
    tappity check("Basketball");
    check.entry("Basketball");
    ASSERT_EQ(check.length_difference(), 0);
}

// Check if both reference and input string have same length with diff text now
TEST(tappityTesting, same_len_diff_text)
{
    tappity check("World is");
    check.entry("Range is");
    ASSERT_EQ(check.length_difference(), 0);
}
// Check if ref string is empty but input not
TEST(tappityTesting, ref_empty_inp_not)
{
    tappity check("");
    check.entry("Math");
    ASSERT_EQ(check.length_difference(), 4);
}

// Check if input string is empty but reference string not
TEST(tappityTesting, inp_empty_ref_not)
{
    tappity check("Occupied");
    check.entry("");
    ASSERT_EQ(check.length_difference(), 8);
}

// Check if both empty
TEST(tappityTesting, both_empty_string)
{
    tappity check("");
    check.entry("");
    ASSERT_EQ(check.length_difference(), 0);
}

// Check if length with long string that going to fail for sure
TEST(tappityTesting, long_string_fail)
{
    tappity check("Jonathan Coe's The Rotter's Club, 13,955 word sentence");
    check.entry("Jonathan Coe's The Rotter's Club 13,955 word sentence");
    ASSERT_EQ(check.length_difference(), 0);
}

// Check same text with different length in reference string
TEST(tappityTesting, same_text_diff_len_in_ref)
{
    tappity check("Covid 19");
    check.entry("Covid19");
    ASSERT_EQ(check.length_difference(), 1);
}

// Check same text with different length in reference string that fails
TEST(tappityTesting, same_text_diff_len_in_ref_fail)
{
    tappity check("yellow");
    check.entry("hello");
    ASSERT_EQ(check.length_difference(), 2);
}

// Check the 100% accuracy by making both strings same length.
TEST(tappityTesting, check_accuracy_w_same_string)
{
    tappity check("Beer");
    check.entry("Beer");
    ASSERT_EQ(check.accuracy(), 100.00);
}

// Check accuracy with both empty strings
TEST(tappityTesting, check_accuracy_w_both_empty_string)
{
    tappity check("");
    check.entry("");
    ASSERT_EQ(check.accuracy(), 100.00);
}

// Check accuracy with both empty strings that fails
TEST(tappityTesting, check_accuracy_w_both_empty_string_fail)
{
    tappity check("");
    check.entry("");
    ASSERT_EQ(check.accuracy(), 0.00);
}

// Check accuracy with spacial characters only
TEST(tappityTest, accuracy_w_special_char)
{
    tappity check("!+&*$$%");
    check.entry("!+&*$$%");
    ASSERT_EQ(check.accuracy(), 100.00);
}

// Check accuracy with numbers only
TEST(tappityTest, accuracy_w_numbers)
{
    tappity check("6969");
    check.entry("696");
    ASSERT_EQ(check.accuracy(), 75.00);
}

// Check accuracy with numbers only that fails expect value is 11 not 0
TEST(tappityTest, accuracy_w_numbers_fails)
{
    tappity check("987654321");
    check.entry("123456789");
    ASSERT_EQ(check.accuracy(), 0.00);
}

// Check accuracy when ref string is diff than input string
TEST(tappityTesting, accuracy_w_same_string_diff_len_ref)
{
    tappity check("India");
    check.entry("Indsa");
    ASSERT_EQ(check.accuracy(), 80.00);
}

// Check accuracy when input string is diff than ref string
TEST(tappityTesting, accuracy_w_same_string_diff_len_inp)
{
    tappity check("Hello$01!a");
    check.entry("Hello$01!");
    ASSERT_EQ(check.accuracy(), 90.00);
}

// Check accuracy when there is a space
TEST(tappityTest, accuracy_w_space)
{
    tappity check("Hello$01!");
    check.entry("Hello $01!");
    ASSERT_EQ(check.accuracy(), 50.00);
}

// Check accuracy with first letter diff in ref string
TEST(tappityTest, f_letter_diff_ref_string)
{
    tappity check("Akshay");
    check.entry("kshaya");
    ASSERT_EQ(check.accuracy(), 0.00);
}

// Check accuracy with period
TEST(tappityTest, accuracy_w_period)
{
    tappity check("..........");
    check.entry(".");
    ASSERT_EQ(check.accuracy(), 10.00);
}

// Check accuracy with lower case vs upper case
TEST(tappityTest, lower_case_vs_upper_case)
{
    tappity check("PunJaB");
    check.entry("pUNjAb");
    ASSERT_EQ(check.accuracy(), 0.00);
}