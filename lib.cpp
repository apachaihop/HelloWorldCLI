#include "lib.hpp"
#include <format>
#include "version.hpp"
namespace lib {
    std::string hello_world() {

        return std::format("Bundle {}\n"
                           "Hello World!!", VERSION);
    }
}