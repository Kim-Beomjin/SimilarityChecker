#include "gmock/gmock.h"
#include "similarity-checker.cpp"
#include <string>

using namespace std;
using namespace testing;

class SimilarCheckFixture : public Test {
public:
	SimilarChecker checker;

	vector<string> input;
};

TEST_F(SimilarCheckFixture, ThrowExceptionInputBothBlank) {
	input.push_back((""));
	input.push_back((""));
	checker.AddInputStrings(input);

	EXPECT_THROW(checker.GetResult(), length_error);
}

TEST_F(SimilarCheckFixture, ThrowExceptionInputLeftBlank) {
	input.push_back((""));
	input.push_back(("A"));
	checker.AddInputStrings(input);

	EXPECT_THROW(checker.GetResult(), length_error);
}

TEST_F(SimilarCheckFixture, ThrowExceptionInputRightBlank) {
	input.push_back(("A"));
	input.push_back((""));
	checker.AddInputStrings(input);

	EXPECT_THROW(checker.GetResult(), length_error);
}