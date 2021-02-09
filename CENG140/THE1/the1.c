#include <stdio.h>
#include <math.h>
#include "the1.h"

/* INITIALIZE THE TREE */
void initialize_the_tree(int binary_tree[MAX_LENGTH], int get_values_from_user) {
    int i;
    
    for (i = 0; i < MAX_LENGTH; i++) {
            binary_tree[i] = -1;
    }
    
    if (get_values_from_user != 0){
        int how_many;
        scanf("%d", &how_many);
        
        for (i = 0; i < how_many; i++) {
            int index, value;
            scanf("%d %d", &index, &value);
            
            if (index >= MAX_LENGTH) {
                continue;
            } else if (binary_tree[index] == -1) {
                binary_tree[index] = value;
            }
        }
    }
}

/* INSERT NODE */
void insert_node(int binary_tree[MAX_LENGTH], int node, char where, int value) {
    
    if (where == 'i') {
        if (binary_tree[node] == -1) {
            binary_tree[node] = value;
        }
    } else if (where == 'l') {
        if (binary_tree[ 2 * node + 1 ] == -1) {
            binary_tree[ 2 * node + 1 ] = value;
        }
    } else if (where == 'r') {
        if (binary_tree[ 2 * node + 2 ] == -1) {
            binary_tree[ 2 * node + 2 ] = value;
        }
    }
    
}

/*DELETE NODE REC*/
void delete_node_rec(int binary_tree[MAX_LENGTH], int node) {
    if (node > MAX_LENGTH) {
        return;
    }
    
    binary_tree[node] = -1;
    delete_node_rec(binary_tree , 2*node+1);
    delete_node_rec(binary_tree, 2*node+2);
}

/*DRAW BINARY TREE*/
void dbt_rec_helper(int depth) {
    if (depth == 0) {
        return;
    }else {
        printf("\t");
        dbt_rec_helper(depth - 1);
    }
}

void draw_binary_tree_rec(int binary_tree[MAX_LENGTH], int root, int depth) {
    
    if (root >= MAX_LENGTH || depth == -1) {
        return;
    }
    if (binary_tree[root] != -1) {
        draw_binary_tree_rec(binary_tree, 2 * root + 1, depth - 1);
        dbt_rec_helper(depth);
        printf("%d\n", binary_tree[root]);
        draw_binary_tree_rec(binary_tree, 2 * root + 2, depth - 1);
    }
}

/*FIND HEIGHT OF TREE REC*/

int fhot_helper(int binary_tree[MAX_LENGTH], int root, int is_first) {
    int height = 0, left_height, right_height;
    if ( root >= MAX_LENGTH ) {
    	return -1;
    }
    if (binary_tree[root] == -1) {
        if (is_first == 1) {
            return 0;
        }
        return -1;
    }
    left_height = fhot_helper(binary_tree, 2*root+1, 0) + 1;
    right_height = fhot_helper(binary_tree, 2*root+2, 0) + 1;
        
    if (left_height > right_height) {
        height = left_height;
    } else {
        height = right_height;
    }
    return height;
}

int find_height_of_tree_rec(int binary_tree[MAX_LENGTH], int root) {
    fhot_helper(binary_tree, root, 1);
}

/*FIND MIN OF TREE REC*/
int fmot_rec_helper(int binary_tree[MAX_LENGTH], int root, int min) {
    
    if ( root > MAX_LENGTH ) {
    	return min;
    }
    if (binary_tree[root] == -1) {
        return min;
    } else if (min == -1) {
        min = binary_tree[root];
    } else if (binary_tree[root] < min ) {
        min = binary_tree[root];
    }
        
    min = fmot_rec_helper(binary_tree, 2*root+1, min);
    min = fmot_rec_helper(binary_tree, 2*root+2, min);
        
    return min;
}

int find_min_of_tree_rec(int binary_tree[MAX_LENGTH], int root) {
    fmot_rec_helper(binary_tree, root, -1);
}


/*BREADTH FIRST SEARCH ITR*/
int breadth_first_search_itr(int binary_tree[MAX_LENGTH], int root, int value) {
    int is_true = 1, i;
    int how_many = 2;
    
    if ( binary_tree[root] == value ) {
    	return root;
    }
    while( is_true ) {
        root = 2 * root + 1;
        for (i = 0; i < how_many; i++) {
            if (root + i >= MAX_LENGTH) {
                return -1;
            }
            if (binary_tree[root + i] == value) {
                return root + i;
            }
        }
        how_many *= 2;
    }
}
     
/*DEPTH FIRST SEARCH REC*/
int dfs_helper(int binary_tree[MAX_LENGTH], int root, int value, int first) {
        
    if ( root > MAX_LENGTH ) {
    	return first;
    }
    if (binary_tree[root] == -1) {
        return first;
    }
        
    first = dfs_helper(binary_tree, 2*root+1, value, first);
    if (first == -1) {
        if (binary_tree[root] == value) {
            first = root;
        }
    }
    first = dfs_helper(binary_tree, 2*root+2, value, first);
        
    return first;
        
}

int depth_first_search_rec(int binary_tree[MAX_LENGTH], int root, int value) {
    dfs_helper(binary_tree, root, value, -1);
}



void print_binary_tree_values(int binary_tree[MAX_LENGTH]) {
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        if (binary_tree[i] != -1) {
            printf("%d - %d\n", i, binary_tree[i]);
        }
    }
}