/** Sean Gurr
 *  C00221886
 *  Ex. 7
 *  Coordinate Conversion
 *  08/11/2017
 */

/**< Preprocessor directives */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <windows.h>


using namespace std;


/**< Function prototypes */
void cartesiantopolar(float x, float y, float *ptr_mag, float *ptr_angle);
void polartocartesian (float mag, float angle, float *ptr_x, float *ptr_y);
char displayMenu();
void cart_to_Pol(void);
void pol_to_Cart(void);


/**< Main function */
int main(void)
{

   /**< Variable declaration */
   char choice;

	do
	{
	    choice = displayMenu();

		/**< switch case statement to implement user's decision */
		switch (choice)
		{
			case 'p':   cart_to_Pol();
                        break;

			case 'c':   pol_to_Cart();
                        break;

			case 'q':
                        cout << "\nGoodbye...\n" << endl;
						break;

			default:
                        cout << "\nInvalid input, try again...\n" << endl;
                        break;


		}
	}
	while (choice != 'q');

	return 0;
}

/**< Display menu fucntion */
char displayMenu(void)
{

        /**< Variable declaration */
        char choice;

        /**< Purpose of code */
        cout << "\nCoordinate Conversion" << endl;

        cout<<  "\n Choose an option from the following: "<<
                "\n 'p' cartesian to polar conversion"<<
                "\n 'c' polar to cartesian conversion"<<
                "\n 'q' to quit programme \t";

		cin >> choice ;

		return choice;

}


void cart_to_Pol(void)
{

    /**<  Variable declarations */
    float x, y, mag, angle;
    float *ptr_mag,*ptr_angle;

    void cartesiantopolar(float, float, float *, float *);


    ptr_mag = &mag;
    ptr_angle = &angle;

    cout << "\nEnter a value for x and y"<<endl;
    cin >> x >> y ;

    cartesiantopolar(x, y, ptr_mag, ptr_angle);

    cout << "\nThe magnitude is: " << mag << endl;
    cout << "\nThe angle is: " << angle << " degrees" << endl;

  return;
}


void cartesiantopolar(float x, float y, float *ptr_mag, float *ptr_angle)
{
   *ptr_mag = sqrt(pow(x,2.0)+ pow(y,2.0));
   *ptr_angle = atan2(y,x) / M_PI * 180.0;

   return;
}


void pol_to_Cart(void)
{

    float rad, angle, x, y;
    //float x =0, y=0, ang =0, rad =0;
    float *ptr_x, *ptr_y;

    ptr_x = &x;
    ptr_y = &y;

    cout << "Enter magnitude for rad : " << endl;
    cin >> rad;
    cout << "Enter angle: " << endl;
    cin>> angle;

    polartocartesian (rad, angle, ptr_x, ptr_y);

    if (y >= 0)
        cout <<"The cartesian co-odinates are : " << x << " + " << y << " j " << endl;
    else
        cout <<"The cartesian co-odinates are : " << x << " - " << fabs(y) << " j " << endl;

     return;
}


void polartocartesian (float rad, float angle, float *ptr_x, float *ptr_y)
{
    *ptr_x = rad * cos(angle / 180 * M_PI);
    *ptr_y = rad * sin(angle / 180 * M_PI);

    return;
}
