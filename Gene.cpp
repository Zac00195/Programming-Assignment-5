#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "Gene.h"
#include "Allele.h"
#include "Chromosome.h"

using namespace std;
char IntenseRed1[] = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
char IntenseBlue1[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
char Red1[] = {0x1b, '[', '0', ';', '3', '1', 'm', 0};
char reset1[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};

Gene::Gene()
{
}
Gene::Gene(Allele Allele1, Allele Allele2)
{
	AlleleA = Allele1;
	AlleleB = Allele2;
}
string Gene::getGeneTraitType()
{
	return traitType;
}
void Gene::setGeneTraitType(string genetrait)
{
	traitType = genetrait;
}
string Gene::getGeneName()
{
	return geneName;
}
void Gene::setGeneName(string genename)
{
	geneName = genename;
}
void Gene::getExpressedTrait()
{
	if (AlleleA.getType() == "Dominant")
	{
		cout << IntenseRed1 << "Expressed Allele: " << reset1 << Red1 << AlleleA.getName() << " - Dominant" << reset1 << endl;
		cout << IntenseRed1 << "Nucldeotide Sequence: " << reset1 << Red1 << AlleleA.getSequence() << reset1 << endl;
	}
	else
	{
		cout << IntenseRed1 << "Expressed Allele: " << reset1 << Red1 << AlleleB.getName() << " - Dominant" << reset1 << endl;
		cout << IntenseRed1 << "Nucldeotide Sequence: " << reset1 << Red1 << AlleleB.getSequence() << reset1 << endl;
	}
}
Allele Gene::getAlleleA()
{
	return AlleleA;
}
Allele Gene::getAlleleB()
{
	return AlleleB;
}
void Gene::setAlleleA(Allele Allele1)
{
	AlleleA = Allele1;
}
void Gene::setAlleleB(Allele Allele2)
{
	AlleleB = Allele2;
}
void Gene::OutputToFile(ofstream &of)
{
	cout << IntenseBlue1 << "Gene Output:" << reset1 << endl;
	of << getGeneName() << "," << getGeneTraitType() << ",";
	cout << geneName << "," << traitType << ",";
	AlleleA.WriteAlleletoFile(of);
	cout << ",";
	AlleleB.WriteAlleletoFile(of);
	cout << endl;
	of << endl;
}
