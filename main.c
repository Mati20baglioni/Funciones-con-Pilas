#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{

    /*INDICE*/
    printf("(1)Cargar pila por teclado:\n");
    printf("(2)Pasar a otra pila:\n");
    printf("(3)Pasar elementos de una pila a otra respetando el orden:\n");
    printf("(4)Encontrar menor elemento de una pila:\n");
    printf("(5)Ordenamiento de pila por seleccion:\n");
    printf("(6)ingresar un elemento a una pila ordenada conservando el orden de la misma:\n");
    printf("(7)Pasar una pila a otra mediante ordenamiento de la pila por insercion:\n");
    printf("(8)Sumar de tope y el anterior de una pila:\n");
    printf("(9)Calcular el promedio de una pila:\n");
    printf("(10)Transformar digitos en un numero decimal:\n");
    printf("(FUNCIONES EXTRA:\n");
    printf("(11)Realizar una funcion que cargue la pila sin utilizar la funcion leer:\n");
    printf("(12)Realizar una funcion que muestre la pila sin utilizar la funcion mostrar:\n");
    printf("\n");
////////////////////////////////////////////////////////////////////////////////

    int op,nuevo;

    char control='s';
    Pila Uno,Dos;
    inicpila(&Uno);
    inicpila(&Dos);
///////////////////////////////////////////////////////////////////////////////
    /*MENU DE OPCIONES*/

    do{
    printf("INGRESE EL NUMERO DE LA OPERACION:\n");
    scanf("%i",&op);
    switch(op)
    {
    case 1:
        CargarPila(&Uno);

    break;

    case 2:
        CargarPila(&Uno);
        PasarPila(&Uno,&Dos);
        mostrar(&Dos);

    break;

    case 3:

        CargarPila(&Uno);
        PasarPila(&Uno,&Dos);
        PasarMismoOrden(&Uno,&Dos);

    break;

    case 4:
        CargarPila(&Uno);
        int Menor=EncontrarMenorEnPila(&Uno);
        printf("EL MENOR ELEMENTO DE LA PILA ES:%i\n",Menor);

    break;

    case 5:
        CargarPila(&Uno);
        OrdenamientoPorSeleccion(&Uno);
        InsertarElementoPila(&Uno);

    break;

    case 6:
        printf("INGRESE LOS VALORES EN ORDEN:\n");
        CargarPila(&Uno);
        printf("ingrese un numero:\n");
        scanf("%i",&nuevo);
        InsertarElementoPila(&Uno,nuevo);

    break;
    case 7:
        printf("INGRESE UNA LISTA DE VALORES EN ORDEN:\n");
        CargarPila(&Uno);
        OrdenamientoPorInsercion(&Uno);

    break;
    case 8:
        printf("INGRESA DATOS EN LA PILA:\n");
        CargarPila(&Uno);
        int suma=SumarTope_Anterior(&Uno);
        printf("la suma es:%i\n",suma);

    break;
    case 9:
        CargarPila(&Uno);
        PromedioDePila(&Uno);
    break;
    case 10:
        printf("INGRESA DATOS DE UN DIGITO A LA PILA:\n");
        CargarPila(&Uno);
        int resultado=Pila_A_Decimal(&Uno);
        printf("EL NUMERO DECIMAL ES:%i\n",resultado);

    break;
    case 11:
        Cargar_Pila_Sin_Leer(&Dos);

    break;

    case 12:
        Mostrar_Alternativa(&Dos);

    break;
    default:
        printf("OPCION NO VALIDA\n");
        printf("INGRESE UN NUMERO DEL 1 AL 10:\n");
        scanf("&d",&op);
    }
    printf("\n");
    printf("DESEA VER OTROS CASOS PRESIONE s/n:\n");
    fflush(stdin);
    scanf("%c",&control);
    }while(control=='s');
    return 0;
}


/*FUNCIONES*/
/*1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.*/

void CargarPila(Pila* Uno)
{
    char control='s';
    while(control=='s')
        {
        printf("INGRESE UN NUMERO:\n");
        leer(Uno);
        printf("DESEA CONTINUAR S/N:\n");
        fflush(stdin);
        scanf("%c",&control);

        }mostrar(Uno);
}

/*FUNCION 2*/
/*Hacer una función que pase todos los elementos de una pila a otra.*/

void PasarPila(Pila* Uno,Pila* Dos)
{
    while(!pilavacia(Uno))
    {
    apilar(Dos,desapilar(Uno));

    }
}

/*FUNCION3*/
/*Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden*/
void PasarMismoOrden(Pila* Uno,Pila* Dos)
{
    Pila Aux;
    inicpila(&Aux);
    while(!pilavacia(Dos))
        {
            apilar(&Aux,desapilar(Dos));
        }/*mostrar(&Aux);*/

}

/*FUNCION 4*/
/* Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.*/

int EncontrarMenorEnPila(Pila* Uno)
{
    Pila Menor, Aux;
    inicpila(&Menor);
    inicpila(&Aux);

    if(!pilavacia(Uno))
    apilar(&Menor,desapilar(Uno));

    while (!pilavacia(Uno))
    {
        if (tope(Uno) < tope(&Menor))
        {
            apilar(&Aux, desapilar(&Menor));
            apilar(&Menor,desapilar(Uno));
        }
        else
        {
            apilar(&Aux, desapilar(Uno));
        }
    }
    while (!pilavacia(&Aux))
    {
        apilar(Uno,desapilar(&Aux));
    }

    return tope(&Menor);
}


/*FUNCION 5*/
/*HACER UNA FUNCION QUE PASE LOS ELEMENTOS DE UNA PILA A OTRA DE MANERA QUE SE GENERE UNA NUEVA PILA ORDENADA.
  USAR LA FUNCION DEL EJERCICIO 4(ORDENAMIENTO POR SELECCION)*/

