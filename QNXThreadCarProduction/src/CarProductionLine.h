/*
 * CarProductionLine.h
 *
 *  Created on: 16 Jul 2022
 *      Author: Engineer
 */

#ifndef CARPRODUCTIONLINE_H_
#define CARPRODUCTIONLINE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>

#define False 0
#define True 1

class CarProductionLine {
public:
	CarProductionLine();
	virtual ~CarProductionLine();
	void Create(pthread_t myProdThread);
private:
	static int CarsBuilt;
	static void * Start(void * Speed);
};

#endif /* CARPRODUCTIONLINE_H_ */
