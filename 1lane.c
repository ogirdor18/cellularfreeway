#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(void)
{

	FILE*arq;
	arq = fopen("dados.dat","w+");
	
	// rua de 0 a comprimento_rua - 1 
	int comprimento_rua = 50, num_carros = 10, veloc_max = 5, tempo_max = 20;
	double probab = 0.3;
	
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
	int t, dist, pos_min = 0;
	for(t = 0; t < tempo_max; t++)
	{
	
		for(i = 0; i < num_carros; i++)
		{	
			if(pos[i] < pos[pos_min])
			{
				pos_min = i;
			}
		
			dist = pos[(i+1)%num_carros] - pos[i];
			
			if(dist < 0)
			{
				dist += comprimento_rua;
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
		
		printf("t = %d   ", t);
		for(i = 0; i < comprimento_rua; i++)
		{
			if(pos[pos_min] == i)
			{
				printf("%d", veloc[pos_min]);
				pos_min = (pos_min + 1)%num_carros;
			}
			else
			{
				printf(".");
			}
		}
		printf("\n");
		
		
		for(i = 0; i < num_carros; i++)
		{
			pos[i] = (pos[i] + veloc[i])%comprimento_rua;
		}
		
	}
	
	fclose(arq);
}
