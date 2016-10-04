//
//  Lipup.cpp
//  chem
//
//  Created by E-Liang Tan on 8/4/12.
//  Copyright (c) 2012 E-Liang Tan. All rights reserved.
//

#include <iostream>
#include "Lipup.h"

#include <map>
#include <vector>
#include <string>

/* Natural language input (grammar search graph)
 
 Greetings (Optional):
 Hi
 Hey you piece of shit
 My friend,
 Computer
 Howdy sir
 
 Pre-request padding:
 What is (a|the) [definition]
 How many [quantity]
 Tell me (the) [definition]
 Give me (the) [definition]
 Spit out (the) [definition]
 
 Request proper:
 name of the H element [definition]
 atoms in periodic table [definition, quantity]
 details of hydrogen [definition]
 (more sophisticated) H [definition]
 
 Post-request padding (Optional):
 *Thank* you.
 Your assistance is greatly *appreciated*, computer.
 You piece of shit.
 
 Computer Responses:
 [unsure] Insufficient parameters. Please be more specific. (more sophisticated: Please specify: a name, a proton number, a chemical symbol)
 [wtf] Request not recognized.
 [out of my ability] Unable to comply.
 [result - single definition] The name is "hydrogen".
 [result - multiple definitions] Hydrogen has: chemical symbol H, proton number 1, relative atomic mass 1.
 [result - quantity] There are x atoms in the periodic table.
 
 */

std::string greetingsC[] = {"hi", "hey", "howdy", "hello", "greetings", "good morning", "morning", "mornin", "good afternoon", "afternoon", "good evening", "evening", "evenin"};
std::string addressC[] = {"you", "you piece of shit", "my friend", "computer", "sir", "all-knowning machine"};
std::string prepreRequestPaddingC[] = {"please", "could you"};
std::string preRequestPaddingIndexC[] = {"what's", "what is", "tell me", "give me", "spit out", "how many", "number of"};
std::string postRequestPaddingC[] = {"thank you", "your assistance is greatly appreciated"};
static std::string determinersC[] = {"the", "a"};

std::string Lipup::asdf(std::string input) {
	std::vector<std::string>::iterator it;
	std::vector<std::string> greetings(greetingsC, greetingsC + sizeof(greetingsC) / sizeof(std::string));
	std::vector<std::string> address(addressC, addressC + sizeof(addressC) / sizeof(std::string));
	std::vector<std::string> prepreRequestPadding(prepreRequestPaddingC, prepreRequestPaddingC + sizeof(prepreRequestPaddingC) / sizeof(std::string));
	std::vector<std::string> postRequestPadding(postRequestPaddingC, postRequestPaddingC + sizeof(postRequestPaddingC) / sizeof(std::string));
	std::vector<std::string> determiners(determinersC, determinersC + sizeof(determinersC) / sizeof(std::string));
	
	std::map<std::string, RequestType> preRequestPadding;
	preRequestPadding["what's"] = RequestTypeDefinition;
	preRequestPadding["what is"] = RequestTypeDefinition;
	preRequestPadding["tell me"] = RequestTypeDefinition;
	preRequestPadding["give me"] = RequestTypeDefinition;
	preRequestPadding["spit out"] = RequestTypeDefinition;
	preRequestPadding["how many"] = RequestTypeQuantity;
	preRequestPadding["number of"] = RequestTypeQuantity;
	
	std::map<std::string, std::string> functions;
	functions["name of"] = "Fname";
	functions["atoms in"] = "Fatoms";
	functions["details of"] = "Fdetails";
	
	std::map<std::string, std::string> keywords;
	keywords["element"] = "Kelement";
	keywords["periodic table"] = "Kptable";
	keywords["proton number"] = "Kprotonnumber";
	keywords["relative atomic mass"] = "Kmass";
	keywords["mass"] = "Kmass";
	
	for (it = greetings.begin(); it < greetings.end(); it++) {
		input.find(*it);
	}
	
	return "";
}
