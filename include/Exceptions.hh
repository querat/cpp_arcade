//
// Created by lina_a on 03/04/16.
//

#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH

#include <exception>
#include <iostream>

namespace Arcade
{
    class Exception : std::exception
    {
        public:
            Exception(const std::string &msg = "");
            virtual ~Exception() throw() { };
            virtual const char *what() const throw();

    private:
        std::string _message;

    };
}
#endif //SNAKE_EXCEPTIONS_HH
