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
    cout<<" Seja bem vindo ao jogo da forca " <<endl;
    cout<< " qual o seu nome ? "<<endl;
    cin>>name;

    for( int i=0; i<strlen(name); i++)
    {
        cout<<name[i];
    }
    cout<< " vamos comecar "<<endl;

}

void word()// colocando as palavras e verificando se são semelhantes ou não
{
    name_player();
    int tentativa=1;
    bool iguais=true;
    int indice_letras=0;
    int contagem=0;
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


    for(int i=strlen(palavra); i<=strlen(palavra); i++)
    {
        cout<<" a palavra tem " << i << " letras "<<endl;
    }
    cout<<endl;
 cout<<" entre letras da palavra "<<endl;//momento do jogador;
 do{


                for (int i=1; i<=7; i++)
                {
                    cin>>letra;
                    bool iguais_letra=false;
                    for(int j=0; j<strlen(palavra); j++)
                  {
                     if(letra==palavra_player[j])
                            {
                                for(int l=0; l<strlen(palavra); l++)
                                    if(palavra[l]==letra)
                                cout<<"letra repetida "<<l<<endl;
                            }
                    if(palavra[j]==letra )
                        {


                            cout<< " a letra " << letra << " esta na palavra na posicao " << j+1 <<endl;
                            palavra_player[indice_letras++]=letra;
                            iguais_letra=true;


                            break;

                        }



                  }
                  cout<<contagem;

                    if(iguais_letra==true)
                        {
                            cout<<" esta letra esta presente na palavra" <<endl;
                            break;
                        }
                    else
                        {
                            cout<<" esta letra nao esta presente na palavra" <<endl;
                             tentativa++;


                        }
                    if(indice_letras==strlen(palavra))
                        {
                            break;
                        }


                }

            if(tentativa==7)//perder por tentativas esgotadas
                {
                    break;//sair da boucle(quebrar ela)
                }


   }while(indice_letras!=strlen(palavra));

       cout<<endl;



        if(indice_letras!=0)
            {
                cout<<" voce ganhou "<<endl;
                cout<<" a palavra e :";
                for(int i=0; i<strlen(palavra); i++)
                {
                    palavra_player[i]=palavra[i];
                    cout<<palavra_player[i];

                }
            }

        else
        {   cout<<" tentativas esgotadas "<<" voce perdeu "<<endl;
            cout<<" a palavra e: ";
            for(int i=0; i<strlen(palavra); i++)
                {
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
