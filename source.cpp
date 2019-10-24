#include <iostream>
#include <fstream>
#include <string>

void dessinerCarre(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = 0; leI < uneTaille; leI++)
  {
    for (int leJ = 0; leJ < unEspace; leJ++)
    {
      std::cout << " ";
    }
    for (int leJ = 0; leJ < uneTaille; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == (uneTaille - 1) || leI == 0 || leI == (uneTaille -1))
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout << '\n';
  }
}

void dessinerTriangleRectangle(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leSommai = 1;
  for (int leI = 0; leI < uneTaille; leI++)
  {
    for (int leJ = 0; leJ < unEspace; leJ++)
    {
      std::cout << " ";
    }

    for (int leJ = 0; leJ < leSommai; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if (leJ == 0 || leJ == (leSommai - 1) || leI == (uneTaille - 1))
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout <<'\n';
    leSommai++;
  }
}

void dessinerTriangleRectangleInv(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leSommai = uneTaille;
  for (int leI = 0; leI < uneTaille; leI++)
  {
    for (int leJ = 0; leJ < unEspace; leJ++)
    {
      std::cout << " ";
    }

    for (int leJ = 0; leJ < leSommai; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if (leJ == 0 || leJ == (leSommai - 1) || leI == 0)
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout <<'\n';
    leSommai--;
  }
}

void dessinerTriangle(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = 0; leI < (uneTaille / 2) + (uneTaille % 2); leI++)
  {
    for (int leJ = 0; leJ < (unEspace + leI); leJ++)
    {
      std::cout << " ";
    }
    for (int leJ = 0; leJ < (uneTaille - leI*2) ; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == ((uneTaille - 1) - (leI * 2)) || leI == 0 )
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout << '\n';
  }
}


void dessinerTriangleInverse(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = (uneTaille / 2) + (uneTaille % 2); leI > -1; leI--)
  {
    for (int leJ = 0; leJ < (unEspace + leI); leJ++)
    {
      std::cout << " ";
    }
    for (int leJ = 0; leJ < (uneTaille - leI*2) ; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == ((uneTaille - 1) - (leI * 2)) || leI == 0 )
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout << '\n';
  }
}

void dessinerLosange(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leTabTest[2] = {uneTaille/2, uneTaille%2};
  bool leMilieur = false;
  for (int leI = 0; leI < uneTaille; leI++) {
    for (int leJ = 0; leJ < unEspace+leTabTest[0]; leJ++) {
      std::cout << " ";
    }
    for (int leJ = 0; leJ < leTabTest[1]; leJ++) {
      std::cout << unCar;
    }
    std::cout << '\n';
    if (leMilieur == false) {
      leTabTest[0] --;
      leTabTest[1] += 2;
    }
    else
    {
      leTabTest[0]++;
      leTabTest[1] -= 2;
    }
    if (leTabTest[0] == 0) {
      leMilieur = true;
    }
  }
}


int decoderForme(std::string uneForme)
{
  std::string lesFormePossible[6]={"carre","triangle rectangle","triangle rectangle inverse","triangle","triangle inverse","losange"};
  for (int leI = 0; leI < 6; leI++)
  {
    if (uneForme == lesFormePossible[leI])
    {
      return leI;
    }
  }
  return -1;
}


int main()
{
  std::ifstream monFichier("figure.txt");
  std::string laForme, leRemplissage;
  int laTaille, laDecal;
  char leCar;
  while (not monFichier.eof())
  {
    getline(monFichier, laForme);
    monFichier >> laTaille;
    monFichier.ignore();

    monFichier >> laDecal;
    monFichier.ignore();

    monFichier >> leCar;
    monFichier.ignore();

    getline(monFichier, leRemplissage);

    switch (decoderForme(laForme)) {
      case 0:
        dessinerCarre(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 1:
        dessinerTriangleRectangle(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 2:
        dessinerTriangleRectangleInv(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 3:
        dessinerTriangle(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 4:
        dessinerTriangleInverse(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 5:
        dessinerLosange(laTaille, laDecal, leCar, leRemplissage);
      break;

      default :
      std::cout << "ERROR ! \n forme non pris en charge" << '\n';
    }
  }
  return 0;
}
