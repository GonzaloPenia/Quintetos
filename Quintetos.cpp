#include <iostream>
#include <cstdlib>
#include "function.h"
#include "rlutil.h"
#include <string.h>

using namespace std;

void opciones (const char*, int, int, bool);
void tiradaDados (int [6]);
int indentificarJugada(int [6]);
void dibujarDados (int, int, int);

int main(){

    int juego =1, y=0, e=0, w=0, s=0,Posy,Posx, num1, key, key1, key2, key3, key4, modo1, modo2, puntosTotales1=0, puntosTotales2=0, ancho=120, alto=30,ronda=0, Fin=0;
    int dado1,Puntos=0,Ganador,PuntosGanador,Caso, PuntosRonda, modojugador, RondaLimite;
    int dados[6], puntoshis[10];
    int TablaPuntuacion[2];
    string jugador1, jugador2, ganadores[10];
    bool empate=false;

    for(int h=0 ; h<10 ; h++){
        puntoshis[h]=0;
        ganadores[h]="";
    }


    rlutil::setBackgroundColor(rlutil::CYAN);
    rlutil::setColor(rlutil::BLACK);
    rlutil::hidecursor();
    do {
        rlutil::cls();
        Sleep(100);
        Recuadro(ancho,alto);               // RECUADRO DEL PROGRAMA
        Printxy("Bienvenido al juego Quinientos",45,12);
        Printxy("Presione ENTER para continuar",45,16);
        Printxy("Alumnos:",3,26);
        Printxy("Juan Pablo Diez",11,27);
        Printxy("Gonzalo Jose Pena Franco",11,28);
        key1 = rlutil::getkey();
        rlutil::cls();

        while(key1==1){
            RecuadroMenu("SELECCIONE EL MODO DE JUEGO",ancho, alto);
            Printxy("-",48,12);
            Printxy("-",48,13);
            opciones("1 Jugador",50,12,y==0);
            opciones("2 Jugadores",50,13,y==1);
            opciones("Salir",50,15,y==3);

            key = rlutil::getkey();//ESTO TE PERMITE MOVERTE POR EL MENU

            switch (key){

            case 14://SUBE
                if(y>0){
                    if(y==3){
                        y--;
                    }
                    y--;
                }
                break;

            case 15://BAJA
                if(y<3){
                    if(y==1){
                        y++;
                    }
                    y++;
                }
                break;

            case 1://ENTER (todo el programa principal se mueve aca)
                rlutil::cls();
                switch(y){

                /*---------------------------------------------------------------------INICIO MODO 1 JUGADOR-------------------------------------------------------------------*/

                case 0://1 JUGADOR
                    modojugador=0;
                    while(modojugador==0){
                        RecuadroMenu("SELECCIONE EL MODO DE JUEGO",ancho, alto);
                        Printxy("-",48,12);
                        Printxy("-",48,13);
                        Printxy("-",48,14);
                        opciones("1 Jugador",50,12,e==0);
                        opciones("Simulacion",50,13,e==1);
                        opciones("Puntuaciones",50,14,e==2);
                        opciones("Salir",50,16,e==4);

                        modo1 = rlutil::getkey();

                        switch (modo1){

                        case 14://SUBE
                            if(e>0){
                                if(e==4){
                                    e--;
                                }
                                e--;
                            }
                            break;

                        case 15://BAJA
                            if(e<4){
                                if(e==2){
                                    e++;
                                }
                                e++;
                            }
                            break;

                        case 1:
                            switch(e){//SELECCIONAR QUE MODO QUIERE ENTRAR O VER LAS MEJORES PUNTUACIONES

                            case 0:// ---------------------------------------------------------------------------------------------------------------------- MODO DE 1 JUGADOR (CON AZAR)

                                rlutil::cls();
                                rlutil::setColor(rlutil::BLACK);
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el nombre del jugador",45,10);
                                rlutil::locate(55,13);
                                cin>>jugador1;
                                Printxy("Ingrese el numero de rondas que desea jugar: ",38,16);
                                cin>>RondaLimite;
                                ronda=0;
                                Fin=0;
                                TablaPuntuacion[1]=0;
                                while (Fin!=1){
                                    rlutil::cls();
                                    ronda++;
                                    PuntosRonda=0;
                                    Sleep(10);
                                    RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],1,PuntosRonda);        //IMPRIMIMOS EL RECUADRO
                                    for (int i=0;i<3;i++){
                                        Posx=20;                        //DIRECCIONES EN X e Y DONDE SE
                                        Posy=12;
                                        Printxy("Presione una tecla para tirar...",45,24);
                                        key3 = rlutil::getkey();
                                        borrarPantalla(5,7,105,18);
                                                                         //EMPEZARAN A DIBUJAR LOS DADOS
                                        tiradaDados(dados);                      //TIRAMOS LOS DADOS
                                        Sleep(100);
                                        for(int j=0 ; j<6 ; j++){                //DIBUJO DE DADOS
                                            dibujarDados2(dados[j],Posx,Posy);
                                            Posx+=15;
                                        }
                                        Puntos=identificarJugada(dados);      //identificarJugada NOS DEVUELVE LOS PUNTOS
                                        RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],i+1,Puntos);
                                        Sleep(100);
                                        if(Puntos>0){                         //ES UNA JUGADA VALIDA
                                            if(PuntosRonda<Puntos){
                                                PuntosRonda=Puntos;           //GUARDAMOS LOS PUNTOS PARA COMPARAR SI SON LOS MAXIMOS DE LA RONDA
                                            }
                                        }
                                        if(Puntos==0){                   //SI SALEN SEIS 6 LOS PUNTOS DE LA RONDA SON = 0
                                            i=3;
                                            PuntosRonda=0;
                                            TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],i+1,Puntos);
                                            Sleep(10);
                                        }
                                        if(Puntos<0){                   //SACASTE ESCALERA
                                            i=3;
                                            rlutil::cls();
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],i+1,Puntos);
                                            Sleep(1000);
                                            TablaPuntuacion[1]=500;
                                            PuntosRonda=0;
                                            Sleep(100);
                                        }

                                    }//FINALIZACION DE LAS 3 TIRADAS i=3
                                    TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                    Printxy("Sumaste ",80,8);
                                    cout<<PuntosRonda<<" puntos en esta ronda";
                                    if (TablaPuntuacion[1]>=500){             //CONDICION PARA QUE EL JUEGO TERMINE
                                        Fin=1;
                                        ganadores[w]=jugador1;                //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                        puntoshis[w]=TablaPuntuacion[1];      //SE GUARDA LA PUNTUACION DEL GANADOR
                                        w++;
                                    }
                                    else {
                                        Printxy("Tiraste tres veces, fin de esta ronda.",40,23);
                                        Printxy("Presione una tecla continuar con la proxima ronda...",40,24);
                                        Printxy("Presione 'q' para salir",10,8);
                                        key4 = rlutil::getkey();              //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                        if (key4==113){//113 ES EL VALOR DE q en ascii
                                            Fin=1;
                                        }
                                    }
                                    if (RondaLimite==ronda){
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida",55,13);
                                        rlutil::locate(47,14);
                                        cout<<"En "<<RondaLimite<<" ronda/as sumaste: "<<TablaPuntuacion[1]<<" puntos.";
                                        Printxy("Has alcanzado el numero maximo de Rondas que habias establecido",33,15);
                                        Printxy("Presione una tecla para salir",49,25);
                                        key3 = rlutil::getkey();
                                        Sleep(1000);
                                        Fin=1;
                                    }
                                }//FIN DEL WHILE DE LA PARTIDA
                                rlutil::cls();
                                Recuadro(ancho,alto);
                                if (TablaPuntuacion[1]>=500){
                                    Printxy("FELICIDADEZ GANASTE",45,14);
                                    rlutil::locate(45,15);
                                    cout<<"En "<<ronda<<" ronda/as sumaste: "<<TablaPuntuacion[1]<<" puntos.";
                                    Printxy("Presione una tecla para salir",49,25);
                                    key3 = rlutil::getkey();
                                    Sleep(1000);
                                }
                                rlutil::cls();

                                break;

                            case 1://// ------------------------------------------------------------------------------------------------------------------MODO DE 1 JUGADOR SIMULADO(SIN AZAR)


                                rlutil::cls();
                                rlutil::setColor(rlutil::BLACK);
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el nombre del jugador",45,10);
                                rlutil::locate(55,13);
                                cin>>jugador1;
                                Printxy("Ingrese el numero de rondas que desea jugar: ",38,16);
                                cin>>RondaLimite;
                                ronda=0;
                                Fin=0;
                                TablaPuntuacion[1]=0;
                                while (Fin!=1){
                                    rlutil::cls();
                                    ronda++;
                                    PuntosRonda=0;
                                    Sleep(10);
                                    RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],1,PuntosRonda);        //IMPRIMIMOS EL RECUADRO
                                    if (ronda==1){
                                        Printxy("Inventa jugadas hasta llegar a 500 puntos.",40,12);
                                        Sleep(3000);
                                    }

                                    for (int i=0;i<3;i++){
                                        Posx=20;                        //DIRECCIONES EN X e Y DONDE SE
                                        Posy=12;
                                        borrarPantalla(5,7,105,18);
                                        inventarDado(dados);
                                        borrarPantalla(5,7,105,18);
                                        Sleep(100);

                                        for(int j=0 ; j<6 ; j++){                //DIBUJO DE DADOS
                                            dibujarDados2(dados[j],Posx,Posy);
                                            Posx+=15;
                                        }
                                        Puntos=identificarJugada(dados);      //identificarJugada NOS DEVUELVE LOS PUNTOS
                                        RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],i+1,Puntos);
                                        Printxy("Presione una tecla para continuar...",40,24);
                                        key3 = rlutil::getkey();
                                        //borrarPantalla(5,7,105,18);
                                        Sleep(100);
                                        if(Puntos>0){                         //ES UNA JUGADA VALIDA
                                            if(PuntosRonda<Puntos){
                                                PuntosRonda=Puntos;           //GUARDAMOS LOS PUNTOS PARA COMPARAR SI SON LOS MAXIMOS DE LA RONDA
                                            }
                                        }
                                        if(Puntos==0){                   //SI SALEN SEIS 6 LOS PUNTOS DE LA RONDA SON = 0
                                            i=3;
                                            PuntosRonda=0;
                                            TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],i+1,Puntos);
                                            Sleep(10);
                                        }
                                        if(Puntos<0){                   //SACASTE ESCALERA
                                            i=3;
                                            Sleep(3000);
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],i+1,Puntos);
                                            TablaPuntuacion[1]=500;
                                            PuntosRonda=0;
                                            Sleep(3000);
                                        }

                                    }//FINALIZACION DE LAS 3 TIRADAS i=3
                                    TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                    Printxy("Sumaste ",80,8);
                                    cout<<PuntosRonda<<" puntos en esta ronda";
                                    if (TablaPuntuacion[1]>=500){             //CONDICION PARA QUE EL JUEGO TERMINE
                                        Fin=1;
                                        ganadores[w]=jugador1;                //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                        puntoshis[w]=TablaPuntuacion[1];      //SE GUARDA LA PUNTUACION DEL GANADOR
                                        w++;
                                    }
                                    else {
                                        Printxy("Tiraste tres veces, fin de esta ronda.",40,23);
                                        Printxy("Presione una tecla continuar con la proxima ronda...",40,24);
                                        Printxy("Presione 'q' para salir",10,8);
                                        key4 = rlutil::getkey();              //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                        if (key4==113){//113 ES EL VALOR DE q en ascii
                                            Fin=1;
                                        }
                                    }
                                    if (RondaLimite==ronda){
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida",55,13);
                                        rlutil::locate(47,14);
                                        cout<<"En "<<RondaLimite<<" ronda/as sumaste: "<<TablaPuntuacion[1]<<" puntos.";
                                        Printxy("Has alcanzado el numero maximo de Rondas que habias establecido",33,15);
                                        Printxy("Presione una tecla para salir",49,25);
                                        key3 = rlutil::getkey();
                                        Sleep(1000);
                                        Fin=1;
                                    }
                                }//FIN DEL WHILE DE LA PARTIDA
                                rlutil::cls();
                                Recuadro(ancho,alto);
                                if (TablaPuntuacion[1]>=500){
                                    Printxy("FELICIDADEZ GANASTE",45,14);
                                    rlutil::locate(45,15);
                                    cout<<"En "<<ronda<<" ronda/as sumaste: "<<TablaPuntuacion[1]<<" puntos.";
                                    Printxy("Presione una tecla para salir",49,25);
                                    key3 = rlutil::getkey();
                                    Sleep(1000);
                                }
                                rlutil::cls();

                                break;

                            case 2://MOSTRAR PUNTOS

                                rlutil::cls();
                                mostrarPuntos(ancho, alto);
                                puntosGanadores(ganadores, puntoshis, ancho,alto);
                                Printxy("Presione una tecla para salir",45,29);
                                key3 = rlutil::getkey();
                                rlutil::cls();

                                break;

                            case 4://SALIR
                                modojugador=1;
                                e=0;
                                key=0;
                                rlutil::cls();

                                break;

                            }//SALE DE SWITCH DE MODO 1 JUGADOR
                            break;
                        }// SALE DEL MODO 1 JUGADOR
                    }//SALE DEL CASE 1 JUGADOR
                    break;

                /*---------------------------------------------------------------------INICIO MODO 2 JUGADORES-------------------------------------------------------------------*/
                case 1://Menu 2 jugadores
                    modojugador=1;
                    while(modojugador==1){
                        RecuadroMenu("SELECCIONE EL MODO DE JUEGO",ancho, alto);
                        Printxy("-",48,12);
                        Printxy("-",48,13);
                        Printxy("-",48,14);
                        opciones("2 Jugadores",50,12,s==0);
                        opciones("Simulacion",50,13,s==1);
                        opciones("Puntuaciones",50,14,s==2);
                        opciones("Salir",50,16,s==4);

                        modo2 = rlutil::getkey();

                        switch (modo2){

                        case 14://SUBE
                            if(s>0){
                                if(s==4){
                                    s--;
                                }
                                s--;
                            }
                            break;

                        case 15://BAJA
                            if(s<4){
                                if(s==2){
                                    s++;
                                }
                                s++;
                            }
                            break;

                        case 1:
                            switch(s){

                            case 0:// ----------------------------------------------------------------------------------------------------------------------- MODO DE 2 JUGADORES(CON AZAR)



                            rlutil::cls();
                                rlutil::setColor(rlutil::BLACK);
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el nombre del jugador 1",45,10);
                                rlutil::locate(50,13);
                                cin>>jugador1;
                                rlutil::cls();
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el nombre del jugador 2",45,10);
                                rlutil::locate(50,13);
                                cin>>jugador2;
                                rlutil::cls();
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el numero de rondas que desea jugar: ",38,10);
                                cin>>RondaLimite;
                                ronda=0;
                                Fin=0;
                                TablaPuntuacion[0]=0;
                                TablaPuntuacion[1]=0;
                                while (Fin!=1){
                                    rlutil::cls();
                                    ronda++;
                                    PuntosRonda=0;
                                    Sleep(10);
                                    RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);//IMPRIMIMOS EL RECUADRO

                                    for (int i=0;i<3;i++){
                                        Posx=20;                                 //DIRECCIONES EN X e Y DONDE SE
                                        Posy=12;

                                        if(i==0){
                                            Printxy("Presione una tecla para tirar...",45,24);
                                            key3 = rlutil::getkey();
                                        }
                                        borrarPantalla(5,7,105,18);
                                        tiradaDados(dados);                     //TIRAMOS LOS DADOS---------------------------------------------------- TIRA DADOS EL JUGADOR 1
                                        borrarPantalla(5,7,105,18);
                                        Sleep(100);
                                        for(int j=0 ; j<6 ; j++){
                                            dibujarDados2(dados[j],Posx,Posy);       //DIBUJO DE DADOS
                                            Posx+=15;
                                        }
                                        Puntos=identificarJugada(dados);      //identificarJugada NOS DEVUELVE LOS PUNTOS
                                        RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],i+1,Puntos);
                                        Sleep(100);
                                        if(Puntos>0){
                                            Printxy("Presione una tecla para continuar...",40,24);
                                            key3 = rlutil::getkey();
                                            borrarPantalla(5,7,105,18);
                                        }

                                        Sleep(100);
                                        if(Puntos>0){                         //ES UNA JUGADA VALIDA
                                            if(PuntosRonda<Puntos){
                                                PuntosRonda=Puntos;           //GUARDAMOS LOS PUNTOS PARA COMPARAR SI SON LOS MAXIMOS DE LA RONDA
                                            }
                                        }
                                        if(Puntos==0){                   //SI SALEN SEIS 6 LOS PUNTOS DE LA RONDA SON = 0
                                            i=3;
                                            PuntosRonda=0;
                                            TablaPuntuacion[0]=(TablaPuntuacion[0]+PuntosRonda);
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);
                                            Sleep(100);
                                        }
                                        if(Puntos<0){                   //SACASTE ESCALERA
                                            i=3;
                                            rlutil::cls();
                                            TablaPuntuacion[0]=500;
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);
                                            PuntosRonda=0;
                                            Sleep(100);
                                        }

                                    }//FINALIZACION DE LAS 3 TIRADAS
                                    TablaPuntuacion[0]=(TablaPuntuacion[0]+PuntosRonda);

                                    Printxy("Fin del turno del jugador 1",50,22);
                                    Printxy("Sumaste ",80,8);
                                    cout<<PuntosRonda<<" puntos en esta ronda";
                                    Sleep(100);
                                    Printxy("Presione cualquier tecla para pasar al siguiente turno",35,25);
                                    Printxy("Presione 'q' para salir",10,8);
                                    key4 = rlutil::getkey();                      //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    if (key4==113){//113 ES EL VALOR DE 'q' en ascii
                                        Fin=1;
                                    }
                                    rlutil::cls();
                                    if (Fin!=1){
                                        Printxy("Presione una tecla para empezar el turno del jugador 2",35,25);
                                        key3 = rlutil::getkey();                    //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    }

                                    rlutil::cls();
                                    PuntosRonda=0;
                                    Sleep(100);
                                    RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],1,PuntosRonda);

                                    for (int i=0;i<3;i++){
                                        Posx=20;                                 //DIRECCIONES EN X e Y DONDE SE
                                        Posy=12;
                                        if(i==0){
                                            Printxy("Presione una tecla para tirar...",45,24);
                                            key3 = rlutil::getkey();
                                        }
                                        borrarPantalla(5,7,105,18);
                                        tiradaDados(dados);                      //TIRAMOS LOS DADOS---------------------------------------------------------TIRA DADOS EL JUGADOR 2
                                        borrarPantalla(5,7,105,18);
                                        Sleep(100);
                                        for(int j=0 ; j<6 ; j++){
                                            dibujarDados2(dados[j],Posx,Posy);       //DIBUJO DE DADOS
                                            Posx+=15;
                                        }
                                        Puntos=identificarJugada(dados);      //identificarJugada NOS DEVUELVE LOS PUNTOS
                                        RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],i+1,Puntos);
                                        Sleep(100);
                                        if(Puntos>0){
                                            Printxy("Presione una tecla para continuar...",40,24);
                                            key3 = rlutil::getkey();
                                            borrarPantalla(5,7,105,18);
                                        }

                                        RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],i+1,Puntos);
                                        Sleep(100);
                                        if(Puntos>0){                         //ES UNA JUGADA VALIDA
                                            if(PuntosRonda<Puntos){
                                                PuntosRonda=Puntos;           //GUARDAMOS LOS PUNTOS PARA COMPARAR SI SON LOS MAXIMOS DE LA RONDA
                                            }
                                        }
                                        if(Puntos==0){                        //SI SALEN SEIS 6 LOS PUNTOS DE LA RONDA SON = 0
                                            i=3;
                                            PuntosRonda=0;
                                            TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                            RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],i+1,Puntos);
                                            Sleep(100);
                                        }
                                        if(Puntos<0){                          //SACASTE ESCALERA
                                            i=3;
                                            rlutil::cls();
                                            RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],i+1,Puntos);
                                            Sleep(100);
                                            TablaPuntuacion[1]=500;
                                            PuntosRonda=0;
                                            Sleep(100);
                                        }

                                    }//FINALIZACION DE LAS 3 TIRADAS
                                    TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                    RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],3,Puntos);
                                    Printxy("Fin del turno del jugador 2",50,22);
                                    Printxy("Sumaste ",80,8);
                                    cout<<PuntosRonda<<" puntos en esta ronda";
                                    Printxy("Presione una tecla para ver las puntuaciones parciales...",36,24);
                                    Printxy("Presione 'q' para salir",10,8);
                                    Printxy("Cualquier otra para continuar jugando",10,10);

                                    key4 = rlutil::getkey();                      //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    if (key4==113){//113 ES EL VALOR DE 'q' en ascii
                                        Fin=1;
                                    }
                                    rlutil::cls();
                                    if (Fin!=1){
                                        RecuadroCambioTurno(ronda, jugador1,jugador2,TablaPuntuacion);
                                        Printxy("Presione una tecla para empezar el turno del jugador 1",35,25);
                                        key3 = rlutil::getkey();                    //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    }

                                    if (TablaPuntuacion[0]>=500&&TablaPuntuacion[1]<500){               //CONDICION PARA QUE EL JUEGO TERMINE
                                        Fin=1;
                                        ganadores[w]=jugador1;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                        puntoshis[w]=TablaPuntuacion[0];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                        w++;
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida.",55,13);
                                        Printxy("Hay un ganador!",45,14);
                                        cout<<jugador1<<" supero los 500 puntos.";
                                        rlutil::locate(47,15);
                                        cout<<"En "<<ronda<<" ronda/as sumaron: ";
                                        rlutil::locate(47,16);
                                        cout<<jugador1<<"  obtuvo: "<<TablaPuntuacion[0]<<" puntos.";
                                        rlutil::locate(47,17);
                                        cout<<jugador2<<"  obtuvo: "<<TablaPuntuacion[1]<<" puntos.";
                                        Sleep(5000);

                                    }
                                    else if(TablaPuntuacion[1]>=500&&TablaPuntuacion[0]<500){
                                        Fin=1;
                                        ganadores[w]=jugador2;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                        puntoshis[w]=TablaPuntuacion[1];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                        w++;
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida.",55,13);
                                        Printxy("Hay un ganador!",45,14);
                                        cout<<jugador2<<" supero los 500 puntos.";
                                        rlutil::locate(47,15);
                                        cout<<"En "<<ronda<<" ronda/as sumaron: ";
                                        rlutil::locate(47,16);
                                        cout<<jugador1<<"  obtuvo: "<<TablaPuntuacion[0]<<" puntos.";
                                        rlutil::locate(47,17);
                                        cout<<jugador2<<"  obtuvo: "<<TablaPuntuacion[1]<<" puntos.";
                                        Sleep(5000);
                                    }
                                    else if(TablaPuntuacion[0]>=500&&TablaPuntuacion[1]>=500){
                                        Fin=1;
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("EMPATE",45,12);
                                        Printxy("Ambos jugadores alcanzaron 500 puntos en la misma ronda",45,13);
                                        rlutil::locate(47,15);
                                        cout<<"En "<<ronda<<" ronda/as sumaron: ";
                                        rlutil::locate(47,16);
                                        cout<<jugador1<<"  obtuvo: "<<TablaPuntuacion[0]<<" puntos.";
                                        rlutil::locate(47,17);
                                        cout<<jugador2<<"  obtuvo: "<<TablaPuntuacion[1]<<" puntos.";
                                        Sleep(5000);
                                        if(TablaPuntuacion[0]>TablaPuntuacion[1]){
                                            ganadores[w]=jugador1;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[0];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                        }
                                        else if(TablaPuntuacion[1]>TablaPuntuacion[0]){
                                            ganadores[w]=jugador2;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[1];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                        }
                                        else if(TablaPuntuacion[1]==TablaPuntuacion[0]){
                                            ganadores[w]=jugador1;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[0];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                            ganadores[w]=jugador2;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[1];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                        }

                                    }
                                    if (RondaLimite==ronda){
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida",55,13);
                                        rlutil::locate(47,14);
                                        cout<<"En "<<RondaLimite<<" ronda/as sumaste: "<<TablaPuntuacion[1]<<" puntos.";
                                        Printxy("Has alcanzado el numero maximo de Rondas que habias establecido",33,15);
                                        Printxy("Presione una tecla para salir",49,25);
                                        key3 = rlutil::getkey();
                                        Sleep(1000);
                                        Fin=1;
                                    }

                                }//FIN DEL WHILE DE LA PARTIDA
                                rlutil::cls();

                                break;


                        case 1:// ------------------------------------------------------------------------------------------------------------------ MODO DE 2 JUGADORES SIMULADO(SIN AZAR)
                                rlutil::cls();
                                rlutil::setColor(rlutil::BLACK);
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el nombre del jugador 1",45,10);
                                rlutil::locate(50,13);
                                cin>>jugador1;
                                rlutil::cls();
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el nombre del jugador 2",45,10);
                                rlutil::locate(50,13);
                                cin>>jugador2;
                                rlutil::cls();
                                Recuadro(ancho,alto);
                                Printxy("Ingrese el numero de rondas que desea jugar: ",38,10);
                                cin>>RondaLimite;
                                ronda=0;
                                Fin=0;
                                TablaPuntuacion[0]=0;
                                TablaPuntuacion[1]=0;
                                while (Fin!=1){
                                    rlutil::cls();
                                    ronda++;
                                    PuntosRonda=0;
                                    Sleep(100);
                                    RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,0);
                                    if (ronda==1){
                                        Printxy("Inventa jugadas hasta llegar a 500 puntos.",40,12);
                                        Sleep(3000);
                                    }

                                    for (int i=0;i<3;i++){
                                        Posx=20;                                 //DIRECCIONES EN X e Y DONDE SE
                                        Posy=12;
                                        borrarPantalla(5,7,105,18);
                                        inventarDado(dados);
                                        borrarPantalla(5,7,105,18);
                                        for(int j=0 ; j<6 ; j++){
                                            dibujarDados2(dados[j],Posx,Posy);       //DIBUJO DE DADOS
                                            Posx+=15;
                                        }
                                        Puntos=identificarJugada(dados);      //identificarJugada NOS DEVUELVE LOS PUNTOS
                                        RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],i+1,Puntos);
                                        rlutil::locate(10,25);
                                        Printxy("Presione una tecla para continuar...",40,24);
                                        key3 = rlutil::getkey();
                                        borrarPantalla(5,7,105,18);
                                        Sleep(100);
                                        if(Puntos>0){                         //ES UNA JUGADA VALIDA
                                            if(PuntosRonda<Puntos){
                                                PuntosRonda=Puntos;           //GUARDAMOS LOS PUNTOS PARA COMPARAR SI SON LOS MAXIMOS DE LA RONDA
                                            }
                                        }
                                        if(Puntos==0){                   //SI SALEN SEIS 6 LOS PUNTOS DE LA RONDA SON = 0
                                            i=3;
                                            PuntosRonda=0;
                                            TablaPuntuacion[0]=(TablaPuntuacion[0]+PuntosRonda);
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);
                                            Sleep(100);
                                        }
                                        if(Puntos<0){                   //SACASTE ESCALERA
                                            i=3;
                                            rlutil::cls();
                                            TablaPuntuacion[0]=500;
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);
                                            PuntosRonda=0;
                                            Sleep(100);
                                        }

                                    }//FINALIZACION DE LAS 3 TIRADAS
                                    TablaPuntuacion[0]=(TablaPuntuacion[0]+PuntosRonda);

                                    Printxy("Fin del turno del jugador 1",50,22);
                                    Printxy("Sumaste ",80,8);
                                    cout<<PuntosRonda<<" puntos en esta ronda";
                                    Sleep(100);
                                    Printxy("Presione cualquier tecla para pasar al siguiente turno",35,25);
                                    Printxy("Presione 'q' para salir",10,8);
                                    key4 = rlutil::getkey();                      //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    if (key4==113){//113 ES EL VALOR DE 'q' en ascii
                                        Fin=1;
                                    }
                                    rlutil::cls();
                                    if (Fin!=1){
                                        RecuadroCambioTurno(ronda, jugador1,jugador2,TablaPuntuacion);
                                        Printxy("Presione una tecla para empezar el turno del jugador 1",35,25);
                                        key3 = rlutil::getkey();                    //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    }

                                    PuntosRonda=0;
                                    rlutil::cls();
                                    PuntosRonda=0;
                                    Sleep(100);
                                    RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],1,PuntosRonda);
                                    Printxy("Inventa jugadas hasta llegar a 500 puntos.",35,8);

                                    for (int i=0;i<3;i++){
                                        Posx=20;                                 //DIRECCIONES EN X e Y DONDE SE
                                        Posy=12;
                                        inventarDado(dados);
                                        borrarPantalla(5,7,105,18);
                                        for(int j=0 ; j<6 ; j++){
                                            dibujarDados2(dados[j],Posx,Posy);       //DIBUJO DE DADOS
                                            Posx+=15;
                                        }
                                        Puntos=identificarJugada(dados);      //identificarJugada NOS DEVUELVE LOS PUNTOS
                                        RecuadroPartida2(jugador1,ronda,TablaPuntuacion[1],i+1,Puntos);
                                        rlutil::locate(10,25);
                                        Printxy("Presione una tecla para continuar...",40,24);
                                        key3 = rlutil::getkey();
                                        borrarPantalla(5,7,105,18);
                                        RecuadroPartida2(jugador2,ronda,TablaPuntuacion[1],i+1,Puntos);
                                        Sleep(100);
                                        if(Puntos>0){                         //ES UNA JUGADA VALIDA
                                            if(PuntosRonda<Puntos){
                                                PuntosRonda=Puntos;           //GUARDAMOS LOS PUNTOS PARA COMPARAR SI SON LOS MAXIMOS DE LA RONDA
                                            }
                                        }
                                        if(Puntos==0){                        //SI SALEN SEIS 6 LOS PUNTOS DE LA RONDA SON = 0
                                            i=3;
                                            PuntosRonda=0;
                                            TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);
                                            Sleep(100);
                                        }
                                        if(Puntos<0){                          //SACASTE ESCALERA
                                            i=3;
                                            rlutil::cls();
                                            TablaPuntuacion[1]=500;
                                            RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);
                                            PuntosRonda=0;
                                            Sleep(100);
                                        }

                                    }//FINALIZACION DE LAS 3 TIRADAS
                                    TablaPuntuacion[1]=(TablaPuntuacion[1]+PuntosRonda);
                                    RecuadroPartida2(jugador1,ronda,TablaPuntuacion[0],1,PuntosRonda);
                                    Printxy("Fin del turno del jugador 2",50,22);
                                    Printxy("Sumaste ",80,8);
                                    cout<<PuntosRonda<<" puntos en esta ronda";
                                    Printxy("Presione una tecla para ver las puntuaciones parciales...",36,24);
                                    Printxy("Presione 'q' para salir",10,8);
                                    Printxy("Cualquier otra para continuar jugando",10,10);

                                    key4 = rlutil::getkey();                      //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    if (key4==113){//113 ES EL VALOR DE 'q' en ascii
                                        Fin=1;
                                    }
                                    rlutil::cls();
                                    if (Fin!=1){
                                        RecuadroCambioTurno(ronda, jugador1,jugador2,TablaPuntuacion);
                                        Printxy("Presione una tecla para empezar el turno del jugador 1",35,25);
                                        key3 = rlutil::getkey();                    //ESPERAMOS QUE INGRESE UNA TECLA PARA CONTINUAR
                                    }

                                    if (TablaPuntuacion[0]>=500&&TablaPuntuacion[1]<500){               //CONDICION PARA QUE EL JUEGO TERMINE
                                        Fin=1;
                                        ganadores[w]=jugador1;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                        puntoshis[w]=TablaPuntuacion[0];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                        w++;
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida.",55,13);
                                        Printxy("Hay un ganador!",45,14);
                                        cout<<jugador1<<" supero los 500 puntos.";
                                        rlutil::locate(47,15);
                                        cout<<"En "<<ronda<<" ronda/as sumaron: ";
                                        rlutil::locate(47,16);
                                        cout<<jugador1<<"  obtuvo: "<<TablaPuntuacion[0]<<" puntos.";
                                        rlutil::locate(47,17);
                                        cout<<jugador2<<"  obtuvo: "<<TablaPuntuacion[1]<<" puntos.";
                                        Sleep(5000);

                                    }
                                    else if(TablaPuntuacion[1]>=500&&TablaPuntuacion[0]<500){
                                        Fin=1;
                                        ganadores[w]=jugador2;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                        puntoshis[w]=TablaPuntuacion[1];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                        w++;
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida.",55,13);
                                        Printxy("Hay un ganador!",45,14);
                                        cout<<jugador2<<" supero los 500 puntos.";
                                        rlutil::locate(47,15);
                                        cout<<"En "<<ronda<<" ronda/as sumaron: ";
                                        rlutil::locate(47,16);
                                        cout<<jugador1<<"  obtuvo: "<<TablaPuntuacion[0]<<" puntos.";
                                        rlutil::locate(47,17);
                                        cout<<jugador2<<"  obtuvo: "<<TablaPuntuacion[1]<<" puntos.";
                                        Sleep(5000);
                                    }
                                    else if(TablaPuntuacion[0]>=500&&TablaPuntuacion[1]>=500){
                                        Fin=1;
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("EMPATE",45,12);
                                        Printxy("Ambos jugadores alcanzaron 500 puntos en la misma ronda",45,13);
                                        rlutil::locate(47,15);
                                        cout<<"En "<<ronda<<" ronda/as sumaron: ";
                                        rlutil::locate(47,16);
                                        cout<<jugador1<<"  obtuvo: "<<TablaPuntuacion[0]<<" puntos.";
                                        rlutil::locate(47,17);
                                        cout<<jugador2<<"  obtuvo: "<<TablaPuntuacion[1]<<" puntos.";
                                        Sleep(5000);
                                        if(TablaPuntuacion[0]>TablaPuntuacion[1]){
                                            ganadores[w]=jugador1;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[0];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                        }
                                        else if(TablaPuntuacion[1]>TablaPuntuacion[0]){
                                            ganadores[w]=jugador2;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[1];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                        }
                                        else if(TablaPuntuacion[1]==TablaPuntuacion[0]){
                                            ganadores[w]=jugador1;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[0];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                            ganadores[w]=jugador2;                  //SE GUARDA EL NOMBRE DEL JUGADOR DEL GANADOR
                                            puntoshis[w]=TablaPuntuacion[1];        //SE GUARDA LA PUNTUACION DEL GANADOR
                                            w++;
                                        }

                                    }
                                    if (RondaLimite==ronda){
                                        rlutil::cls();
                                        Recuadro(ancho,alto);
                                        Printxy("Fin de la partida",55,13);
                                        rlutil::locate(47,14);
                                        cout<<"En "<<RondaLimite<<" ronda/as sumaste: "<<TablaPuntuacion[1]<<" puntos.";
                                        Printxy("Has alcanzado el numero maximo de Rondas que habias establecido",33,15);
                                        Printxy("Presione una tecla para salir",49,25);
                                        key3 = rlutil::getkey();
                                        Sleep(1000);
                                        Fin=1;
                                    }

                                }//FIN DEL WHILE DE LA PARTIDA
                                rlutil::cls();

                                break;

                            case 2://MOSTRAR MEJORES PUNTUACIONES

                                rlutil::cls();
                                mostrarPuntos(ancho, alto);
                                puntosGanadores(ganadores, puntoshis, ancho,alto);
                                Printxy("Presione una tecla para salir",45,29);
                                key3 = rlutil::getkey();
                                rlutil::cls();

                                break;

                            case 4://SALIR A SELECCIONAR NUM DE JUGADORES
                                modojugador=0;
                                e=0;
                                key=0;
                                rlutil::cls();
                                break;


                            }//FIN DEL SWITCH DE LOS DISTINTOS MODOS
                        }//SALIR DEL MODO 2 JUGADORES
                    }//FIN DE WHILE 2 JUGADORES
                    break;


                case 3://SALIR MENU DE INICIO
                    key1=0;
                    break;
                }

            }//SALIDA DEL SWITCH KEY
        }
    }while(juego!=0);

  return 0;
}

