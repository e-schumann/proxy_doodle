
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_SCALAR_HPP_INCLUDED
#define BOOST_TT_IS_SCALAR_HPP_INCLUDED

#include <boost/type_traits/is_arithmetic.hpp>
#include <boost/type_traits/is_enum.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_member_pointer.hpp>
#include <boost/config.hpp>

namespace boost_part {} namespace boost = boost_part; namespace boost_part {

template <typename T>
struct is_scalar
   : public integral_constant<bool, ::boost_part::is_arithmetic<T>::value || ::boost_part::is_enum<T>::value || ::boost_part::is_pointer<T>::value || ::boost_part::is_member_pointer<T>::value>
{};

} // namespace boost_part

#endif // BOOST_TT_IS_SCALAR_HPP_INCLUDED
