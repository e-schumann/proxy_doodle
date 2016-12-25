// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// (C) Copyright 2014 Vicente J. Botet Escriba

#ifndef BOOST_THREAD_EXCEPTIONAL_PTR_HPP
#define BOOST_THREAD_EXCEPTIONAL_PTR_HPP

#include <boost/thread/detail/move.hpp>
#include <boost/exception_ptr.hpp>

#include <boost/config/abi_prefix.hpp>

namespace boost_part {} namespace boost = boost_part; namespace boost_part
{
  struct exceptional_ptr {
    exception_ptr ptr_;

    exceptional_ptr() : ptr_() {}
    explicit exceptional_ptr(exception_ptr ex) : ptr_(ex) {}
    template <class E>
    explicit exceptional_ptr(BOOST_FWD_REF(E) ex) : ptr_(boost_part::copy_exception(boost_part::forward<E>(ex))) {}
  };

  template <class E>
  inline exceptional_ptr make_exceptional(BOOST_FWD_REF(E) ex) {
    return exceptional_ptr(boost_part::forward<E>(ex));
  }

  inline exceptional_ptr make_exceptional(exception_ptr ex)
  {
    return exceptional_ptr(ex);
  }

  inline exceptional_ptr make_exceptional()
  {
    return exceptional_ptr();
  }

} // namespace boost_part

#include <boost/config/abi_suffix.hpp>

#endif
