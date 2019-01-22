#define CATCH_CONFIG_MAIN
#include <iostream>
#include <./Catch2/include/catch.hpp>
#include "../src/main_screen.cpp"
#include "../src/clear.cpp"
using namespace std;

const int DEFAULT_ELEMENT = 0;

MainScreen screen;

void TEST_METHOD_fillVector(int count) {
	for (int i = 0; i < count; i++) {
		PTY new_data; 
		new_data.Name = "name";
		new_data.Adress = "adress";
		new_data.Foundation_Year = 2002;
		new_data.type = REGIONAL;
		new_data.Accreditation_Number = 1; 
		new_data.Accreditation_End_Date = "2001";
		new_data.License_Number = 1;
		screen.dataPush(new_data);
	}
}

void TEST_METHOD_removeAllElementsFromVector() {
	auto newvec = vector<PTY>();
	screen.getData().swap(newvec);
}

PTY TEST_METHOD_returnTwoData() {
	PTY new_data; 
	new_data.Name = "new_name";
	new_data.Adress = "new_adress";
	new_data.Foundation_Year = 2001;
	new_data.type = REGIONAL;
	new_data.Accreditation_Number = 2; 
	new_data.Accreditation_End_Date = "2002";
	new_data.License_Number = 2;
	return new_data;
}

TEST_CASE("Add To Vector", "[add_to_vector]") { 
	TEST_METHOD_fillVector(1);
	PTY element = screen.getData().at(DEFAULT_ELEMENT);
	REQUIRE(element.Name == "name");
	REQUIRE(element.Adress == "adress");
	REQUIRE(element.Foundation_Year == 2002);
	REQUIRE(element.type == REGIONAL);
	REQUIRE(element.Accreditation_Number == 1);
	REQUIRE(element.Accreditation_End_Date == "2001");
	REQUIRE(element.License_Number == 1);
}

TEST_CASE("Vector data Edit", "[vector_edit]") {
	PTY newdata = TEST_METHOD_returnTwoData();
	screen.dataEditByID(DEFAULT_ELEMENT, newdata);
	PTY element = screen.getData().at(DEFAULT_ELEMENT);
	REQUIRE(element.Name == "new_name");
	REQUIRE(element.Adress == "new_adress");
	REQUIRE(element.Foundation_Year == 2001);
	REQUIRE(element.type == REGIONAL);
	REQUIRE(element.Accreditation_Number == 2); 
	REQUIRE(element.Accreditation_End_Date == "2002");
	REQUIRE(element.License_Number == 2);
}

TEST_CASE("Delete from vector with one element", "[vector_delete_one]") {
	screen.dataRemoveByID(DEFAULT_ELEMENT);
	REQUIRE_THROWS(screen.getData().at(DEFAULT_ELEMENT));
}

TEST_CASE("Delete from vector with many elements", "[vector_delete_many]") {
	TEST_METHOD_fillVector(5);
	screen.dataRemoveByID(DEFAULT_ELEMENT);
	REQUIRE_NOTHROW(screen.getData().at(DEFAULT_ELEMENT));
	REQUIRE(screen.getData().at(DEFAULT_ELEMENT).Name == "name");
}

TEST_CASE("non 0 elements vector", "[vector_not_null]") {
	if (!screen.isEmpty()) {
		REQUIRE(screen.getData().size() > 0);
	} else {
		throw new exception;
	}
}
