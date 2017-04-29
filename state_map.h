//
//  state_map.h
//  Scanner
//
//  Created by 林理露 on 29/04/2017.
//  Copyright © 2017 林理露. All rights reserved.
//

#ifndef state_map_h
#define state_map_h

#include "Scanner.h"

extern std::unordered_map<std::pair<states,char>,states,pair_hash> state_map;

void init_statemap();

#endif /* state_map_h */
