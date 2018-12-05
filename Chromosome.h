#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Allele.h"
#include "Gene.h"

using namespace std;
class Chromosome
{
  private:
	vector<Gene> Genes;

  public:
	Chromosome();
	void AnalyzeGenotype();
	void AddGene(Gene g);
	void OutputfromFile(ofstream &);
	void InputfromFile(ifstream &);
	Chromosome operator+(Chromosome rhs);

	//Gene FindGene(string Name);
	//bool RunUnitTest;
};