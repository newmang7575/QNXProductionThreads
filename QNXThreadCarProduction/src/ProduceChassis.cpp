/*
 * ProduceChassis.cpp
 *
 *  Created on: 16 Jul 2022
 *      Author: Engineer
 */

#include "ProduceChassis.h"

int ProduceChassis::ChassisCount;

ProduceChassis::ProduceChassis() {
	// TODO Auto-generated constructor stub

}

ProduceChassis::~ProduceChassis() {
	// TODO Auto-generated destructor stub
}

void ProduceChassis::Create(pthread_t myEngineThread) {
	// TODO Auto-generated constructor stub
	std::cout << "Car Production Create" << std::endl;
	pthread_create(&myEngineThread, NULL, Start, (void *) 123);
}

void * ProduceChassis::Start(void * Speed)
{
	std::cout << "Production Chassis Start" << std::endl;
	for (;;)
	{
		std::cout << "Chassis Build Chassis " << ChassisCount << std::endl;
		sleep(8);

		ChassisCount++;

		//if (!GetEngine()){ std::cout << "Waiting for Engine" << std::endl;}
		//elseif (!GetChassis()){ std::cout << "Waiting for Chassis" << std::endl;}
	}

	std::cout << "Chassis Thread Exit" << std::endl;

	return 0;
}

bool ProduceChassis::isChassisAvailable(void)
{
	if (ChassisCount >0) {return True;}
	else { return False; }
}

void ProduceChassis::installChassis(void)
{
	ChassisCount--;
	std::cout << "Chassis Install Chassis " << ChassisCount << std::endl;
}

