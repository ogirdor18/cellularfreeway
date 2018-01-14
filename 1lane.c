#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(void){

	FILE*arq;
	arq = fopen("dados.dat","w+");
	
	// rua de 0 a comprimento_rua - 1 
	int comprimento_rua = 100, num_carros = 3, veloc_max = 5, tempo_max = 20, probab = 0.25;
	
	//velocidade: numero de posições que o carro andará num passo
	int pos[num_carros], veloc[num_carros];

	//inicialização
	int i;
	for(i = 0; i < num_carros; i++)
	{
		pos[i] = i*comprimento_rua/num_carros;
		veloc[i] = 0;
	}
	
	//passo
	int t, dist;
	for(t = 0; t < tmax; t++)
	{
		for(i = 0; i < num_carros; i++)
		{	
			//condições de contorno periódicas
			if(pos[i+1] < pos[i])
			{
				dist = comprimento_rua - (pos[i] - pos[i+1]);
			}
			else
			{
				dist = pos[i+1] - pos[i];
			}
			
			if((veloc[i] < veloc_max) && (dist > veloc[i] + 1))
			{
				veloc[i]++;
			}
			else if(dist < veloc[i] + 1)
			{
				veloc[i] = dist - 1;
			}
			if((veloc[i] > 0) && (drand48() < probab))
			{
				veloc[i]--;
			}
		}
		
		for(i = 0; i < num_carros; i++)
		{
			pos[i] += veloc[i];
			if(pos[i] >= comprimento_rua)
			{
				pos[i] -= comprimento_rua;
			}
		}
	}
	
	
	fclose(arq);
}




