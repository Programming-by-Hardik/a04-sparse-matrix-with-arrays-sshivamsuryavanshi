[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/eTMt0O7O)
# C Programming Assignment: Sparse Matrix Representation as an Array

## Objective
In this assignment, you will represent a **Sparse Matrix** using a compressed array format. Sparse matrices are matrices in which most elements are zero, and only non-zero elements are stored to save memory and improve efficiency. You will implement functions to create, store, and manipulate sparse matrices in a compressed array format.

## Tasks
You are required to complete the following tasks:

### 1. `createSparseMatrix`
- **Function Prototype**: `void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols);`
- **Description**: This function converts a given 2D matrix (with dimensions `rows x cols`) into a sparse matrix representation. Each non-zero element will be represented as a triplet: 
  - **Row index**
  - **Column index**
  - **Value**
- **Example**: For a 4x4 matrix:
0 0 3 0
0 4 0 0
0 0 0 5
0 2 0 6

The sparse matrix would store the non-zero values as:
4 4 5      (4x4 matrix with 5 non-zero elements)
0 2 3      (Element at row 0, column 2 is 3)
1 1 4      (Element at row 1, column 1 is 4)
2 3 5      (Element at row 2, column 3 is 5)
3 1 2      (Element at row 3, column 1 is 2)
3 3 6      (Element at row 3, column 3 is 6)

### 2. `printSparseMatrix`
- **Function Prototype**: `void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount);`
- **Description**: This function prints the sparse matrix in a tabular format, displaying the row index, column index, and value of each non-zero element.

## Instructions

1. **Open the `sparse_matrix_assignment.c` file**:
 - The file contains the main program structure with test cases for the `createSparseMatrix` and `printSparseMatrix` functions.
 - Your task is to complete the functions `createSparseMatrix` and `printSparseMatrix`.

2. **Fill in the TODO sections**:
 - **In `createSparseMatrix`**: Implement the logic to traverse the given original matrix, find non-zero values, and store them in the sparse matrix.
 - **In `printSparseMatrix`**: Implement the logic to print the sparse matrix in the format: `Row   Column   Value`.

3. **Run the test cases**:
 - The provided test cases automatically check if your implementation is correct.
 - The results will show either `PASSED` or `FAILED` for each test.

4. **Submit your completed `sparse_matrix_assignment.c` file**.

## Running the Program

### Compilation and Execution

1. **Manual Compilation**:
 - Compile the program using the following command:
   ```bash
   gcc -o sparse_matrix_assignment hello.c
   ```

2. **Run the Program**:
 ```bash
 ./sparse_matrix_assignment
 ```
 The program will run the test cases and output whether they passed or failed.

**Expected Output**

When all tests pass, you should see output similar to:
testCreateSparseMatrix PASSED
Expected Sparse Matrix Output:
Row    Column   Value
4      4        5
0      2        3
1      1        4
2      3        5
3      1        2
3      3        6
testPrintSparseMatrix PASSED