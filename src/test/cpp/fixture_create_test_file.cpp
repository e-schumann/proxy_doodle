/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   fixture_create_test_file.cpp
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 26, 2016, 2:24 AM
 *
 * @Brief Brief description of fixture_create_test_file.cpp.
 *
 * Description:
 */

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------
#include <boost/filesystem/fstream.hpp>

// Include project headers
// -----------------------


// Include declaration header
// --------------------------
#include <fixture_create_test_file.h>

 test::fixture_create_test_file::fixture_create_test_file() {
    current_path_ = fs::current_path();
 }

void test::fixture_create_test_file::SetUp() {
   write_xml( "Hugo", 25 );
   write_xml( "Otto", 12 );
   write_xml( "Karl", 88 );
   write_json( "Emilia", 43 );
   write_json( "Hillary", 62 );
   write_json( "Carla", 22 );
}

void test::fixture_create_test_file::TearDown() {
   remove_xml( "Hugo ");
   remove_xml( "Otto ");
   remove_xml( "Karl ");
   remove_json( "Emilia ");
   remove_json( "Hillary ");
   remove_json( "Carla ");
}

void test::fixture_create_test_file::write_xml( std::string const& name, int age ) const {
   auto file_path = current_path_ / (name + ".xml");
   fs::ofstream out_file( file_path );
   out_file << "<testdata>\n"
            << "  <name>" << name << "</name>\n"
            << "  <age>" << age << "</age>\n"
            << "</testdata>\n";
   out_file.flush();
}

void test::fixture_create_test_file::write_json( std::string const& name, int age ) const {
   auto file_path = current_path_ / (name + ".json");
   fs::ofstream out_file( file_path );
   out_file << "{ \n  \"testdata\" : \n"
            << "  {\n    \"name\" : \"" << name << "\",\n"
            << "     \"age\" : " << age << "\n"
            << "  }\n"
            << "}\n";
   out_file.flush();
}

void test::fixture_create_test_file::remove_xml( std::string const& name ) const {
   auto file_path = current_path_ / (name + ".xml");
   if ( fs::exists( file_path ) ) {
      fs::remove( file_path );
   }
}

void test::fixture_create_test_file::remove_json( std::string const& name ) const {
   auto file_path = current_path_ / (name + ".json");
   if ( fs::exists( file_path ) ) {
      fs::remove( file_path );
   }
}

std::string test::fixture_create_test_file::get_file_content( std::string const& filename ) const {
   std::string file_content;
   auto file_path = current_path_ / filename;
   if ( fs::exists( file_path ) ) {
     fs::ifstream in_stream( file_path );
     // Read the file content in a preallocated fitting string
     in_stream.seekg(0, std::ios::end);
     file_content.reserve(in_stream.tellg());
     in_stream.seekg(0, std::ios::beg);
     file_content.assign((std::istreambuf_iterator<char>(in_stream)), std::istreambuf_iterator<char>());
   }
   return file_content;
}