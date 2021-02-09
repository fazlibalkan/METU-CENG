#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "the2.h"

/*
INPUT:
    int *row_count: vertical size of the matrix to be assigned (passed by reference from the main function)
    int *row_size: horizontal size of the matrix to be assigned (passed by reference from the main function)

OUTPUT:
    double **matrix: created data matrix

METHOD:
    This function creates the matrix streamed via stdin. 
    During this process, assigns row_count and row_size variables.
*/
double **initialize_the_data(int *row_count, int *row_size) { 
    
    double **array, num;
    int i = 0, j = 0, rc = 1, rs = 1, counted = 0, done_rs = 0;;
    
    array = (double **) malloc(sizeof(int *) * (rc));
    array[i] = (double *) malloc(sizeof(double) * (rs));
    while (1) {
        scanf("%lf", &num);
        if( num == -1 && j == 0 ) {
            array[i][j] = -1;
            break;
        }
        if (num != -1) {
            array[i][j] = num;
            j++;
            rs++;
            array[i] = (double *) realloc(array[i], sizeof(double) * rs);
        } else {
            array[i][j] = -1;
            if (counted == 0) {
                done_rs = rs;
            }
            j = 0;
            i++;
            rc++;
            rs = 1;
            array = (double**) realloc(array, sizeof(int *) * rc);
            array[i] = (double *) malloc(sizeof(double) * rs);
            counted = 1;
        }
    }
    
    *row_size = done_rs - 1;
    *row_count = rc - 1;
    
    return array;
    
}

/*
INPUT:
    double **matrix: data matrix
    int n: number of rows to be printed
    int row_size: horizontal size of the matrix

METHOD:
    This function prints first n row of the matrix.
*/
void print_first_n_row(double **matrix, int n, int row_size) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < row_size; j++) {
            printf("%.4f", matrix[i][j]);
            if ( j != row_size - 1) {
                printf(" ");
            }
        }
        if ( i != n - 1) {
            printf("\n");
        }
    }
}

/*
INPUT:
    double **matrix: data matrix
    int row_size: horizontal size of the data matrix
    int row1: index of the first row in the calculation
    int row2: index of the second row in the calculation

METHOD:
    This function calculates dot product of the row1 and the row2 and prints it in the following format:
        Dot product of rows <row1>, <row2>: <dot_product>
*/
void calculate_dot_product(double **matrix, int row_size, int row1, int row2) {
    int i = 0;
    double dot_product = 0, temp = 0;
    
    for (i = 0; i < row_size; i++) {
        temp = matrix[row1][i] * matrix[row2][i];
        dot_product += temp;
    }
    
    printf("Dot product of rows %d, %d: %.4f", row1, row2, dot_product);
}

/*
INPUT:
    double **matrix: data matrix
    int row_count: vertical size of the data matrix
    int row_size: horizontal size of the data matrix

OUTPUT:
    double **covariance_matrix: Created covariance matrix with size of row_size X row_size

METHOD:
    This function creates covariance matrix of the original data matrix and returns it.

*/
double **calculate_covariance_matrix(double **matrix, int row_count, int row_size) { 

    double **array, mean_1 = 0, mean_2 = 0, sum = 0;
    int i, j, k;
    
    array = (double**) malloc(sizeof(int*) * (row_size + 1));
    
    for (i = 0; i < row_size + 1; i++) {
        array[i] = malloc(sizeof(double) * (row_size + 1));
        if (i == row_size) {
            array[i][0] = -1;
        } else {
            array[i][row_size] = -1;
        }
    }
    
    for (i = 0; i < row_size; i++) {
        for (j = 0; j < row_size; j++) {
            mean_1 = 0;
            mean_2 = 0;
            for (k = 0; k < row_count; k++) {
                    mean_1 += matrix[k][i];
                    mean_2 += matrix[k][j];
            }
            mean_1 /= row_count;
            mean_2 /= row_count;
            sum = 0;
            for (k = 0; k < row_count; k++) {
                sum += ((matrix[k][i] - mean_1) * (matrix[k][j] - mean_2));
            }
            array[i][j] = (sum / (row_count - 1));
        }
    }
    return array; 
}

/*
INPUT:
    double **matrix: data matrix
    int row_count: vertical size of the data matrix
    int row_size: horizontal size of the data matrix

OUTPUT:
    double **result: Created result matrix with size of row_size X row_size

METHOD:
    This function calculates x^T * x. First finds the transpose of the original data matrix and apply matrix multiplication.
    At the end it returns the calculated matrix with size of row_size X row_size.

*/
double **calculate_x_transpose_times_x(double **matrix, int row_count, int row_size) { 
    double **tr_matrix, **result;
    int i, j, k;
    
    tr_matrix = (double **) malloc(sizeof(int *) * row_size);
    for (i = 0; i < row_size; i++) {
        tr_matrix[i] = malloc(sizeof(double) * row_count);
    }
    /*Transpose*/
    for(i = 0; i < row_count; i++) {
        for (j = 0; j < row_size; j++) {
            tr_matrix[j][i] = matrix[i][j];
        }
    }
    /*Resulted Matrix*/
    result = (double **) malloc(sizeof(int *) * row_size );
    
    for (i = 0; i < row_size; i++) {
        result[i] = malloc(sizeof(double) * row_size);
    }
    
    /*Matrix Multiplication*/
    /*
    row_count of transpose = row_size = i
    row_size of normal = row_size = j
    row_size of transpose = row_count = k
    */
    for (i = 0; i < row_size; i++) {
        for (j = 0; j < row_size; j++) {
            for (k = 0; k < row_count; k++) {
                result[i][j] += tr_matrix[i][k] * matrix[k][j];
            }
        }
    }
    return result; 
    
}

