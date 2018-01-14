#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){

	FILE*arq;
	arq = fopen("dados.dat","w+");

	int N, L, j, x, y, i, cima, direita;
	double p, z;
	
	p = 0.5;
	N = 50 ;
	L = 10 ;	

	int pos[L][L];

	
	/*	adicionando carros	*/

	/*	0 == sem carro   	*/
	/*	1 == carro para cima	*/
	/*     -1 == carro para direita	*/


	cima   = N/2;
	direita= N/2;


	/*	sorteio inicial de carros e direcoes	*/

	for (j = 0; j < L; j++){

		for (i = 0; i < L; i++){

			z = drand48();
				
			if( z < ( (double)N)/(2*L*L) && cima > 0 ){

				pos[j][i] = 1;
				cima --;

			}			

			else if( z < ( (double)N)/(L*L) && direita > 0 ){

				pos[j][i] = -1;
				direita --;
			}

			else
				pos[j][i] = 0;	
		}
	}

	/*	sorteio carros e direcoes que sobraram	*/

	for ( i = cima; i > 0; i-- ){

		x = (int)drand48()*L;
		y = (int)drand48()*L;

		while( pos[x][y] != 0 ){

			x = (int)drand48()*L;
			y = (int)drand48()*L;
		}

		pos[x][y] = 1;
	}

	for ( i = direita; i > 0; i-- ){

		x = (int)drand48()*L;
		y = (int)drand48()*L;

		while( pos[x][y] != 0 ){

			x = (int)drand48()*L;
			y = (int)drand48()*L;
		}

		pos[x][y] = -1;
	}



	/*	PRINT condicao inicial	*/

	for ( j = 0; j < L; j++ ){

		for ( i = 0; i < L; i++ ){
		
			fprintf( arq, "%d %d %d \n", j, i, pos[j][i]);
		}	for ( j = 0; j < L; j++ ){

		for ( i = 0; i < L; i++ ){

	}


	/*	ITERACOES 	*/



	/* TROCA DE DIRECAO? */
	for( t = 0; t = tf; t++ ){

		
		for ( j = 0; j < L; j++ ){

			for ( i = 0; i < L; i++ ){
			
				z = drand48();
				
				if( z < p ){

					pos[i][j] = -pos[i][j];

				}
			}
	}

	/*	ANDAR PARA CIMA && DI	*/

		

	for ( j = 0; j < L; j++ ){

		for ( i = 0; i < L; i++ ){

			if( pos[i][j] = 1 ){
			
				if( pos[i][j+1] = -1 )


			}

		}
	}





	}
fclose(arq);
}


