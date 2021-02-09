#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "the3.h"


void add_meal(Node **meals_head, char *name, int count){
    Meal *temp_Meal;
    Node *temp_Node;
    Node *checking;
    
    temp_Meal = (struct Meal *) malloc(sizeof(struct Meal));
    temp_Node = (struct Node*) malloc(sizeof(struct Node));
    checking = (struct Node*) malloc(sizeof(struct Node));
    
    if (temp_Meal){
        if(temp_Node){
            if (checking){
                
                temp_Meal->name = name;
                temp_Meal->count = count;
                
                temp_Node->node = temp_Meal;
                
                checking = *meals_head;
                while ( 1 ) {
                    if (*meals_head == NULL) {
                        *meals_head = temp_Node;
                        break;
                    } else if ( checking->next == NULL ) {
                        checking->next = temp_Node;
                        break;
                    }
                    checking = checking->next;
                }
            }
        }
    }
}


void add_philosopher(Node **philosophers_head, char *name, char *favorite_meal, int age){
    Philosopher *temp_Philo;
    Node *temp_Node;
    Node *checking;
    
    temp_Philo = (struct Philosopher*) malloc(sizeof(struct Philosopher));
    temp_Node = (struct Node*) malloc(sizeof(struct Node));
    checking = (struct Node*) malloc(sizeof(struct Node));
    
    if (temp_Philo){
        if(temp_Node){
            if (checking){
                
                temp_Philo->name = name;
                temp_Philo->favorite_meal = favorite_meal;
                temp_Philo->age = age;
                
                temp_Node->node = temp_Philo;
                
                checking = *philosophers_head;
                while (1) {
                    if (*philosophers_head == NULL) {
                        *philosophers_head = temp_Node;
                        break;
                    } else if (checking->next == NULL ) {
                        checking->next = temp_Node;
                        break;
                    }
                    checking = checking->next;
                }
            }
        }
    }
}

void place_philosophers(Node **table_head, Node *philosophers){
    
    int age, curr_age;
    Node *np, *philo_Node, *curr, *prev;
    np = (Node *) malloc(sizeof(Node));
    np = philosophers;
    
    while (np != NULL) {
        age = ((Philosopher*)(np->node))->age;
        philo_Node = (Node *) malloc(sizeof(Node));
        philo_Node->node = (Philosopher*) np->node;

        if( *table_head == NULL) {
            *table_head = philo_Node;
            ((Philosopher*)(philo_Node->node))->sitting = 1;
            np = np->next;
            continue;
        }
        curr = *table_head;
        prev = NULL;
        
        curr_age = ((Philosopher*)(curr->node))->age;
        
        while (age > curr_age) {
            prev = curr;
            curr = curr->next;
                
            if (curr == NULL) {
                break;
            }
            curr_age = ((Philosopher*)(curr->node))->age;
        }
            
           
        if (curr){
            philo_Node->next = curr;
        }
            
        if (prev) {
            prev->next = philo_Node;
        } else {
            *table_head = philo_Node;
        }
        ((Philosopher*)(philo_Node->node))->sitting = 1;
        np = np->next;
    }
    
    
    np = *table_head;
    while (1) {
        if (np->next == NULL) break;
        np = np->next;
    }
    np->next = *table_head;
    
}


void remove_philosopher(Node **table_head, int index, int size_of_table){
    Node *before, *after, *np;
    int i;
    
    before = NULL;
    after = NULL;
    np = *table_head;
    
    for (i = 0; i < size_of_table; i++) {
        after = np->next;
        if (i == index) {
            if (before == NULL) {
                /* if it is the first node */
                before = *table_head;
                for (i = 0; i < size_of_table-1; i++) {
                    before = before->next;
                }
                *table_head = after;
            }
            before->next = after;
            break;
        }
        before = np;
        np = np->next;
    }
    
}


void serve_meals(Node *table, Node *meals){
    int len = get_length(table);
    int i;
    Node *np, *np_m;
    Philosopher *temp_Philo;
    
    np = table;
    temp_Philo = (Philosopher*)(np->node);
    
    for (i = 0; i < len; i++) {
        np_m = meals;
        while(1) {
            if ( strcmp( temp_Philo->favorite_meal, ((Meal*)(np_m->node))->name) == 0 ) {
                ((Meal*)(np_m->node))->count--;
                break;
            }
            np_m = np_m->next;
        }
        np = np->next;
        temp_Philo = (Philosopher*)(np->node);
    }
    
}

void print_list(Node *list, void (*helper_print)(void *)){
    
    Node *temp_Node;
    temp_Node = (struct Node*) malloc(sizeof(struct Node));
    temp_Node = list;
    
    while (1) {
        if (temp_Node->next == NULL) {
            helper_print(temp_Node->node);
            break;
        } else {
            helper_print(temp_Node->node);
            temp_Node = temp_Node->next;
        }
    }
}


void print_meal_node(void *meal){
    meal = (struct Meal*) meal;
    printf("Name: %s, count: %d\n", ((struct Meal*)meal)->name, ((struct Meal*)meal)->count);
}


void print_philosopher_node(void *philosopher){
    philosopher = (struct Philosopher*) philosopher;
    printf("Name: %s, favorite meal: %s, age: %d\n", ((struct Philosopher*)philosopher)->name, ((struct Philosopher*)philosopher)->favorite_meal, ((struct Philosopher*)philosopher)->age);
}

void print_table(Node *table){
    Node *before, *this_node, *after;
    int length, i;
    
    length = get_length(table);
    
    this_node = table;
    after = this_node->next;
    
    before = table;
    for (i = 0; i < length - 1; i++) {
        before = before->next;
    }
    
    for (i = 0; i < length; i++) {
        printf("%s -> %s -> %s\n", ((Philosopher*)(before->node))->name, ((Philosopher*)(this_node->node))->name, ((Philosopher*)(after->node))->name);
        before = before->next;
        this_node = this_node->next;
        after = after->next;
    }
    
}

int get_length(Node *list){
    
    int length = 0;
    Node *np, *first;
    np = list;
    first = list;
    
    while (1) {
        np = np->next;
        length += 1;
        if (np == NULL) {
            break;
        } else if (np == first) {
            break;
        }
    }
    return length;
    
}

Philosopher *get_philosopher(Node *philosophers, int index){
    Node *np;
    int i;
    
    np = philosophers;
    for (i = 0; i < index; i++) {
        np = np->next;
    }
    
    return ((Philosopher*)(np->node));
}