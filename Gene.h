#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include "Allele.h"

using namespace std;
class Gene
{
  private:
	string traitType;
	string geneName;
	Allele AlleleA;
	Allele AlleleB;

  public:
	Gene(Allele Allele1, Allele Allele2);
	Gene();

	string getGeneTraitType();
	void setGeneTraitType(string geneTrait);
	string getGeneName();
	void setGeneName(string geneName);
	void getExpressedTrait();
	void OutputToFile(ofstream &of);

	Allele getAlleleA();
	void setAlleleA(Allele Allele1);
	Allele getAlleleB();
	void setAlleleB(Allele Allele2);
	//BoolTest
};