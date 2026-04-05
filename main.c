#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

__attribute__((noreturn)) void usage(const char* name) {
	printf("Usage: %s 'binary number'\n", name);
	exit(1);
}

__attribute__((noreturn)) void die(const char* s){
	fprintf(stderr, "%s\n", s);
	exit(1);
}

size_t _strlen(const char* s){

	size_t res = 0;
	while(*s++ != '\0') res++;
	return res;
}

int to_dec(const char* bin){

	const size_t len = _strlen(bin);
	int sum = 0;

	for(size_t i = 0; i < len; i++){
		int bit = bin[i] - '0';
		sum = sum * 2 + bit;
	}
	return sum;
}

bool valid_input(const char* s){

	while(*s){
		if((*s & ~1) != '0')
			return false;
		s++;
		}
	
	return true;
}

int main(int argc, char** argv){

	if(argc < 2) usage(argv[0]);
	char* bin = argv[1];

	if(!valid_input(bin)) die("Expected a binary number"); 
	const int dec = to_dec(bin);
	printf("Number in decimal form: %i\n", dec);

	return 0;
}
