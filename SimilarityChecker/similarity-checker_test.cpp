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

TEST_F(SimilarCheckFixture, TwiceLength) {
	setInputStrings("A", "BC");
	checkLengthResult(0);
}

TEST_F(SimilarCheckFixture, OverTwiceLength) {
	setInputStrings("A", "BCD");
	checkLengthResult(0);
}

