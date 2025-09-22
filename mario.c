#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_space(int spaces);
void print_row(int brickes);

int main(void)
{
    //Get pyramid's height from the user
    int h = get_height();

    //Print a pyramid of that height
    for (int i = 0; i < h; i++)
    {
        // Print spaces
        print_space(h - i - 1);
        // Print bricks
        print_row(i + 1);
        // Print gap
        printf("  ");
        // Print brickes 2nd time
        print_row(i+1);
        printf("\n");
    }
}

// Prompt the user for the pyramid's height
int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1);
    return h;
}

//Print spaces
void print_space(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}
//Print bricks
void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}
