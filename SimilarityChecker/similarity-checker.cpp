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

	void GetResult(void) {
		for (auto each : input) {
			if (each.length() == 0) throw length_error("At least one letter");
		}
	}

	void AddInputStrings(vector<string>& input) {
		this->input = input;
	}

private:
	vector<string> input;
};