//
//  XML_generator.cpp
//  Scanner
//
//  Created by 林理露 on 23/04/2017.
//  Copyright © 2017 林理露. All rights reserved.
//
#include <iostream>
#include "XML_generator.h"

XML::XML():header("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"){}

void XML::add_child(node n)
{
    childs.push_back(n);
}

void XML::print_all(std::string xml_name)
{
    std::cout<<header<<std::endl;
    std::cout<<"<project name=\""<<xml_name<<"\">"<<std::endl;
    for(node n:childs)
    {
        n.print(1);
    }
    std::cout<<"</project>"<<std::endl;
}

void node::add_attribute(std::string attribute)
{
    attributes.push_back(attribute);
}

void node::add_value(std::string value)
{
    values.push_back(value);
}

void node::add_child(node n)
{
    childs.push_back(n);
}

void node::print(int sps)
{
    if (!values.empty() && values.size() != attributes.size()) {
        std::cerr<<"Attributes and values are not corresponding!"<<std::endl;
        exit(1);
    }
    
    if (values.empty()) {
        //donnot have values
        for(int i = 0;i < attributes.size() ;++i)
        {
            for (int j = 0; j < sps; ++j) {
                std::cout<<"  ";
            }
            std::cout<<"<"<<attributes[i]<<">"<<std::endl;
            for(node n: childs)
            {
                n.print(sps+1);
            }
            for (int j = 0; j < sps; ++j) {
                std::cout<<"  ";
            }
            std::cout<<"</"<<attributes[i]<<">"<<std::endl;
        }
    }
    else
    {
        //have values,then no childs
        for(int i = 0;i < attributes.size() ;++i)
        {
            for (int j = 0; j < sps; ++j) {
                std::cout<<"  ";
            }
            //if (values[i].c_str()[0] == '<' || values[i].c_str()[0] == '>') {
//                std::cout<<"<\\"<<attributes[i]<<">"<<values[i]<<"</"<<attributes[i]<<">"<<std::endl;
//            }else{
                std::cout<<"<"<<attributes[i]<<">"<<values[i]<<"</"<<attributes[i]<<">"<<std::endl;
//            }
            
        }
    }
}
