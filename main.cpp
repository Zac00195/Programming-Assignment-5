/*	Project:    Programming Assignment 5
	Name:       Zac Birringer
    Partner:    PARTNER'S NAME IF ANY
    Class:      CSC 1810 - Section 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>
#include "Allele.h"
#include "Gene.h"
#include "Chromosome.h"

using namespace std;
char Red[] = {0x1b, '[', '0', ';', '3', '1', 'm', 0};
char Green[] = {0x1b, '[', '0', ';', '3', '2', 'm', 0};
char Yellow[] = {0x1b, '[', '0', ';', '3', '3', 'm', 0};
char Blue[] = {0x1b, '[', '0', ';', '3', '4', 'm', 0};
char Purple[] = {0x1b, '[', '0', ';', '3', '5', 'm', 0};
char Teal[] = {0x1b, '[', '0', ';', '3', '6', 'm', 0};
char White[] = {0x1b, '[', '0', ';', '3', '7', 'm', 0};

char IntenseRed[] = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
char IntenseGreen[] = {0x1b, '[', '1', ';', '3', '2', 'm', 0};
char IntenseYellow[] = {0x1b, '[', '1', ';', '3', '3', 'm', 0};
char IntenseBlue[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
char IntensePurple[] = {0x1b, '[', '1', ';', '3', '5', 'm', 0};
char IntenseTeal[] = {0x1b, '[', '1', ';', '3', '6', 'm', 0};
char IntenseWhite[] = {0x1b, '[', '1', ';', '3', '7', 'm', 0};

char reset[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};

int response = 0;

int main()
{
	Chromosome C;
	while (response != 6)
	{
		cout << Teal << "MENU" << reset << endl;
		cout << Teal << "1 - Create Chromosome" << reset << endl;
		cout << Teal << "2 - Analyze Chromosome" << reset << endl;
		cout << Teal << "3 - Output Chromosome to File" << reset << endl;
		cout << Teal << "4 - Input Chromosome From File" << reset << endl;
		cout << Teal << "5 - Combine Chromosomes" << reset << endl;
		cout << Teal << "6 - Exit" << reset << endl;
		cout << IntenseTeal << "Please Enter Your Choice (1-6)" << reset << endl;
		cin >> response;
		cout << endl;

		if (response == 1)
		{
			string response = "y";
			while (response == "y")
			{
				string geneName;
				string geneTrait;
				cout << IntenseBlue << "Gene Information: " << reset << endl;
				cout << IntenseYellow << "Please Enter a Name for the New Gene" << reset << endl;
				cin.ignore();
				getline(cin, geneName);
				cout << IntenseYellow << "Please Enter the Gene Trait (e.g. Hair Color, Eye Color, Size, etc.)" << reset << endl;
				getline(cin, geneTrait);
				cout << endl;

				string nameA;
				string typeA;
				string sequenceA;
				cout << IntenseBlue << "Allele A Information: " << reset << endl;
				cout << IntenseYellow << "Please Enter Allele A's Varient (e.g. Blonde, Dark, Short, etc)" << reset << endl;
				getline(cin, nameA);
				cout << IntenseYellow << "Please Enter Allele A's Type (Dominant/Recessive)" << reset << endl;
				getline(cin, typeA);
				cout << IntenseYellow << "Please Enter Allele A's Nucleotide Sequence" << reset << endl;
				getline(cin, sequenceA);
				Allele AlleleA(nameA, typeA, sequenceA);
				cout << endl;

				string nameB;
				string typeB;
				string sequenceB;
				cout << IntenseBlue << "Allele B Information: " << reset << endl;
				cout << IntenseYellow << "Please Enter Allele B's Varient (e.g. Blonde, Dark, Short, etc)" << reset << endl;
				getline(cin, nameB);
				cout << IntenseYellow << "Please Enter Allele B's Type (Dominant/Recessive)" << reset << endl;
				getline(cin, typeB);
				cout << IntenseYellow << "Please Enter Allele B's Nucleotide Sequence" << reset << endl;
				getline(cin, sequenceB);
				Allele AlleleB(nameB, typeB, sequenceB);
				cout << endl;

				Gene Gene1(AlleleA, AlleleB);
				Gene1.setGeneName(geneName);
				Gene1.setGeneTraitType(geneTrait);
				C.AddGene(Gene1);
				cout << IntenseYellow << "Do You Want Another Gene? (y/n)" << reset << endl;
				cin >> response;
				cout << endl;
			}
		}

		else if (response == 2)
		{
			C.AnalyzeGenotype();
			//of<<Gene.getGeneName() << "," << Gene.getGeneTraitType() << "," << AlleleAtype << "," << AlleleA varrient << "," << Nucleotide Sequence << ","
			//<< Allele type << ","<< allele varient "," << Nucleodie Sequecnce << endl;
		}

		else if (response == 3)
		{
			string fileresponse;
			cout << IntenseYellow << "What File Would You Like to Export From? (e.g. myText.txt)" << reset << endl;
			cin >> fileresponse;
			cout << endl;
			ofstream myOutput;
			myOutput.open(fileresponse);
			C.OutputfromFile(myOutput);
			myOutput.close();
			cout << endl;
			cout << Red << "Your " << reset << Blue << fileresponse << reset << Red << " was created" << reset << endl;
		}

		else if (response == 4)
		{
			string fileresponse;
			cout << IntenseYellow << "What File Would You Like to Import From? (e.g. myText.txt)" << reset << endl;
			cin >> fileresponse;
			cout << endl;
			ifstream myInput;
			myInput.open(fileresponse);
			C.InputfromFile(myInput);
			myInput.close();
			cout << endl;
		}

		else if (response == 5)
		{
			cout << IntenseYellow << "Chromosome_3=Chromsome_1+Chromsome_2" << reset << endl;
			C.operator+(C);
		}

		else if (response == 6)
		{
			cout << IntenseWhite << "Thank You - Goodbye" << reset << endl;
		}
		else
		{
			break;
		}
	}

	// This causes the program to pause at its completion.
	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}