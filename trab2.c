#include<string.h>

int roman_to_int_vect(const char* rom, int* processed){
	int size = strlen(rom);
	for(int i=0; i<size;i++){
		switch (rom[i]){
			case 'I':
				processed [i]= 1;
				break;
			case 'V':
				processed [i]= 5;
				break;
			case 'X':
				processed [i]= 10;
				break;
			case 'L':
				processed [i]= 50;
				break;
		}	
	}
	return 0;
}

int processa_romanos(const char* num){
	int size = strlen(num), processed [size];
	int ant = 0;
	int result = 0;
	roman_to_int_vect(num, processed);
	for(int i=0; i<size;i++){
		result += processed[i];
		if(ant < processed[i])
			result -= 2*ant;
		if(size > i+1)
			ant = processed[i];
	}
	return result;
}