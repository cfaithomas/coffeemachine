#include <stdio.h>
#include <string.h>

int main() {
    /******************ressources machines**************************/
    int water=400;
    int milk=540;
    int coffee=120;
    int nbcups=0;
    int money=550;
    /*****************parametres machines****************************/
    enum consocoffee {Cafe=5,Eau=10,Gobelets=1};
    enum consolatte{Cafelatte=5,Milklatte=5,Eaulate=10,Gobeletslatte=1};
    enum consocapu{Cafecapu=5,Milkcapu=10,Eaucapu=10,Gobeletscapu=1};
    const float prix=0.40;

    char choice[255];
    printf("Write action (buy,fill,take,remaining,exit:");
    scanf("%s",choice);

    if (strcmp(choice, "buy") == 0)
    {
       int choixbuy=0;
       int dispocoffee=coffee;
       int dispomilk=milk;
       int dispowater=water;
       int dispocups=nbcups;
       int nbcoffee=0;
       int nblatte=0;
       int nbcapu=0;
       /******************************affichage du menu****************************/
        printf("1-espresso");
        printf("2-latte");
        printf("3-cappucino");

       scanf("%d",&choixbuy);
       /***********************************test du choix utilisateur***************/
       switch(choixbuy)
       {
           case 1:
               /************************test disponibilité café********************/

               while(dispocoffee>=Cafe &&dispowater>=Eau && dispocups>=Gobelets)
               {
                   dispocoffee-=Cafe;
                   dispowater-=Eau;
                   dispocups-=Gobelets;
                   nbcoffee++;
               }
               if(nbcoffee>0)
               {
                   printf("I have enough ressources,making your coffee");
               }
               break;
           case 2:
               /***********************test disponibilté late**********************/
               while(coffee>=Cafelatte &&water>=Eaulate && nbcups>=Gobeletslatte&&dispomilk>=Milklatte)
               {
                   dispocoffee-=Cafelatte;
                   dispowater-=Eaulate;
                   dispocups-=Gobeletslatte;
                   dispomilk-=Milklatte;
                   nblatte++;
               }
               if(nblatte>0)
               {
                   printf("I have enough ressources,making your latte");
               }
               break;

           case 3:
               /**********************test disponibilité capuccino*****************/
               while(coffee>=Cafecapu &&water>=Eaucapu && nbcups>=Gobeletscapu&&dispomilk>=Milkcapu)
               {
                   dispocoffee-=Cafecapu;
                   dispowater-=Eaucapu;
                   dispocups-=Gobeletscapu;
                   dispomilk-=Milklatte;
                   nblatte++;
               }
               if(nbcapu>0)
               {
                   printf("I have enough ressources,making your capuccino");
               }
               break;


       }
    }
    else
    if (strcmp(choice, "fill") == 0)
    {
        printf("fill");
    }
    else
    if (strcmp(choice, "take") == 0)
    {
        printf("take");
    }
    else
    if(strcmp(choice,"remaining"))
    {


      /*********affichage des restants**************************************/
       printf("%d of water",water);
       printf("%d of milk",milk);
       printf("%d of coffee beans",coffee);
       printf("%d of disposable cups");
       printf("%d of money",money);
    }
    else
    if (strcmp(choice, "exit") == 0)
    {
        return 0;
    }


}