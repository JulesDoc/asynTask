#include "task.h"

int Task::s_ID = 0;

Task::Task(std::string type):m_type(type){
	m_ID = s_ID++; //This is on purpose in order to start from 0.
	m_t1 =  nullptr;
	m_quit = false;
	m_ready = true;
	m_finished = false;
	m_state = "running";
	std::cout << "Starting a new Task " << m_type << " with ID = " << m_ID << '\n';
}

const int& Task::getID() const{
	return m_ID;
}
