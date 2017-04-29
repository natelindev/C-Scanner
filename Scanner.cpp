//
//  Scanner.cpp
//  Scanner
//
//  Created by 林理露 on 23/04/2017.
//  Copyright © 2017 林理露. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include "Scanner.h"
#include "state_map.h"

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cerr<<"Usage: "<<argv[0]<<" <input c filename> <output xml filename>"<<std::endl;
        exit(1);
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    std::string xml_name = argv[2];
    init_keymap();
    init_opmap();
    init_statemap();
    char cur_char;
    int line_count = 1,word_count = 1;
    std::string idt,opt,dgt,str;
    std::vector<node> token;
    
    auto cur_state = states::STATE_DFT;
    
    while (std::cin.get(cur_char)) {
        switch (state_map[std::pair<states,char>(cur_state,cur_char)]) {
            case states::STATE_DFT:
                handle_idt();
                handle_opt();
                handle_dgt();
                handle_str();
                handle_spt();
                if (cur_char == '\n') {
                    ++line_count;
                }
                cur_state = states::STATE_DFT;
                break;
            case states::STATE_IDT:
                handle_opt();
                handle_dgt();
                handle_spt();
                idt.push_back(cur_char);
                cur_state = states::STATE_IDT;
                break;
            case states::STATE_DGT:
                handle_idt();
                handle_opt();
                handle_spt();
                dgt.push_back(cur_char);
                cur_state = states::STATE_DGT;
                break;
            case states::STATE_OPT:
                handle_idt();
                handle_dgt();
                handle_spt();
                opt.push_back(cur_char);
                cur_state = states::STATE_OPT;
                break;
                
            case states::STATE_SPT:
                handle_idt();
                handle_dgt();
                handle_opt();
                handle_spt();
                cur_state = states::STATE_SPT;
                break;
            case states::STATE_STR:
                str.push_back(cur_char);
                cur_state = states::STATE_STR;
                break;
            case states::STATE_ERR:
            default:
                std::cerr<<"Unexpected character: "<<static_cast<int>(cur_char)<<std::endl;
                break;
        }
    }
    
    //XML output
    XML xml;
    node tks,end,tk;
    tks.add_attribute("tokens");
    tk.add_attribute("token");
    end.add_attribute("number");
    end.add_attribute("value");
    end.add_attribute("type");
    end.add_attribute("line");
    end.add_attribute("valid");
    end.add_value(std::to_string(word_count));
    end.add_value("#");
    end.add_value("#");
    end.add_value(std::to_string(line_count));
    end.add_value("true");
    tk.add_child(end);
    token.push_back(tk);
    for(node t: token)
    {
        tks.add_child(t);
    }
    xml.add_child(tks);
    xml.print_all(xml_name);
    return 0;
}


