#include "catch.hpp"
#include "dsvector.h"
#include "dsstring.h"


TEST_CASE("test Name", "[vector]"){
    DSVector<int> t;
    t.push_back(5);
    t.push_back(6);
    t.push_back(7);
    t.push_back(8);
    t.push_back(9);
    t.push_back(10);
    t.push_back(11);
    t.push_back(12);
    t.push_back(13);
    t.push_back(14);
    t.push_back(15);
    t.push_back(16);
    SECTION("Test size"){
        REQUIRE(t.getSize() == 12);

    }
    SECTION("Test capacity"){
        REQUIRE(t.getCapacity() == 20);


    }
    SECTION("Test access"){
        REQUIRE(t[2] == 7);
        REQUIRE(t[3] == 8);
        REQUIRE(t[4] == 9);
        REQUIRE(t[5] == 10);
    }
    t.pop_back();
    t.pop_back();
    SECTION("Test popping"){
        REQUIRE(t.getSize() == 10);
    }
    SECTION("Test if empty"){
        REQUIRE(t.empty() == false);
        t.clear();
        REQUIRE(t.getSize() == 0);
        REQUIRE(t.empty() == true);
    }
}

TEST_CASE("dsstring vector", "[vector]"){
    DSVector<DSString> somevec;
    somevec.push_back("hello");
    somevec.push_back("you");
    somevec.push_back("my");
    somevec.push_back("yes");
    SECTION("Test size"){
        REQUIRE(somevec.getSize() == 4);
    }
    SECTION("Test capacity"){
        REQUIRE(somevec.getCapacity() == 10);
    }
    SECTION("Test access"){
        REQUIRE(somevec[0] == "hello");
        REQUIRE(somevec[1] == "you");
        REQUIRE(somevec[2] == "my");
    }
    somevec.pop_back();
    SECTION("Size after popping"){
        REQUIRE(somevec.getSize() == 3);
    }
}
