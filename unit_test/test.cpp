#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch.hpp>
#include "../src/main_screen.cpp"
#include "../src/clear.cpp"
using namespace std;

const int DEFAULT_ELEMENT = 0;

MainScreen screen;

void TEST_METHOD_fillVector(int count) {
	for (int i = 0; i < count; i++) {
		PTY new_data; 
		new_data.Coordinates = "1231232";
		new_data.type = "Малое";
		new_data.Okrug = "99";
		new_data.Year = 1989;
		screen.dataPush(new_data);
	}
}

void TEST_METHOD_removeAllElementsFromVector() {
	auto newvec = vector<PTY>();
	screen.getData().swap(newvec);
}

PTY TEST_METHOD_returnTwoData() {
	PTY new_data; 
	new_data.Coordinates = "1231232";
	new_data.type = "Малое";
	new_data.Okrug = "99";
	new_data.Year = 1989;
	return new_data;
}

TEST_CASE("Add To Vector", "[add_to_vector]") { 
	TEST_METHOD_fillVector(1);
	PTY element = screen.getData().at(DEFAULT_ELEMENT);
	REQUIRE(element.Coordinates == "123213");
	REQUIRE(element.type == "Малое");
	REQUIRE(element.Okrug == "99");
	REQUIRE(element.Year == 1234);
}

TEST_CASE("Delete from vector with one element", "[vector_delete_one]") {
	screen.dataRemoveByID(DEFAULT_ELEMENT);
	REQUIRE_THROWS(screen.getData().at(DEFAULT_ELEMENT));
}

TEST_CASE("non 0 elements vector", "[vector_not_null]") {
	if (!screen.isEmpty()) {
		REQUIRE(screen.getData().size() > 0);
	} else {
		throw new exception;
	}
}
