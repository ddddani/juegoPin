#include <stdio.h>
#include <string.h>

int pinCorrect(int pin[]){

	int okPin[5] = {1,2,3,4};
	int found = 1;
	int count = 0;

	while(found == 1 && count < 4){
		if(okPin[count] == pin[count]){count ++;}
		else found = 0;
	}
	return found;
}

int pinCheck(int pin[]){

	static int counter = 0;
	int correct = pinCorrect(pin);

	if(counter < 3 && correct == 1){
		counter = 0;
		return counter;
	}else if(counter < 3 && correct == 0){
		counter ++;
		return counter;
	}else{
		counter = -1;
		return counter;
	}
}


int main(void){
	int count;

	do{
		printf("Escribe el PIN: \n");
		char read[20];
		scanf("%19s", read);
		int pin[4];

		if(strlen(read) != 4){
			printf("El PIN debe contener 4 dígitos");
			continue;
		}

		for(int i = 0; i < 4; i++){
			pin[i] = read[i] - '0';
		}

		count = pinCheck(pin);
		if(count == 0){
			printf("Pin correcto\n");
			count = -1;
		}else if(count != -1){
			printf("Vuelve a intentarlo\n");
		}else{
			printf("Demasiados errores\n");
		}
	}while(count != -1);
	return 0;
}

