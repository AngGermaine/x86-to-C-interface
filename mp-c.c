#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function prototypes for assembly functions
extern void calculate_dx_asm(float *x1, float *x2, float *dx, int n);
extern void calculate_dy_asm(float *y1, float *y2, float *dy, int n);
extern void calculate_z_asm(float *dx, float *dy, float *z, int n);

// C-based implementation of the calculation
void calculate_dx_c(float *x1, float *x2, float *dx, int n) {
	int i;
    for (i = 0; i < n; i++) {
        dx[i] = x2[i] - x1[i];
    }
}

void calculate_dy_c(float *y1, float *y2, float *dy, int n) {
	int i;
    for (i = 0; i < n; i++) {
        dy[i] = y2[i] - y1[i];
    }
}

void calculate_z_c(float *dx, float *dy, float *z, int n) {
	int i;
    for (i = 0; i < n; i++) {
        z[i] = sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
    }
}

void randomize_vector(float *vec, int n) {
	int i;
    for (i = 0; i < n; i++) {
        int whole = rand() % 10 + 1; // Random integer from 1-10
    
        // Generate a random fractional part
        float fractional = (rand() / (float)RAND_MAX) * 1.0f;   
        fractional = roundf(fractional * 10.0f) / 10.0f;

        vec[i] = whole + fractional;  // Random values between 0 and 10
    }
}

