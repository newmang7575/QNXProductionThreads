/*
 * ProduceChassis.h
 *
 *  Created on: 16 Jul 2022
 *      Author: Engineer
 */

#ifndef PRODUCECHASSIS_H_
#define PRODUCECHASSIS_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>

#define False 0
#define True 1

class ProduceChassis {
public:
	ProduceChassis();
	virtual ~ProduceChassis();
	void Create(pthread_t myProdThread);
	void installChassis(void);
	bool isChassisAvailable(void);
private:
	static int ChassisCount;
	static void * Start(void * Speed);
};

#endif /* PRODUCECHASSIS_H_ */
