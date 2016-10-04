//
//  Lipup.h
//  chem
//
//  Created by E-Liang Tan on 8/4/12.
//  Copyright (c) 2012 E-Liang Tan. All rights reserved.
//

#ifndef chem_Lipup_h
#define chem_Lipup_h

enum _requestType {
	RequestTypeDefinition,
	RequestTypeQuantity
};
typedef _requestType RequestType;

class Lipup {
public:
	std::string asdf(std::string input); // Returns name of function that was intended to be called
};

#endif
