/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   decoder_proxy.h
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 26, 2016, 10:24 AM
 *
 * @Brief Brief description of file.
 *
 * Description:
 */


// Create a comment in the ELF object file structure for
// error tracing reasons.
// -----------------------------------------------------

#if defined( __unix__ ) || defined( __unix )
#ident "@(#) decoder_proxy 2016-12-26 10:24:48 Eike Schumann"
#endif


// Ensure that only a C++ compiler tries to compile this file to avoid
// some 'interesting' error messages from C compilers
// ---------------------------------------------------------------------

#if !defined( __cplusplus )
#error The file __FILE__ requires to be compiled by a C++ compiler!
#endif


// Include guard to avoid multiple inclusion
// -----------------------------------------
#ifndef DECODER_PROXY_H
#define DECODER_PROXY_H

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------
#include <memory>

// Include project headers
// -----------------------
#include <decoder_interface.h>
#include <context_singleton.h>

// Synopsis/Namespace interface:
// This section lists the classes, functions and types provided by this
// file as well as forward declaration of classes, functions and types
// provided by custom components.
// --------------------------------------------------------------------
namespace tuto {
  class decoder_proxy;
  //Forward declarations
  struct decoder_interface;
  struct parser_interface;
}

// Declarations of the class interfaces
// ------------------------------------
class tuto::decoder_proxy : public tuto::utl::instance_scope::context_singleton<tuto::decoder_proxy>,
                            public tuto::decoder_interface {
  std::shared_ptr<parser_interface> parser_;
  std::unique_ptr<decoder_interface> decoder_;
public:
  decoder_proxy( parser_interface* );
  pt::ptree decode( std::string const& data ) const override;
};


// Definition of (inlined) methods and functions ( most likely template related ).
// ------------------------------------------------------------------------------



#endif /* DECODER_PROXY_H */