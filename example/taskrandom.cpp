#include <random>
#include "taskrandom.h"

void TaskRandom::funType(){//This task lasts for a random period

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,100000000);
	int dice;  // generates number in the range n..m

	while (!m_finished && !m_quit){
		std::unique_lock<std::mutex> lck(m_mtx);
		m_cv.wait(lck, [this]{return (m_ready);});
		dice = distribution(generator);
		if(dice == 69) {
			m_finished = true;
			m_state = "completed";
		}
	}

}




