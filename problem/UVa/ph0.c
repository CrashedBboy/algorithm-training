#include "stdio.h"
#include "stdlib.h"
const int MAX = 20;
int cmpfunc (const void * a, const void * b){
       return ( *(int*)a - *(int*)b );
}
int main(){
    FILE *file;
    FILE *output;
    char buffer;
    int MaxDegree;
    int treeMaxDegree;
    int treeArray[MAX];
    int length = 0;
    int i = 0;
    file = fopen("input.txt", "r");
    output = fopen("output.txt", "a");
    buffer = fgetc(file);
    MaxDegree = buffer - '0';
    buffer = fgetc(file);
    while((buffer = fgetc(file)) != EOF){
        if(buffer != '\n' && buffer != ' '){
            treeArray[length] = buffer - '0';
            length += 1;
        }else if(buffer == '\n'){
            qsort(treeArray, length, sizeof(int), cmpfunc);
            fprintf(output, "%d\n", length);
            for(i = 0; i < length; i++){
                if(i < (length-2)){
                    int j;
                    for(j = i + 1; j < length; j++){
                        if(treeArray[j] > treeArray[i]){
                            treeArray[i] -= 1;
                            treeArray[j] -= 1;
                            fprintf(output, "%d %d\n", i+1 , j+1);
                            break;
                        }
                    }
                }else if(i == (length-2)){
                   fprintf(output, "%d %d\n", i+1 , i+2);
                }
            }
            fprintf(output, "\n");
            length = 0;
        }
    }
    fclose(file);
    fclose(output);
    return 0;
}

/*-----------------------------------------------------------------------------
 * Describe:
 * Let d1, d2, …, dn, n ≥ 2, be positive integers. Prove that if d1 + d2 + … + dn = 2n − 2,
 * then there exists a tree with n vertices of degrees exactly d1, d2.., dn,
 * Based on your proof, design an efficient algorithm to construct such a tree.
 *
 * Input:
 * You will get the maximum degree of vertices (e.g. 3) in the first line and some sequences in the next lines in which the integers of each sequence indicate a tree with n vertices of degrees exactly d1, d2, …, dn.
 *
 * Output:
 * For each tree, you should print the number of vertices and all the edges in order of label where the vertices are numbered from 1 to n.
 * And each output should be separated by one space line for each input sequence.
 *
 * Sample Input:
 * 3
 * 1 2 1
 * 1 3 1 1 2
 * 1 3 2 2 1 1
 *
 * Sample Output:
 * 3
 * 1 2
 * 2 3
 * 5
 * 1 2
 * 2 3
 * 2 5
 * 4 5
 * 6
 * 1 2
 * 2 3
 * 2 6
 * 3 4
 * 4 5
 ---------------------------------------------------------------------------------*/
