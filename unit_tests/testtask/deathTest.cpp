#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "task.h"

//Verify behavior of the program when a statement cause exit with no-zero code

void funError(){
	Task t("dummy");
	std::cerr << "Unexpected happened...!!" << '\n';
	exit(1);
}


//Test that program quit unexpectely
TEST(test_DeathTest, testExitCode1){

	EXPECT_EXIT(funError(), ::testing::ExitedWithCode(1), "");
}

