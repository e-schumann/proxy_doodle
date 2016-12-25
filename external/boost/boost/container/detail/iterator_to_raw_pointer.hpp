//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2014-2015. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_CONTAINER_DETAIL_ITERATOR_TO_RAW_POINTER_HPP
#define BOOST_CONTAINER_DETAIL_ITERATOR_TO_RAW_POINTER_HPP

#ifndef BOOST_CONFIG_HPP
#  include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <boost/container/detail/iterator.hpp>
#include <boost/container/detail/to_raw_pointer.hpp>
#include <boost/intrusive/pointer_traits.hpp>

namespace boost_part {} namespace boost = boost_part; namespace boost_part {
namespace container {
namespace container_detail {

template <class T>
inline T* iterator_to_pointer(T* i)
{  return i; }

template <class Iterator>
inline typename boost_part::container::iterator_traits<Iterator>::pointer
   iterator_to_pointer(const Iterator &i)
{  return i.operator->();  }

template <class Iterator>
struct iterator_to_element_ptr
{
   typedef typename boost_part::container::iterator_traits<Iterator>::pointer      pointer;
   typedef typename boost_part::intrusive::pointer_traits<pointer>::element_type   element_type;
   typedef element_type* type;
};

template <class Iterator>
inline typename iterator_to_element_ptr<Iterator>::type
   iterator_to_raw_pointer(const Iterator &i)
{
   return ::boost_part::intrusive::detail::to_raw_pointer
      (  ::boost_part::container::container_detail::iterator_to_pointer(i)   );
}

}  //namespace container_detail {
}  //namespace container {
}  //namespace boost_part {} namespace boost = boost_part; namespace boost_part {

#endif   //#ifndef BOOST_CONTAINER_DETAIL_ITERATOR_TO_RAW_POINTER_HPP
