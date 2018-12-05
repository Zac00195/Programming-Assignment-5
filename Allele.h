#pragma once
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
class Allele
{
  private:
	string varientName;
	string varientType;
	string nucleotideSequence;

  public:
	Allele(string Allelename, string Alleletype, string Allelesequence);
	Allele();
	string getName();
	void setName(string NameA);
	string getType();
	void setType(string TypeA);
	string getSequence();
	void setSequence(string SequenceA);
	void WriteAlleletoFile(ofstream &);
	bool RunUnitTest();
};