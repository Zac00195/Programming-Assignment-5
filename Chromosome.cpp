#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>
#include "Allele.h"
#include "Gene.h"
#include "Chromosome.h"

using namespace std;
char IntenseRed2[] = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
char Red2[] = {0x1b, '[', '0', ';', '3', '1', 'm', 0};
char IntenseBlue2[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
char reset2[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};

Chromosome::Chromosome()
{
}
void Chromosome::AnalyzeGenotype()
{
	for (unsigned int i = 0; i < Genes.size(); i++)
	{
		cout << IntenseBlue2 << "Gene " << i + 1 << ": " << reset2 << endl;
		cout << IntenseRed2 << "Gene Name: " << reset2 << Red2 << Genes.at(i).getGeneName() << reset2 << endl;
		cout << IntenseRed2 << "Genetic Trait: " << reset2 << Red2 << Genes.at(i).getGeneTraitType() << reset2 << endl;
		Genes.at(i).getExpressedTrait();
		cout << endl;
	}
}
void Chromosome::AddGene(Gene g)
{
	Genes.push_back(g);
}
void Chromosome::OutputfromFile(ofstream &of)
{
	for (unsigned int i = 0; i < Genes.size(); i++)
	{
		Genes.at(i).OutputToFile(of);
	}
}
void Chromosome::InputfromFile(ifstream &file)
{
	string geneData, genename, genetrait, alleleAvariation, alleleAtype, alleleAsequence, alleleBvariation, alleleBtype, alleleBsequence;
	while (file.good())
	{
		getline(file, geneData, ',');
		getline(file, genename, ',');
		getline(file, genetrait, ',');
		getline(file, alleleAvariation, ',');
		getline(file, alleleAtype, ',');
		getline(file, alleleAsequence, ',');
		Allele alleleA(alleleAvariation, alleleAtype, alleleAsequence);

		getline(file, alleleBvariation, ',');
		getline(file, alleleBtype, ',');
		getline(file, alleleBsequence, ',');
		Allele alleleB(alleleBvariation, alleleBtype, alleleBsequence);

		Gene newgene(alleleA, alleleB);
		newgene.setGeneName(genename);
		newgene.setGeneTraitType(genetrait);
		Genes.push_back(newgene);
	}
}
/*string line;
	while (getline(of, line))
	{
		int pos = line.find(",");
		string geneName = line.substr(0, pos);
		line.erase(pos);
		pos = line.find(",");
		Gene tempGene;
		tempGene.setGeneName(geneName);
		Genes.push_back(tempGene);
	}*/
Chromosome Chromosome::operator+(Chromosome rhs)
{
	Chromosome newChromosome;

	Allele newAlleleA, newAlleleB;
	//int randomSelection = 0;
	//int maxcombos = 4;
	//randomSelection = rand() % maxcombos;
	for (unsigned int i = 0; i < Genes.size(); i++)
	{
		newAlleleA = Genes.at(i).getAlleleA();
		// get an allele from the corresponding gene in Chromosme rhs.
		newAlleleB = Genes.at(i).getAlleleB();

		Gene newGene(newAlleleA, newAlleleB);
		newChromosome.AddGene(newGene);
	}
	return newChromosome;
}
