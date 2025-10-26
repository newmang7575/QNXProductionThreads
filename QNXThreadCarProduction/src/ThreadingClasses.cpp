#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>

#include "CarProductionLine.h"
#include "ProduceEngine.h"
#include "ProduceChassis.h"
using namespace std;

void * Thread1(void * Sem1)
{
	puts("Thread 1");
	sleep(2);
	//while (Sem1 == False)
	//{
	//	sleep (2);
	//puts("\nThread1 Wait on Sem1");
	//}

	puts("Thread 1 Exit");
	return 0;
}

void * Thread2(void * Sem1)
{
	//Semaphore tmpSem1 = (Semaphore)Sem1;
	puts("Thread 2");
	sleep (100);
	//tmpSem1.SetSem1(True);
	puts("Thread 2 Exit");
	return 0;
}

int main() {
	std::cout << "Hello World!!!" << std::endl; // prints Hello World!!!

	//GnSemaphore mySem;
	CarProductionLine * myCarProductionLine = new CarProductionLine();
	ProduceEngine * myProduceEngine = new ProduceEngine();
	ProduceChassis * myProduceChassis = new ProduceChassis();

	//YourClass* pSomeInstance = new YourClass();
	  pthread_t our_thread_id_1;
	  pthread_t our_thread_id_2;
	  pthread_t carProd_thread_id;
	  pthread_t engineProd_thread_id;
	  pthread_t chassisProd_thread_id;

	  myCarProductionLine->Create(carProd_thread_id);
	  myProduceEngine->Create(engineProd_thread_id);
	  myProduceChassis->Create(chassisProd_thread_id);

	  pthread_create(&our_thread_id_1, NULL, Thread1, (void *) 123);
	  pthread_create(&our_thread_id_2, NULL, Thread2, (void *) 123);

	  pthread_join(our_thread_id_1, NULL);
	  pthread_join(our_thread_id_2, NULL);
	  pthread_join(carProd_thread_id, NULL);
	  pthread_join(engineProd_thread_id, NULL);
	  pthread_join(chassisProd_thread_id, NULL);

	return 0;
}
