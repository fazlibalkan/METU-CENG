/* IT WILL NOT BE USED IN GRADING! YOU CAN USE IT FOR TESTING PURPOSES.*/
#include <stdio.h>
#include <stdlib.h>
#include "the3.h"


int main() {
    Node *meals = NULL;
    Node *philosophers = NULL;
    Node *table = NULL;

    add_meal(&meals, "Kung Pao", 3);
    add_meal(&meals, "Tofu", 1);
    add_meal(&meals, "Wonton", 2);
    add_meal(&meals, "Fried Rice", 3);

    add_philosopher(&philosophers, "Lao Tzu", "Wonton", 1424);
    add_philosopher(&philosophers, "Confucius", "Tofu", 1145);
    add_philosopher(&philosophers, "Mozi", "Fried Rice", 1976);
    add_philosopher(&philosophers, "Shang Yang", "Fried Rice", 1555);
    
    
    place_philosophers(&table, philosophers);
    print_table(table);
    
    return 0;
}