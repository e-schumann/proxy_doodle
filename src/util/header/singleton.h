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
 * @File   singleton.h
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 24, 2016, 12:39 PM
 *
 * @Brief Brief description of file.
 *
 * Description:
 */


// Create a comment in the ELF object file structure for
// error tracing reasons.
// -----------------------------------------------------

#if defined( __unix__ ) || defined( __unix )
#ident "@(#) singleton 2016-12-24 12:39:36 Eike Schumann"
#endif


// Ensure that only a C++ compiler tries to compile this file to avoid
// some 'interesting' error messages from C compilers
// ---------------------------------------------------------------------

#if !defined( __cplusplus )
#error The file __FILE__ requires to be compiled by a C++ compiler!
#endif


// Include guard to avoid multiple inclusion
// -----------------------------------------
#ifndef SINGLETON_H
#define SINGLETON_H

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------
#include <utility>
#include <functional>

// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------


// Include project headers
// -----------------------


// Synopsis/Namespace interface:
// This section lists the classes, functions and types provided by this
// file as well as forward declaration of classes, functions and types
// provided by custom components.
// --------------------------------------------------------------------
namespace prxy { namespace utl {
  template < typename T > class singleton;
}}

// Declarations of the class interfaces
// ------------------------------------
template < typename T > class prxy::utl::singleton {
protected:
  singleton() = default;
  singleton( singleton const& ) = delete;
  singleton& operator=( singleton const& ) = delete;
  virtual ~singleton() = default;
public:
  template < typename Context, typename... Args > static T& instance( Args... args );
private:
  template < typename Context > static T& apply( std::function<T&()>& func );
  template < typename Context, typename... Args > static T& create_meyer_instance( Args... args );
};

// Definition of (inlined) methods and functions ( most likely template related ).
// ------------------------------------------------------------------------------

template < typename T > template < typename Context, typename... Args >
static T& prxy::utl::singleton<T>::instance( Args... args ) {
  static auto unique_func = std::bind( create_meyer_instance< Context, Args...>, args... );
  return apply<Context>( unique_func );
}

template < typename T > template < typename Context >
static T& prxy::utl::singleton<T>::apply( std::function<T&()>& func ) {
  static T& ref_instance = func();
  return ref_instance;
}

template < typename T > template < typename Context, typename... Args >
static T& prxy::utl::singleton<T>::create_meyer_instance(Args... args) {
  static T instance{ std::forward<Args>(args)...};
  return instance;
}


#endif /* SINGLETON_H */