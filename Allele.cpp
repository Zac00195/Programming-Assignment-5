#include <iostream>
#include <string>
#include <fstream>
#include "Allele.h"
#include <cassert>
using namespace std;

Allele::Allele(string Allelename, string Alleletype, string Allelesequence)
{
	varientName = Allelename;
	varientType = Alleletype;
	nucleotideSequence = Allelesequence;
}
Allele::Allele()
{
}
string Allele::getName()
{
	return varientName;
}
void Allele::setName(string NameA)
{
	varientName = NameA;
}
string Allele::getType()
{
	return varientType;
}
void Allele::setType(string TypeA)
{
	varientType = TypeA;
}
string Allele::getSequence()
{
	return nucleotideSequence;
}
void Allele::setSequence(string SequenceA)
{
	nucleotideSequence = SequenceA;
}
void Allele::WriteAlleletoFile(ofstream &of)
{
	of << varientName << "," << varientType << "," << nucleotideSequence << ",";
	cout << varientName << "," << varientType << "," << nucleotideSequence;
}

bool Allele::RunUnitTest()
{
	Allele myAllele("xyz", "abc", "str");
	if (myAllele.getName() != "xyz")
	{
		cout << "Allele Name Does Not Equal the Varient Name\n";
	}
	/*assert(varientName == Allelename);
	//assert(varientType == Alleletype);
	std::cout << "Allele Type Does Not Equal the Varient Type\n";
	//assert(nucleotideSequence == Allelesequence);
	std::cout << "Allele Nucleotide Sequence Does Not Equal the Varient Sequence\n";*/
}