#pragma once

#include <cstdlib>
#include <cstring>
#include <exception>
#include <memory>
#include <sstream>
#include <string>

namespace Traverse::Exception {
    class Exception : public std::exception {

    };

    #define DECLARE_EXCEPTION(NAME, CLS, BASE) \
        class CLS: public BASE { \
            public: \
                inline static const char* name = NAME; \
                const char* message; \
\
                CLS() : message("") {} \
                CLS(const char* t_message) : message(t_message) {} \
\
                inline const char* what() const noexcept override { \
                    std::ostringstream ss; \
                    ss << name << ": " << message; \
                    std::string strVer = ss.str(); \
                    char* returnStr = (char*)malloc(strVer.size()); \
                    strncpy(returnStr, strVer.c_str(), strVer.size()); \
                    return returnStr; \
                } \
        };

    // Exceptions
    DECLARE_EXCEPTION("ConfigLoadException", ConfigLoadException, Exception)
}