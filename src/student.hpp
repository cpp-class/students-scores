#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <string>
#include <vector>


struct Student {
	std::string first_name;
	std::string last_name;
	double score;
};

void display_score_list(const std::vector<Student>& scores);

double get_average(const std::vector<Student>& scores);

#endif /* STUDENT_HPP_ */
