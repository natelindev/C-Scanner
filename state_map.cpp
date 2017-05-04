//
//  state_map.cpp
//  Scanner
//
//  Created by 林理露 on 29/04/2017.
//  Copyright © 2017 林理露. All rights reserved.
//

#include <unordered_map>
#include "Scanner.h"
#include "state_map.h"

std::unordered_map<std::pair<states,char>,states,pair_hash> state_map;

states get_state(states cur_state,const char cur_char)
{
    static bool next_sign_digit =false;
    if (next_sign_digit && (cur_char == '-' || cur_char == '+')){
        next_sign_digit = false;
        return states::STATE_DGT;
    }
    if (cur_state == states::STATE_STR && cur_char!= '\"' && cur_char != '\'' && cur_char != '\n') {
        return states::STATE_STR;
    }
    else{
        if(cur_state == states::STATE_DGT && (cur_char == 'e' || cur_char == 'E'))
        {
            next_sign_digit = true;
        }
        return state_map[std::pair<states,char>(cur_state,cur_char)];
    }
}

void init_statemap()
{
    //TABLE for DFA states
    //operator signs
    state_map[std::pair<states,char>(states::STATE_DFT,'+')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'-')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'*')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'/')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'%')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'<')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'>')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'=')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'!')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'~')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'&')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'^')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'|')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,',')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'.')] = states::STATE_OPT;
    
    state_map[std::pair<states,char>(states::STATE_IDT,'+')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'-')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'*')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'/')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'%')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'<')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'>')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'=')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'!')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'~')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'&')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'^')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'|')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,',')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'.')] = states::STATE_OPT;
    
    state_map[std::pair<states,char>(states::STATE_OPT,'+')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'-')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'*')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'/')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'%')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'<')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'>')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'=')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'!')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'~')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'&')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'^')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'|')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,',')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'.')] = states::STATE_OPT;
    
    state_map[std::pair<states,char>(states::STATE_SPT,'+')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'-')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'*')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'/')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'%')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'<')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'>')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'=')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'!')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'~')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'&')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'^')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'|')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,',')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'.')] = states::STATE_OPT;
    
    state_map[std::pair<states,char>(states::STATE_DGT,'+')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'-')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'*')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'/')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'%')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'<')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'>')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'=')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'!')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'~')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'&')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'^')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'|')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,',')] = states::STATE_OPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'.')] = states::STATE_DGT;
    
    //separator signs
    
    state_map[std::pair<states,char>(states::STATE_DFT,'{')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'}')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'[')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DFT,']')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DFT,'(')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DFT,')')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DFT,';')] = states::STATE_SPT;
    
    state_map[std::pair<states,char>(states::STATE_IDT,'{')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'}')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'[')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_IDT,']')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_IDT,'(')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_IDT,')')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_IDT,';')] = states::STATE_SPT;
    
    state_map[std::pair<states,char>(states::STATE_OPT,'{')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'}')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'[')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_OPT,']')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_OPT,'(')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_OPT,')')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_OPT,';')] = states::STATE_SPT;
    
    state_map[std::pair<states,char>(states::STATE_SPT,'{')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'}')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'[')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_SPT,']')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_SPT,'(')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_SPT,')')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_SPT,';')] = states::STATE_SPT;
    
    state_map[std::pair<states,char>(states::STATE_DGT,'{')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'}')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'[')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DGT,']')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DGT,'(')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DGT,')')] = states::STATE_SPT;
    state_map[std::pair<states,char>(states::STATE_DGT,';')] = states::STATE_SPT;
    
    //identifier signs
    
    state_map[std::pair<states,char>(states::STATE_DFT,'A')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'B')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'C')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'D')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'E')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'F')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'G')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'H')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'I')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'J')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'K')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'L')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'M')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'N')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'O')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'P')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'Q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'R')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'S')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'T')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'U')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'V')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'W')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'X')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'Y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'Z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'a')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'b')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'c')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'d')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'e')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'f')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'g')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'h')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'i')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'j')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'k')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'l')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'m')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'n')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'o')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'p')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'r')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'s')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'t')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'u')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'v')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'w')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'x')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'_')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_DFT,'1')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'2')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'3')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'4')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'5')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'6')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'7')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'8')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'9')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DFT,'0')] = states::STATE_DGT;
    
    state_map[std::pair<states,char>(states::STATE_IDT,'A')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'B')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'C')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'D')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'E')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'F')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'G')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'H')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'I')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'J')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'K')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'L')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'M')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'N')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'O')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'P')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'Q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'R')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'S')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'T')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'U')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'V')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'W')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'X')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'Y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'Z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'a')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'b')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'c')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'d')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'e')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'f')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'g')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'h')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'i')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'j')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'k')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'l')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'m')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'n')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'o')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'p')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'r')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'s')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'t')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'u')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'v')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'w')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'x')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'_')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'1')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'2')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'3')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'4')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'5')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'6')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'7')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'8')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'9')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_IDT,'0')] = states::STATE_IDT;
    
    state_map[std::pair<states,char>(states::STATE_OPT,'A')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'B')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'C')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'D')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'E')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'F')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'G')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'H')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'I')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'J')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'K')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'L')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'M')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'N')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'O')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'P')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'Q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'R')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'S')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'T')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'U')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'V')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'W')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'X')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'Y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'Z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'a')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'b')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'c')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'d')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'e')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'f')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'g')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'h')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'i')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'j')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'k')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'l')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'m')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'n')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'o')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'p')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'r')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'s')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'t')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'u')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'v')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'w')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'x')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'_')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_OPT,'1')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'2')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'3')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'4')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'5')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'6')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'7')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'8')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'9')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_OPT,'0')] = states::STATE_DGT;
    
    state_map[std::pair<states,char>(states::STATE_SPT,'A')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'B')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'C')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'D')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'E')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'F')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'G')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'H')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'I')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'J')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'K')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'L')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'M')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'N')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'O')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'P')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'Q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'R')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'S')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'T')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'U')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'V')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'W')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'X')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'Y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'Z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'a')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'b')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'c')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'d')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'e')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'f')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'g')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'h')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'i')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'j')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'k')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'l')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'m')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'n')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'o')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'p')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'q')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'r')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'s')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'t')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'u')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'v')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'w')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'x')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'y')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'z')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'_')] = states::STATE_IDT;
    state_map[std::pair<states,char>(states::STATE_SPT,'1')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'2')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'3')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'4')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'5')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'6')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'7')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'8')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'9')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_SPT,'0')] = states::STATE_DGT;
    
    state_map[std::pair<states,char>(states::STATE_DGT,'A')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'B')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'C')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'D')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'E')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'F')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'G')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'H')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'I')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'J')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'K')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'L')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'M')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'N')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'O')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'P')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'Q')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'R')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'S')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'T')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'U')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'V')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'W')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'X')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'Y')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'Z')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'a')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'b')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'c')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'d')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'e')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'f')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'g')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'h')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'i')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'j')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'k')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'l')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'m')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'n')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'o')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'p')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'q')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'r')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'s')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'t')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'u')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'v')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'w')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'x')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'y')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'z')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'_')] = states::STATE_ERR;
    state_map[std::pair<states,char>(states::STATE_DGT,'1')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'2')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'3')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'4')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'5')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'6')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'7')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'8')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'9')] = states::STATE_DGT;
    state_map[std::pair<states,char>(states::STATE_DGT,'0')] = states::STATE_DGT;
    
    // string literal signs
    state_map[std::pair<states,char>(states::STATE_DFT,'\"')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_IDT,'\"')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_OPT,'\"')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_DGT,'\"')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_SPT,'\"')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_STR,'\"')] = states::STATE_DFT;
    
    state_map[std::pair<states,char>(states::STATE_DFT,'\'')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_IDT,'\'')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_OPT,'\'')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_DGT,'\'')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_SPT,'\'')] = states::STATE_STR;
    state_map[std::pair<states,char>(states::STATE_STR,'\'')] = states::STATE_DFT;
    
    //space signs
    state_map[std::pair<states,char>(states::STATE_DFT,' ')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_DFT,'\t')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_DFT,'\n')] = states::STATE_DFT;
    
    state_map[std::pair<states,char>(states::STATE_OPT,' ')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_OPT,'\t')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_OPT,'\n')] = states::STATE_DFT;
    
    state_map[std::pair<states,char>(states::STATE_SPT,' ')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_SPT,'\t')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_SPT,'\n')] = states::STATE_DFT;
    
    state_map[std::pair<states,char>(states::STATE_DGT,' ')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_DGT,'\t')] = states::STATE_DFT;
    state_map[std::pair<states,char>(states::STATE_DGT,'\n')] = states::STATE_DFT;
    
    state_map[std::pair<states,char>(states::STATE_STR,'\n')] = states::STATE_ERR;
}