/*
INPUT:
    double **matrix: data matrix
    int *group_count: number of the groups to be assigned (passed by reference from the main function)
    int row_count: vertical size of the data matrix
    int row_size: horizontal size of the data matrix
    int group_column: index of the column to apply grouping over
    int operation: index of the operation to apply during grouping
        SUM -> 0
        AVG -> 1
        MAX -> 2
        MIN -> 3

OUTPUT:
    double **grouped_matrix: Created grouped matrix with size of group_count X row_size

METHOD:
    This function applies grouping over desired column index, creates a grouped matrix. It returns this grouped matrix.
    During this process it calculates group count and assigns to the variable.

*/
double **group_by(double **matrix, int *group_count, int row_count, int row_size, int group_column, int operation) {
    double **group, *list;
    double num;
    int i,  j, k, a, how_many, new_row_count = 0, is_there = 0, is_first = 1;
	
    

    for (i = 0; i < row_count; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (matrix[j][group_column] == matrix[i][group_column]) {
                is_there = 1;
                break;
            }
        }
        if (is_first) {
        	new_row_count++;
        	list = (double *) malloc( sizeof(double) * new_row_count);
        	list[new_row_count - 1] = matrix[i][group_column];
        	is_first = 0;
        } else { 
        	if (is_there == 0) {
        		new_row_count++;
        		list = (double *) realloc(list, sizeof(double) * new_row_count);
        	    list[new_row_count - 1] = matrix[i][group_column];
        	    
        	}
        	is_there = 0;
        }

        
    }
    
    *group_count = new_row_count;
    
    group = (double**) malloc(sizeof(double*) * (*group_count));
    for (i = 0; i < new_row_count; i++) {
        group[i] = malloc(sizeof(double) * row_size);
    }
    
    
    if ( operation == 0 ) {
        i = 0;
        a = 0;
        
        while ( i < new_row_count ) {
            num = list[i];
            for (j = 0; j < row_count; j++) {
                if ( matrix[j][group_column] == num ) {
                    for (k = 0; k < row_size; k++) {
                        if ( k != group_column ) {
                            group[a][k] += matrix[j][k];
                            continue;
                        }
                        group[a][k] = matrix[j][k];
                    }
                }
            }
            a++;
            i++;
        }
        
    } else if ( operation == 1 ) {
        i = 0;
        a = 0;
        while ( i < new_row_count ) {
            how_many = 0;
            num = list[i];
            for (j = 0; j < row_count; j++) {
                if ( matrix[j][group_column] == num ) {
                    how_many += 1;
                    for (k = 0; k < row_size; k++) {   
                        if ( k != group_column ) {
                            group[a][k] += matrix[j][k];
                            continue;
                        }
                        group[a][k] = matrix[j][k];
                    }
                }
            }
            for (k = 0; k < row_size; k++) {
                if ( k != group_column ) {
                    group[a][k] /= how_many;
                    continue;
                }
            }
            a++;
            i++;
        }
        
    } else if ( operation == 2 ) {
    	i = 0;
        a = 0;
        while ( i < new_row_count ) {
            num = list[i];
            is_first = 1;
            for (j = 0; j < row_count; j++) {
                if ( matrix[j][group_column] == num ) {
                    for (k = 0; k < row_size; k++) {
                        if ( k != group_column ) {
                            if ( is_first ) {
                                group[a][k] = matrix[j][k];
                            } else {
                                if ( matrix[j][k] > group[a][k] ) {
                                    group[a][k] = matrix[j][k];
                                }
                            }
                            continue;
                        }
                        group[a][k] = matrix[j][k];
                    }
                    is_first = 0;
                }
            }
            a++;
            i++;
        }
        
    } else if ( operation == 3 ) {
        i = 0;
        a = 0;
        while ( i < new_row_count ) {
            num = list[i];
            is_first = 1;
            for (j = 0; j < row_count; j++) {
                if ( matrix[j][group_column] == num ) {
                    for (k = 0; k < row_size; k++) {
                        if ( k != group_column ) {
                            if ( is_first ) {
                                group[a][k] = matrix[j][k];
                            } else {
                                if ( matrix[j][k] < group[a][k] ) {
                                    group[a][k] = matrix[j][k];
                                }
                            }
                            continue;
                        }
                        group[a][k] = matrix[j][k];
                    }
                    is_first = 0;
                }
            }
            a++;
            i++;
        }
    } 
    
    
    return group; 
}

/*
INPUT:
    double **matrix: data matrix
    int row_count: vertical size of the data matrix
    int row_size: horizontal size of the data matrix
    double **kernel: kernel matrix
    int kernel_height: vertical size of the kernel matrix
    int kernel_width: horizontal size of the kernel matrix

OUTPUT:
    double **convoluted_matrix: Created convoluted matrix

METHOD:
    This function applies convolution over data matrix using kernel matrix and returns created matrix.

*/
double **convolution(double **matrix, int row_count, int row_size, double **kernel, int kernel_height, int kernel_width) {
    double **solution, willbeadded;
    int sol_width, sol_height, i, j, x, y;
    
    
    sol_height = row_count - kernel_height + 1;
    sol_width = row_size - kernel_width + 1;
    
    solution = (double **) malloc(sizeof( int * ) * sol_height);
    for (i = 0; i < sol_height; i++) {
        solution[i] = (double *) malloc(sizeof(double) * sol_width); 
    }
    
    for (i = 0; i < sol_height; i++) {
        for (j = 0; j < sol_width; j++) {
            willbeadded = 0;
            for (x = 0; x < kernel_height; x++) {
                for (y = 0; y < kernel_width; y++) {
                    willbeadded += (matrix[i + x][j + y] * kernel[x][y]);
                }
            }
            solution[i][j] = willbeadded;
        }
    }
    
    
    return solution;
}