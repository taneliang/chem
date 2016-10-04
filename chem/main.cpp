//
//  main.cpp
//  chem
//
//  Created by E-Liang Tan on 4/4/12.
//  Copyright (c) 2012 IntelligentMonkey. All rights reserved.
//

#include <iostream>
#include <string>
#include "Lipup.h"

static const int NumberOfElements = 118;

enum _chem_element_categories {
	Metalloids,
	Halogens,
	NobleGases,
	
	AlkaliMetals,
	AlkalineEarthMetals,
	Lanthanoids,
	Actinoids,
	TransitionMetals,
	PostTransitionMetals
};
typedef _chem_element_categories ElementCategories;

struct _chem_element {
	const char *name;
	const char *atomicSymbol;
	unsigned int protonNumber;
	float relativeAtomicMass;
};
typedef _chem_element Element;

struct _chem_ion {
	Element element;
	int charge;
};
typedef _chem_ion Ion;

struct _chem_periodic_table {
	Element elements[NumberOfElements];
};
typedef _chem_periodic_table PeriodicTable;

PeriodicTable CreateNewPeriodicTable(void) {
	
	Element elements[NumberOfElements] = 
	{
		{ "hydrogen", "H", 1, 1 },
		{ "helium", "He", 2, 4 },
		{ "lithium", "Li", 3, 7 },
		{ "beryllium", "Be", 4, 9 },
		{ "boron", "B", 5, 11 },
		{ "carbon", "C", 6, 12 },
		{ "nitrogen", "N", 7, 14 },
		{ "oxygen", "O", 8, 16 },
		{ "fluorine", "F", 9, 19 },
		{ "neon", "Ne", 10, 20 },
		{ "sodium", "Na", 11, 23 },
		{ "magnesium", "Mg", 12, 24 },
		{ "aluminium", "Al", 13, 27 },
		{ "silicon", "Si", 14, 28 },
		{ "phosphorus", "P", 15, 31 },
		{ "sulfur", "S", 16, 32 },
		{ "chlorine", "Cl", 17, 35.5 },
		{ "argon", "Ar", 18, 40 },
		{ "potassium", "K", 19, 39 },
		{ "calcium", "Ca", 20, 40 },
		{ "scandium", "Sc", 21, 45 },
		{ "titanium", "Ti", 22, 48 },
		{ "vandanium", "V", 23, 51 },
		{ "chromium", "Cr", 24, 52 },
		{ "manganese", "Mn", 25, 55 },
		{ "iron", "Fe", 26, 56 },
		{ "cobalt", "Co", 27, 59 },
		{ "nickel", "Ni", 28, 59 },
		{ "copper", "Cu", 29, 64 },
		{ "zinc", "Zn", 30, 65 },
		{ "gallium", "Ga", 31, 70 },
		{ "germanium", "Ge", 32, 73 },
		{ "arsenic", "As", 33, 75 },
		{ "selenium", "Se", 34, 79 },
		{ "bromine", "Br", 35, 80 },
		{ "krypton", "Kr", 36, 84 },
		{ "rubidium", "Rb", 37, 85 },
		{ "strontium", "Sr", 38, 88 },
		{ "yttrium", "Y", 39, 89 },
		{ "zirconium", "Zr", 40, 91 },
		{ "niobium", "Nb", 41, 93 },
		{ "molybdenum", "Mo", 42, 96 },
		{ "technetium", "Tc", 43, 98 },
		{ "ruthenium", "Ru", 44, 101 },
		{ "rhodium", "Rh", 45, 103 },
		{ "palladium", "Pd", 46, 106 },
		{ "silver", "Ag", 47, 108 },
		{ "cadmium", "Cd", 48, 112 },
		{ "indium", "In", 49, 115 },
		{ "tin", "Sn", 50, 119 },
		{ "antimony", "Sb", 51, 122 },
		{ "tellurium", "Te", 52, 128 },
		{ "iodine", "I", 53, 127 },
		{ "xenon", "Xe", 54, 131 },
		{ "caesium", "Cs", 55, 133 },
		{ "barium", "Ba", 56, 137 },
		{ "lanthanum", "La", 57, 139 },
		{ "cerium", "Ce", 58, 140 },
		{ "praseodymium", "Pr", 59, 141 },
		{ "neodymium", "Nd", 60, 144 },
		{ "promethium", "Pm", 61, 145 },
		{ "samarium", "Sm", 62, 150 },
		{ "europium", "Eu", 63, 152 },
		{ "gadolinium", "Gd", 64, 157 },
		{ "terbium", "Tb", 65, 159 },
		{ "dysprosium", "Dy", 66, 162 },
		{ "holmium", "Ho", 67, 165 },
		{ "erbium", "Er", 68, 167 },
		{ "thulium", "Tm", 69, 169 },
		{ "ytterbium", "Yb", 70, 173 },
		{ "lutetium", "Lu", 71, 175 },
		{ "hafnium", "Hf", 72, 178 },
		{ "tantalum", "Ta", 73, 181 },
		{ "tungsten", "W", 74, 184 },
		{ "rhenium", "Re", 75, 186 },
		{ "osmium", "Os", 76, 190 },
		{ "irdium", "Ir", 77, 192 },
		{ "platinum", "Pt", 78, 195 },
		{ "gold", "Au", 79, 197 },
		{ "mercury", "Hg", 80, 201 },
		{ "thallium", "Tl", 81, 204 },
		{ "lead", "Pb", 82, 207 },
		{ "bismuth", "Bi", 83, 209 },
		{ "polonium", "Po", 84, 209 },
		{ "astatine", "At", 85, 210 },
		{ "radon", "Rn", 86, 222 },
		{ "francium", "Fr", 87, 223 },
		{ "radium", "Ra", 88, 226 },
		{ "actinium", "Ac", 89, 227 },
		{ "thorium", "Th", 90, 232 },
		{ "protactinium", "Pa", 91, 231 },
		{ "uranium", "U", 92, 238 },
		{ "neptunium", "Np", 93, 237 },
		{ "plutonium", "Pu", 94, 244 },
		{ "americium", "Am", 95, 243 },
		{ "curium", "Cm", 96, 247 },
		{ "berkelium", "Bk", 97, 247 },
		{ "californium", "Cf", 98, 251 },
		{ "einsteinnium", "Es", 99, 252 },
		{ "fermium", "Fm", 100, 257 },
		{ "mendelevium", "Md", 101, 258 },
		{ "nobelium", "No", 102, 259 },
		{ "lawrencium", "Lr", 103, 262 },
		{ "rutherfordium", "Rf", 104, 267 },
		{ "dubnium", "Db", 105, 268 },
		{ "seaborgium", "Sg", 106, 271 },
		{ "bohrium", "Bh", 107, 272 },
		{ "hassium", "Hs", 108, 270 },
		{ "meitnerium", "Mt", 109, 246 },
		{ "darmstadtium", "Ds", 110, 281 },
		{ "roentgenium", "Rg", 111, 280 },
		{ "copernicium", "Cn", 112, 285 },
		{ "ununtrium", "Uut", 113, 284 },
		{ "flerovium", "Fl", 114, 289 },
		{ "ununpentium", "Uup", 115, 288 },
		{ "livermorium", "Lv", 116, 293 },
		{ "ununseptium", "Uus", 117, 294 },
		{ "ununoctium", "Uuo", 118, 294 },
	};
	
	PeriodicTable periodicTable;
	for (int i = 0; i < NumberOfElements; i++) {
		periodicTable.elements[i] = elements[i];
	}
	return periodicTable;
}

int main(int argc, const char * argv[])
{
//	PeriodicTable periodicTable = CreateNewPeriodicTable();
	
	char inputC[2000] = "hi";
//	scanf("%[^\n]s", inputC);
	std::string input = (inputC);
//	std::getline(std::cin, input);
//	std::cout << input;
	
	Lipup lipup;
	std::string output = lipup.asdf(input);
		
    return 0;
}

