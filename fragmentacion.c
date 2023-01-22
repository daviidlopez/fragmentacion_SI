#include <stdio.h>
#define TAM 8

void InputArray(const char cadena[], float array[],short tamanio, short *cont);
void OrdenarArrayDesc(float array[], short tamanio);
void SinAlgoritmo(const float bloque[], short cont_bloque, const float proceso[], short cont_proceso);
main() {
	//INICIALIZACION
	float bloque[TAM], proceso[TAM];
	short num_bloque = 0, num_proceso = 0, i = 0;
	
	for (i = 0; i < TAM; i++) {
		bloque[i] = 0;
		proceso[i] = 0;
	}
	//CODE
	InputArray("Bloque", bloque, TAM, &num_bloque);
	InputArray("Proceso", proceso, TAM, &num_proceso);
	
	SinAlgoritmo(bloque, num_bloque, proceso, num_proceso);
	
	return 0;
}

void SinAlgoritmo(const float bloque[], short cont_bloque, const float proceso[], short cont_proceso) {
	float aux_bloque_desc[cont_bloque], aux_proceso_desc[cont_proceso], frag_ex = 0, frag_in = 0;
	short i = 0, j = 0, encontrado = 0;
	for (i = 0; i < cont_bloque; i++)
		aux_bloque_desc[i] = bloque[i];
	for (i = 0; i < cont_bloque; i++)
		aux_proceso_desc[i] = proceso[i];
	
	OrdenarArrayDesc(aux_bloque_desc, cont_bloque);
	OrdenarArrayDesc(aux_proceso_desc, cont_proceso);
	
	
	printf("FI = "); frag_in = 0;
	for (i = 0; i < cont_proceso; i++) {
	j = 0; encontrado = 0;
	do {
		if (aux_proceso_desc[i] <= aux_bloque_desc[j] && aux_bloque_desc > 0) {
			printf("(%.1f - %.1f) + ", aux_bloque_desc[j], aux_proceso_desc[i]);
			frag_in = frag_in + (aux_bloque_desc[j] - aux_proceso_desc[i]);
			aux_bloque_desc[j] = 0;
			encontrado = 1;
		} else
			j++;
	
	} while(!encontrado && j < cont_bloque);
	
	}
	printf("= %.1f \n", frag_in);
	
	//Output Fragmentación externa

	printf("FE = ");
	frag_ex = 0;
	for (i = 0; i < cont_bloque; i++)
		if (aux_bloque_desc[i] > 0) {
			frag_ex += aux_bloque_desc[i];
			printf("%.1f + ", aux_bloque_desc[i]);
		}
	
	printf("= %.1f \n", frag_ex);
	
	//Output Fragmentación total
	printf("FT = %.1f + %.1f = %.1f", frag_in, frag_ex, frag_in + frag_ex);
	
	
	
	return;
}

void InputArray(const char CADENA[], float array[],short tamanio, short *cont) {
	float aux = 0;
	printf("%s 1: ", CADENA);
	scanf("%f", &aux);
	fflush(stdin);
	*cont = 0;
	while (aux > 0 && *cont < tamanio) {
		array[*cont] = aux;
		(*cont)++; //Operator Precedence
		printf("%s %hd: ", CADENA, *cont + 1);
		scanf("%f", &aux);
		fflush(stdin);
	}
	return;
}

void OrdenarArrayDesc(float array[], short tamanio) {
	short i = 0, flag = 0, aux = 0, tope = 0;
	tope = tamanio - 1;
	do {
		flag = 0;
		for (i = 0; i < tope; i++)
			if (array[i] > array[i + 1]) {
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				flag = 1;
			}
	} while(flag);
	return;
}


