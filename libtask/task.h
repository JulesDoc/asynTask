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
	std::mutex m_mtx;
	std::condition_variable m_cv;	
public:
	Task(){};//User provided default constructor. (could be also asked by "default")
        Task(std::string type);
        
	Task(Task&& other);//Move constructor
	Task& operator=(Task&& other);//Move assignement
	
	virtual ~Task();
	
	void resume();
	void pause();
	void stop();
	
	const int& getID() const;
	const std::string& getState() const;
	const std::string& getType() const;
	
	virtual void funType();//This will be overrided by derived types of tasks
	
	void setState(std::string);
	void showStatus() const;
	const bool& isFinished() const;
	
	//To avoid copies of task objects
	Task(const Task& other) = delete;
	Task& operator=(const Task& other) = delete;

};

#endif /* TASK_H_ */

