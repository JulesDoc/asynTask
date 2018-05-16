#include "taskloop.h"

void TaskLoop::funType(){

	long long x = 0;
	while (!m_finished && !m_quit){
		std::unique_lock<std::mutex> lck(m_mtx);
		m_cv.wait(lck, [this]{return (m_ready);});
		x += 1;
		if(x==100000000) {
			m_finished = true;
			m_state = "completed";
		}
	}
}



