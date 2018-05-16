#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

#ifndef TASK_H_
#define TASK_H_

class Task{

protected:
	static int s_ID;
	int m_ID;
	std::string m_state;
	std::string m_type;
	
public:
        Task(std::string type);
	virtual ~Task();
	void resume();
	void pause();
	void stop();


};

#endif /* TASK_H_ */

