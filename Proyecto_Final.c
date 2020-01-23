#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tam 50
void Facil (int puntos[tam], int dificultad[tam], int count);
void Medio (int puntos[tam], int dificultad[tam], int count);
void Dificil (int puntos[tam], int dificultad[tam], int count);
void Puntuacion (char usuario[tam][20], int puntos[tam], int dificultad[tam]);
void Ingreso (char pin[10], char usuario[tam][20], int puntos[tam], int dificultad[tam], int count);
void OrdenaDatos (char usuario[tam][20], int puntos[tam], int dificultad[tam]);
void EliminaDatos (char usuario[tam][20], int puntos[tam], int dificultad[tam]);
void ModificaDatos (char usuario[tam][20], int puntos[tam], int dificultad[tam]);
FILE *archivo;
void main()
{
    int op, count=0, puntos[tam]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, dificultad[tam]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char usuario[tam][20], pin[10];
    char FAC[10]={"FACIL"}, MED[10]="MEDI", DIF[10]="DIFI";
    setlocale(LC_ALL,"spanish");
    do
    {
        printf("MENU\n1)Empezar\n2)Puntuación\n3)Salir\nEscoja una opción: ");
        scanf("%d",&op);
        switch(op)
        {
        	case 1:
        		
        		printf("Para escoger una dificultad, escriba su usario y uno de los tres siguientes códigos:\n");
                printf("Facil: FACIL\nMedio:MEDI\nDificil: DIFI\n");
                printf("Nombre de usuario: ");
                fflush(stdin);
                gets(usuario[count]);
                printf("Contrasena: ");
                gets(pin);
                do
                {
            	    if (strcmp(pin,FAC)==0||strcmp(pin, MED)==0||strcmp(pin,DIF)==0)
				    {
				        Ingreso (pin, usuario, puntos, dificultad, count);
				    }
				    else
				    {
				    	printf("Nombre de usuario: ");
    		            fflush(stdin);
    		            gets(usuario[count]);
    		            printf("Contrasena: ");
    		            gets(pin);
					}
				}while(strcmp(pin,FAC)!=0||strcmp(pin, MED)!=0||strcmp(pin,DIF)!=0);
                getch();
            	system("cls");
            break;
            case 2:
            	Puntuacion(usuario,puntos,dificultad);
            	getch();
            	system("cls");
            break;
            case 3:
            	exit(0);
            break;
            default:
            	printf("Opción no valida, regresando a MENU...");
            	getch();
            	system("cls");
            break;
		}
		count++;
    }while (op!=3);
}
void Ingreso (char pin[10], char usuario[tam][20],int puntos[tam], int dificultad[tam], int count)
{
    if(strcmp(pin,"FACIL")==0)
    {
    	printf("Ha elegido la dificultad FACIL\n");
        Facil(puntos, dificultad, count);
    }
    else if (strcmp(pin,"MEDI")==0)
    {
        printf("Ha elegido la dificultad MEDIA\n");
        Medio(puntos, dificultad, count);
    }
    else if (strcmp(pin,"DIFI")==0)
    {
        printf("Ha elegido la dificultad DIFICIL\n");
        Dificil(puntos, dificultad, count);
    }
    main();
    
}
void Facil (int puntos[tam], int dificultad[tam], int count)
{
	int buenas[21]={1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1};//aquie pones las respuestas correctas
    int i,j,k,respondio;
    int pregunta[21]={1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1};
    srand(time(NULL));
	int Selrand;
	char preguntas[25][100]={"pregunta", //AQui van preguntas
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta"};
    char respuestas[25][3][60]={//aqui van respuestas
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"}};
	
	Selrand=rand()%20;
	k=Selrand;
	for (i=0;i<10;i++)
	{
		if(k>20)
		{
			k=0;
		}
		printf("%d  %d  %s\n",i+1,k,preguntas[k]);
		for (j=0;j<3;j++)
		{
			printf("%s\n",respuestas[k][j]);
		}
		printf("Respuesta: ");
		scanf("%d",&respondio);
		if((respondio-1)==buenas[pregunta[k]])
		{
			printf("Correcto\n");
			puntos=puntos+100;
		}
		else
		{
			printf("Incorrecto\n");
		}
		k++;		
	}
	getch();
	system("cls");
}
void Dificil (int puntos[tam], int dificultad[tam], int count)
{
	int buenas[61]={1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,
                    1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,
                    1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2};//aquie pones las respuestas correctas
    int i,j,k,respondio;
    int pregunta[61]={1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,
                    1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,
                    1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2};
    srand(time(NULL));
	int Selrand, op;
	char preguntas[65][100]={"pregunta", 
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta"};
    char respuestas[65][3][60]={//aqui van respuestas
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"}};
	
	Selrand=rand()%20;
	k=Selrand;
	for (i=0;i<30;i++)
	{
		if(k>60)
		{
			k=0;
		}
		printf("%d  %d  %s\n",i+1,k,preguntas[k]);
		for (j=0;j<3;j++)
		{
			printf("%s\n",respuestas[k][j]);
		}
		printf("Respuesta: ");
		scanf("%d",&respondio);
		if((respondio-1)==buenas[pregunta[k]])
		{
			printf("Correcto\n");
			puntos=puntos+100;
		}
		else
		{
			printf("Incorrecto\n");
			puntos=puntos-100;
		}
		k++;		
	}
	getch();
	system("cls");
}
void Medio (int puntos[tam], int dificultad[tam], int count)
{
	int buenas[41]={1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,
                    1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2};//aquie pones las respuestas correctas
    int i,j,k,respondio;
    int pregunta[41]={1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,
                    1,2,0,1,2,1,2,0,1,2,1,2,0,1,2,1,2,0,1,2};
    srand(time(NULL));
	int Selrand, op;
	char preguntas[45][100]={"pregunta", //AQui van preguntas
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta",
                             "pregunta"};
    char respuestas[45][3][60]={//aqui van respuestas
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"},
                               {"R1","R2","R3"}};
	
	Selrand=rand()%40;
	k=Selrand;
	for (i=0;i<20;i++)
	{
		if(k>40)
		{
			k=0;
		}
		printf("%d  %d  %s\n",i+1,k,preguntas[k]);
		for (j=0;j<3;j++)
		{
			printf("%s\n",respuestas[k][j]);
		}
		printf("Respuesta: ");
		scanf("%d",&respondio);
		if((respondio-1)==buenas[pregunta[k]])
		{
			printf("Correcto\n");
			puntos=puntos+100;
		}
		else
		{
			printf("Incorrecto\n");
			puntos=puntos-50;
		}
		k++;		
	}
	getch();
	system("cls");
}
void Puntuacion (char usuario[tam][20],int puntos[tam], int dificultad[tam])
{
	int op, i;
	char DIF[30];
	archivo=fopen("Puntuacion.txt","w");
	do
	{
		OrdenaDatos(usuario, puntos, dificultad);
		printf("\tNOMBRE\t\tDIFICULTAD\t\tPUNTUACION\n\n");
		fputs("\n\tNOMBRE\t\tDIFICULTAD\t\tPUNTUACION\n\n",archivo);
		for(i=0;i<10;i++)
		{
			if(dificultad[i]==0)
			{
				strcpy(DIF,"INDEFINIDO");
			}
			else if(dificultad[i]==1)
			{
				strcpy(DIF,"FACIL");
			}
			else if (dificultad[i]==2)
			{
				strcpy(DIF,"MEDIO");
			}
			else
			{
				strcpy(DIF,"DIFICIL");
			}
			printf("%d.-\t%s\t\t%s\t\t%d\n",i+1,usuario[i],DIF,puntos[i]);
			fprintf(archivo,"%d.-\t%s\t\t%s\t\t%d\n",i+1,usuario[i],DIF,puntos[i]);
		}
		printf("\nQue acción desea realizar\n1. Modificar Datos\n2.Eliminar Datos\n3.Regresar al menu\nElección: ");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				ModificaDatos(usuario, puntos, dificultad);
				getch();
				system("cls");
        	break;
        	case 2:
        		EliminaDatos(usuario, puntos, dificultad);
        		getch();
				system("cls");
			break;
			case 3:
				getch();
				system("cls");
			break;
			default:
				printf("Por favor ingrese una opción valida.");
				getch();
				system("cls");
			break;
		}
	}while(op!=3);
	fclose(archivo);
}
void OrdenaDatos (char usuario[][20],int puntos[], int dificultad[])
{
	char USU[20];
    int num,i,j;
    for (i=0;i<tam;i++)
    {
    	for(j=0;j<tam;j++)
    	{
    		if (puntos[j]<puntos[i])
    		{
    			num=puntos[i];
    			puntos[i]=puntos[j];
    			puntos[j]=num;
    			num=dificultad[i];
    			dificultad[i]=dificultad[j];
    			dificultad[j]=num;
    			strcpy(USU,usuario[i]);
    			strcpy(usuario[i],usuario[j]);
    			strcpy(usuario[j],USU);
			}
		}    
	}
}
void EliminaDatos (char usuario[tam][20], int puntos[tam], int dificultad[tam])
{
	int op, i;
	char DIF[30];
	printf("\tNOMBRE\t\tDIFICULTAD\t\tPUNTUACION\n\n");
	for(i=0;i<10;i++)
	{
		if(dificultad[i]==0)
		{
			strcpy(DIF,"INDEFINIDO");
		}
		else if(dificultad[i]==1)
		{
			strcpy(DIF,"FACIL");
		}
		else if (dificultad[i]==2)
		{
			strcpy(DIF,"MEDIO");
		}
		else
		{
			strcpy(DIF,"DIFICIL");
		}
		printf("%d.-\t%s\t\t%s\t\t%d\n",i+1,usuario[i],DIF,puntos[i]);
	}
	printf("¿Cuál de los datos desea eliminar?\n");
	scanf("%d",&op);
	op=op-1;
	strcpy(usuario[op],"INDEF");
	puntos[op]=0;
	dificultad[op]=0;
	printf("Los datos de la posición %d han sido eliminados...",op+1);
}
void ModificaDatos (char usuario[tam][20], int puntos[tam], int dificultad[tam])
{
	int op, i;
	char DIF[30];
	printf("\tNOMBRE\t\tDIFICULTAD\t\tPUNTUACION\n\n");
	for(i=0;i<10;i++)
	{
		if(dificultad[i]==0)
		{
			strcpy(DIF,"INDEFINIDO");
		}
		else if(dificultad[i]==1)
		{
			strcpy(DIF,"FACIL");
		}
		else if (dificultad[i]==2)
		{
			strcpy(DIF,"MEDIO");
		}
		else
		{
			strcpy(DIF,"DIFICIL");
		}
		printf("%d.-\t%s\t\t%s\t\t%d\n",i+1,usuario[i],DIF,puntos[i]);
	}
	printf("¿Cuál de los datos desea modificar? \n");
	scanf("%d",&op);
	op=op-1;
	printf("Ingrese un nuevo usuario: ");
	fflush(stdin);
	gets(usuario[op]);
	printf("El usuario de la posición %d ha sido modificado...",op+1);
}
