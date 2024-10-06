#include <stdio.h>
#include <stdlib.h>

void apply_function(double* arr, size_t size, void (*func)(double*, size_t));

void apply_function(double* arr, size_t arr_size, void (*func)(double*, size_t)) {
    return func(arr,arr_size);
}

void calculate(double initial, void (*func_passed)(double*,size_t)) {
    double numbers[50];
    size_t numbers_size = sizeof(numbers)/sizeof(numbers[0]);

    for (int i=0; i < numbers_size; i++) {
        numbers[i] = initial;
        // printf("index: %u,value: %f\n",i, numbers[i]);
    }

    int i = 0;
    while (i < numbers_size) {
        printf("Reading numbers (to stop reading insert 'x'): ");
        char input;
        scanf("%s",&input);

        if (input == 'x'){
            break;
        }

        double input_number = atof(&input);
        // printf("input number: %f, index: %d\n",input_number, i);
        numbers[i] = input_number;
        i++;
    }

    printf("You entered:\n");
    for (int j = 0; j < i; j++) {
        printf("%f ", numbers[j]);
    }
    printf("\n");

    apply_function(numbers, numbers_size, func_passed);
}

void add_numbers(double* array, size_t array_size) {
    double sum = 0.0;
    // printf("arr0 %f",array[0]);
    for (size_t i=0; i < array_size; i++) {
        // printf("number %f, index: %d\n",array[i],i);
        sum += array[i];
    }

    printf("Sum of all numbers: %f\n",sum);
}

void multiply_numbers(double* array, size_t array_size) {
    double multiplied = 1.0;
    // printf("arr0 %f",array[0]);
    
    for (size_t i=0; i < array_size; i++) {
        printf("number %f, index: %d\n",array[i],i);
        multiplied *= array[i];
    }

    printf("All numbers multiplied: %f\n",multiplied);

}

void divide_numbers(double* array, size_t array_size) {
    double divided = 1.0;
    for (size_t i=0; i < array_size; i++) {
        printf("number %f, index: %d\n",array[i],i);
        divided /= array[i];
    }

    printf("All numbers divided: %f\n",divided);
}

void prompt() {
    printf("Choose action:\n");
    printf("0. exit\n");
    printf("1. sum any numbers\n");
    printf("2. multiply any numbers\n");
    printf("3. divide any numbers\n");
    printf("Number limit: %d\n",50);
    
    char action;
    printf("Input option: ");
    scanf("%s",&action);
    printf("\n");

    switch (action) {
        case '0':
            printf("Exiting\n");
            exit(0);
            break;
        case '1':
            calculate(0.0,add_numbers);
            break;
        case '2':
            calculate(1.0,multiply_numbers);
            break;
        case '3':
            calculate(1.0,divide_numbers);
            break;
        default:
            printf("unimplemented\n");
            exit(0);
    }
}

int main() {
    prompt();
    return 0;
}
