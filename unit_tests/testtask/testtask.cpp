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
//Using EXPECT for tipical cases
//Using ASSERT for edge cases

//To check proper assignment of unique ID for each task
TEST_F(MyTaskTest, testingTaskID){

	int i = tsk->getID();
	EXPECT_LE(0,i);
}

//To test the init state of a Task is correct.
TEST_F(MyTaskTest, testingState){

	const char * str1= tsk->getState().c_str();
	EXPECT_STREQ("running", str1);
}

//To test if the type of a task if correct
TEST_F(MyTaskTest, testingType){
	const char * str1= tsk->getType().c_str();
	EXPECT_STREQ("dummy", str1);
}

//To test a correct state change from running to paused
TEST_F(MyTaskTest, testingStateChangeToPause){
	tsk->pause();
	const char * str1= tsk->getState().c_str();
	EXPECT_STREQ("paused", str1);
}

//To test a correct state change from paused to resume(running)
TEST_F(MyTaskTest, testingStateChangeToResume){
	tsk->pause();
	tsk->resume();
	const char * str1= tsk->getState().c_str();
	EXPECT_STREQ("running", str1);
}

//To test a proper stop of a task
TEST_F(MyTaskTest, testingStateChangeToStop){
	tsk->stop();
	const char * str1= tsk->getState().c_str();
	EXPECT_STREQ("stopped", str1);
}

//To test that stop is a final state
TEST_F(MyTaskTest, testingStopFinalState){
	tsk->stop();
	tsk->resume();
	const char * str1 = tsk->getState().c_str();
	EXPECT_STRNE("running", str1);
}

