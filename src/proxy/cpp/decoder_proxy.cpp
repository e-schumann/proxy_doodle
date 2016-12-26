/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   decoder_proxy.cpp
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 26, 2016, 10:24 AM
 *
 * @Brief Brief description of decoder_proxy.cpp.
 *
 * Description:
 */

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------


// Include project headers
// -----------------------
#include <decoder.h>
#include <parser_interface.h>

// Include declaration header
// --------------------------
#include <decoder_proxy.h>

tuto::pt::ptree tuto::decoder_proxy::decode( std::string const& data ) const {
    return decoder_->decode(data);
}

// ToDo: This initialization list needs some attention ...
tuto::decoder_proxy::decoder_proxy( parser_interface* parser) : parser_{parser}, decoder_{new decoder(parser_)} {
}
