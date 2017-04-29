//
//  Scanner.h
//  Scanner
//
//  Created by 林理露 on 29/04/2017.
//  Copyright © 2017 林理露. All rights reserved.
//

#ifndef Scanner_h
#define Scanner_h

#include "word_recognizer.h"
#include "XML_generator.h"
#define handle_idt() \
{\
    if (!idt.empty()) { \
        node tk,v;\
        tk.add_attribute("token");\
        v.add_attribute("number");\
        v.add_attribute("value");\
        v.add_attribute("type");\
        v.add_attribute("line");\
        v.add_attribute("valid");\
        v.add_value(std::to_string(word_count));\
        v.add_value(idt);\
        if (is_keyword(idt)) { \
            v.add_value("keyword");\
        }else{\
            v.add_value("identifier");\
        }\
        v.add_value(std::to_string(line_count));\
        v.add_value("true");\
        tk.add_child(v);\
        token.push_back(tk);\
        ++word_count;\
        idt.clear();\
    }\
}

#define handle_opt() \
{\
    if (!opt.empty()) { \
        node tk,v;\
        tk.add_attribute("token");\
        v.add_attribute("number");\
        v.add_attribute("value");\
        v.add_attribute("type");\
        v.add_attribute("line");\
        v.add_attribute("valid");\
        v.add_value(std::to_string(word_count));\
        v.add_value(opt);\
        if (is_operator(opt)) { \
            v.add_value("operator");\
        }else{\
            v.add_value("identifier");\
        }\
        v.add_value(std::to_string(line_count));\
        v.add_value("true");\
        tk.add_child(v);\
        token.push_back(tk);\
        ++word_count;\
        opt.clear();\
    }\
}

#define handle_dgt() \
{\
    if (!dgt.empty()) { \
        node tk,v;\
        tk.add_attribute("token");\
        v.add_attribute("number");\
        v.add_attribute("value");\
        v.add_attribute("type");\
        v.add_attribute("line");\
        v.add_attribute("valid");\
        v.add_value(std::to_string(word_count));\
        v.add_value(dgt);\
        if (is_int(dgt)) { \
            v.add_value("const_i");\
        }else if (is_float(dgt)){\
            v.add_value("const_f");\
        }else if (is_hex(dgt)){\
            v.add_value("const_h");\
        }else if (is_oct(dgt)){\
            v.add_value("const_o");\
        }else{\
            v.add_value("error");\
        }\
        v.add_value(std::to_string(line_count));\
        v.add_value("true");\
        tk.add_child(v);\
        token.push_back(tk);\
        ++word_count;\
        dgt.clear();\
    }\
}

#define handle_str() \
{\
    if (!str.empty()) { \
        node tk,v;\
        tk.add_attribute("token");\
        v.add_attribute("number");\
        v.add_attribute("value");\
        v.add_attribute("type");\
        v.add_attribute("line");\
        v.add_attribute("valid");\
        v.add_value(std::to_string(word_count));\
        v.add_value(str+"\"");\
        v.add_value("stringLiteral");\
        v.add_value(std::to_string(line_count));\
        v.add_value("true");\
        tk.add_child(v);\
        token.push_back(tk);\
        ++word_count;\
        str.clear();\
    }\
}

#define handle_spt() \
{\
    if(is_separator(cur_char)){\
        node tk,v;\
        tk.add_attribute("token");\
        v.add_attribute("number");\
        v.add_attribute("value");\
        v.add_attribute("type");\
        v.add_attribute("line");\
        v.add_attribute("valid");\
        v.add_value(std::to_string(word_count));\
        v.add_value(std::string(1,cur_char));\
        v.add_value("separator");\
        v.add_value(std::to_string(line_count));\
        v.add_value("true");\
        tk.add_child(v);\
        token.push_back(tk);\
        ++word_count;\
    }\
}

enum class states:unsigned int{
    STATE_DFT=0,//default state
    STATE_IDT=1,//identifier state
    STATE_OPT=2,//operator state
    STATE_SPT=3,//seprator state
    STATE_DGT=4,//digit state
    STATE_STR=6,//string literal state
    STATE_ERR=7//when something go wrong
};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        std::size_t h1 = static_cast<std::size_t>(p.first);
        std::size_t h2 = static_cast<std::size_t>(p.second);
        std::size_t h3 = static_cast<std::size_t>(states::STATE_ERR);
        return h1*h3+h2;
    }
};

void init_statemap();


#endif /* Scanner_h */
