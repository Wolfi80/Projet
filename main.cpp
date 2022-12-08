#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
using namespace std;
int game=1;
int nb_allumettes;
char nom[30],niv,prem[30],buffer[256],tour;

void parametre(){   //fonction d'initialisation des paramètres du jeu.

    cout<<"Quel est votre nom ?\n"; //nom du joueur
    cin>>nom;
    cout<<endl;

    do {
        cout<<"Choississez le niveau de l'ordinateur N pour naif ou E pour expert : \n"; //niveau de l'ordinateur
        cin>>niv;
    }
    while (niv!='E' && niv!='e' && niv!='n' && niv!='N');
    cout<<endl;

    if (niv=='E' || niv=='e'){
        niv=1;
    }
    else{
        niv=0;
    }

    do {
        cout<<"Choississez le nombre d'alumettes( entre 1 et 30): \n";                 //nombre d'allumettes
        cin>>buffer;
        nb_allumettes=atoi(buffer);
        if (nb_allumettes==0){
            cout<<"entrée invalide"<<endl<<endl;
        }
    }
    while (nb_allumettes<1 || nb_allumettes>30);
    cout<<endl;

    do {                                                                                //premier à jouer
        cout<<"Quel joueur commence ? "<<nom<<" ou Ordinateur ?\n";
        cin>>prem;
    }
    while (strcmp(prem,nom) && strcmp(prem,"Ordinateur") && strcmp(prem,"ordinateur") && strcmp(prem,"ordi" )&& strcmp(prem,"o") && strcmp(prem,"O"));
    cout<<endl;


    cout<<"Les paramètres de la partie sont définis, vous pouvez commencer à jouer :"<<endl<<endl;
    if (prem=="Ordinateur" || prem=="ordinateur" || prem=="O" || prem=="o" || prem=="Ordi" || prem=="ordi"){    //ne s'affiche pas
        cout<<"C'est à l'ordinateur de commencer.";
        tour=1;
    }
    else{
        cout<<"C'est à "<<prem<<" de commencer."<<endl<<endl;
        tour=0;

    }

}


void affichage(int nb_allumettes){
    int nb_lignes,i,j,derniere_ligne;
    nb_lignes=floor(nb_allumettes/5);
    for (i=1;i<=nb_lignes;i++){
        for (j=1;j<=5;j++){
            cout<<" ! ";
        }
    cout<<endl;
    }
    for (derniere_ligne=1;derniere_ligne<=nb_allumettes%5;derniere_ligne++){
        cout<<" ! ";
    }
    cout<<endl;
}


void tourOrdinateur(){                                 //tour ordinateur
    int choix_allumettes;
    if (niv==0){    //naif
        choix_allumettes=rand() %3 +1;
        cout<<"L'ordinateur a enlevé "<<choix_allumettes<<" allumettes."<<endl<<endl;
        tour=0;

    }

    if(niv==1){ //expert
        if (nb_allumettes%4-1<1){
            choix_allumettes=nb_allumettes%4-1;
            nb_allumettes=nb_allumettes-choix_allumettes;
            tour=0;
        }
    nb_allumettes=nb_allumettes-choix_allumettes;
    affichage(nb_allumettes);
    }

}

void tourJoueur(){                                                   //tour du joueur
    int choix_allumettes;
    cout<<"Entrez le nombre d'allumettes que vous souhaitez enlever : "<<endl;
    cin>>choix_allumettes;
    nb_allumettes=nb_allumettes-choix_allumettes;
    affichage(nb_allumettes);
    tour=1;
}



void jeualterne(int tour){
    if (tour==0){
        tourJoueur();
    }
    if (tour==1){
        tourOrdinateur();
    }
}





int main()
{

    parametre();

    affichage(nb_allumettes);
    while(game==1){
          jeualterne(tour);

    }


    return 0;
}
