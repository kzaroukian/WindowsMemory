// lab10again.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ctrl + f5 to run

// Lab 10 Programming Assignment
// Marc Chesebro and Kaylin Zaroukian

#include "pch.h"
#include <iostream>
#include <Windows.h>

int main()
{
    // get page size
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	printf("Page Size: %lu\n", info.dwPageSize);

	// allocate memory
	void* test = malloc(250000);
	
	MEMORY_BASIC_INFORMATION buf;
	
	// get state
	VirtualQuery(test, &buf, 250000);
	char ans[10];

	if (buf.State == MEM_COMMIT) {
		memcpy(ans, "Committed", 10);
	}
	if (buf.State == MEM_RESERVE) {
		memcpy(ans, "Reserved", 10);
	}
	if (buf.State == MEM_FREE) {
		memcpy(ans, "Free", 10);
	}
	printf("State: %s\n",ans);
	
	free(test);
	printf("Page size %lu \n", info.dwPageSize);

}
