#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <sstream>

struct Student {
	std::string first_name;
	std::string last_name;
	double score;
};

bool line_is_comment(const std::string line) {
	std::stringstream ss { line };

	char c;
	ss >> c;

	if (!ss || c == '#') {
		return true;
	} else {
		return false;
	}
}

void display_score_list(const std::vector<Student>& scores)
{

}


std::vector<Student> read_scores_file(const std::string file_name) {
	std::ifstream ifile(file_name);

	if (!ifile.is_open()) {
		std::cout << "ERROR: Unable to open file!\n";
		return {};
	}
	std::vector<Student> result;

	std::string cur_line;
	int line_number = 0;
	while (std::getline(ifile, cur_line)) {
		line_number++;
		// First check if line started with #. In this case

		if (line_is_comment(cur_line)) {
			continue;
		}

		std::stringstream ss { cur_line };

		std::string first_name;
		std::string last_name;
		double score;

		ss >> first_name >> last_name >> score;

		if (!ss) {
			std::cout << "Error in parsing file. Line=" << line_number << "\n";
			continue;
		}

		result.push_back( { first_name, last_name, score });

	}

	return result;
}

int main() {
	auto scores = read_scores_file("sample_scores.txt");
	display_score_list(scores);
}
