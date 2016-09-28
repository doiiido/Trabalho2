/**
* Programa desenvolvido por Lincoln Abreu Barbosa, 14/0045023
*	https://github.com/doiiido/Trabalho2
**/

#include<string.h>

/**
* roman_to_int_vect processa a string do numero romano convertendo-a em um vetor de inteiros
* dos respectivos algarismos: CXI->[100, 10, 1], retornando -1 se houver algum caractere inválido.
**/

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
			case 'C':
				processed [i]= 100;
				break;
			case 'D':
				processed [i]= 500;
				break;
			case 'M':
				processed [i]= 1000;
				break;
			default:
				return -1;
		}	
	}
	return 0;
}

/** 
*	valid_roman verifica se o número romano dado é válido, ou seja respeita as regras se subtração e adição romanas
*	ele utiliza a roman_to_int_vect pra verificar se nao há caracteres inválidos.
**/

bool valid_roman (const char* rom){
	int size = strlen(rom), processed [size], ant1=3000, ant2=3000, ant3 = 0;
	if(roman_to_int_vect(rom, processed) == 0){
		for(int i=0; i<size;i++){
			if(ant2 < ant1 && ant2 <= processed[i]){
			/**
			*	IXI e semelhantes
			**/
				return false;
			}else if(ant3 == ant2 && ant3 == ant1 && ant3 == processed[i]){ 
			/**
			*	para invalidar 4 caracters iguais
			**/
				return false;
			}else if(ant2 <= ant1 && ant1 < processed[i]){/*IIV*/
				return false;
			}
			else if((ant1 == 5 || ant1 == 50 || ant1 ==500) && ant1 <= processed[i]){
			/**
			*	invalida VX LC DM VV LL DD 
			**/
				return false;
			}
			if(size > i+1){
				ant3 = ant2;
				ant2 = ant1;
				ant1 = processed[i];
			}
		}
		return true;
	}
	return false;
}

/** 
*	utiliza valid_roman e roman_to_int_vect para verificar a validade de um numero romano e transforma-lo em um vetor de inteiros respectivamente,
*	sua função é processar o vetor de inteiros e computar o resultado aplicando as regras de soma e subtração romanas e retornar -1 para
*	algarismos inválidos.
**/

int processa_romanos(const char* num){
	int size = strlen(num), processed [size];
	int ant = 0;
	int result = 0;
	if(valid_roman(num)){
		roman_to_int_vect(num, processed);
		for(int i=0; i<size;i++){
			result += processed[i];
			if(ant < processed[i])
			/**
			*	um pequeno problema encontrado, o algarismo já estava somado ao tentar subtraí-lo, por isso é subtraido 2 vezes
			**/
				result -= 2*ant;
			if(size > i+1)
				ant = processed[i];
		}
		return result;
	}
	return -1;	
}