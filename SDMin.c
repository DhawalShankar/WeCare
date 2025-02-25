#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_SYMPTOMS_LEN 200
#define MAX_MEDICATIONS_LEN 200

// Structure to store patient information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char gender;
    float height;
    float weight;
    char symptoms[MAX_SYMPTOMS_LEN];
    char medications[MAX_MEDICATIONS_LEN];
    char date[11]; // Format: YYYY-MM-DD
} Patient;

// Global variables
Patient patients[MAX_RECORDS];
int patientCount = 0;

// Function prototypes
void displayMenu();
void addPatient();
void viewPatients();
void searchPatient();
void calculateBMI();
void medicationReminder();
void firstAidGuide();
void saveData();
void loadData();
float calculateBMIValue(float height, float weight);
void getCurrentDate(char *dateStr);

int main() {
    int choice;
    
    printf("\n======================================\n");
    printf("    WELCOME TO WECARE HEALTHCARE    \n");
    printf("         ASSISTANT SYSTEM          \n");
    printf("======================================\n");
    
    loadData(); // Load existing data if available
    
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                calculateBMI();
                break;
            case 5:
                medicationReminder();
                break;
            case 6:
                firstAidGuide();
                break;
            case 7:
                saveData();
                printf("\nData saved successfully. Exiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}

// Function to display main menu
void displayMenu() {
    printf("\n--- WECARE HEALTHCARE ASSISTANT MENU ---\n");
    printf("1. Add New Patient Record\n");
    printf("2. View All Patient Records\n");
    printf("3. Search Patient Record\n");
    printf("4. BMI Calculator\n");
    printf("5. Medication Reminder\n");
    printf("6. First Aid Guide\n");
    printf("7. Save & Exit\n");
}

// Function to add a new patient record
void addPatient() {
    if (patientCount >= MAX_RECORDS) {
        printf("\nError: Maximum record limit reached!\n");
        return;
    }
    
    Patient newPatient;
    
    printf("\n--- ADD NEW PATIENT ---\n");
    
    // Clear input buffer
    while (getchar() != '\n');
    
    printf("Enter patient name: ");
    fgets(newPatient.name, MAX_NAME_LEN, stdin);
    newPatient.name[strcspn(newPatient.name, "\n")] = 0; // Remove newline
    
    printf("Enter age: ");
    scanf("%d", &newPatient.age);
    
    printf("Enter gender (M/F): ");
    scanf(" %c", &newPatient.gender);
    
    printf("Enter height (in meters): ");
    scanf("%f", &newPatient.height);
    
    printf("Enter weight (in kg): ");
    scanf("%f", &newPatient.weight);
    
    // Clear input buffer
    while (getchar() != '\n');
    
    printf("Enter symptoms: ");
    fgets(newPatient.symptoms, MAX_SYMPTOMS_LEN, stdin);
    newPatient.symptoms[strcspn(newPatient.symptoms, "\n")] = 0; // Remove newline
    
    printf("Enter medications (if any): ");
    fgets(newPatient.medications, MAX_MEDICATIONS_LEN, stdin);
    newPatient.medications[strcspn(newPatient.medications, "\n")] = 0; // Remove newline
    
    getCurrentDate(newPatient.date);
    
    patients[patientCount++] = newPatient;
    printf("\nPatient record added successfully!\n");
}

// Function to view all patient records
void viewPatients() {
    if (patientCount == 0) {
        printf("\nNo patient records found!\n");
        return;
    }
    
    printf("\n--- ALL PATIENT RECORDS ---\n");
    printf("%-4s %-20s %-5s %-6s %-8s %-8s %-10s\n", 
           "No.", "Name", "Age", "Gender", "Height", "Weight", "Date");
    printf("----------------------------------------------------------\n");
    
    for (int i = 0; i < patientCount; i++) {
        printf("%-4d %-20s %-5d %-6c %-8.2f %-8.2f %-10s\n", 
               i+1, 
               patients[i].name, 
               patients[i].age, 
               patients[i].gender, 
               patients[i].height, 
               patients[i].weight,
               patients[i].date);
    }
    
    printf("\nPress any key to continue...");
    getchar();
    getchar();
}

// Function to search for a patient record
void searchPatient() {
    if (patientCount == 0) {
        printf("\nNo patient records found!\n");
        return;
    }
    
    char searchName[MAX_NAME_LEN];
    int found = 0;
    
    // Clear input buffer
    while (getchar() != '\n');
    
    printf("\nEnter patient name to search: ");
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline
    
    printf("\n--- SEARCH RESULTS ---\n");
    
    for (int i = 0; i < patientCount; i++) {
        if (strstr(patients[i].name, searchName) != NULL) {
            printf("\nRecord #%d:\n", i+1);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %c\n", patients[i].gender);
            printf("Height: %.2f m\n", patients[i].height);
            printf("Weight: %.2f kg\n", patients[i].weight);
            printf("BMI: %.2f\n", calculateBMIValue(patients[i].height, patients[i].weight));
            printf("Symptoms: %s\n", patients[i].symptoms);
            printf("Medications: %s\n", patients[i].medications);
            printf("Record Date: %s\n", patients[i].date);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching records found!\n");
    }
    
    printf("\nPress any key to continue...");
    getchar();
}

// Function to calculate BMI
void calculateBMI() {
    float height, weight, bmi;
    
    printf("\n--- BMI CALCULATOR ---\n");
    printf("Enter height (in meters): ");
    scanf("%f", &height);
    
    printf("Enter weight (in kg): ");
    scanf("%f", &weight);
    
    bmi = calculateBMIValue(height, weight);
    
    printf("\nYour BMI: %.2f\n", bmi);
    printf("BMI Category: ");
    
    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi < 25) {
        printf("Normal weight\n");
    } else if (bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obesity\n");
    }
    
    printf("\nPress any key to continue...");
    getchar();
    getchar();
}

// Helper function to calculate BMI value
float calculateBMIValue(float height, float weight) {
    return weight / (height * height);
}

// Function for medication reminder
void medicationReminder() {
    char medicationName[50];
    int frequency;
    
    printf("\n--- MEDICATION REMINDER SETUP ---\n");
    
    // Clear input buffer
    while (getchar() != '\n');
    
    printf("Enter medication name: ");
    fgets(medicationName, 50, stdin);
    medicationName[strcspn(medicationName, "\n")] = 0; // Remove newline
    
    printf("Enter daily frequency (how many times per day): ");
    scanf("%d", &frequency);
    
    printf("\nMedication reminder set for '%s' %d time(s) per day.\n", medicationName, frequency);
    
    if (frequency == 1) {
        printf("Recommended time: 9:00 AM\n");
    } else if (frequency == 2) {
        printf("Recommended times: 9:00 AM and 9:00 PM\n");
    } else if (frequency == 3) {
        printf("Recommended times: 8:00 AM, 2:00 PM, and 8:00 PM\n");
    } else {
        printf("Please consult your doctor for optimal timing.\n");
    }
    
    printf("\nPress any key to continue...");
    getchar();
    getchar();
}

// Function for first aid guide
void firstAidGuide() {
    int choice;
    
    printf("\n--- FIRST AID GUIDE ---\n");
    printf("1. Cuts and Scrapes\n");
    printf("2. Burns\n");
    printf("3. Choking\n");
    printf("4. Sprains\n");
    printf("5. Return to Main Menu\n");
    
    printf("\nSelect emergency type: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\n--- CUTS AND SCRAPES ---\n");
            printf("1. Clean the wound with mild soap and water\n");
            printf("2. Apply pressure to stop bleeding\n");
            printf("3. Apply an antibiotic ointment\n");
            printf("4. Cover with a sterile bandage\n");
            printf("5. Seek medical help for deep cuts\n");
            break;
        case 2:
            printf("\n--- BURNS ---\n");
            printf("1. Cool the burn with cool running water for 10-15 minutes\n");
            printf("2. Don't apply ice directly to the burn\n");
            printf("3. Cover with a clean, dry cloth\n");
            printf("4. Don't break blisters\n");
            printf("5. Seek medical help for severe burns\n");
            break;
        case 3:
            printf("\n--- CHOKING ---\n");
            printf("1. Encourage coughing to clear the blockage\n");
            printf("2. If unable to cough, perform abdominal thrusts (Heimlich maneuver)\n");
            printf("3. Call emergency services if choking persists\n");
            break;
        case 4:
            printf("\n--- SPRAINS ---\n");
            printf("1. Remember RICE: Rest, Ice, Compression, Elevation\n");
            printf("2. Apply ice for 20 minutes every 2-3 hours\n");
            printf("3. Use a compression bandage\n");
            printf("4. Elevate the injured area\n");
            printf("5. Seek medical help if severe pain or inability to bear weight\n");
            break;
        case 5:
            return;
        default:
            printf("\nInvalid choice!\n");
    }
    
    printf("\nPress any key to continue...");
    getchar();
    getchar();
}

// Function to save data to file
void saveData() {
    FILE *file = fopen("healthcare_data.dat", "wb");
    if (file == NULL) {
        printf("\nError: Unable to save data!\n");
        return;
    }
    
    fwrite(&patientCount, sizeof(int), 1, file);
    fwrite(patients, sizeof(Patient), patientCount, file);
    
    fclose(file);
}

// Function to load data from file
void loadData() {
    FILE *file = fopen("healthcare_data.dat", "rb");
    if (file == NULL) {
        return; // File doesn't exist yet, which is fine
    }
    
    fread(&patientCount, sizeof(int), 1, file);
    fread(patients, sizeof(Patient), patientCount, file);
    
    fclose(file);
}

// Function to get current date
void getCurrentDate(char *dateStr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateStr, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}
