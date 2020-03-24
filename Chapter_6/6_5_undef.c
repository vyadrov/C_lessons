#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct nlist {              /* table entry: */
    struct nlist *next;     /* next entry in chain */
    char *name;             /* defined name */
    char *defn;             /* replacement text */
};


#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}


/* lookup: look for s in hashtab */

struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;  /* found */
    return NULL;        /* not found */
}

struct nlist *lookup(char *);
char *strdup(const char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)  { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));

        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else  /* already there */
        free((void *) np->defn);    /* free the previous defn */

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    return np;
}

int undef(char* name) {
    struct nlist *np1, *np2;
    unsigned hashval = hash(name);
    
    for (np1 = hashtab[hashval], np2 = NULL; np1 != NULL; np2 = np1, np1 = np1->next) {
        if (strcmp(np1->name, name) == 0) {
            if (np2 == NULL) {
                hashtab[hash(name)] = np1->next;
            } else {
                np2->next = np1->next;
            }
        free(np1->name);
        free(np1->defn);
        free(np1);
        return 0;
        }
    }
    return 1;
}


int main(int argc, char *argv[]) {
    int i;
    install("id", "Savenok");
    install("id1", "Denkin");
    install("id2", "Iadrov");
    install("id3", "Savchenko");
    install("id4", "Parkhomenko");
    install("id5", "Slipchenko");
    
    printf("Finding: id - %s, id1 - %s, id2 - %s, id3 - %s, id4 - %s, id5 - %s\n", lookup("id")->defn, lookup("id1")->defn, lookup("id2")->defn, lookup("id3")->defn, lookup("id4")->defn, lookup("id5")->defn);
    printf("Undefing %s - res %d\n", "id3", undef("id3"));
    printf("Finding: id - %p, id - %p, id2 - %p, id3 - %p, id4 - %p, id5 - %p\n", lookup("id"), lookup("id1"), lookup("id2"), lookup("id3"), lookup("id4"), lookup("id5"));

    return 0;
}