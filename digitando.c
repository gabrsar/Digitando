

//Bibliotecas
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
//Defines!!!

#define clrscr() system("cls")
#define TAM_C 60   //Tamanho maximo de colunas do texto
#define TAM_X 19   //Tamanho maximo de linhas do texto
#define loopExe 20 //Tamanho do loop de vezes que repete o exercico de frases.
#define l_t 2     //tipo da linha, passado para a função linha.
#define ERROS_PER 5
//Declarando funçoes
void frases();                      //Função para digitar frases ex. asdfg asdfg...
void jogo();                        //Função de joguinho... quando aparece uma letra tem 1 seg para apertar.
int linha(int start,int end,int tipo,int pula,int repete);
void creditos();
//Programinha para treinar digitar.
int main(){           
     int opc,x=0,y;
     system("title Digitando0.o 0.1  Desenvolvido por Gabriel Saraiva.");
     
     do{
        clrscr();
        printf("\n Digitand0.o Por Gabriel Saraiva");
        y=linha(0,33,l_t,1,1);
        printf("\n%c  1 - Frase                    %c",y,y);
        printf("\n%c  2 - Jogo                     %c",y,y); 
        printf("\n%c  3 - Sair                     %c",y,y);
        printf("\n%c  4 - Creditos                 %c",y,y);
        y=linha(0,33,l_t,1,1);
        printf("\n Entre com a Opção desejada:");
        scanf("%d",&opc);
        
        if (opc == 1){
           frases();
           x=1;
        }
        else if(opc ==2){
             jogo();
             x=1;
        }
        
        else if(opc==4){
             creditos();
             x=1;
        }
        
     }while(x!=0);
}

void frases(){
     
     //Variaveis Locais
     char digitado[TAM_C];
     char letra;
     int atual=0;
     int ir=0;
     int x,y;
     int hit=0;
     int ret=0;
     int erros=0;
     int acertos=0;
     int passou=0;
     char arquivo[TAM_X][TAM_C]={"asdfg asdfg asdfg asdfg asdfg asdfg asdfg asdfg asdfg asdfg",
                                 "qwert qwert qwert qwert qwert qwert qwert qwert qwert qwert",
                                 "zxcvb zxcvb zxcvb zxcvb zxcvb zxcvb zxcvb zxcvb zxcvb zxcvb",
                                 "çlkjh çlkjh çlkjh çlkjh çlkjh çlkjh çlkjh çlkjh çlkjh çlkjh",
                                 "poiuy poiuy poiuy poiuy poiuy poiuy poiuy poiuy poiuy poiuy",
                                 ";.,mn ;.,mn ;.,mn ;.,mn ;.,mn ;.,mn ;.,mn ;.,mn ;.,mn ;.,mn",
                                 "a baba a baba a baba a baba a baba a baba a baba a baba abb",
                                 "o bobo o bobo o bobo o bobo o bobo o bobo o bobo o bobo obb",
                                 "a baba cuida do bebe, a baba cuida do bebe, a baba cuida do",
                                 "a faca, o vovo, a faca, o ovo, a faca, o vovo, a faca e o v",
                                 "o vovo e a faca o vovo e a faca o vovo e a faca o vovo e a ",
                                 "fazer bolo é simples, basta seguir a receita e ser paciente",
                                 "dinheiro que é bom nois no have, se nois havesse nao estava",
                                 "aqui trabalhando igual uns condenado. abcdefghijlmnopqrstuv",
                                 "aabscddfegfqgwheirjtlzmxncovpbqprosituuyvçxlzkajhb;c.d,emfn",
                                 "açsldkfjgh açsldkfjgh açsldkfjgh açsldkfjgh açsldkfjgh açsl",
                                 "qpwoeiruty qpwoeiruty qpwoeiruty qpwoeiruty qpwoeiruty qpwo",
                                 "z;x.c,vmbn z;x.c,vmbn z;x.c,vmbn z;x.c,vmbn z;x.c,vmbn z;x.",
                                 "qazpl,wsxokmedcijnrfvuhbtgb qazpl,wsxokmedcijnrfvuhbtgb asd"};
     


     //Inicio do Vamo-Ve!
     clrscr();
     do{
         printf("\nDigite o missão em que parou, 0 para começar e 999 para ver todas missões:");
         scanf("%d",&ir);

         if(ir==999){
                     for(x=0;x<TAM_X;x++){
                                          printf("\n %3d - |%s|",x,arquivo[x]);
                     }
                     printf("\n");
         }
     }while(ir==999);
         
     atual=ir;
     
     //Reseta Vars     
     letra='\0';
     ret=0;
     x=0;
     hit=0;
     erros=0;
     acertos=0;
     passou=0;
     
     clrscr();     
     printf("Exercicio %d. ESC para sair e ENTER quando acabar.",ir);
     linha(0,65-16,l_t,1,1);
     for(y=0;y<loopExe;y++){
         printf("\n\n%2d  |%s|\n    |",y,arquivo[atual]);
         
         for(x=0;x<=TAM_C-2;x++){
            letra=getch();
            hit++;
            if (letra==27 ){
                    x=1000;y=1000; // Desativa o do while e o for...
            }
            else if (letra!=27){
                 if(letra == arquivo[atual][x]){
                    digitado[x]=letra;
                    printf("%c",letra);
                    acertos++;
                 }
                 else{
                      //printf("#\a"); //O \a é para emitir sons pelo BeeP do sistema está desativado pois enrosca um pouco o desempenho.
                      printf("#");
                      erros++;
                 }
            }      
         }
         printf("|");
     }
     if (erros>=ERROS_PER || hit<TAM_C){
          printf("\n\nNao Passou, voce cometeu %d erros, acertou apenas %d de %d",erros,acertos,TAM_C);
                         
     }
     else{
          printf("\n\nPassou, voce cometeu %d erros, acertou %d de %d, Parabens!",erros,acertos,TAM_C);
     }
     printf("\n\n\n\n");
     linha(4,65,l_t,1,1);
     getch();


}


