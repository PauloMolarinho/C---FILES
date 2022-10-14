#include<stdio.h>
#include<stdlib.h>

typedef struct {
char gender, smoker;
int age;
} Cadastro;

int main(){


Cadastro cad;

Cadastro cad2;

int s, cont=0, fum=0, cont2=0, cont3=0;

FILE *file;

file = fopen("respostas.bin","wb");

do{

	printf("\type your gender: (F) ou (M) ");
	fflush(stdin);
	scanf("%c",&cad.gender);
	printf("\nDo you smoke? Y ou N\n");
	fflush(stdin);
	scanf("%c",&cad.smoker);
	printf("\nType your age: ");
	scanf("%d",&cad.age);
	fwrite(&cad, sizeof(Cadastro), 1, file);
	printf("\n\n(( Do you want to add one more person? If yes type 1, if you dont, then type any other number. ))\n\n");
	scanf("%d",&s);
	
}while(s==1);

fclose(file);
FILE *file2;
file2 = fopen("respostas.bin","rb");
system("cls");

while(fread(&cad2,sizeof(Cadastro), 1, file2)){
	printf("\n\ngender: %c\nsmoker?%c\nage:%d",cad2.gender,cad2.smoker,cad2.age);
	if(cad2.smoker == 'Y' || cad2.smoker == 'y'){
		fum++;
}

if(cad2.gender == 'M' && cad2.smoker == 'N' && cad2.age<40){
	cont2++;	
}


if(cad2.gender == 'F' && cad2.smoker == 'Y' && cad2.age>40){
cont3++;	
}




cont++;
}

printf("\n\nsmokers: %d%% \n\nPercentage of non-smoking men under 40 years of age: %d%% \n\nPercentage of female smokers over 40: %d%%",(fum*100)/cont,(cont2*100)/cont,(cont3*100)/cont);
fclose(file2);
}

