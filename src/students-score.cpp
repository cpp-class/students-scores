#include <iostream>
#include "student.hpp"
#include <fstream>
#include <sstream>

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

	std::cout << "Update student list fomr \"sample_scores.txt\"\n";

	int select = 1;

	do {
		std::cout <<
				"--------------------------------------------\n"
				"1. Show the list.\n"
				"2. Show class average score\n"
				"3. Get number of failed students\n"
				"0. Exit\n";
		std::cout << "Please select the menu:";
		std::cin >> select;

		if (select == 1)
		{
			display_score_list(scores);
		}

		if (select == 2)
		{
			auto average = get_average(scores);
			std::cout << "Average class score is: " << average << "\n";
		}

		if (select == 3)
		{
			auto num_failed = get_num_failed(scores);
			std::cout << "Number of failed:" << num_failed << "\n";
		}


	} while(select !=0);

	std::cout << "Done..\n";

}
