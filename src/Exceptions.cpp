//
// Created by lina_a on 03/04/16.
//

#include "Exceptions.hh"


Arcade::Exception::Exception(const std::string &msg) : _message(msg)
{

}


const char *Arcade::Exception::what() const throw()
{
    return this->_message.c_str();
}
