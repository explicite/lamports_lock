#pragma once
class lamports_lock
{
public:
	int acc_number(int);
	void lock(int);
	void unlock(int);
	lamports_lock(int);
	lamports_lock(void);
	~lamports_lock(void);
private:
	int number_of_threads;
	bool *flag;
	int *number;
	int max();
};

