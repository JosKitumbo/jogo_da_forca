#include <iostream>
#include <string.h>
using namespace std;

void name_player( ) //name
{
   char name[10];
    cout<< " qual o seu nome ? ";
    cin>>name;
    for( int i=0; i<strlen(name); i++)
    {
        cout<<name[i];
    }

}


void word()// colocando as palavras e verificando se são semelhantes ou não
{
    bool iguais=true;
    bool iguais_letra=false;
    int contagem=0;
    char palavra[10];//palavra a ser encontrada
    char palavra_player[10];
    char letra;//jogada
    cout<<" Seja bem vindo ao jogo da forca " <<endl;
    do
    {
        cout<<"entre uma palavra com pelo menos duas letras"<<endl;
        cin>>palavra;
        cout<<endl;
        if(strlen(palavra)<2)
        {
            cout<<"numero de letras insuficiente"<<endl;
        }
        else
         {
            cout<<" palavra aceite "<<endl;
        }

        cout<<endl;

    }while(strlen(palavra)<2);

    for(int i=strlen(palavra); i<=strlen(palavra); i++)
    {
        cout<<" a palavra tem " << i << " letras "<<endl;
    }


//player guessing the letters
   do
    {
        cout<<" entre letras da palavra "<<endl;
        do{

        cin>>letra;
        cout<<endl;
            for(int i=0; i<=strlen(palavra); i++)
            {

                if(palavra[i]==letra)
                {
                    cout<< " a letra " << letra << " esta na palavra na posicao " << i <<endl;
                    palavra_player[i]=letra;
                    iguais_letra=true;


                }

            }

            if(iguais_letra==true)
            {
                cout<<" esta letra esta presente na palavra" <<endl;
            }
            else
            {
                cout<<" esta letra nao esta presente na palavra" <<endl;
                contagem++;

            }
            if(contagem==7)
            {
                cout<<"tentativas esgotadas " <<endl;
                break;
            }
                for(int i=0; i<=strlen(palavra); i++)
            {
                cout<<palavra_player[i]<<endl;
            }

        }while(strlen(palavra_player)+1!=strlen(palavra));


        if(strlen(palavra_player)==strlen(palavra))
        {
            cout<<"numero de letras suficiente"<<endl;
        }
        else
         {
            cout<<" erro no numero de lettras "<<endl;
        }

        cout<<endl;

    }while(strlen(palavra_player)!=strlen(palavra));

        for(int i=0; i<strlen(palavra); i++)
    {
           if(palavra_player[i]!=palavra[i])
             {
                 iguais=false;
                 break;
             }


    }

    cout<<endl;


   if(iguais==false)
   {
       cout<<" voce perdeu ";
   }
   else
    cout<<" voce ganhou ";




}



int main()
{

    word();
}
