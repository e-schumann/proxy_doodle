/*
 * The MIT License
 *
 * Copyright 2016 Eike Schumann <e-schumann@online.de>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * @File   singletonTest.h
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 24, 2016, 1:49 PM
 *
 * @Brief Brief description of file.
 *
 * Description:
 */


// Create a comment in the ELF object file structure for
// error tracing reasons.
// -----------------------------------------------------

#if defined( __unix__ ) || defined( __unix )
#ident "@(#) singletonTest 2016-12-24 13:49:02 Eike Schumann"
#endif


// Ensure that only a C++ compiler tries to compile this file to avoid
// some 'interesting' error messages from C compilers
// ---------------------------------------------------------------------

#if !defined( __cplusplus )
#error The file __FILE__ requires to be compiled by a C++ compiler!
#endif


// Include guard to avoid multiple inclusion
// -----------------------------------------
#ifndef SINGLETONTEST_H
#define SINGLETONTEST_H

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------


// Include project headers
// -----------------------
#include <singleton.h>
#include <object_counter.h>

// Synopsis/Namespace interface:
// This section lists the classes, functions and types provided by this
// file as well as forward declaration of classes, functions and types
// provided by custom components.
// --------------------------------------------------------------------
namespace test {
  struct constructor_test_class;
  struct constructor_test_class2;
  template < unsigned int n> class multiple_constructors;
}

// Declarations of the class interfaces
// ------------------------------------


struct test::constructor_test_class : public tuto::utl::singleton<constructor_test_class>,
                                      public tuto::utl::object_counter<constructor_test_class> {
  constructor_test_class() {};
  constructor_test_class( constructor_test_class const&) {};
  ~constructor_test_class() {};
};

struct test::constructor_test_class2 : public tuto::utl::object_counter<constructor_test_class2> {
  constructor_test_class2() {};
  constructor_test_class2( constructor_test_class2 const&) {};
  ~constructor_test_class2() {};
};

template < unsigned int n> class test::multiple_constructors : public tuto::utl::singleton<multiple_constructors<n>>,
                                                               public tuto::utl::object_counter<multiple_constructors<n>> {
  std::string name_;
  unsigned int id_;
public:
  multiple_constructors();
  multiple_constructors( std::string const& name );
  multiple_constructors( unsigned int id );
  multiple_constructors( std::string const& name, unsigned int id );
  ~multiple_constructors() = default;

  std::string const& name() const;
  unsigned int id() const;
};


// Definition of (inlined) methods and functions ( most likely template related ).
// ------------------------------------------------------------------------------

template < unsigned int n> inline test::multiple_constructors<n>::multiple_constructors() : name_(""), id_(0) {
}

template < unsigned int n> inline test::multiple_constructors<n>::multiple_constructors( std::string const& name ) : name_(name), id_(0) {
}

template < unsigned int n> inline test::multiple_constructors<n>::multiple_constructors( unsigned int id ) : name_(""), id_(id) {
}

template < unsigned int n> inline test::multiple_constructors<n>::multiple_constructors( std::string const& name, unsigned int id ) : name_(name), id_(id) {
}

template < unsigned int n> inline std::string const& test::multiple_constructors<n>::name() const {
  return name_;
}

template < unsigned int n> inline unsigned int test::multiple_constructors<n>::id() const {
  return id_;
}

#endif /* SINGLETONTEST_H */