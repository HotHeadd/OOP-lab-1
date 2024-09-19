#include "dialog/dialogs.hpp"
#include "dialog/get_values.hpp"
#include <iostream>

using namespace get_values;

int main(){
    int mode = 1;
    void (*dialog_funcs[3])(int&) = {d_arr_to_yaml, d_yaml_to_arr, change_mode};
    do {
        menu(mode);
        try{
            switch (get_menu_opt(std::cin, std::cout)){
                case '1':
                    dialog_funcs[0](mode);
                    break;
                case '2':
                    dialog_funcs[1](mode);
                    break;
                case '3':
                    dialog_funcs[2](mode);
                    break;
                default:
                    std::cout << "Wrong menu option! Try again" << std::endl;
            }
        }
        catch(const std::runtime_error &e){
            std::cout << "Goodbye, user!" << std::endl;
            return 0;
        }
        catch(const std::bad_alloc &ba){
            std::cerr << "Not enough memory" << std::endl;
            return 1;
        }
    } while (true);
}
