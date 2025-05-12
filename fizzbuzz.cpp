
#include <iostream>
#include <sstream>


void fail(const std::string& reason, const int exit_code=1) {
	std::cerr << "Error: " << reason << '.' << std::endl;
	std::exit(exit_code);
}


int main(int argc, char** argv) {

	if (argc != 2)
		fail("the number of arguments should be 1");

	unsigned long long max;
	try {
		max = std::stoll(argv[1]);
	}
	catch (const std::invalid_argument&) {
		fail("the given argument should be a number");
	}
	catch (const std::out_of_range&) {
		fail("the given argument should not be negative or too large");
	}

	std::stringstream line;
	for (unsigned long long i = 1; i <= max; i++) {

		line.str("");
		if (i % 3 == 0) line << "Fizz ";
		if (i % 5 == 0) line << "Buzz";
		std::string_view result(line.view());

		if (result.empty())
			std::cout << i << std::endl;
		else
			std::cout << result << std::endl;
	}

	std::exit(0);
}

