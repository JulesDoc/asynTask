#ifndef TASKSLEEP_H_
#define TASKSLEEP_H_

#include "task.h"

class TaskSleep final: public Task{

public:
	TaskSleep():Task("sleep"){};
	~TaskSleep(){};
	void funType() override;
};

#endif /* TASKSLEEP_H_ */
