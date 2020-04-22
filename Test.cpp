#include "FamilyTree.hpp"
#include "doctest.h"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test add father") {
    Tree T("Lee");
    T.addFather("Lee", "Ron");
    T.addFather("Ron", "Yosef");
    T.addFather("Yosef", "Daniel");
    CHECK(T.relation("Ron") == string("father"));
    CHECK(T.find("father") == string("Ron"));
    CHECK(T.relation("David") == string("unrelated"));
    CHECK_THROWS_AS(T.addFather("Lee", "David"), std::exception);
    CHECK(T.relation("Yosef") == string("grandfather"));
    CHECK(T.relation("Daniel") == string("great-grandfather"));
    CHECK(T.relation("") == string("unrelated"));
    CHECK_THROWS_AS(T.addFather("Lee", "David"), std::exception);
    CHECK_THROWS_AS(T.addFather("Lee", "Alon"), std::exception);
    CHECK_THROWS_AS(T.addFather("Lee", "Omri"), std::exception);
};

TEST_CASE("Test add father") {
    Tree T("Liron");
    T.addFather("Liron", "Moshe");
    T.addFather("Moshe", "Yosef");
    T.addFather("Yosef", "Yakov");
    CHECK(T.relation("Moshe") == string("father"));
    CHECK(T.find("father") == string("Moshe"));
    CHECK(T.relation("David") == string("unrelated"));
    CHECK_THROWS_AS(T.addFather("Lee", "David"), std::exception);
    CHECK(T.relation("Yosef") == string("grandfather"));
    CHECK(T.relation("Yakov") == string("great-grandfather"));
    CHECK(T.relation("") == string("unrelated"));
    CHECK_THROWS_AS(T.addFather("Liron", "David"), std::exception);
    CHECK_THROWS_AS(T.addFather("Liron", "Alon"), std::exception);
    CHECK_THROWS_AS(T.addFather("Liron", "Omri"), std::exception);
};

TEST_CASE("Test add father") {
    Tree T("Noffar");
    T.addFather("Noffar", "Israel");
    T.addFather("Israel", "Dovi");
    T.addFather("Dovi", "Itay");
    T.addFather("Itay", "Yair");
    T.addFather("Yair", "Raz");
    CHECK(T.relation("Israel") == string("father"));
    CHECK(T.find("father") == string("Israel"));
    CHECK(T.relation("David") == string("unrelated"));
    CHECK_THROWS_AS(T.addFather("Noffar", "David"), std::exception);
    CHECK(T.relation("Dovi") == string("grandfather"));
    CHECK(T.relation("Itay") == string("great-grandfather"));
    CHECK(T.relation("Yair") == string("great-great-grandfather"));
    CHECK(T.relation("Raz") == string("great-great-great-grandfather"));
    CHECK(T.relation("") == string("unrelated"));
    CHECK_THROWS_AS(T.addFather("Noffar", "David"), std::exception);
    CHECK_THROWS_AS(T.addFather("Noffar", "Alon"), std::exception);
    CHECK_THROWS_AS(T.addFather("Noffar", "Omri"), std::exception);
};

TEST_CASE("Test add mother") {
    Tree T("Lee");
    T.addMother("Lee", "Yahalomit");
    T.addMother("Yahalomit", "Yehudit");
    T.addMother("Yehudit", "Sigal");
    CHECK(T.relation("Yahalomit") == string("mother"));
    CHECK(T.find("mother") == string("Yahalomit"));
    CHECK(T.relation("Michal") == string("unrelated"));
    CHECK_THROWS_AS(T.addMother("Lee", "Noa"), std::exception);
    CHECK(T.relation("Yehudit") == string("grandmother"));
    CHECK(T.relation("Sigal") == string("great-grandmother"));
    CHECK(T.relation("") == string("unrelated"));
    CHECK_THROWS_AS(T.addMother("Lee", "Rotem"), std::exception);
    CHECK_THROWS_AS(T.addMother("Lee", "Hadar"), std::exception);
    CHECK_THROWS_AS(T.addMother("Lee", "Noa"), std::exception);
};
TEST_CASE("Test add mother") {
    Tree T("Liron");
    T.addMother("Liron", "Miri");
    T.addMother("Miri", "Moran");
    T.addMother("Moran", "Shlomit");
    CHECK(T.relation("Miri") == string("mother"));
    CHECK(T.find("mother") == string("Miri"));
    CHECK(T.relation("Michal") == string("unrelated"));
    CHECK_THROWS_AS(T.addMother("Lee", "Noa"), std::exception);
    CHECK(T.relation("Moran") == string("grandmother"));
    CHECK(T.relation("Shlomit") == string("great-grandmother"));
    CHECK(T.relation("") == string("unrelated"));
    CHECK_THROWS_AS(T.addMother("Liron", "Rotem"), std::exception);
    CHECK_THROWS_AS(T.addMother("Liron", "Hadar"), std::exception);
    CHECK_THROWS_AS(T.addMother("Liron", "Noa"), std::exception);
};

