#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char owner[20];
    char chipNum[10];
    float price;
} PetPatient;

void printOwner(PetPatient patients[], unsigned length, float price) {
    for (int i=0; i<length; i++) {
        if (patients[i].price == price){
            printf("%s - %s\n", patients[i].owner, patients[i].chipNum);

        }

    }
    printf("No such data...\n");
}

void printPatientsWithPrice(float minPrice) {
    FILE *file = fopen("animalsBin.bin", "rb");
    if (file == NULL) {
        printf("Грешка при отваряне на файл.\n");
        exit(1);
    }

    PetPatient patient;
    int bytesRead;
    while ((bytesRead = fread(&patient, sizeof(patient), 1, file)) == 1) {
        if (patient.price >= minPrice) {
            printf("Име на собственик: %s\n", patient.owner);
            printf("Номер на чип: %s\n", patient.chipNum);
            printf("Цена за преглед: %.2f\n\n", patient.price);
        }
    }
    fclose(file);
}


PetPatient createPatient() {
    PetPatient patient;

    printf("Patient owner: ");
    fgets(patient.owner, sizeof(patient.owner), stdin);
    printf("Patient chipNum: ");
    fgets(patient.chipNum, sizeof(patient.chipNum), stdin);
    printf("Price: ");
    scanf("%f", &patient.price);

    getchar(); // Read the newline character

    FILE *patientTXT = fopen("PatientTXT.txt", "a");
    if (patientTXT == NULL) {
        printf("Грешка при отваряне на файл.\n");
        exit(1);
    }
    fprintf(patientTXT, "%s,%.2f\n", patient.owner, patient.price);
    fclose(patientTXT);

    return patient;
}

int main() {
    PetPatient patients[50];
    for (int i = 0; i < 50; i++) {
        patients[i] = createPatient();
        char choice;
        printf("Искате ли да добавите още пациенти? (y/n): ");
        scanf(" %c", &choice);
        getchar();  // Прочитане на излишния нов ред

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }
    float minPrice;

    printf("Въведете минимална цена за преглед: ");
    scanf("%f", &minPrice);

    printPatientsWithPrice(minPrice);

    return 0;
}

