#include "task.h"

int Task::s_ID = 0;

Task::Task(std::string type):Task(){
	m_type = type;
	m_ID = s_ID++; //This is on purpose in order to start from 0.
	m_t1 =  nullptr;
	m_quit = false;
	m_ready = true;
	m_finished = false;
	m_state = "running";
	std::cout << "Starting a new Task " << m_type << " with ID = " << m_ID << '\n';
	try{
		m_t1 = new std::thread(&Task::funType, this);
	}
	catch (std::exception& e){
		std::cout << "Standard exception " << e.what() << '\n';
	}

}
//Move constructor
Task::Task(Task&& other){
	m_ID = std::move(other.m_ID);
	m_quit = std::move(other.m_quit);
	m_state = std::move(other.m_state);
	m_type = std::move(other.m_state);
	m_ready = std::move(other.m_ready);
	m_finished = std::move(other.m_finished);
	m_t1 = other.m_t1;
	other.m_t1 = nullptr;

}
//Move assignment
Task& Task::operator=(Task&& other){
	if(&other == this)
		return *this;
	m_ID = std::move(other.m_ID);
	m_quit = std::move(other.m_quit);
	m_state = std::move(other.m_state);
	m_type = std::move(other.m_state);
	m_ready = std::move(other.m_ready);
	m_finished = std::move(other.m_finished);
	m_t1 = other.m_t1;
	other.m_t1 = nullptr;
	return *this;
}

void Task::resume() {
	if (m_state=="paused"){

		m_ready = true;
		std::cout << "The Task " << m_ID << " is resumed" << '\n';
		m_cv.notify_all();
		m_state = "running";
	}
	else std::cout << "Task with ID " << m_ID << " can't be resumed -- see status" << '\n';
}

void Task::pause() {
	if (m_state=="running"){

		m_ready = false;
		std::cout << "The Task "  << m_ID << " is pause" << '\n';
		m_cv.notify_all();
		m_state = "paused";
	}
	else std::cout << "Task with ID " << m_ID << " can't be paused -- see status" << '\n';
}

void Task::stop(){
	if (m_state!="stopped" && m_state!="completed"){

		m_state = "stopped";
		std::cout << "The Task "  << m_ID << " is stopped" << '\n';
		this->Task::~Task();
	}
	else std::cout << "Task with ID " << m_ID << " can't be stopped -- see status" << '\n';
}

void Task::funType(){
//This method will be overrided by derived classes
//Uncomment this if want to have feedback
	/*std::cout << "Dummy Task: doing nothing" << '\n';*/
}

const std::string& Task::getState() const{
	return m_state;
}

void Task::setState(std::string state){
	m_state = state;
}

void Task::showStatus() const{
	std::cout << "----Status of Task type " << getType() << " with ID ";
	std::cout << m_ID << " is: ";
	std::cout << m_state << '\n';
}

const std::string& Task::getType() const{
	return m_type;
}

const int& Task::getID() const{
	return m_ID;
}

const bool& Task::isFinished() const{
	return m_finished;
}

Task::~Task(){
//Resource acquisition is initialization.
	//Avoid task get stuck if exception thrown or function return...
	m_quit = true;
	m_ready = true;
	m_cv.notify_all();
	if(m_t1 && m_t1->joinable()) m_t1->join();
	delete m_t1;
}



