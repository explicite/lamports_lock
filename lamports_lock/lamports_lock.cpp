#include "stdafx.h"
#include "lamports_lock.h"

int lamports_lock::acc_number(int arg){
	return number[arg];
}

void lamports_lock::lock(int arg){
	flag[arg] = true;
	number[arg] = max() + 1; 
	flag[arg] = false;

	for(int i = 0; i < number_of_threads; i++){
		while(flag[i]);
		while((number[i] != 0) && (number[i]) < (number[arg]));
	}
}

void lamports_lock::unlock(int arg){
	number[arg] = 0;
}

int lamports_lock::max(){
	int max = number[0];
	for(int i = 0; i < number_of_threads; i++)
		if(number[i] > max)
			max = number[i];
	return max;
}

lamports_lock::lamports_lock(int arg){
	number_of_threads = arg;
	number = new int[arg];
	flag = new bool[arg];

	for(int i = 0; i < arg; i++){
		number[i] = 0;
		flag[i] = false;
	}
}

lamports_lock::lamports_lock(void)
{
}

lamports_lock::~lamports_lock(void)
{
	delete flag;
	delete number;
}
