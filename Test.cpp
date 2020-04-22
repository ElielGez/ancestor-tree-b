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
    CHECK(T.relation("Ron") == string("father"));                 //normal check
    CHECK(T.find("father") == string("Ron"));                     //normal check
    CHECK(T.relation("David") == string("unrelated"));            //normal check
    CHECK_THROWS_AS(T.addFather("Lee", "David"), std::exception); // already got father
    CHECK(T.relation("Yosef") == string("grandfather"));          //normal check
    CHECK(T.relation("Daniel") == string("great-grandfather"));   //normal check

    CHECK(T.relation("") == string("unrelated"));                 //check relation on empty string
    CHECK_THROWS_AS(T.addFather("Lee", "David"), std::exception); //already got father
    CHECK_THROWS_AS(T.addFather("Lee", "Alon"), std::exception);  //already got father
    CHECK_THROWS_AS(T.addFather("Lee", "Omri"), std::exception);  //already got father
};

//same as test case above with different tree
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

//same as test case above with different tree
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
    CHECK(T.relation("Yahalomit") == string("mother"));           //normal check
    CHECK(T.find("mother") == string("Yahalomit"));               // normal check
    CHECK(T.relation("Michal") == string("unrelated"));           //normal check
    CHECK_THROWS_AS(T.addMother("Lee", "Noa"), std::exception);   // already got mother
    CHECK(T.relation("Yehudit") == string("grandmother"));        //normal check
    CHECK(T.relation("Sigal") == string("great-grandmother"));    // normal check
    CHECK(T.relation("") == string("unrelated"));                 //check relation on empty string
    CHECK_THROWS_AS(T.addMother("Lee", "Rotem"), std::exception); //already got mother
    CHECK_THROWS_AS(T.addMother("Lee", "Hadar"), std::exception); //already got mother
    CHECK_THROWS_AS(T.addMother("Lee", "Noa"), std::exception);   //already got mother
};

//same as test case above with different tree
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
    CHECK(T.relation("Ron") == string("father"));              //normal check
    CHECK(T.relation("Yahalomit") == string("mother"));        //normal check
    CHECK(T.relation("Michal") == string("unrelated"));        //normal check
    CHECK(T.relation("Yehudit") == string("grandmother"));     //normal check
    CHECK(T.relation("Sigal") == string("great-grandmother")); //normal check
    CHECK(T.relation("David") == string("unrelated"));         //normal check doesn't exist
    CHECK(T.relation("Yosef") == string("grandfather"));       //normal check
    CHECK(T.relation("Daniel") == string("great-grandfather"));
    CHECK(T.relation("") == string("unrelated")); //check relation on empty string
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
    CHECK(T.find("mother") == string("Yahalomit")); //normal check
    CHECK(T.find("grandmother") == string("Yehudit"));
    CHECK(T.find("great-grandmother") == string("Sigal"));
    CHECK(T.find("father") == string("Ron"));
    CHECK(T.find("grandfather") == string("Yosef"));
    CHECK(T.find("great-grandfather") == string("Daniel"));
    CHECK_THROWS_AS(T.find("uncle"), std::exception);  //check on relation that doesn't exist
    CHECK_THROWS_AS(T.find("cousin"), std::exception); //check on relation that doesn't exist
    CHECK_THROWS_AS(T.find("nephew"), std::exception); //check on relation that doesn't exist
    CHECK_THROWS_AS(T.find("niece"), std::exception);  //check on relation that doesn't exist
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
    T.remove("Ron");                                   // good remove
    CHECK_THROWS_AS(T.find("father"), std::exception); // there is not father , I deleted him now (above)
    T.addFather("Lee", "Ron");
    T.addFather("Ron", "Daniel");
    T.remove("Daniel");                                           // first remove daniel the grandfather
    T.remove("Ron");                                              //then remove the father , see that the remove of Daniel doesn't effect on Ron (no error)
    CHECK_THROWS_AS(T.find("great-grandfather"), std::exception); // there is no great-grandfather , error
    CHECK_THROWS_AS(T.find("grandfather"), std::exception);       // there is no grandfather , just remove him
    CHECK_THROWS_AS(T.find("father"), std::exception);            // there is no father , just remove him

    //same check as above , but this time on the mother
    T.addMother("Lee", "Yael");
    T.remove("Yael");
    CHECK_THROWS_AS(T.find("mother"), std::exception);
    T.addMother("Lee", "Yael");
    T.addMother("Yael", "Noa");
    T.remove("Yael");                                             // this time remove the mother Yael
    CHECK_THROWS_AS(T.remove("Noa"), std::exception);             //and then try to remove Noa , but it's error , because Noa removed with Yael remove
    CHECK_THROWS_AS(T.find("great-grandmother"), std::exception); // there is no great-grandmother, error
    CHECK_THROWS_AS(T.find("grandmother"), std::exception);       // there is no grandmother , just remove her
    CHECK_THROWS_AS(T.find("mother"), std::exception);            // there is no mother , just remove her

    CHECK_THROWS_AS(T.remove(""), std::exception);       // error try to remove unexisted node
    CHECK_THROWS_AS(T.remove("blabla"), std::exception); // error try to remove unexisted node
    CHECK_THROWS_AS(T.remove("test"), std::exception);   // error try to remove unexisted node
};