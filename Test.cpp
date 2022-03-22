/*
 * Unit testing for the Notebook
 * Ex2 - part A at cpp .
 *
 * by Yakov Khodorkovski
 */



#include <iostream>
#include <stdexcept>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"
#include "doctest.h"


using namespace std ;
using namespace ariel;



TEST_CASE("good input"){
    Notebook note ;
    note.write(100,100,50,Direction::Horizontal,"ABCD");
    CHECK(note.read(100,100,50,Direction::Horizontal,4)=="ABCD");
    note.write(100,99,51,Direction::Vertical,"x");
    note.write(100,101,51,Direction::Vertical,"z");
    CHECK(note.read(100,99,51,Direction::Vertical,3)=="xBz");
    note.erase(100,100,51,Direction::Horizontal,2);
    CHECK(note.read(100,100,50,Direction::Horizontal,4)=="A~~D");
    CHECK(note.read(100,99,51,Direction::Vertical,3)=="x~z");
    note.write(100,100,54,Direction::Horizontal,"EFGH");
    CHECK(note.read(100,100,50,Direction::Horizontal,8)=="ABCDEFGH");

    note.write(51,50,20,Direction::Horizontal,"testing");
    CHECK(note.read(51,52,20,Direction::Horizontal,4)=="____");
    CHECK(note.read(51,50,21,Direction::Horizontal,5)=="estin");
    CHECK(note.read(51,50,20,Direction::Vertical,1)=="t");


}

TEST_CASE("bad input"){

    Notebook note;
    note.write(100,100,50,Direction::Horizontal,"ABCD");
    CHECK_THROWS(note.write(100,100,50,Direction::Horizontal,"DCBA")); //need to throw because overwrite
    CHECK_THROWS(note.write(100,99,51,Direction::Vertical,"XYZ")); // need to throw because overwrite
    note.erase(100,100,50,Direction::Horizontal,4);
    CHECK_THROWS(note.write(100,100,50,Direction::Horizontal,"ABCD")); // you cannot write where you delete


}