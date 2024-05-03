#include <iostream>
#include <string.h>
using namespace std;

void name_player()
{
    char name[10];
    cout<< " qual o seu nome ? ";
    cin>>name;
    for( int i=0; i<strlen(name); i++)
    {
        cout<<name[i];
    }

}


void word()
{
    char palavra[10];
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


}

void word_guess()
{
    word();
    char palavra_player[10];
    cin>>palavra_player[10];
   int i;




}
int main()
{
    word();
}
