#include "gtest/gtest.h"
#include "task.h"

class MyTaskTest : public ::testing::Test{
protected:
	virtual void SetUp(){

		std::string m_state;
		std::string m_type = "dummy";
		tsk = new Task(m_type);
	}
	virtual void TearDown(){

	}

	Task* tsk;
};

TEST_F(MyTaskTest, testingTaskID){

	int i = tsk->getID();
	EXPECT_LE(0,i);
}

