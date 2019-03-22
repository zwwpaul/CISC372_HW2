/* Header file for the evens library.
 * This serves as the interface for the library.
 */

/* Finds the even numbers in the given sequence.
 * Consumes:
 *   p : pointer to the first int in the sequence
 *   n : the number of ints in the given sequence
 *   num_evens (out): used to return the number of even numbers
 * Returns:
 *   A newly allocated sequence consisting of the even numbers
 *   from the original sequence.
 * Notes:
 *   - the memory allocated for the resulting sequence will be 
 *     exactly enough to hold num_evens ints
 *   - this function will not modify the original sequence
 */
int * find_evens(int * p, int n, int * num_evens);

/* Prints an array of ints to stdout.  The ints are separated
 * by a space.  A newline is printed at the end.
 * Consumes:
 *   p : pointer to the first in the sequence
 *   n : the number of ints in the sequence
 */
void print_array(int * p, int n);
