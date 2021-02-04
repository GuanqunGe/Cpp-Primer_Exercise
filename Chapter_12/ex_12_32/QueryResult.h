#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <set>
#include "../include/StrBlob.h"

class QueryResult{
friend std::ostream &print( std::ostream &, const QueryResult &);
public:
    
    using line_no = std::vector<std::string>::size_type;

    QueryResult(const std::string &s=""):word(s), lines(std::make_shared<std::set<line_no>>()){}
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> lpt, const StrBlob &fpt): word(s), lines(lpt), file(fpt){}
private:
    std::string word;
    std::shared_ptr<std::set<line_no>> lines;
    StrBlob file;
};

std::ostream &print( std::ostream &, const QueryResult &);
#endif

