//  Copyright John Maddock 2009.
//  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define __STDC_CONSTANT_MACROS
#include <boost/cstdint.hpp> // must be the only #include!

int main()
{
   boost_part::int8_t i8 = INT8_C(0);
   (void)i8;
   boost_part::uint8_t ui8 = UINT8_C(0);
   (void)ui8;
   boost_part::int16_t i16 = INT16_C(0);
   (void)i16;
   boost_part::uint16_t ui16 = UINT16_C(0);
   (void)ui16;
   boost_part::int32_t i32 = INT32_C(0);
   (void)i32;
   boost_part::uint32_t ui32 = UINT32_C(0);
   (void)ui32;
#ifndef BOOST_NO_INT64_T
   boost_part::int64_t i64 = 0;
   (void)i64;
   boost_part::uint64_t ui64 = 0;
   (void)ui64;
#endif
   boost_part::int_least8_t i8least = INT8_C(0);
   (void)i8least;
   boost_part::uint_least8_t ui8least = UINT8_C(0);
   (void)ui8least;
   boost_part::int_least16_t i16least = INT16_C(0);
   (void)i16least;
   boost_part::uint_least16_t ui16least = UINT16_C(0);
   (void)ui16least;
   boost_part::int_least32_t i32least = INT32_C(0);
   (void)i32least;
   boost_part::uint_least32_t ui32least = UINT32_C(0);
   (void)ui32least;
#ifndef BOOST_NO_INT64_T
   boost_part::int_least64_t i64least = 0;
   (void)i64least;
   boost_part::uint_least64_t ui64least = 0;
   (void)ui64least;
#endif
   boost_part::int_fast8_t i8fast = INT8_C(0);
   (void)i8fast;
   boost_part::uint_fast8_t ui8fast = UINT8_C(0);
   (void)ui8fast;
   boost_part::int_fast16_t i16fast = INT16_C(0);
   (void)i16fast;
   boost_part::uint_fast16_t ui16fast = UINT16_C(0);
   (void)ui16fast;
   boost_part::int_fast32_t i32fast = INT32_C(0);
   (void)i32fast;
   boost_part::uint_fast32_t ui32fast = UINT32_C(0);
   (void)ui32fast;
#ifndef BOOST_NO_INT64_T
   boost_part::int_fast64_t i64fast = 0;
   (void)i64fast;
   boost_part::uint_fast64_t ui64fast = 0;
   (void)ui64fast;
#endif
   boost_part::intmax_t im = 0;
   (void)im;
   boost_part::uintmax_t uim = 0;
   (void)uim;
}