TEST_CASE("Test relation") {
    Tree T("Lee");
    T.addFather("Lee", "Ron");
    T.addFather("Ron", "Yosef");
    T.addFather("Yosef", "Daniel");
    T.addMother("Lee", "Yahalomit");
    T.addMother("Yahalomit", "Yehudit");
    T.addMother("Yehudit", "Sigal");
    CHECK(T.relation("Ron") == string("father"));
    CHECK(T.relation("Yahalomit") == string("mother"));
    CHECK(T.relation("Michal") == string("unrelated"));
    CHECK(T.relation("Yehudit") == string("grandmother"));
    CHECK(T.relation("Sigal") == string("great-grandmother"));
    CHECK(T.relation("David") == string("unrelated"));
    CHECK(T.relation("Yosef") == string("grandfather"));
    CHECK(T.relation("Daniel") == string("great-grandfather"));
    CHECK(T.relation("") == string("unrelated"));
    CHECK(T.relation("Alon") == string("unrelated"));
    CHECK(T.relation("Hadar") == string("unrelated"));
    CHECK(T.relation("Yael") == string("unrelated"));
};
TEST_CASE("Test relation") {
    Tree T("Liron");
    T.addMother("Liron", "Miri");
    T.addMother("Miri", "Moran");
    T.addMother("Moran", "Shlomit");
    T.addFather("Liron", "Moshe");
    T.addFather("Moshe", "Yosef");
    T.addFather("Yosef", "Yakov");
    CHECK(T.relation("Miri") == string("mother"));
    CHECK(T.relation("Moran") == string("grandmother"));
    CHECK(T.relation("Shlomit") == string("great-grandmother"));
    CHECK(T.relation("") == string("unrelated"));
    CHECK(T.relation("Yosef") == string("grandfather"));
    CHECK(T.relation("Yakov") == string("great-grandfather"));
};

TEST_CASE("Test find") {
    Tree T("Lee");
    T.addFather("Lee", "Ron");
    T.addFather("Ron", "Yosef");
    T.addFather("Yosef", "Daniel");
    T.addMother("Lee", "Yahalomit");
    T.addMother("Yahalomit", "Yehudit");
    T.addMother("Yehudit", "Sigal");
    CHECK(T.find("mother") == string("Yahalomit"));
    CHECK(T.find("grandmother") == string("Yehudit"));
    CHECK(T.find("great-grandmother") == string("Sigal"));
    CHECK(T.find("father") == string("Ron"));
    CHECK(T.find("grandfather") == string("Yosef"));
    CHECK(T.find("great-grandfather") == string("Daniel"));
    CHECK_THROWS_AS(T.find("uncle"), std::exception);
    CHECK_THROWS_AS(T.find("cousin"), std::exception);
    CHECK_THROWS_AS(T.find("nephew"), std::exception);
    CHECK_THROWS_AS(T.find("niece"), std::exception);
    CHECK_THROWS_AS(T.find(""), std::exception);
};

TEST_CASE("Test find") {
    Tree T("Liron");
    T.addFather("Liron", "Omer");
    T.addFather("Omer", "Yosef");
    T.addFather("Yosef", "Daniel");
    T.addMother("Liron", "Ronit");
    T.addMother("Ronit", "Mirav");
    T.addMother("Mirav", "Sigal");
    CHECK(T.find("mother") == string("Ronit"));
    CHECK(T.find("grandmother") == string("Mirav"));
    CHECK(T.find("great-grandmother") == string("Sigal"));
    CHECK(T.find("father") == string("Omer"));
    CHECK(T.find("grandfather") == string("Yosef"));
    CHECK(T.find("great-grandfather") == string("Daniel"));
    CHECK_THROWS_AS(T.find("uncle"), std::exception);
    CHECK_THROWS_AS(T.find("cousin"), std::exception);
    CHECK_THROWS_AS(T.find("nephew"), std::exception);
    CHECK_THROWS_AS(T.find("niece"), std::exception);
    CHECK_THROWS_AS(T.find(""), std::exception);
};

TEST_CASE("Test remove") {
    Tree T("Lee");
    T.addFather("Lee", "Ron");
    T.remove("Ron");
    CHECK_THROWS_AS(T.find("father"), std::exception);
    T.addFather("Lee", "Ron");
    T.addFather("Ron", "Daniel");
    T.remove("Daniel");
    T.remove("Ron");
    CHECK_THROWS_AS(T.find("great-grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("grandfather"), std::exception);
    CHECK_THROWS_AS(T.find("father"), std::exception);

    T.addMother("Lee", "Yael");
    T.remove("Yael");
    CHECK_THROWS_AS(T.find("mother"), std::exception);
    T.addMother("Lee", "Yael");
    T.addMother("Yael", "Noa");
    T.remove("Yael");
    CHECK_THROWS_AS(T.remove("Noa"), std::exception);
    CHECK_THROWS_AS(T.find("great-grandmother"), std::exception);
    CHECK_THROWS_AS(T.find("grandmother"), std::exception);
    CHECK_THROWS_AS(T.find("mother"), std::exception);
    CHECK_THROWS_AS(T.remove(""), std::exception);
    CHECK_THROWS_AS(T.remove("blabla"), std::exception);
    CHECK_THROWS_AS(T.remove("test"), std::exception);
};