void print_vectors_inline(const char *name, float *x1, float *x2, float *y1, float *y2, float *z, int n) {
    printf("%s (first 10 elements):\n", name);
    int i;
    for (i = 0; i < 10; i++) {
        printf("z[%d] = %.1f || x1 = %.1f, x2 = %.1f, y1 = %.1f, y2 = %.1f\n", 
            i, z[i], x1[i], x2[i],y1[i], y2[i]);
    }
}
int main() {
    int i, j;
    
    // Prompt for input size and vectors from the user
    int n;
    printf("Enter the number of elements for the input vectors (n): ");
    scanf("%d", &n);

    // Allocate memory for user input vectors and results
    float *x1 = (float *)malloc(n * sizeof(float));
    float *x2 = (float *)malloc(n * sizeof(float));
    float *y1 = (float *)malloc(n * sizeof(float));
    float *y2 = (float *)malloc(n * sizeof(float));
    float *dx = (float *)malloc(n * sizeof(float));
    float *dy = (float *)malloc(n * sizeof(float));
    float *z = (float *)malloc(n * sizeof(float));

    // Input the x1, x2, y1, and y2 vectors
    printf("Enter elements for vector x1:\n");
    for (i = 0; i < n; i++) {
        printf("x1[%d]: ", i);
        scanf("%f", &x1[i]);
    }

    printf("Enter elements for vector x2:\n");
    for (i = 0; i < n; i++) {
        printf("x2[%d]: ", i);
        scanf("%f", &x2[i]);
    }

    printf("Enter elements for vector y1:\n");
    for (i = 0; i < n; i++) {
        printf("y1[%d]: ", i);
        scanf("%f", &y1[i]);
    }

    printf("Enter elements for vector y2:\n");
    for (i = 0; i < n; i++) {
        printf("y2[%d]: ", i);
        scanf("%f", &y2[i]);
    }

    // Perform calculations using assembly functions
    calculate_dx_asm(x1, x2, dx, n);
    calculate_dy_asm(y1, y2, dy, n);
    calculate_z_asm(dx, dy, z, n);

    // Print the calculated vector z
    printf("\nCalculated vector Z using ASM:\n");
    for (i = 0; i < n; i++) {
        printf("z[%d] = %.5f (dx = %.2f, dy = %.2f)\n", i, z[i], dx[i], dy[i]);
    }

    // Free allocated memory
    free(x1);
    free(x2);
    free(y1);
    free(y2);
    free(dx);
    free(dy);
    free(z);
    
    
    
    
    
    
    
    
    
    int sizes[] = {1 << 20, 1 << 24, 1 << 26}; // Test sizes: 2^20, 2^24, 2^30
    int iterations = 30;

    srand(time(NULL));  // Seed random number generator

    // Iterate over the sizes array
    for (j = 0; j < 3; j++) {
    	printf("\nKernel# %d\n", j+1);
		printf("________________________________________________________________________\n");
        int n = sizes[j]; // Set the current size

        // Allocate memory for vectors and results
        float *x1 = (float *)malloc(n * sizeof(float));
        float *x2 = (float *)malloc(n * sizeof(float));
        float *y1 = (float *)malloc(n * sizeof(float));
        float *y2 = (float *)malloc(n * sizeof(float));
        float *dx = (float *)malloc(n * sizeof(float));
        float *dy = (float *)malloc(n * sizeof(float));
        float *z = (float *)malloc(n * sizeof(float));

        // Initialize vectors with random values
        randomize_vector(x1, n);
        randomize_vector(x2, n);
        randomize_vector(y1, n);
        randomize_vector(y2, n);
        
        

        // Time the kernel execution
        clock_t start, end;
        float total_time = 0.0;

        // Run the kernel 30 times for average execution time
        for (i = 0; i < iterations; i++) {
            start = clock();

            // Perform calculations using assembly functions
            calculate_dx_asm(x1, x2, dx, n);
            calculate_dy_asm(y1, y2, dy, n);
            
            calculate_z_asm(dx, dy, z, n);

            end = clock();
            total_time += (float)(end - start) / CLOCKS_PER_SEC;
        }
			int k;
            for (k = 0; k < 10; k++) {
   				 printf("dx[%d] = %.1f || dy[%d] = %.1f\n", k, dx[k], k, dy[k]);
			}

        // Print the first 10 elements of z (which is the result of sqrt(dx^2 + dy^2))
        printf("\nFirst 10 elements of vector Z (using ASM, size = %d):\n", n);
        print_vectors_inline("vectors", x1, x2, y1, y2, z, n);

        // Calculate and print the average execution time
        float avg_time = total_time / iterations;
        printf("Average execution time for %d elements (using ASM): %.6f seconds\n", n, avg_time);
        printf("Total execution time for %d elements (using ASM): %.6f seconds\n", n, total_time);

        printf("\nSANITY CHECK....\nC CALCULATIONS...\n", n);


		// Now check the C implementation for correctness
        float *dx_c = (float *)malloc(n * sizeof(float));
        float *dy_c = (float *)malloc(n * sizeof(float));
        float *z_c = (float *)malloc(n * sizeof(float));

		clock_t c_start, c_end;
        float c_total_time = 0.0;
		for (i = 0; i < iterations; i++) {
            c_start = clock();

            // Run the C version of the calculations
        	calculate_dx_c(x1, x2, dx_c, n);
        	calculate_dy_c(y1, y2, dy_c, n);
        	calculate_z_c(dx_c, dy_c, z_c, n);

            c_end = clock();
            c_total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
        }
        

     	printf("DONE CALCULATING IN C!\n", n);
     	
     	printf("\nFirst 10 elements of vector Z (C calculation, size = %d):\n", n);
        print_vectors_inline("vectors (C)", x1, x2, y1, y2, z_c, n);
        float c_avg_time = c_total_time / iterations;
        printf("Average execution time for %d elements (using C): %.6f seconds\n", n, c_avg_time);
        printf("Total execution time for %d elements (using C): %.6f seconds\n", n, c_total_time);

        // Check if the results from C and ASM are close enough (considering possible floating point precision)
        int match = 1;
        for (i = 0; i < n; i++) {
            if (fabs(z[i] - z_c[i]) > 1e-8) {
                printf("Mismatch at index %d: ASM: %.8f, C: %.8f\n", i, z[i], z_c[i]);
                match = 0;
            }
        }

        if (match) {
            printf("C and ASM calculations match.\n");
        } else {
            printf("C and ASM calculations do not match.\n");
        }

        // Free allocated memory for this iteration
        free(x1);
        free(x2);
        free(y1);
        free(y2);
        free(dx);
        free(dy);
        free(z);
        free(dx_c);
        free(dy_c);
        free(z_c);
        printf("________________________________________________________________________\n");

    }

    return 0;
}


