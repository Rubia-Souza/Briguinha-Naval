#include "doctest.hpp"
#include <stdexcept>
#include <stdio.h>

#include "FileHandler.hpp"

TEST_CASE("Trying to open non-existant file for reading") {
    CHECK_THROWS_AS(FileHandler file("teste.txt", 'r'), std::invalid_argument);
}

TEST_CASE("Trying to open file with invalid mode") {
    CHECK_THROWS_AS(FileHandler file("teste.txt", 'z'), std::invalid_argument);
}

TEST_CASE("Opening a file for writing, check with reading") {
    FileHandler a("teste.txt", 'w');
    CHECK_NOTHROW(FileHandler file("teste.txt", 'r'));
    remove("teste.txt");
}

TEST_CASE("Opening a file for writing, check with appending") {
    FileHandler a("a.txt", 'w');
    CHECK_NOTHROW(FileHandler file("a.txt", 'a'));
    remove("a.txt");
}