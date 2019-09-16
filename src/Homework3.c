/*
 ============================================================================
 Name        : Homework3.c
 Author      : Eric Lopes
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "EricLopes.h"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW3!!!");
	if(tests()){
		puts("Tests passed.");
		production(argc,argv);
	}
	else{
		puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
