#include <stdio.h>

//Code by Shelly Naomi Flores López

struct fila {
   int front;
   int rear;
   int elementos[6];
};

void insert(struct fila *,int);
void remove(struct fila *);
void imprimir(struct fila *);
void estacionamiento(struct fila *, int);


main()
{
	struct fila f,cn,cp;
	int n,o;
	
	f.front=0;
	f.rear=0;
	cn.front=0;
	cn.rear=0;
	cp.front=0;
	cp.rear=0;
	do
	{
		printf("Seleccione una opcion:\n1.Insert\n2.Remove\n3.Imprimir\n4.Estacionamiento\n6.Salir\n");
		scanf("%d",&o);
		switch(o)
		{
			case 1:
				printf("Dame el elemento a insertar\n");
              	scanf("%d", &n);
              	insert(&f, n);
				break;
			case 2:
				remove(&f);
				break;
			case 3:
				imprimir(&f);
				break;
			case 4:
				printf("Que auto quieres remover?\n");
				scanf("%d", &n);
				estacionamiento(&f,n);
				break;	
			//case 5:banco(&cn,&cp);break;
			case 6:printf("Adios\n");break;
			default:printf("Opcion no valida\n");break;
		}
	}while(o!=6);
}

void insert(struct fila *pf,int n)
{
	if(pf->rear==5)
		pf->rear=0;
	else
		(pf->rear)++;
	
	if(pf->front==pf->rear)
	{
		//primero avanzo recibo y si ahy overfloe regreso
		printf("Overflow\n");
		if(pf->rear==0)
			pf->rear=5;
		else
			(pf->rear)--;
	}
	else
		pf->elementos[pf->rear]=n;
	
}

void remove(struct fila *pf)
{
	if(pf->front==pf->rear)
		printf("Underflow\n");
	else
	{
		if(pf->front==5)
			pf->front=0;
		else
			(pf->front)++;
	}
	
}

void imprimir(struct fila *pf)
{
	int i=pf->front;
	
	if(pf->front==pf->rear)
		printf("Esta vacio");
	else
	{
		do
		{
			if(i==5)
				i=0;
			else
				i++;
			printf("%d ",pf->elementos[i]);
		}while(i!=pf->rear);	
	}
	printf("\n");
	
}

void estacionamiento(struct fila *pf, int n)
{
	int temp;
	
	do
	{
		if(pf->front==5)
			temp=pf->elementos[0];
		else
			temp=pf->elementos[pf->front+1];
			
		remove(pf);
		if(pf->elementos[pf->front]!=n)
			insert(pf,temp);
		
	}while(pf->elementos[pf->front]!=n);
	
	imprimir(pf);
}
