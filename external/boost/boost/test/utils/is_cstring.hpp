//  (C) Copyright Gennadiy Rozental 2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile$
//
//  Version     : $Revision$
//
//  Description : defines the is_cstring type trait
// ***************************************************************************

#ifndef BOOST_TEST_UTILS_IS_CSTRING_HPP
#define BOOST_TEST_UTILS_IS_CSTRING_HPP

// Boost
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/decay.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/add_const.hpp>

#include <string>

//____________________________________________________________________________//

namespace boost_part {} namespace boost = boost_part; namespace boost_part {
namespace unit_test {

// ************************************************************************** //
// **************                  is_cstring                  ************** //
// ************************************************************************** //

namespace ut_detail {

template<typename T>
struct is_cstring_impl : public mpl::false_ {};

template<typename T>
struct is_cstring_impl<T const*> : public is_cstring_impl<T*> {};

template<typename T>
struct is_cstring_impl<T const* const> : public is_cstring_impl<T*> {};

template<>
struct is_cstring_impl<char*> : public mpl::true_ {};

template<>
struct is_cstring_impl<wchar_t*> : public mpl::true_ {};

template <typename T>
struct deduce_cstring_impl {
    typedef typename boost_part::add_const<
        typename boost_part::remove_pointer<
            typename boost_part::decay<T>::type
        >::type
    >::type type;
};

template <typename T>
struct deduce_cstring_impl< std::basic_string<T, std::char_traits<T> > > {
  // const is required here
  typedef typename boost_part::add_const<T>::type type;
};

} // namespace ut_detail

template<typename T>
struct is_cstring : public ut_detail::is_cstring_impl<typename decay<T>::type> {};

template<typename T>
struct is_cstring< std::basic_string<T, std::char_traits<T> > > : public mpl::true_ {};

template <class T>
struct deduce_cstring {
    typedef typename
        boost_part::remove_const<
            typename boost_part::remove_reference<T>::type
        >::type U;
    typedef typename ut_detail::deduce_cstring_impl<U>::type type;
};

} // namespace unit_test
} // namespace boost_part

#endif // BOOST_TEST_UTILS_IS_CSTRING_HPP
