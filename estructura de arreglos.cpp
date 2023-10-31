#include <stdio.h>
#include <string.h>
struct alumno {
	int exp;
	float cal[3];
	float promedio;
	};
main()
{
     int i, j;
     float suma=0;
	 struct alumno datos[2]; 
   for (i=0; i<2; i++)
	{
       	printf("Ingresa el expediente de alumno %d: ", i+1);
	 scanf("%d", &datos[i].exp);
		for(j=0; j<3; j++)
		{
		   printf("Ingresa la calificación %d de alumno %d: ", j+1, i+1);
	        	   scanf("%f", &datos[i].cal[j]);
	        	   suma=suma+datos[i].cal[j];
		}		
	datos[i].promedio=suma/3;
	}
	printf("ALUMNO\tEXPEDIENTE\tPROMEDIO\n");
	printf("Mario   \t%d     \t%.2f\n", datos[0].exp, datos[0].promedio);
	printf("Arturo   \t%d     \t%.2f\n", datos[1].exp, datos[1].promedio);
 
}

