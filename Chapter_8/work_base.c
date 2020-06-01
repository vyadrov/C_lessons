#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define VARIANT_NUMBER 100
#define BUF_LENGTH 20
#define MAX_VARIANT 5

char* f_name = "file.dat";

typedef struct employee {
    char* lastname;
    int id;
    int year;
    struct employee* next;
} employee_t;

int add_employee(employee_t** head, char* lastname, int id, int year);
void find_emplyee_by_lastname(employee_t* head);
void scan_employee_data(employee_t** head);
void find_employee_by_id(employee_t* head);
void print_employees(employee_t* head);
int get_variant(int count);
int save(char* f_name, struct employee* p);
int load(char* f_name);

void scan_employee_data(employee_t** head) {
    int id;
    int year;
    char lastname[BUF_LENGTH];

    printf("Please enter last name for new employee: ");
    scanf("%s", &lastname[0]);
    printf("Please enter id for new employee: ");
    scanf("%d", &id);
    printf("Please enter year of birth for new employee: ");
    scanf("%d", &year);
    add_employee(head, lastname, id, year);
}

int add_employee(employee_t** head, char* lastname, int id, int year) {
    employee_t* e;
    employee_t* tmp;
    tmp = *head;

    e = malloc(sizeof(struct employee));
    e->lastname = strdup(lastname);
    e->id = id;
    e->year = year;
    e->next = NULL;

    if (tmp == NULL) {
        *head = e;
    }
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = e;
    }

    save(f_name, e);
}

void find_employee_by_lastname(employee_t* head) {
    employee_t* tmp;
    char temp_lastname[BUF_LENGTH];
    tmp = head;

    printf("Please enter employee's last name for finding: ");
    scanf("%s", temp_lastname);

    while (tmp != NULL && strcmp(tmp->lastname, temp_lastname)) {
        tmp = tmp->next;
    }
    if (tmp != NULL) {
        printf("| %20s | %11d | %4d |\n", tmp->lastname, tmp->id, tmp->year);
        printf("+---------------------+-------------+------+\n");
    }
    else {
        printf("%s is not found\n", temp_lastname);
    }
}

void find_employee_by_id(employee_t* head) {
    employee_t* tmp;
    int temp_id;
    tmp = head;
    printf("Please enter employee's ID number for finding: ");
    scanf("%d", &temp_id);

    while (tmp != NULL && (tmp->id != temp_id)) {
        tmp = tmp->next;
    }
    if (tmp != NULL) {
        printf("| %20s | %11d | %4d |\n", tmp->lastname, tmp->id, tmp->year);
        printf("+---------------------+-------------+------+\n");
    }
    else {
        printf("Emploee with id #%d is not found\n", temp_id);
    }
}

int save(char* f_name, struct employee* p)
{
    FILE* fp;

    if ((fp = fopen(f_name, "a+t")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    fprintf(fp, "| %19s | %11d | %4d |\n", p->lastname, p->id, p->year);
    fclose(fp);
    return 0;
}

int load(char* f_name) {
    FILE* fp;
    char* c;
    char i;
    int size = sizeof(struct employee);
    struct employee* ptr = (struct employee*)malloc(size);
    c = (char*)ptr;

    if ((fp = fopen(f_name, "rb")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    printf("+---------------------+-------------+------+\n");
    printf("|         Employee    |    ID       | Year |\n");
    printf("+---------------------+-------------+------+");

    while ((i = getc(fp)) != EOF) {
        printf("%c", i);
    }

    fclose(fp);
    printf("+---------------------+-------------+------+\n");
    free(ptr);
    return 0;
}

int get_variant(int count) {
    int variant;
    char s[VARIANT_NUMBER];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect option. Please try again: ");
        scanf("%s", s);
    }

    return variant;
}

void print_menu() {
    printf("Employee database\n");
    printf("1. Add new employee\n");
    printf("2. Print the list of employees \n");
    printf("3. Find employee by lastname\n");
    printf("4. Find employee by ID number\n");
    printf("5. Exit\n");
    printf(">");
}

int main() {
    employee_t* ptr_head = NULL;
    int var;

    do {
        print_menu();

        var = get_variant(MAX_VARIANT);

        switch (var) {
        case 1:
            scan_employee_data(&ptr_head);
            break;

        case 2:
            load(f_name);
            break;

        case 3:
            find_employee_by_lastname(ptr_head);
            break;

        case 4:
            find_employee_by_id(ptr_head);
            break;
        }

    } while (var != MAX_VARIANT);

    return 0;
}