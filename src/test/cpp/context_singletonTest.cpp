/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   context_singleton.cpp
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 25, 2016, 9:16 AM
 *
 * @Brief Brief description of context_singleton.cpp.
 *
 * Description:
 */

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------
#include <gtest/gtest.h>

// Include project headers
// -----------------------


// Include declaration header
// --------------------------
#include <context_singletonTest.h>


TEST( context_singletonTest, context01 ) {
   using namespace tuto::utl;

   int count{0};

  {
      typedef test::multiple_ctors<test::context1_tag,1> test_class;

      test_class& instance = test_class::instance("wow");
      count = instance.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance.id(), 0 );
      EXPECT_EQ( instance.name(), "wow" );
      count = instance.num_created();
      EXPECT_EQ( count, 1 );

      test_class& instance2 = test_class::instance(10U);
      count = instance2.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance2.id(), 0 );
      EXPECT_EQ( instance2.name(), "wow" );
      count = instance2.num_created();
      EXPECT_EQ( count, 1 );

      test::multiple_ctors<test::context2_tag,1>& instance3 = test::multiple_ctors<test::context2_tag,1>::instance(10U);
      count = instance3.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance3.id(), 10U );
      EXPECT_TRUE( instance3.name().empty() );
      count = instance3.num_created();
      EXPECT_EQ( count, 1 );

  }
}

TEST( context_singletonTest, context02 ) {
   using namespace tuto::utl;

   int count{0};

  {
      typedef test::plain_multiple_ctors<1> test_class;

      test_class& instance = test_class::instance<test::context1_tag>("wow");
      count = instance.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance.id(), 0 );
      EXPECT_EQ( instance.name(), "wow" );
      count = instance.num_created();
      EXPECT_EQ( count, 1 );

      test_class& instance2 = test_class::instance<test::context1_tag>(10U);
      count = instance2.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance2.id(), 0 );
      EXPECT_EQ( instance2.name(), "wow" );
      count = instance2.num_created();
      EXPECT_EQ( count, 1 );

      // With instance contexts we can have multiple instances of 'singletonized' classes.
      // (thanks to Scott Meyers implementation of singletons!)
      test_class& instance3 = test_class::instance<test::context2_tag>(10U);
      count = instance3.num_created();
      EXPECT_EQ( count, 2 );
      EXPECT_EQ( instance3.id(), 10 );
      EXPECT_TRUE( instance3.name().empty() );
      count = instance3.num_created();
      EXPECT_EQ( count, 2 );

      test_class& instance4 = test_class::instance<test::context3_tag>( "Hello", 42U);
      count = instance4.num_created();
      EXPECT_EQ( count, 3 );
      EXPECT_EQ( instance4.id(), 42 );
      EXPECT_EQ( instance4.name(), "Hello" );
      count = instance4.num_created();
      EXPECT_EQ( count, 3 );
  }
}

