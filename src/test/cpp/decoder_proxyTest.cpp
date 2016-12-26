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
      base_command::decode( content );
   }
};

//class command_b : public base_command<command_b> {
//   std::unique_ptr< tuto::parser_interface> parser_;
//public:
//   command_b() : parser_{new tuto::parser_xml} {
//   }
//
//   tuto::pt::ptree decode( std::string const& content ) {
//      base_command::decode( content, parser_.get() );
//   }
//};
//
//class command_c : public base_command<command_c> {
//   std::unique_ptr< tuto::parser_interface> parser_;
//public:
//   command_c() : parser_{new tuto::parser_xml} {
//   }
//
//   tuto::pt::ptree decode( std::string const& content ) {
//      base_command::decode( content, parser_.get() );
//   }
//};
//
//class command_d : public base_command<command_d> {
//   std::unique_ptr< tuto::parser_interface> parser_;
//public:
//   command_d() : parser_{new tuto::parser_json} {
//   }
//
//   tuto::pt::ptree decode( std::string const& content ) {
//      base_command::decode( content, parser_.get() );
//   }
//};
//
//class command_e : public base_command<command_e> {
//   std::unique_ptr< tuto::parser_interface> parser_;
//public:
//   command_e() : parser_{new tuto::parser_json} {
//   }
//
//   tuto::pt::ptree decode( std::string const& content ) {
//      base_command::decode( content, parser_.get() );
//   }
//};
//
//class command_f : public base_command<command_f> {
//   std::unique_ptr< tuto::parser_interface> parser_;
//public:
//   command_f() : parser_{new tuto::parser_json} {
//   }
//
//   tuto::pt::ptree decode( std::string const& content ) {
//      base_command::decode( content, parser_.get() );
//   }
//};

TEST_F( file_fixture, test02 ) {
   auto content = get_file_content( "Hugo.xml");
   command_a a;
   auto props = a.decode( content );
//   EXPECT_EQ( "Hugo", props.get("testdata.name", "") );
//   EXPECT_EQ( 25, props.get("testdata.age", 0) );
}


