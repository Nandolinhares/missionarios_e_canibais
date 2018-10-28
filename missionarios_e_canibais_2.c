/*Author: Fernando Linhares
	2018 - UENF*/

#include <stdio.h>
#include <stdlib.h>

/*Declarando variáveis*/
int dmissionarios = 3; //Emissários no lado direito do rio
int emissionarios = 0; //Emissários no lado esquerdo do rio
int dcanibais = 3;     //Canibais no lado direito do rio
int ecanibais = 0;	   //Canibais no lado esquerdo do rio  
int barco = 0;		     //Barco	
int resp1,resp2;			 //Resposta 1 e resposta 2

/*Mostra quantos missionários e canibais estão na esquerda e direita,
	respectivamente*/
void mostra(){
	printf("Direita :: %d Canibais e %d Missionarios\n ",dcanibais,dmissionarios);
	printf("\n\nEsquerda :: %d Canibais e %d Missionarios\n\n",ecanibais,emissionarios);
	printf("Ecanibais :: %d e Emissários :: %d\n",ecanibais, emissionarios);
	//system(" pause");
}

void zerar(){
	resp1 = 0;
	resp2 = 0;
}

/*Apresentação inicial do programa*/
void apresentacao(){
	printf("\n\n-----------PROGRAMA MISSIONÁRIOS E CANIBAIS-----------\n\n");
	printf("Ajude estes 3 canibais e 3 missionarios a atravessarem o rio.\n");
	printf("\n\n-----------REGRAS-----------------\n\n"); 
	printf("1) Nao deixe os canibais em maior numero junto dos missionarios em nenhum dos lados, senao eles comerao os missionarios\n");
	printf("2) O barco deve ter pelo menos 1 passageiro para se locomover!!!\n");
	printf("BOM JOGO\n");
	getchar();
	system("clear");
}

int main(){
	int direita = 1;
	int esquerda = 0;
	apresentacao();
	mostra();

	/*Lado Direito do Rio*/

	do{
		printf(" \n\nLado Direito\n");
		printf("Colocar no barco:\n");
		printf("Missionario = 1\n");
		printf("Canibal     = 2\n");
		printf("Ninguem     = 3\n");
		do{
			do{
				do{
					/*O resp 1 e resp 2 foram iniciados com 0. Portanto, entrarão no While.
						Depois será armazenada um valor na váriável 1 e se esta for menor que 1,
						ou maior que 3, retornará uma resposta Inválida.*/
					while(resp1 < 1 || resp1 > 3){
						scanf("%d",&resp1);
						if (resp1 < 1 || resp1 > 3)
						{
							printf("Opção Inválida! Digite novamente\n");
						}
					}
					/*O resp 1 e resp 2 foram iniciados com 0. Portanto, entrarão no While.
						Depois será armazenada um valor na váriável 1 e se esta for menor que 1,
						ou maior que 3, retornará uma resposta Inválida.*/
					while(resp2 < 1 || resp2 >= 3){
						scanf("%d",&resp2);
						if (resp2 < 1 || resp2 > 3)
						{
							printf("Opção Inválida! Digite novamente\n");
						}  /*Se tiver um valor 3 na resposta 2 e já tiver saído um numero 3 na resposta 1, então será enviada uma mensagem acusando que nãop tem ninguém no barco.*/
						else if (resp2 == 3)
						{
							if (resp1 == 3)
							{
								printf("Pelo menos um passageiro deve ir.\n");
							}
						}
					}

				} while(resp1 == 3 && resp2 == 3); /*Ele fará isso apenas uma vez devido a essa condição.*/

				/*Se a resp 1 recebe 2, então decremento o canibal do lado direito e 
					incremento o do lado esquerdo*/	
				if (resp1 == 2)
				{
					dcanibais--;
					ecanibais++;
				}
				else if (resp1 == 1)
				{
					dmissionarios--;
					emissionarios++;
				}

				if (resp2 == 2)
				{
					dcanibais--;
					ecanibais++;
				}
				else if (resp2 == 1)
				{
					dmissionarios--;
					emissionarios++;
				}

			} while((dmissionarios < 0) && (dmissionarios > 3));/*Fará apenas uma vez*/
		} while((dcanibais < 0) && (dcanibais > 3));

		/*Condição para perda do jogo*/
		if (emissionarios > 0)
			{
				if (ecanibais > emissionarios)
				{
					system("clear");
					mostra();
					printf("Fim de Jogo! Tem mais canibais que emissários.\n");
					break;
				}
				if ((emissionarios == 3) && (ecanibais == 3))
				{
					system("clear");
					mostra();
					printf("Você ganhou!\n");
					break;
				}
			}
			if (dmissionarios > 0)
			{
				if (dcanibais > dmissionarios)
				{
					system("clear");
					mostra();
					printf("Fim de Jogo! Tem mais canibais que emissários.\n");
					break;
				}
			}


		system("clear");
		mostra();
		zerar();

		printf(" \n\nLado Esquerdo\n");
		printf("Colocar no barco:\n");
		printf("Missionario = 1\n");
		printf("Canibal     = 2\n");
		printf("Ninguem     = 3\n");

		do{
			do{
				do{
					while(resp1 < 1 || resp1 > 3){
						scanf("%d",&resp1);
						if (resp1 < 1 || resp1 > 3)
						{
							printf("Opção Inválida! Digite novamente\n");
						}
					}

					while(resp2 < 1 || resp2 > 3){
						scanf("%d",&resp2);
						if (resp2 < 1 || resp2 > 3)
						{
							printf("Opção Inválida! Digite novamente\n");
						}
						else if (resp2 == 3)
						{
							if (resp1 == 3)
							{
								printf("Pelo menos um passageiro deve ir.\n");
							}
						}
					}
				} while(resp1 == 3 && resp2 == 3);

				if(resp1==2){
					ecanibais--;
					dcanibais++;
				}
				else if(resp1==1){
					emissionarios--;
					dmissionarios++;
				}
		 
		 		if(resp2==2){
					ecanibais--;
				  dcanibais++;
				}
				else if(resp2==1){
					emissionarios--;
					dmissionarios++;
				}
			} while((emissionarios < 0) && (emissionarios > 3));/*Condição para executar apenas uma vez*/
		} while((ecanibais < 0) && (ecanibais > 3)); /*Condição para executar apenas uma vez*/

		/*Condição para perda do jogo*/
		  if (emissionarios > 0)
			{
				if (ecanibais > emissionarios)
				{
					system("clear");
					mostra();
					printf("Fim de Jogo! Tem mais canibais que emissários no lado esquerdo.\n");
					break;
				}
				if ((emissionarios == 3) && (ecanibais == 3))
				{
					printf("Você ganhou!\n");
				}
			}
			if (dmissionarios > 0)
			{
				if (dcanibais > dmissionarios)
				{
					system("clear");
					mostra();
					printf("Fim de Jogo! Tem mais canibais que emissários no lado direito.\n");
					break;
				}
			}


		system("clear");
		mostra();
		zerar();	

	} while((emissionarios + ecanibais) != 6);	
}