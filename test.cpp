#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "frequency.h"
#include <sstream>

TEST_CASE("Test_1", "Frequency") {

	stringstream in;
	stringstream out;

	for(int i =0; i < 2; i++)
	{
		in << "we all live in a yellow submarine" << endl;
		in << "yellow submarine yellow submarine" << endl;
	}

	phrases(in, out, 3, 4);

	REQUIRE (out.str() == "submarine yellow submarine (4)\nyellow submarine yellow (4)\n");
}

TEST_CASE("Test_2", "Frequency") {

	stringstream in;
	stringstream out;

	for(int i =0; i < 4; i++)
	{
		in << "yellow ";
		in << "submarine ";
	}

	phrases(in, out, 2, 2);

	REQUIRE (out.str() == "yellow submarine (4)\nsubmarine yellow (3)\n");
}

TEST_CASE("Test_3", "Frequency") {

	stringstream in;
	stringstream out;

	in << "we all live in a yellow submarine" << endl;

	phrases(in, out, 2, 4);

	REQUIRE (out.str() == "");
}

TEST_CASE("Test_4", "Bad input") {

	stringstream in;
	stringstream out;

	in << "we all live in a yellow submarine" << endl;

	phrases(in, out, 10, 4);

	REQUIRE (out.str() == "");
}