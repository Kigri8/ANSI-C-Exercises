#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  int menu;
  cout << "11 Makeup_Style:" << endl;
  cout << "22 Bridal:" << endl;
  cout << "33 Quinceañera:" << endl;
  cout << "44 Cocktail:" << endl;
  cout << "55 Casual:" << endl;
  cin >> menu;
  switch(menu)
    {
    case 11:
      cout << "Makeup styling service Bridal: " << endl;
      cout << "Cost 120 US$" <<endl;
      break;
    case 22:
      cout << "Makeup styling service Quinceañera: " << endl;
      cout << "Cost 90 US$" <<endl;
      break;
    case 33:
      cout << "Makeup styling service Cocktail:  " <<endl;
      cout << "Cost 60 US$" <<endl;
      break;
     
    case 44:
    cout << "Makeup styling service Casual: " <<endl;
    cout << "Cost 40 US$" <<endl;
     break;
     
     
    default:
      cout << "ERROR, We do not have this service" << endl;
      break;
    }
   
   
     system("pause");
     
     return 0;
}
