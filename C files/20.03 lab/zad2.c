#include <stdio.h>
#include <string.h>
#define SIZE 100

int main()
{
    char text[SIZE]; //zadelqme pamet

    fgets(text, SIZE, stdin); // pulnim masiva ot klaviaturata

    // fgets e po-dobra funkciq ot scanf. argumentite sa - ime na nasiv, goleminata mu, stdin ili stdout

    int wordC = 0;

    for(int i = 0; i< strlen(text); i++){ // minavame prez vseki simvol

            // The strlen() function takes a string as an argument and returns its length.

        if ((text[i] < 'A' || text[i] > 'Z') && (text[i] < 'a' || text[i] > 'z')){ //ako ne e bukva e razdelitel
            wordC++; // broim
        }
    }
    printf("%d", wordC);
    return 0;


}
