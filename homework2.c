#include <stdio.h>
int IntToBinary(int num); //Secundary Function of the program
int main()
{
    int k = 25; //Variable to count the number of prime numbers 
    int count_num = 0, num = 2, count = 0;
    int is_primer, start_in;
    while (count_num < k) // As long as count_num is less than the desired k it will search for prime numbers
    {
        is_primer = 1;
        for (start_in = 2; start_in < num; ++start_in) { // While start_in is less than num it is executed
            if (num % start_in == 0) { //if the residue of the numer evaluated in start_in is equal to 0 
                is_primer = 0; //is_primer is equal to 0 and the cicle end
                break;
            }
        }
        
        if (is_primer)
        {
            printf("%d is a primer number - in binary is ",num); //print the primer number found
            IntToBinary(num); //call to the secundary function 
            count_num++;   //add one to count_num until be equal to k (all the prime numbers need it) 
            
            
        }
        num++; //add one a num to evaluate the next number of the positive real numbers
    }
    return 0;
} //the cicle is repeated until count_num < k 

int IntToBinary(int num) 
{
    //Convert int to binary
    int i,j,sum;
    int binary[100]; // asign an extension 100 digits for the binary number
    for(i=0; num>0; i++) //started with i in 0, while num be greater than 0 
    {
        binary[i] = num % 2; //the number of prime number is divided by 2  and based on that it is determined whether to encode 1 or 0
        num = num / 2; //the result of the before function  still divided by 2 until the number be 0
    }
    
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d",binary[j]); // print the binary code of the prime number
    }
    printf("\n"); //pass to the next line
    return 0;
}
/*
000000001
000011111
000100101
000101001
000110101
000111011
000111101
001000011
001000111
001001001
001001111
*/