#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//JOGO DA FORCA
class game{
 public:

    void name_player( ) {//name
      char name[10];
      cout<<"Seja bem-vindo ao jogo da forca " <<endl;
      cout<<"Regras de funcionamento : " ;
      cout<<"Deves descobrir de qual animal se trata " <<endl;
      cout<<"Tens direito a primeira letra do animal e a 7 tentativas " <<endl;
      cout<<"Caso repitas uma mesma letra errada ou certa, as tentativas nao irao diminuir " <<endl;
      cout<<"Qual seu nome ? "<<endl;
      cin>>name;

      for( int i=0; i<strlen(name); i++){
        cout<<name[i];
       }
      cout<< ", vamos a isso! "<<endl;
    }

    void word(){// colocando as palavras e verificando se são semelhantes ou não ( toda estrutura do jogo)
      name_player();
      int contagem;//contar a ocorrencia de uma variavel
      int tentativa=1;//variavel para contar quantas tentativas restam
      bool letras_iguais=true;
      int indice_letras=1;//para atribuir um indice a uma variavel dentro d
      bool sair_boucle=false;// sair da boucle mae
      bool sair_boucle1=false;// sair da boucle mae
      char palavra[50];//palavra a ser encontrada
      char palavra_player[50];//grupo de palavras digitadas pelo jogador
      char letra;   //letra a ser inserida

      ifstream MyReadFile("palavras.txt.txt");//leitura do ficheiro txt
      string mytext;
      int contagem_txt=0;

      while(MyReadFile>>mytext){
        contagem_txt++;
      }
      MyReadFile.close();
      srand(time(NULL));
      int x = rand()%contagem_txt;//escolher uma palavra aleatoria
      ifstream MyReadFile1("palavras.txt.txt");

      for(int i=1; i<x; i++){
        MyReadFile1>>mytext;
      }
      MyReadFile1.close();
      for(int i=0; i<mytext.size(); i++){
            palavra[i]=mytext[i];
      }
      cout<<endl;
      cout<<"Um animal de: " << strlen(palavra)<< " letras "<<endl;

      cout<<endl;
      string barras[mytext.size()];
      barras[0]=palavra[0];
      cout<<barras[0]<<" ";
      for(int i=1; i<mytext.size(); i++){
           barras[i]="_";
           cout<<barras[i]<<" ";
      }
     cout<<endl;
     cout<<"Entre as letras da palavra : "<<endl;//momento do jogador;

    do{


      for (int i=1; i<=7; i++){
      contagem=0;
      cout<<"Tentativas : "<<tentativa<<"/7"<<endl;
      cout<<endl;
      char repetir_letra='*';
      repetir_letra=letra;
      cin>>letra;
      if(letra==repetir_letra){
            cout<<"Tentou esta letra antes! "<<endl;
            cout<<"Queira refazer ";
            break;
        }
     bool iguais_letra=false;
     for(int j=1; j<strlen(palavra); j++){
            if(palavra[j]==letra ){
                contagem++;
                if(contagem==1){
                    cout<< "A letra '" << letra << "' se encontra na posicao " << j+1 <<endl;
                    indice_letras++;
                    palavra_player[indice_letras]=letra;
                    barras[j]=letra;
                    iguais_letra=true;
                }
                if(contagem==2){
                    cout<< "aussi na posicao " <<j+1 <<endl;
                    indice_letras++;
                    palavra_player[indice_letras]=letra;
                    barras[j]=letra;
                    iguais_letra=true;
                }
                if(contagem==3){
                    cout<< "e" << " na palavra na posicao " << j+1 <<endl;
                    indice_letras++;
                    palavra_player[indice_letras]=letra;
                    barras[j]=letra;
                    iguais_letra=true;
                }

            }


            }
    for(int i=0; i<mytext.size(); i++){
           cout<<barras[i]<<" ";
        }
            cout<<endl;
    if(iguais_letra==true){
                    cout<<"Congrats!!" <<endl;
                    break;
      }else{
            cout<<"Mistake!!" <<endl;
             cout<<"Queira retentar" <<endl;
            tentativa++;
        }
    if(tentativa==7){//perder por tentativas esgotadas
                  sair_boucle=true;//sair da boucle(quebrar ela)
                  break;
                }
    if(indice_letras==strlen(palavra)){
                    sair_boucle1=true;
                    break;
        }

     }
    cout<<endl;
    if(sair_boucle1==true){
            break;
        }
    if(sair_boucle==true){//perder por tentativas esgotadas
            break;//sair da boucle(quebrar ela)
        }

   }while(indice_letras!=strlen(palavra));

       cout<<endl;

    if(indice_letras==strlen(palavra)){
            cout<<"Ganhou!! "<<endl;
            cout<<"A palavra era : ";
            for(int i=0; i<strlen(palavra); i++){
                palavra_player[i]=palavra[i];
                cout<<palavra_player[i];
                }
            }
    else{
         cout<<"Tentativas esgotadas "<<". Perdeu!! "<<endl;
         cout<<"A palavra era: ";
         for(int i=0; i<strlen(palavra); i++){
            palavra_player[i]=palavra[i];
            cout<<palavra_player[i];
         }
       }
   }

};

int main()
{
   game object_call_game;
   object_call_game.word();

}