//Função do modo jogo!
void jogo(){
     int n_rnd=0; //Numero rand.
     int x=0,x_do=1,tt=0;     //tempo
     float ft,fa,media=0;
     int acertos=0,erros=0,total=0; //Nao precisa nem falar...
     char digitado=0;
     
     //Iniciando o Seerder???O_O do rand (www.Cplusplus.com http://www.cplusplus.com/reference/clibrary/cstdlib/rand.html) Creditos. :)
     srand(time(NULL)); // Pelo jeito avisa que srand vai receber o parametro time null...

     time_t t1,t2;
     t1=time(NULL);
     
     do{
                       
        x_do=1;
        clrscr();
        n_rnd=rand()%49+41 ;
        
        for(x=0;x<38;x++)
                         printf(" "); //Joga caracter no meio da tela!
                         
        printf("%c -> ",n_rnd);        
        digitado = toupper(getch());
        
        if (digitado==n_rnd){
           printf("%c",digitado);
           acertos++;
        }
        else if(digitado==13 || digitado==27){
                             x_do=0;
        }
        else{
           printf("#");
           erros++;
        }
        total++;
        printf("\n");
                                
     }while(x_do!=0);
     t2=time(NULL);
     
     
/*     //Gambiarra para a media funcionar//
     tt=t2-t1;
     ft=tt;             //printf("\n%.2f",ft);
     fa=acertos;        //printf("\n%.2f",fa);
     media=(ft/fa);
     
     EMbora nao esteja exibindo a media, deve ser feito assim ou melhor que isso. hauhauha O_o
*/

     printf("\n\n Você digitou %d teclas em %d segundos.Acertou %d, errou %d.%c\n\n",total-1,tt,acertos,erros,001);
     getch();     
}
     
int linha(int start,int end,int tipo,int pula,int repete){
     int x,y,z;
     printf("\n");
     for(x=0;x<start;x++)printf(" ");
     if(tipo==1) y=176;
          else if(tipo==2) y=177;
               else if(tipo==3) y=178;
                    else if(tipo==4) y=219;
                         else y=176;
                       
      for (z=0;z<repete;z++){                  
         for (x=start;x<end;x++) printf("%c",y);

         if(repete>1)printf("\n");
      }
      return y;
}

void creditos(){

     int x;
     x=001;
     printf("\n\n%c%c%c   Feito por Gabriel Saraiva!!! Esse programa tem 236 linhas   %c%c%c",x,x,x,x,x,x);
     getch();
}




