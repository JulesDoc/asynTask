/*
 * TaksLoop.h
 *
 *  Created on: May 12, 2018
 *      Author: jules
 */

#ifndef TASKRANDOM_H_
#define TASKRANDOM_H_

#include "task.h"

class TaskRandom final : public Task{

public:
	TaskRandom():Task("random"){};
	~TaskRandom(){};
	void funType() override;
};

#endif /* TASKRANDOM_H_ */
