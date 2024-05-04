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

class myclass{
public:
void word()// colocando as palavras e verificando se são semelhantes ou não
{

    bool iguais=true;
    int indice_letras=0;
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


 cout<<" entre letras da palavra "<<endl;//momento do jogador;
   do{


                for (int i=1; i<=7; i++)
                {   cout<<" tentativa " <<i<<endl;
                    cin>>letra;
                    contagem++;


                    bool iguais_letra=false;
                    for(int j=0; j<strlen(palavra); j++)
                  {

                        if(palavra[j]==letra)
                        {
                            cout<< " a letra " << letra << " esta na palavra na posicao " << i <<endl;
                            palavra_player[indice_letras++]=letra;
                            iguais_letra=true;
                            break;

                        }


                  }
                    cout<<" indice letra "<<indice_letras <<endl;

                    if(iguais_letra==true)
                        {
                            cout<<" esta letra esta presente na palavra" <<endl;
                            break;
                        }
                    else
                        {
                            cout<<" esta letra nao esta presente na palavra" <<endl;

                        }
                    if(indice_letras==strlen(palavra))
                        {
                            break;
                        }


                }

            if(contagem==7)//perder por tentativas esgotadas
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
            cout<<" tentativas esgotadas "<<" voce perdeu "<<endl;


}

};

int main()
{
    myclass object;
    object.word();
}
