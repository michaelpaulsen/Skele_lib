#ifndef ERROR_D
#define ERROR_D
#include <string>

enum Error_t {
    OK,
    INVALID_TYPE,
    INVALID_INPUT,
    DATA_INVALID,
    DIV_BY_NULL
};
template<typename V_T> struct Error_Or_T {

    V_T GetVal() {
        return value;
    }
    Error_t GetError() {
        return error;
    }
    bool IsDataValid() {
        return this->error == Error_t::OK;
    }
    Error_Or_T(V_T v, Error_t e) {
        value = v;
        error = e;
    }
private:
    V_T value;
    Error_t error;
};
void perror_t(std::string errorName, std::string errorMsg) {
    printf("-- %s --\n", errorName.c_str());
    printf("%s\n", errorMsg.c_str());
}
void perror_c(Error_t v, size_t lineNumber = 0) {

    if (v) { 
        //this is the same as doing v != Error_t::OK bc Error_t::OK == 0 and 0 is falsey 
  
        switch (v) {
        case INVALID_TYPE: {
            perror_t("INVALID TYPE", "the type supplied to the template is incorrect");
            break;
        }
        case INVALID_INPUT: {
            perror_t("INVALID_INPUT", "the vlaue supplied to the function is incorrect");
            break;
        }
        case DIV_BY_NULL: {
            perror_t("DIV_BY_NULL", "tried to divide by zero");
            break;
        }
        default: {
            perror_t("UNKNOWN", "it should be impossible to see this if you do you need to add another error to the switch statement in perror_c")
        }
        }
        if (lineNumber != 0 ) printf("on line %llu\n\n", lineNumber); // this wont work if you don't properly format your code so format your code. 

    }
}
#endif // ERROR_D
