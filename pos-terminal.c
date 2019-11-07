#include<stdio.h>
#include<math.h>

int main()
{
  double apples_cost=3.59;
  double tomatoes_cost=2.29;
  double lettuce_cost=1.49;
  double cucumbers_cost=1.29;
  unsigned number_apples;
  unsigned number_cucumbers;
  unsigned number_tomatoes;
  unsigned number_lettuce;
  double apples_weight;
  int choice;

  do
  {
    /* you can use a printf() function for each line */
    printf("MAIN MENU\n");
    printf("Option Action\n");
    /* etc */

    printf("Enter the desired option: ");
    choice = getchar();

    switch (choice)
    {
      case 'A':
        printf("Weight in kg of apples: %s");
        scanf("%le", &apples_weight);
        break;
    }

  } while (choice !='&');

  return (0);
}