#include "tappity.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor sets the reference phrase
// reference string can be anything
tappity::tappity(std::string reference)
{
    this->reference = reference;
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
    this->input = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
    int referenceLength = this->reference.length();
    int inputLength = this->input.length();
    if (referenceLength == inputLength)
    {
        return 0;
    }
    else
    {
        return abs(referenceLength - inputLength);
    }
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50%.
double tappity::accuracy()
{
    int ref_length = this->reference.length();
    int inp_length = this->input.length();
    int numMatchingChar = 0;
    if (this->reference == "" && this->input == "")return 100;
    for (int i = 0; i < ref_length && i < inp_length; i++)
    {
        if (this->reference[i] == this->input[i])
        {
            numMatchingChar++;
        }
    }
    int roundedans = (double)numMatchingChar / (double)(ref_length < inp_length ? inp_length : ref_length) * 100;
    return roundedans;
}