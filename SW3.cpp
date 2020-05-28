#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void delay() //funkcja dająca półsekundowe opóźnienie
{
    int c, d = 0;
    for (c = 1; c <= 32767; c++)
        for (d = 1; d <= 8192; d++)
        {
        }
}

void IntToBinary(unsigned char input) //funkcja do wyświetlania diod
{
    short i = 7;
    while (i >= 0)
    {
        printf("%d", (input >> i) & 1);
        i--;
    }

    printf("   ");
}

int main()
{
    unsigned char display = 0;
again: // niekończąca się pętla
        printf("\r");
        IntToBinary(display); // wyświetlenie licznika
        if (display > 50) // jeśli licznik przekroczy wartość 50, zaświecają się wszystkie diody 
        {
            printf("\r");
            IntToBinary(255);
        }
        char ch = _getch(); // wczytanie klawisza z klawiatury
        if (ch == 72) // jeśli wciśnieta zostanie strzałka w górę, następuje inkrementacja licznika
        {
            display++;
        }
        if (ch == 80) // jeśli wciśnieta zostanie strzałka w dół, następuje dekrementacja licznika
        {
            display--;
        }
        if (display > 50) /* jeśli licznik przekroczy wartość 50, wyświetla się alarm, który polega na tym, że 
                          zaczyna mrugać jedna dioda przez 3 sekundy, a na koniec zaświecają się wszystkie diody */
        {
            printf("\r");
            delay();
            IntToBinary(1);
            printf("\r");
            delay();
            IntToBinary(0);
            printf("\r");
            delay();
            IntToBinary(1);
            printf("\r");
            delay();
            IntToBinary(0);
            printf("\r");
            delay();
            IntToBinary(1);
            printf("\r");
            delay();
            IntToBinary(0);
            delay();
        }

    goto again;
}

