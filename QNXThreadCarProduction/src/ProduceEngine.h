/*
 * ProduceEngine.h
 *
 *  Created on: 16 Jul 2022
 *      Author: Engineer
 */

#ifndef PRODUCEENGINE_H_
#define PRODUCEENGINE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>

#define False 0
#define True 1

class ProduceEngine {
public:
	ProduceEngine();
	virtual ~ProduceEngine();
	void Create(pthread_t myProdThread);
	void installEngine(void);
	bool isEngineAvailable(void);
private:
	static int EngineCount;
	static void * Start(void * Speed);
};

#endif /* PRODUCEENGINE_H_ */
