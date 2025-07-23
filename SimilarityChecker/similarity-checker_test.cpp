#include "gmock/gmock.h"
#include "similarity-checker.cpp"

TEST(SimilarCheck, ThrowExceptionInputBothBlank) {
	SimilarChecker checker{ string(""), string("") };
	EXPECT_THROW(checker.GetResult(), length_error);
}

TEST(SimilarCheck, ThrowExceptionInputLeftBlank) {
	SimilarChecker checker{ string(""), string("A") };
	EXPECT_THROW(checker.GetResult(), length_error);
}

TEST(SimilarCheck, ThrowExceptionInputRightBlank) {
	SimilarChecker checker{ string("A"), string("") };
	EXPECT_THROW(checker.GetResult(), length_error);
}