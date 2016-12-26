/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   parser_interface.h
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 26, 2016, 12:16 PM
 *
 * @Brief Brief description of file.
 *
 * Description:
 */


// Create a comment in the ELF object file structure for
// error tracing reasons.
// -----------------------------------------------------

#if defined( __unix__ ) || defined( __unix )
#ident "@(#) parser_interface 2016-12-26 12:16:01 Eike Schumann"
#endif


// Ensure that only a C++ compiler tries to compile this file to avoid
// some 'interesting' error messages from C compilers
// ---------------------------------------------------------------------

#if !defined( __cplusplus )
#error The file __FILE__ requires to be compiled by a C++ compiler!
#endif


// Include guard to avoid multiple inclusion
// -----------------------------------------
#ifndef PARSER_INTERFACE_H
#define PARSER_INTERFACE_H

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------
#include <string>

// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------
#include <boost/property_tree/ptree.hpp>

// Include project headers
// -----------------------


// Synopsis/Namespace interface:
// This section lists the classes, functions and types provided by this
// file as well as forward declaration of classes, functions and types
// provided by custom components.
// --------------------------------------------------------------------
namespace tuto {
  struct parser_interface;
  namespace pt = boost::property_tree;
}

// Declarations of the class interfaces
// ------------------------------------
struct tuto::parser_interface {
  virtual pt::ptree parse( std::string const& data ) const = 0;
  virtual ~parser_interface() = default;
};

// Definition of (inlined) methods and functions ( most likely template related ).
// ------------------------------------------------------------------------------



#endif /* PARSER_INTERFACE_H */