void OrdenamientoPorSeleccion(Pila* Uno)
{

    Pila Ordenada;
    inicpila(&Ordenada);

    while (!pilavacia(Uno))
    {
        apilar(&Ordenada,EncontrarMenorEnPila(Uno));

    }
    mostrar(&Ordenada);
}

/*FUNCION 6*/
/*Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.*/
//FUNCIONA TAMBIEN
/*
void InsertarElementoPila(Pila* ordenada, int nuevo)
{
    Pila Aux,Aux2;
    inicpila(&Aux);
    inicpila(&Aux2);

    apilar(&Aux,nuevo);
    mostrar(&Aux);

    while(!pilavacia(&Aux))
    {
        if(tope(ordenada)>tope(&Aux))
        {
            apilar(&Aux2,desapilar(ordenada));
        }
        else
        {
            apilar(&Aux2,desapilar(&Aux));
        }
    }

    while(!pilavacia(ordenada))
    {
        apilar(&Aux2,desapilar(ordenada));
    }
    while(!pilavacia(&Aux2))
    {
     apilar(ordenada,desapilar(&Aux2));
    }
mostrar(ordenada);
}
*/
//6 FUNCIONA TAMBIEN
void InsertarElementoPila(Pila* ordenada, int nuevo)
{
    Pila Aux;
    inicpila(&Aux);

    while((!pilavacia(ordenada))&&(tope(ordenada)>nuevo))
    {
        apilar(&Aux,desapilar(ordenada));
    }apilar(ordenada,nuevo);
    while(!pilavacia(&Aux))
    {
        apilar(ordenada,desapilar(&Aux));
    }
    /*mostrar(ordenada);*/
}

/*FUNCION 7*/

/*7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)*/

void OrdenamientoPorInsercion(Pila* Original)
{
    Pila NuevaPilaOrdenada;
    inicpila(&NuevaPilaOrdenada);

    while(!pilavacia(Original))
    {
        InsertarElementoPila(&NuevaPilaOrdenada,desapilar(Original));
    }

    mostrar(&NuevaPilaOrdenada);

}

/*8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.*/


int SumarTope_Anterior(Pila* Datos)
{
    Pila Aux;
    inicpila(&Aux);

    apilar(&Aux,desapilar(Datos));
    int suma=tope(Datos)+tope(&Aux);
    apilar(Datos,desapilar(&Aux));
    printf("LOS DATOS EN LA PILA:\n");
    mostrar(Datos);
    return suma;
}
/*FUNCION 9*/
/*9. Hacer una función que calcule el promedio de los elementos de una pila,
 para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida.
En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.*/

int SumarPilaCompleta(Pila* Datos)
{
    int Sumatoria=0;
    Pila Aux;
    inicpila(&Aux);

    while(!pilavacia(Datos))
    {
        Sumatoria+=tope(Datos);
        apilar(&Aux,desapilar(Datos));
    }
    while(!pilavacia(&Aux))
    {
        apilar(Datos,desapilar(&Aux));
    }

    printf("la suma es:%i\n",Sumatoria);
    return Sumatoria;
}

int ContadorPila(Pila* Datos)
{
    Pila Aux;
    inicpila(&Aux);
    int Contador=0;
    while(!pilavacia(Datos))
    {
        apilar(&Aux,desapilar(Datos));
        Contador++;
    }
    // printf("TOTAL DE DATOS ENCONTRADOS EN LA PILA:%i\n",Contador);
    return Contador;
}

float DivisionDePila(int numerador,int denominador)
{
     float division=(float)numerador/denominador;
     return division;
}

int PromedioDePila(Pila* Datos)
{
    int suma=SumarPilaCompleta(Datos);
    int contador=ContadorPila(Datos);
    float Promedio=DivisionDePila(suma,contador);
    printf("EL PROMEDIO DE LA PILA ES:%.2f\n",Promedio);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*FUNCION 10*/
/*
10. Hacer una función que reciba una pila con números de un solo dígito
(es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:

1
4
6
7
5

Debe retornar el número: 14675
*/
////////////////////////////////////////COREGIR NO FUNCIONA NI A PALOS///////////////////////////////////////////////////////////
int Pila_A_Decimal(Pila* Digitos)
{
    int contador=ContadorPila(Digitos);
    int mult=10;
    int elevado=0;
    int resultado=0;
    Pila Aux;
    inicpila(&Aux);
    for(int i=0;i<contador;i++)
    {
        apilar(&Aux,desapilar(Digitos));
        tope(&Aux)*mult^elevado;
        elevado++;
        resultado+=tope(&Aux);
    }
    return resultado;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  FUNCION EXTRA (11)
void Cargar_Pila_Sin_Leer(Pila* Datos)
{
    int numero;
    char control='s';
    while(control == 's')
    {
        printf("INGRESE UN NUMERO:\n");
        scanf("%i",&numero);
        apilar(Datos, numero);
        printf("DESEA CONTINUAR:");
        fflush(stdin);
        scanf(" %c", &control);

    }

   // mostrar(Datos);

}

//FUNCION EXTRA (12)
void Mostrar_Alternativa(Pila* Dada)
{
    Cargar_Pila_Sin_Leer(Dada);
    Pila Aux;
    inicpila(&Aux);

    while(!pilavacia(Dada))
    {
        apilar(&Aux,desapilar(Dada));
    }
    while(!pilavacia(&Aux))
    {
        printf("%i\t",tope(&Aux));
        apilar(&Dada,desapilar(&Aux));
    }


}
