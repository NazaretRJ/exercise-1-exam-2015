/* ejercicio 1 del examen de febrero de 2015
  Dada la especificación de SecuenciaEnteros, se quiere implementar un método llamado Topk 
 que devuelva una nueva secuencia de enteros que contenga la selección de los k mayores elementos ordenados de mayor a menor 
 a partir de la secuencia de enteros original. La secuencia de enteros original no debe cambiar tras la ejecución de este método.
En caso de que k = total_utilizados, se extraen todos los elementos ordenados.
 Ejemplo: el Topk con k = 4 de {4,2,-3,8,10,0,6,4} devuelve {10,8,6,4}.  */
 
 #include<iostream>
 using namespace std;
 
 class SecuenciaEnteros {
private: 
static const int TAMANIO = 50; 
char vector_entero[TAMANIO]; 
int total_utilizados; 

public: 
SecuenciaEnteros(){
	total_utilizados=0;
 } 
int TotalUtilizados(){ 
return total_utilizados;
}
 int Capacidad(){ 
  return TAMANIO;
}
void Aniade_Enteros(int nuevo){ 
   if (total_utilizados < TAMANIO){
    	vector_entero[total_utilizados] = nuevo; 
		total_utilizados++;
	}
} 
int Elemento(int indice){ 
 return vector_entero[indice]; 
} 
void Elimina (int posicion){ 
	if (posicion >= 0 && posicion < total_utilizados){ 
		int tope = total_utilizados-1;
		for (int i = posicion ; i < tope ; i++)
			vector_entero[i] = vector_entero[i+1];
			total_utilizados--;
		}
} 


/*Este método ordena los enteros de menor a mayor*/
void Ordena(){
	int izquierda,i;
	int a_desplazar;
	
		for(izquierda=1;izquierda<total_utilizados;izquierda++){
			a_desplazar=vector_entero[izquierda];
				for(i=izquierda;i>0 && a_desplazar < vector_entero[i-1];i--)
					vector_entero[i]=vector_entero[i-1];
			vector_entero[i]=a_desplazar;
		}
}

/*Este método ordena los enteros de mayor a menor*/
void Ordena_Mayor(){
	int izquierda,i;
	int a_desplazar;
	
		for(izquierda=1;izquierda<total_utilizados;izquierda++){
			a_desplazar=vector_entero[izquierda];
				for(i=izquierda; i>0 && a_desplazar > vector_entero[i-1] ;i--){
					vector_entero[i]=vector_entero[i-1];
				}
			vector_entero[i]=a_desplazar;
		}
}

bool Tope(int tope){
	bool valido=false;
	if(tope>0 && tope < total_utilizados)
		valido=true;
	return valido;
}
int TotalUtilizadosNuevo(int tope){
	bool valido;
	valido=Tope(tope);
	if(valido)
		total_utilizados=tope;
	return total_utilizados;
}
};

int main(){
	const int CENTINELA=-999;
	SecuenciaEnteros cadena_original;
	int tope,numero;
	
	cout<<"Para parar pulsar: "<<CENTINELA;
	do{
		cout<<"\n introduzca un numero: ";
		cin>>numero;
		if(numero!=CENTINELA)
			cadena_original.Aniade_Enteros(numero);
	}while(numero!=CENTINELA);
	
	/* Una opción: que se copie todo la cadena,se ordene y se varíe el total utilizados */
	SecuenciaEnteros cadena(cadena_original);
	
	cout<<"Introduzca el numero tope: ";
	cin>>tope;
	
	cadena.Ordena_Mayor();
	
	int total=cadena.TotalUtilizadosNuevo(tope);
	
	for(int i=0;i<total;i++)
		cout<<cadena.Elemento(i)<<" ";
	
	
}
