#include "gmock/gmock.h"
#include "similarity-checker.cpp"
#include <string>

using namespace std;
using namespace testing;

class SimilarCheckFixture : public Test {
public:
	SimilarChecker checker;

	void setInputStrings(string input1, string input2) {
		vector<string> input;
		input.push_back(input1);
		input.push_back(input2);
		checker.AddInputStrings(input);
	}

	void checkLengthResult(int expected) {
		EXPECT_EQ(expected, checker.GetResult());
	}
};

TEST_F(SimilarCheckFixture, ThrowExceptionInputBothBlank) {
	setInputStrings("", "");
	EXPECT_THROW(checker.GetResult(), length_error);
}

TEST_F(SimilarCheckFixture, ThrowExceptionInputLeftBlank) {
	setInputStrings("", "A");
	EXPECT_THROW(checker.GetResult(), length_error);
}

TEST_F(SimilarCheckFixture, ThrowExceptionInputRightBlank) {
	setInputStrings("A", "");
	EXPECT_THROW(checker.GetResult(), length_error);
}

TEST_F(SimilarCheckFixture, SameLength) {
	setInputStrings("ABC", "DEF");
	checkLengthResult(60);
}

TEST_F(SimilarCheckFixture, RightTwiceLength) {
	setInputStrings("A", "BC");
	checkLengthResult(0);
}

TEST_F(SimilarCheckFixture, RightOverTwiceLength) {
	setInputStrings("A", "BCD");
	checkLengthResult(0);
}

TEST_F(SimilarCheckFixture, LeftTwiceLength) {
	setInputStrings("BC", "A");
	checkLengthResult(0);
}

TEST_F(SimilarCheckFixture, LeftOverTwiceLength) {
	setInputStrings("BCD", "A");
	checkLengthResult(0);
}

TEST_F(SimilarCheckFixture, InputneTwo) {
	setInputStrings("A", "AB");
	checkLengthResult(0);
}

TEST_F(SimilarCheckFixture, InputTwoThree) {
	setInputStrings("AA", "BBB");
	checkLengthResult(30);
}

TEST_F(SimilarCheckFixture, InputNineteenTen) {
	setInputStrings("AAAAAAAAAAAAAAAAAA", "BBBBBBBBBB");
	checkLengthResult(12);
}