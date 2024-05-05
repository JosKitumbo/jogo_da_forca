#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



class myclassgame{
public:



    void name_player( ) //name
{
   char name[10];
    cout<<"Seja bem vindo ao jogo da forca (Sobre animais) " <<endl;
    cout<< "Qual seu nome ? "<<endl;
    cin>>name;

    for( int i=0; i<strlen(name); i++)
    {
        cout<<name[i];
    }
    cout<< ", vamos a isso! "<<endl;

}

void word()// colocando as palavras e verificando se são semelhantes ou não
{
    name_player();
    int tentativa=1;
    bool iguais=true;
    int indice_letras=0;
    bool sair_boucle=false;
    bool sair_boucle1=false;
    int terceira_ocorrencia=-1;
    int segunda_ocorrencia=-1;
    char palavra[10];//palavra a ser encontrada
    char palavra_player[10];
    char letra;//jogada
         ifstream MyReadFile("palavras.txt.txt");
         string mytext;
         int contagem_txt=0;

        while(MyReadFile>>mytext)
        {
            contagem_txt++;

        }
          MyReadFile.close();

         srand(time(NULL));
       int x = rand()%contagem_txt;
       ifstream MyReadFile1("palavras.txt.txt");

        for(int i=0; i<=x; i++)
        {
            MyReadFile1>>mytext;
        }
       MyReadFile1.close();
       for(int i=0; i<mytext.size(); i++)
        {
            palavra[i]=mytext[i];

        }
       cout<<endl;
        cout<<"A palavra tem " << strlen(palavra)<< " letras "<<endl;

 cout<<"Entre as letras da palavra : "<<endl;//momento do jogador;
 do{

    for (int i=1; i<=7; i++)
        {    int contagem=0;
            cout<<"Tentativas : "<<tentativa<<"/7"<<endl;
            char repetir_letra=letra;
            cin>>letra;

            if(letra== repetir_letra)
            {
                cout<<"Tentou esta letra antes! "<<endl;
                break;
            }
            bool iguais_letra=false;
            for(int j=0; j<strlen(palavra); j++)
            {
                if(palavra[j]==letra )
                    {   contagem++;
                        if(contagem==1)
                        {
                        cout<< "A letra '" << letra << "' se encontra na posicao " << j+1 <<endl;
                        indice_letras++;
                        palavra_player[indice_letras]=letra;
                        iguais_letra=true;
                        }
                        if(contagem==2)
                        {
                        cout<< "na posicao " <<j+1 <<endl;
                        indice_letras++;
                        palavra_player[indice_letras]=letra;
                        iguais_letra=true;
                        }
                        if(contagem==3)
                        {
                        cout<< "e" << " na palavra na posicao " << j+1 <<endl;
                        indice_letras++;
                        palavra_player[indice_letras]=letra;
                        iguais_letra=true;
                    }
                    }
            }
            if(iguais_letra==true)
                {
                    cout<<"Congrats!!" <<endl;
                    break;
                }
            else
                {
                    cout<<"Mistake!!" <<endl;
                    tentativa++;
                }
            if(tentativa==7)//perder por tentativas esgotadas
                {
                  sair_boucle=true;//sair da boucle(quebrar ela)
                  break;
                }
            if(indice_letras==strlen(palavra))
                {
                    sair_boucle1=true;
                    break;
                }

                }
                  cout<<endl;
                 if(sair_boucle1==true)
                    {
                        break;
                    }
                 if(sair_boucle==true)//perder por tentativas esgotadas
                    {
                        break;//sair da boucle(quebrar ela)
                    }



   }while(indice_letras!=strlen(palavra));

       cout<<endl;


        if(indice_letras==strlen(palavra))
            {
                cout<<"Ganhou!! "<<endl;
                cout<<"A palavra era : ";
                for(int i=0; i<strlen(palavra); i++){
                    palavra_player[i]=palavra[i];
                    cout<<palavra_player[i];
                }
            }else
                {   cout<<"Tentativas esgotadas "<<". Perdeu!! "<<endl;
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
    myclassgame object;
   object.word();

}
