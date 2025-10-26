/*
 * ProduceEngine.cpp
 *
 *  Created on: 16 Jul 2022
 *      Author: Engineer
 */

#include "ProduceEngine.h"

int ProduceEngine::EngineCount;

ProduceEngine::ProduceEngine() {
	// TODO Auto-generated constructor stub
	EngineCount=0;
}

ProduceEngine::~ProduceEngine() {
	// TODO Auto-generated destructor stub
}

void ProduceEngine::Create(pthread_t myEngineThread) {
	// TODO Auto-generated constructor stub
	std::cout << "Car Production Create" << std::endl;
	pthread_create(&myEngineThread, NULL, Start, (void *) 123);
}

void * ProduceEngine::Start(void * Speed)
{
	std::cout << "Production Engine Start" << std::endl;
	for (;;)
	{
		std::cout << "Engine Build Engine " << EngineCount << std::endl;
		sleep(10);

		EngineCount++;

		//if (!GetEngine()){ std::cout << "Waiting for Engine" << std::endl;}
		//elseif (!GetChassis()){ std::cout << "Waiting for Chassis" << std::endl;}
	}

	std::cout << "Engine Thread Exit" << std::endl;

	return 0;
}

bool ProduceEngine::isEngineAvailable(void)
{
	if (EngineCount >0) {return True;}
	else { return False; }
}

void ProduceEngine::installEngine(void)
{
	EngineCount--;
	std::cout << "Engine Install Engine " << EngineCount << std::endl;
}

