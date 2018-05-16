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
	bool m_quit;
	bool m_ready;
	bool m_finished;
	std::thread* m_t1;	
public:
        Task(std::string type);
	~Task();
	void resume();
	void pause();
	void stop();
	const int& getID() const;

};

#endif /* TASK_H_ */

