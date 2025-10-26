/*
 * CarProductionLine.cpp
 *
 *  Created on: 16 Jul 2022
 *      Author: Engineer
 */

#include "CarProductionLine.h"
#include "ProduceEngine.h"
#include "ProduceChassis.h"

int CarProductionLine::CarsBuilt;

CarProductionLine::CarProductionLine() {
	// TODO Auto-generated constructor stub
	std::cout << "Ctr Car Production" << std::endl;
	CarsBuilt=0;;

}

CarProductionLine::~CarProductionLine() {
	// TODO Auto-generated destructor stub
}

void CarProductionLine::Create(pthread_t myProdThread) {
	// TODO Auto-generated constructor stub
	std::cout << "Car Production Create" << std::endl;
	pthread_create(&myProdThread, NULL, Start, (void *) 123);
}

void * CarProductionLine::Start(void * Speed)
{
	std::cout << "Car Production Start" << std::endl;

	ProduceEngine * myEngine = new ProduceEngine();
	ProduceChassis * myChassis = new ProduceChassis();

	for (;;)
	{
		std::cout << "Car Production Cars Built " << CarsBuilt << std::endl;
		sleep(5);

		if (myEngine->isEngineAvailable() && (myChassis->isChassisAvailable()))
		{
			myEngine->installEngine();
			myChassis->installChassis();
			CarsBuilt++;
		}
		else
		{
			std::cout << "Car Production NO PARTS" << std::endl;
		}

		//if (!GetEngine()){ std::cout << "Waiting for Engine" << std::endl;}
		//elseif (!GetChassis()){ std::cout << "Waiting for Chassis" << std::endl;}
	}

	std::cout << "Car Production Thread Exit" << std::endl;

	return 0;
}


