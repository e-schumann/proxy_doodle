/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   context_context_singleton.h
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 25, 2016, 9:12 AM
 *
 * @Brief Brief description of file.
 *
 * Description:
 */


// Create a comment in the ELF object file structure for
// error tracing reasons.
// -----------------------------------------------------

#if defined( __unix__ ) || defined( __unix )
#ident "@(#) context_context_singleton 2016-12-25 09:12:56 Eike Schumann"
#endif


// Ensure that only a C++ compiler tries to compile this file to avoid
// some 'interesting' error messages from C compilers
// ---------------------------------------------------------------------

#if !defined( __cplusplus )
#error The file __FILE__ requires to be compiled by a C++ compiler!
#endif


// Include guard to avoid multiple inclusion
// -----------------------------------------
#ifndef CONTEXT_SINGLETON_H
#define CONTEXT_SINGLETON_H

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
namespace tuto { namespace utl {
  namespace class_scope {
    template < typename Context, typename T > class context_singleton;
  }
  namespace instance_scope {
    template < typename T > class context_singleton;
  }
}}

// Declarations of the class interfaces
// ------------------------------------
template < typename context, typename T > class tuto::utl::class_scope::context_singleton {
protected:
  context_singleton() = default;
  context_singleton( context_singleton const& ) = delete;
  context_singleton& operator=( context_singleton const& ) = delete;
  virtual ~context_singleton() = default;
public:
  template < typename... Args > static T& instance( Args... args );
//  template < typename Context, typename... Args > static T& instance( Args... args );
private:
  static T& apply( std::function<T&()> const& func );
  template < typename... Args > static T& create_meyer_instance( Args... args );
//  template < typename Context, typename... Args > static T& create_meyer_instance( Args... args );
};

// ------------------------------------------------------------------------------

template < typename T > class tuto::utl::instance_scope::context_singleton {

protected:
  context_singleton() = default;
  context_singleton( context_singleton const& ) = delete;
  context_singleton& operator=( context_singleton const& ) = delete;
  virtual ~context_singleton() = default;

public:

  template < typename Context, typename... Args >
  static T& instance( Args... args );

  private:

  template < typename Context>
  static T& apply( std::function<T&()> const& func );

  template < typename Context, typename... Args >
  static T& create_meyer_instance( Args... args );
};

// Definition of (inlined) methods and functions ( most likely template related ).
// ------------------------------------------------------------------------------

template < typename Context, typename T > template < typename... Args >
inline T& tuto::utl::class_scope::context_singleton<Context, T>::instance( Args... args ) {
  static auto unique_func = std::bind( create_meyer_instance< Args...>, args... );
  return apply( unique_func );
}

template < typename Context, typename T >
inline T& tuto::utl::class_scope::context_singleton<Context, T>::apply( std::function<T&()> const& func ) {
  static T& ref_instance = func();
  return ref_instance;
}

template < typename Context, typename T > template < typename... Args >
inline T& tuto::utl::class_scope::context_singleton<Context, T>::create_meyer_instance(Args... args) {
  static T instance{ std::forward<Args>(args)... };
  return instance;
}
// ------------------------------------------------------------------------------

//#include <iostream>
//#include <typeinfo>

template < typename T > template < typename Context, typename... Args >
inline T& tuto::utl::instance_scope::context_singleton<T>::instance( Args... args ) {
  auto unique_func = std::bind( create_meyer_instance< Context, Args...>, args... );
//  std::cout << "--------------------> Return static func object of type: " << typeid(unique_func).name() << std::endl;
  return apply<Context>( unique_func );
}

template < typename T > template < typename Context>
inline T& tuto::utl::instance_scope::context_singleton<T>::apply( std::function<T&()> const& func ) {
  static T& ref_instance = func();
  return ref_instance;
}

template < typename T > template < typename Context, typename... Args >
inline T& tuto::utl::instance_scope::context_singleton<T>::create_meyer_instance(Args... args) {
  static T instance{ std::forward<Args>(args)... };
//  static T instance( args... );
//  std::cout << "--------------------> Return static of type: " << typeid(instance).name() << std::endl;
  return instance;
}

#endif /* CONTEXT_SINGLETON_H */