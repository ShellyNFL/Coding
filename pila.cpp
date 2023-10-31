//Code by Shelly Naomi Flores Lopez
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct pila{
   int top;
   int topb;
   int elementos[10];
   int balanceo[20];	
};

void push(struct pila *ps, int x);
void pop(struct pila *ps);
void imprimir (struct pila *ps);
void balanceo (struct pila *ps, char []);


int main (){
	struct pila s;
	s.top=-1;
	s.topb=-1;
	int op,valor;
	char entrada[30];
	int tamanio;
	do{
		
	
		printf("INSERTA EL NUMERO DEPENDIENDO DE LA ACCION A REALIZAR:\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.imprimir\n");
		printf("4.balanceo\n");
		printf("5.salir\n");
		scanf("%d",&op);
		
		switch(op){
		
			case 1: //push
				if(s.top<9){
					printf("Dame el elemento a insertar\n");
		        	scanf("%d",&valor);
		        	push(&s, valor);
				}else{
					cout<< "Overflow"<<endl;
				}
				 
		        break;
		    case 2: //pop
		    if(s.top>=0){
			
		    	pop(&s);
			}else{
				cout<< "Underflow"<<endl;
			}
		    	break;
		    case 3:
		    	imprimir(&s);
		    	break;
		    case 4: //balanceo

		    	cout << "Escribe la frase a verificar su balanceo: ";
				scanf("%s",&entrada);
			
				
				balanceo(&s, entrada);
		    	break;
		    
		    default:
		    	printf("Ciao");
		    	
		    	break;
	    }

    }while(op<5);	

}

void push(struct pila *ps, int x){
	ps->top++;

		ps->elementos[ps->top]=x;
		printf("Inserccion exitosa \n");
	
}

void pop (struct pila *ps){
	ps->top--;
	printf("Eliminacion exitosa\n");
		
}

void imprimir (struct pila *ps){
	if (ps->top>=0){
		for (int i=0; i<=ps->top;i++){
			printf("%d \n",ps->elementos[i]); 
		}
	}else{
		printf("La pila esta vacia \n");
	}	
}


void balanceo (struct pila *ps, char entrada[]){
	bool b=true;
	for (int i=0;i<strlen(entrada);i++){
	
				switch (entrada[i]){
					case '{':
						ps->topb++;
						ps->balanceo[ps->topb]='{';	
						break;
					case '[':
						ps->topb++;
						ps->balanceo[ps->topb]='[';
						break;
					case '(':
						ps->topb++;
						ps->balanceo[ps->topb]='(';
						break;
					case '}':
						
						if ((ps->balanceo[ps->topb])=='{'){
							ps->topb--;	
						}else{
							b=false;
						}
						break;
					case ']':
						
						if ((ps->balanceo[ps->topb])=='['){
							ps->topb--;	
							
						}else{
							b=false;
						}
						break;
					case ')':
						
						if ((ps->balanceo[ps->topb])=='('){
							ps->topb--;	
						}else{
							b=false;
						}
						break;						
					default:
						ps->topb--;
						break;		
			}	
	} if (b==true && ps->topb==-1){
		cout<<"Balanceada \n";
	}else{
		cout<<"No balanceada \n";	
	}
}




