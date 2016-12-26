/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   decoder_proxyTest.cpp
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 26, 2016, 11:37 AM
 *
 * @Brief Brief description of decoder_proxyTest.cpp.
 *
 * Description:
 */

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------
#include <memory>

// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------
#include <gtest/gtest.h>

// Include project headers
// -----------------------
#include <fixture_create_test_file.h>
#include <decoder_proxy.h>
#include <parser_xml.h>
#include <parser_json.h>
#include <singleton.h>

// Include declaration header
// --------------------------

struct context1{};
struct context2{};

typedef test::fixture_create_test_file file_fixture; // Oh Google, WHY macros...?
TEST_F( file_fixture, test01 ) {
   using namespace tuto;

   decoder_interface& decoder_proxy1 = decoder_proxy::instance<context1>( new parser_xml );

   std::string content = get_file_content( "Hugo.xml");
   auto props = decoder_proxy1.decode( content );

   auto name = props.get("testdata.name","");
   auto age  = props.get("testdata.age",0);

   EXPECT_EQ( "Hugo", name );
   EXPECT_EQ( 25, age );



   decoder_interface& decoder_proxy2 = decoder_proxy::instance<context2>( new parser_json );
   content = get_file_content( "Carla.json");

   props = decoder_proxy2.decode( content );
   name = props.get("testdata.name","");
   age  = props.get("testdata.age",0);
   EXPECT_EQ( "Carla", name );
   EXPECT_EQ( 22, age );
}


template <typename T, typename P> struct base_command {
   static tuto::pt::ptree decode( std::string const& content ) {
      tuto::decoder_interface& decoder_proxy = tuto::decoder_proxy::instance<T>( &tuto::utl::singleton<P>::instance() );
      return decoder_proxy.decode( content );
   }
};


struct command_a : public base_command<command_a, tuto::parser_xml> {
   tuto::pt::ptree decode( std::string const& content ) {
      return base_command::decode( content );
   }
};

struct command_b : public base_command<command_b, tuto::parser_xml> {
   tuto::pt::ptree decode( std::string const& content ) {
      return  base_command::decode( content );
   }
};

struct command_c : public base_command<command_c, tuto::parser_xml> {
   tuto::pt::ptree decode( std::string const& content ) {
      return base_command::decode( content );
   }
};

struct command_d : public base_command<command_d, tuto::parser_json> {
   tuto::pt::ptree decode( std::string const& content ) {
      return base_command::decode( content );
   }
};

struct command_e : public base_command<command_e, tuto::parser_json> {
   tuto::pt::ptree decode( std::string const& content ) {
      return base_command::decode( content );
   }
};

struct command_f : public base_command<command_f, tuto::parser_json> {
   tuto::pt::ptree decode( std::string const& content ) {
      return base_command::decode( content );
   }
};

TEST_F( file_fixture, test02 ) {
   auto content = get_file_content( "Hugo.xml");
   command_a a;
   auto props = a.decode( content );
   EXPECT_EQ( "Hugo", props.get("testdata.name", "") );
   EXPECT_EQ( 25, props.get("testdata.age", 0) );

   content = get_file_content( "Otto.xml");
   props = a.decode( content );
   EXPECT_EQ( "Otto", props.get("testdata.name", "") );
   EXPECT_EQ( 12, props.get("testdata.age", 0) );

   content = get_file_content( "Karl.xml");
   props = a.decode( content );
   EXPECT_EQ( "Karl", props.get("testdata.name", "") );
   EXPECT_EQ( 88, props.get("testdata.age", 0) );

   content = get_file_content( "Carla.json");
   EXPECT_ANY_THROW(
      props = a.decode( content );
   );


   command_b b;
   content = get_file_content( "Otto.xml");
   props = b.decode( content );
   EXPECT_EQ( "Otto", props.get("testdata.name", "") );
   EXPECT_EQ( 12, props.get("testdata.age", 0) );

   command_c c;
   content = get_file_content( "Karl.xml");
   props = c.decode( content );
   EXPECT_EQ( "Karl", props.get("testdata.name", "") );
   EXPECT_EQ( 88, props.get("testdata.age", 0) );

   command_d d;
   content = get_file_content( "Emilia.json");
   props = d.decode( content );
   EXPECT_EQ( "Emilia", props.get("testdata.name", "") );
   EXPECT_EQ( 43, props.get("testdata.age", 0) );

   content = get_file_content( "Hillary.json");
   props = d.decode( content );
   EXPECT_EQ( "Hillary", props.get("testdata.name", "") );
   EXPECT_EQ( 62, props.get("testdata.age", 0) );

   content = get_file_content( "Carla.json");
   props = d.decode( content );
   EXPECT_EQ( "Carla", props.get("testdata.name", "") );
   EXPECT_EQ( 22, props.get("testdata.age", 0) );

   command_e e;
   content = get_file_content( "Emilia.json");
   props = e.decode( content );
   EXPECT_EQ( "Emilia", props.get("testdata.name", "") );
   EXPECT_EQ( 43, props.get("testdata.age", 0) );

   command_f f;
   content = get_file_content( "Emilia.json");
   props = f.decode( content );
   EXPECT_EQ( "Emilia", props.get("testdata.name", "") );
   EXPECT_EQ( 43, props.get("testdata.age", 0) );

   content = get_file_content( "Karl.xml");
   EXPECT_ANY_THROW(
      props = f.decode( content );
   );
}


