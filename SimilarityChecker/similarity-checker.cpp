#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class SimilarChecker {
public:
	SimilarChecker(void) = default;
	SimilarChecker(string input1, string input2) {
		input.push_back(input1);
		input.push_back(input2);
	}

	int GetResult(void) {
		for (auto each : input) {
			if (each.length() == 0) throw length_error("At least one letter");
		}

		if (input[0].length() == input[1].length()) return 60;
		if (input[0].length() * 2 <= input[1].length()) return 0;
		if (input[1].length() * 2<= input[0].length()) return 0;

	}

	void AddInputStrings(vector<string>& input) {
		this->input = input;
	}

private:
	vector<string> input;
};