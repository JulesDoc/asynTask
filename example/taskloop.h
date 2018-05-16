/*
 * TaksLoop.h
 *
 *  Created on: May 12, 2018
 *      Author: jules
 */

#ifndef TASKLOOP_H_
#define TASKLOOP_H_

#include "task.h"

class TaskLoop final: public Task{

public:
	TaskLoop():Task("loop"){};
	~TaskLoop(){};
	void funType() override;
};

#endif /* TAKSLOOP_H_ */
