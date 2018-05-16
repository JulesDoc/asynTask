#include "tasksleep.h"

void TaskSleep::funType(){

	for(int i = 0; i < 10000 && !m_quit ; ++i){
		std::unique_lock<std::mutex> lck(m_mtx);
		m_cv.wait(lck, [this]{return (m_ready);});
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	if (!m_quit){
		m_finished = true;
		m_state = "completed";
	}
}



