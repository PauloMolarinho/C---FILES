#include<stdio.h>
#include<stdlib.h>
int main(){
	int ra, ra2, x=0, op, s=1, i;
	float nota, nota2[999], soma;
	FILE *file;
	

	do{
			printf("\nChoose an option:\n\n(1)Add Student\n(2)Show Grades\n(3)Calculate the average grade\n(4)Exit");
	        scanf("%d",&op);
	        
		switch(op){
			case 1:
				file = fopen("tabelanotas.txt", "w");
					do{
						
                      printf("\nType the grade: ");
                      scanf("%f", &nota);
                      printf("\nType the student registration: ");
                      scanf("%d", &ra);
                      fprintf(file,"%f %d\n",nota,ra);
                      printf("\nDo you want to add more students? type 0, if you dont, type any number :D\n\n");
                      scanf("%d",&x);
                      
                    }while(x==0);
                   fclose(file);
			break;
				
				case 2:
				   file = fopen("tabelanotas.txt", "r");
					
				   printf("\n\n");
				   i=0;
				while(fscanf(file,"%f %d",&nota2[i], &ra2) != EOF){
				printf("\nRegistration: %d\Grade: %f\n\n",ra2,nota2[i]);
					i++;
				}
					
					
			fclose(file);
					
					
			break;
					
				case 3:
				file = fopen("tabelanotas.txt", "r");
					
				printf("\n\n");
				i=0;
					while(fscanf(file,"%f %d",&nota2[i],&ra2)!=EOF){
						soma += nota2[i];
						i++;
					}
					
				printf("\n\n\nThe average Grade is: %f\n\n\n",(soma/i));
				fclose(file);
				break;
						
			case 4:
			 s=0;
			break;
				
								
		}
		
	}while(s==1);
	
	
}

