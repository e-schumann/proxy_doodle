/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   parser_json.cpp
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 26, 2016, 1:55 PM
 *
 * @Brief Brief description of parser_json.cpp.
 *
 * Description:
 */

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------
#include <sstream>

// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------
#include <boost/property_tree/json_parser.hpp>

// Include project headers
// -----------------------


// Include declaration header
// --------------------------
#include <parser_json.h>

tuto::pt::ptree tuto::parser_json::parse( std::string const& data ) const {
   std::stringstream stream;
   stream << data;

   pt::ptree return_ptree;
   pt::read_json( stream, return_ptree );

   return return_ptree;
}