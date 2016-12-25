/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   context_singletonTest.h
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 25, 2016, 9:18 AM
 *
 * @Brief Brief description of file.
 *
 * Description:
 */


// Create a comment in the ELF object file structure for
// error tracing reasons.
// -----------------------------------------------------

#if defined( __unix__ ) || defined( __unix )
#ident "@(#) context_singletonTest 2016-12-25 09:18:28 Eike Schumann"
#endif


// Ensure that only a C++ compiler tries to compile this file to avoid
// some 'interesting' error messages from C compilers
// ---------------------------------------------------------------------

#if !defined( __cplusplus )
#error The file __FILE__ requires to be compiled by a C++ compiler!
#endif


// Include guard to avoid multiple inclusion
// -----------------------------------------
#ifndef CONTEXT_SINGLETONTEST_H
#define CONTEXT_SINGLETONTEST_H

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------


// Include project headers
// -----------------------
#include <context_singleton.h>
#include <object_counter.h>

// Synopsis/Namespace interface:
// This section lists the classes, functions and types provided by this
// file as well as forward declaration of classes, functions and types
// provided by custom components.
// --------------------------------------------------------------------
namespace test {
  struct context1_tag;
  struct context2_tag;
  struct context3_tag;
  template < typename Context, unsigned int n> class multiple_ctors;
}

// Declarations of the class interfaces
// ------------------------------------
struct test::context1_tag {
};

struct test::context2_tag {
};

struct test::context3_tag {
};

template < typename Context, unsigned int n> class test::multiple_ctors :
    public tuto::utl::context_singleton<Context, multiple_ctors<Context, n>>,
    public tuto::utl::object_counter<multiple_ctors<Context, n>> {
  std::string name_;
  unsigned int id_;
public:
  multiple_ctors();
  multiple_ctors( std::string const& name );
  multiple_ctors( unsigned int id );
  multiple_ctors( std::string const& name, unsigned int id );
  ~multiple_ctors() = default;

  std::string const& name() const;
  unsigned int id() const;
};

// Definition of (inlined) methods and functions ( most likely template related ).
// ------------------------------------------------------------------------------

#include <iostream>

template < typename Context, unsigned int n>
inline test::multiple_ctors<Context, n>::multiple_ctors() : name_(""), id_(0) {
  std::cout << "--------------------------------> Create with default ctor" << std::endl;
}

template < typename Context, unsigned int n>
inline test::multiple_ctors<Context, n>::multiple_ctors( std::string const& name ) : name_(name), id_(0) {
  std::cout << "--------------------------------> Create with name ctor" << std::endl;
}

template < typename Context, unsigned int n>
inline test::multiple_ctors<Context, n>::multiple_ctors( unsigned int id ) : name_(""), id_(id) {
  std::cout << "--------------------------------> Create with id ctor" << std::endl;
}

template < typename Context, unsigned int n>
inline test::multiple_ctors<Context, n>::multiple_ctors( std::string const& name, unsigned int id ) : name_(name), id_(id) {
  std::cout << "--------------------------------> Create with full ctor" << std::endl;
}

template < typename Context, unsigned int n>
inline std::string const& test::multiple_ctors<Context, n>::name() const {
  return name_;
}

template < typename Context, unsigned int n>
inline unsigned int test::multiple_ctors<Context, n>::id() const {
  return id_;
}


#endif /* CONTEXT_SINGLETONTEST_H */