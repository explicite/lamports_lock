#include "stdafx.h"
#include "lamports_lock.h"

const int NUMBER_OF_THREADS = 10;
lamports_lock lock = lamports_lock(NUMBER_OF_THREADS);
void initialize_threads();

int _tmain(int argc, _TCHAR* argv[])
{
	initialize_threads();
	pthread_exit(NULL);
	system("PAUSE");
	return 0;
}

void* writer(void* arg){
	int id = *(int*) &arg;
	for(int i = 0; i < 10; i++){
		lock.lock(id);
		//Your critical section
		lock.unlock(id);
	}
	return 0;
}

void initialize_threads(){
	for(int i = 0; i < NUMBER_OF_THREADS; i++){
		pthread_t thread = pthread_t();
		int rc = pthread_create(&thread, NULL, writer, (void*) i);
		if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
        }
	}
}
