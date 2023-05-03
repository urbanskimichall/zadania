#include <gtest/gtest.h>
#include "../function.h"

TEST (STRING_CUTTING, checkIfStringIsNotCut)
{
    //GIVEN
    std::string input{"axb caaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacbac xba"};
    std::string stringToCut{"ab c"};

    //WHEN, THEN
    EXPECT_EQ(getReduced(input, &isGivenStringToCut, stringToCut), "axb caaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacbac xba");
}

TEST (STRING_CUTTING, checkIfStringIsCut)
{
    //GIVEN
    std::string input{"ab caaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacbac ba"};
    std::string stringToCut{"ab c"};

    //WHEN, THEN
    EXPECT_EQ(getReduced(input, &isGivenStringToCut, stringToCut), "aaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacba");
}

TEST (STRING_CUTTING, checkIfStringIsCutFromLeftSideOnly)
{
    //GIVEN
    std::string input{"ab caaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacbac baa"};
    std::string stringToCut{"ab c"};

    //WHEN, THEN
    EXPECT_EQ(getReduced(input, &isGivenStringToCut, stringToCut), "aaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacbac baa");
}

TEST (STRING_CUTTING, checkIfStringIsCutFromRightSideOnly)
{
    //GIVEN
    std::string input{"abx caaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacbac ba"};
    std::string stringToCut{"ab c"};

    //WHEN, THEN
    EXPECT_EQ(getReduced(input, &isGivenStringToCut, stringToCut), "abx caaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacba");
}





