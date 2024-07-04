#include <iostream>
#include "cstring"
#include "string.h"
using namespace std;
#include<math.h>


void multiplyMatrices(double firstMatrix[][99], double secondMatrix[][99], double multResult[][99], int rowFirst, int columnFirst, int rowSecond, int columnSecond);
int rows_calc(char str_input[]){int z=0,r=1;
    while (str_input[z] != NULL){
        if (str_input[z] == ',')
            r++;
        z++;
    }return r;
}
int columns_calc(char str_input[]){
    int columns =1;
    for (int i = 1; i < strlen(str_input) ; ++i) {
        if (str_input[i]==',')
            break;
        if (str_input[i]==' ')
            columns++;
    }
    return columns;
}



int main() {
    int number, no_of_numbers, f = 0, z = 0, O = 0, rows_one, columns_one, rows_two, columns_two, inputs_num = 0, rows, columns;
    char input_one[100], input_two[100], matrix_operator[2];
    double final_matrix[99][99],inverse[99][99], matrix_one[99][99], matrix_two[99][99], num_array[99], num,determinant;

    gets(input_one);
    gets(matrix_operator);
    gets(input_two);
    char str1[99], str2[99];
    strcpy(str1, input_one);
    strcpy(str2, input_two);
    // CALCULATING THE NUMBER OF ROWS & COLUMNS
    rows_one = rows_calc(input_one), columns_one = columns_calc(input_one);
    rows_two = rows_calc(input_two), columns_two = columns_calc(input_two);
    rows = rows_one, columns = columns_one;
    //no_of_numbers = rows_one * columns_one;
    //cout <<columns_one <<' '<<columns_two;
    if (input_one[0] == '[' && input_two[0] == '[') {
        if (matrix_operator[0] =='*'){
            if (columns_one != rows_two){
                cout <<"ERROR!";
                return 0;
            }
        }else if (rows_one != rows_two || columns_one != columns_two) {
            cout << "ERROR!";
            return 0;
        }
    }


    if (input_one[0] == '[') {
        inputs_num++;
        // STRING INPUT --> NUM ARRAY
        for (int i = 0; i < strlen(input_one); ++i) { //CLEANING THE STR
            if (input_one[i] == '[' || input_one[i] == ']' || input_one[i] == ',')
                input_one[i] = ' ';
        }
        char *token = strtok(input_one, " ");
        while (token != NULL) { //ASSIGNMENT TO ARRAY
            num_array[z] = stod(token);
            token = strtok(NULL, " ");
            z++;
        }
        //INT ARRAY --> MATRIX
        for (int j = 0; j < rows_one; ++j) {
            for (int k = 0; k < columns_one; ++k) {
                // we have to get the element
                matrix_one[j][k] = num_array[O];
                O++;
            }
        }
    } else {
        num = stod(input_one);
    }
    if (input_two[0] == '[') {
        // STRING INPUT --> NUM ARRAY
        for (int i = 0; i < strlen(input_two); ++i) { //CLEANING THE STR
            if (input_two[i] == '[' || input_two[i] == ']' || input_two[i] == ',')
                input_two[i] = ' ';
        }
        char *token = strtok(input_two, " ");
        while (token != NULL) { //ASSIGNMENT TO ARRAY
            num_array[z] = stod(token);
            token = strtok(NULL, " ");
            z++;
        }
        //INT ARRAY --> MATRIX
        for (int j = 0; j < rows_two; ++j) {
            for (int k = 0; k < columns_two; ++k) {
                // we have to get the element
                matrix_two[j][k] = num_array[O];
                O++;
            }
        }
    } else {
        num = stod(input_two);
    }

    if (matrix_operator[0] == '+') {
        for (int j = 0; j < rows_one; ++j) {
            for (int k = 0; k < columns_one; ++k) {
                // we have to get the element
                final_matrix[j][k] = matrix_one[j][k] + matrix_two[j][k];

            }
        }
    } else if (matrix_operator[0] == '-') {
        for (int j = 0; j < rows_one; ++j) {
            for (int k = 0; k < columns_one; ++k) {
                // we have to get the element
                final_matrix[j][k] = matrix_one[j][k] - matrix_two[j][k];

            }
        }
    } else if (matrix_operator[0] == '*') {
        if (str2[0]=='['&&str1[0]!='['){
            rows=rows_two;
            columns=columns_two;
            for (int j = 0; j < rows_two; ++j) {
                for (int k = 0; k < columns_two; ++k) {
                    final_matrix[j][k] = num * matrix_two[j][k];
                }
            }
        }
        if (str1[0]=='['&&str2[0]!='['){
            for (int j = 0; j < rows_one; ++j) {
                for (int k = 0; k < columns_one ; ++k) {
                    final_matrix[j][k] = num * matrix_one[j][k];
                }
            }
        }
        if (str2[0]=='['&&str1[0]=='['){

            columns = columns_two;
            multiplyMatrices(matrix_one, matrix_two,final_matrix, rows_one, columns_one, rows_two, columns_two);

        }

    } else if (matrix_operator[0] == '/') {
        if (rows_two != columns_two){
            cout << "ERROR!";
            return 0;
        }
        //finding determinant


    }



    cout <<'[';
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < columns ; ++k) {
            if (k==0&& j==0){
                cout << final_matrix[j][k];
            } else {
                cout << ' ' << final_matrix[j][k];
            }
        }
        if (j==rows-1)
            break;
        cout <<',';
    }
    cout<< ']' <<endl;
    return 0;
}
void multiplyMatrices(double firstMatrix[99][99], double secondMatrix[99][99], double mult[99][99], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
    int i, j, k;
    for(i = 0; i < rowFirst; ++i)
    {
        for(j = 0; j < columnSecond; ++j)
        {
            for(k=0; k<columnFirst; ++k)
            {
                mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }

}
