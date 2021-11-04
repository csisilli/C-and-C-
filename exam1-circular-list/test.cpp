#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "circular-list.h"
using namespace std;

//const bool identical = true;

// You will likely benefit from referencing 10-linked-list/ while adding
// these tests. You don't need to be nearly as extensive - but you will be
// evaluated on your ability to design good tests.
TEST_CASE("TEST CASE:1, If the list is empty")
{
    // The user did not put any input into the list 
     CircularList<int>lists;
    REQUIRE(lists.size()==0);
    REQUIRE(lists.is_empty()==true);
    
}
TEST_CASE("TEST CASE:2, If the list is empty clear it")
{
    // The user did not put any input into the list it will be cleared
     CircularList<int>lists;
    REQUIRE(lists.size()==0);
    REQUIRE(lists.is_empty()==true);
    list.clear();
}

TEST_CASE("TEST CASE:3, First number in the list loops back to the first")
{
    // If the number is 5 it should loop in a circle back to 5
   CircularList<int> lists;
   REQUIRE(list.is_empty() == false);
    lists.find(5);
    REQUIRE(lists.begin()==5);
    REQUIRE(lists.size()==1);
}
TEST_CASE("TEST CASE:4, First then second number in the list loops back to the first ")
{
    //If there is two numbers the first number always need to be looped back
    CircularList<int> lists;
   REQUIRE(lists.size()==2);
   REQUIRE(list.is_empty() == false);
   lists.find(5);
   lists.find(3);
   REQUIRE(lists.begin()==5);

}
TEST_CASE("TEST CASE:5, First then third number in the list loops back to the first ")
{
    //If there is three numbers the first number always need to be looped back
   CircularList<int> lists;
   REQUIRE(list.is_empty() == false);
   REQUIRE(lists.size()==3);
   lists.find(5);
   lists.find(3);
   lists.find(4);
   REQUIRE(lists.begin()==5);

}
TEST_CASE("TEST CASE:6, First then third number in the list loops back to the first ")
{
    //If there is four numbers the first number always need to be looped back
   CircularList<int> lists;
   REQUIRE(list.is_empty() == false);
   REQUIRE(lists.size()==4);
   lists.find(5);
   lists.find(3);
   lists.find(4);
   lists.find(13);
   REQUIRE(lists.begin()==5);

}
TEST_CASE("TEST CASE:7, First then third number in the list loops back to the first ")
{
    //If there is five numbers the first number always need to be looped back
   CircularList<int> lists;
   REQUIRE(list.is_empty() == false);
   REQUIRE(lists.size()==5);
   lists.find(5);
   lists.find(3);
   lists.find(6);
   lists.find(4);
   lists.find(13);
   REQUIRE(lists.begin()==5);

}
TEST_CASE("TEST CASE:8, First then third number in the list loops back to the first ")
{
    //If there is five numbers the first number will be removed ...
    // and the next number will always need to be looped back
    CircularList<int> lists;
   REQUIRE(list.is_empty() == false);
   lists.find(5);
   lists.find(3);
   lists.find(6);
   lists.find(4);
   lists.find(13);
   REQUIRE(lists.begin()==3);
   REQUIRE(lists.size()==4);

}


