#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define VARIANT_NUMBER 100
#define BUF_LENGTH 50
#define MAX_VARIANT 6

char* file_name = "file.dat";
int id = 1;

typedef struct employee {
    char* lastname;
    int id;
    int year;
    struct employee* next;
} employee_t;

employee_t *add_employee(employee_t** head, char* lastname, int id, int year);
employee_t *find_employee_by_id(employee_t* head, int id);
void find_employee_by_lastname(employee_t* head);
void scan_employee_data(employee_t** head);
void delete_list(employee_t* head);
void delete_employee_by_id(employee_t** head, int id);
void printheader();
int get_variant(int count);
int save(char* file_name, struct employee* p);
int load(char* file_name, employee_t** head);

void scan_employee_data(employee_t** head) {
    int year;
    char lastname[BUF_LENGTH];
    employee_t *e = NULL;

    printf("Please enter last name for new employee: ");
    scanf("%s", &lastname[0]);
    printf("Please enter year of birth for new employee: ");
    scanf("%d", &year);

    while ((e = find_employee_by_id(*head, id)) != NULL) {
		id += 1;
    }

    e = add_employee(head, lastname, id, year);
    save(file_name, e);
}

employee_t *add_employee(employee_t** head, char* lastname, int id, int year) {
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

    return e;
}

void find_employee_by_lastname(employee_t* head) {
    employee_t* tmp;
    char temp_lastname[BUF_LENGTH];
    tmp = head;

    printf("Please enter employee's last name for finding: ");
    scanf("%s", temp_lastname);

    printheader();

    while (tmp != NULL && strcmp(tmp->lastname, temp_lastname)) {
        tmp = tmp->next;
    }
    if (tmp != NULL) {
        printf("| %19s | %11d | %4d |\n", tmp->lastname, tmp->id, tmp->year);
        printf("+---------------------+-------------+------+\n");
    }
    else {
        printf("%s is not found\n", temp_lastname);
    }
}

employee_t *find_employee_by_id(employee_t* head, int id) {
    employee_t* tmp;
    tmp = head;

    while (tmp != NULL && (tmp->id != id)) {
        tmp = tmp->next;
    }
    
    return tmp;
}

int save(char* file_name, struct employee* p) {
    FILE* fp;

    if ((fp = fopen(file_name, "a+t")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    
    fprintf(fp, "%s %d %d\n", p->lastname, p->id, p->year);
    fclose(fp);
    return 0;
}

int re_save(employee_t* head, char* file_name) {
    FILE* fp;
    employee_t* e;

    if ((fp = fopen(file_name, "w+t")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    while (head != NULL) {
        fprintf(fp, "%s %d %d\n", head->lastname, head->id, head->year);
        head = head->next;           
    }    
    
    fclose(fp);
    return 0;
}

int load(char* file_name, employee_t** head) {
    FILE* fp;
    char ch;
    char buff[BUF_LENGTH];
    int i;
    char* tok;
    int id;
    int year;
    char* lastname;    

    printheader();
    
    if ((fp = fopen(file_name, "rb")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    i = 0;
    while ((ch = getc(fp)) != EOF) {

        if (ch == '\n') {
            buff[i] = '\0';

            tok = strtok(buff, " ");
            lastname = strdup(tok);
            printf("| %19s ", lastname);

            tok = strtok(NULL, " ");
            id = atoi(tok);
            printf("| %11d ", id);

            tok = strtok(NULL, " ");
            year = atoi(tok);
            printf("| %4d |\n", year);

            add_employee(head, lastname, id, year);
        
            i = 0;
            continue;
        }

        buff[i] = ch;
        i += 1;
    }

    fclose(fp);
    printf("+---------------------+-------------+------+\n");
    return 0;
}

void delete_list(employee_t* head) {
    struct employee* current;
    head = NULL;
    
        while (head != NULL) {
            current = head;
            head = head->next;
            free(current);
        }

    head = NULL;
}

void delete_employee_by_id(employee_t** head, int id) {	
    employee_t* curr = *head;
    employee_t* tmp = NULL;

    while (curr != NULL && (curr->id != id)) {
	    tmp = curr;
        curr = curr->next; 
    }

    if (curr == NULL) { 
        return;
    }

    if (tmp != NULL) {
        printf("%p\n", curr->next);
        tmp->next = curr->next;
    } else {
        *head = curr->next;
    }

    free(curr);

    re_save(*head, file_name);
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

void printheader() {
    printf("+---------------------+-------------+------+\n");
    printf("|         Employee    |    ID       | Year |\n");
    printf("+---------------------+-------------+------+\n");
}

void print_menu() {
    printf("Employee database\n");
    printf("1. Add new employee\n");
    printf("2. Print the list of employees \n");
    printf("3. Find employee by lastname\n");
    printf("4. Find employee by ID number\n");
    printf("5. Delete employee by ID number\n");
    printf("6. Exit\n");
    printf(">");
}

int main() {
    employee_t* ptr_head = NULL;
    int var;
    int temp_id;
    employee_t *tmp;

    load(file_name, &ptr_head);
    
    do {
        print_menu();

        var = get_variant(MAX_VARIANT);

        switch (var) {
        case 1:
            scan_employee_data(&ptr_head);
            break;

        case 2:
            ptr_head = NULL;
            delete_list(ptr_head);
            load(file_name, &ptr_head);
            break;

        case 3:
            find_employee_by_lastname(ptr_head);
            break;

        case 4:
    	    printf("Please enter employee's ID number for finding: ");
    	    scanf("%d", &temp_id);

    	    printheader();
            tmp = find_employee_by_id(ptr_head, temp_id);
	    if (!tmp) {
                printf("Emploee with id #%d is not found\n", temp_id);
	    } else {
                printf("| %19s | %11d | %4d |\n", tmp->lastname, tmp->id, tmp->year);
                printf("+---------------------+-------------+------+\n");
	    }
            break;

        case 5:
        	printf("Please enter employee's ID number for deleting: ");
    	    scanf("%d", &temp_id);

            delete_employee_by_id(&ptr_head, temp_id);
            break;
        }

    } while (var != MAX_VARIANT);

    delete_list(ptr_head);

    return 0;
}
