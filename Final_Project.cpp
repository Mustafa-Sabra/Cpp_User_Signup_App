
//including the dependencies
#include <iostream>
#include <array>
#include <string>

//add the user-defined datatypes
enum class options{
    add             = 1 ,
    fetch           = 2 , 
    quit            = 3
};

class Record{
    public:
        std::string name;
        int age ;
};

//Functions declarations
std::string     print_option        (const options option)                              ;
void            print_msg           (const std::string msg)                             ;
options         user_select         (void)                                              ;
std::istream&   operator>>          (std::istream& input_stream, options & option)      ;
void            add_record          (std::string name, int age)                         ;
void            fetch_record        (int id)                                            ;

//Global variables declarations
constexpr options DEFAULT_VALUE     =       options::quit                               ;
int COUNTER                         =       0                                           ;
std::array<Record,100>Records_Arr;

int main()
{
    //Menu Array
    std::array < options, 3> options_arr {options::add, options::fetch, options::quit};

    //Local variables
    options user_option             = DEFAULT_VALUE     ;
    bool quit_option                = false             ;
    std::string name                                    ;
    int age                                             ;
    int id                                              ;

    print_msg("User Signup Application \n")             ;           //Welcoming message

    while(!quit_option)
    {

        print_msg("\nPlease select an option : \n")     ;

        for(options opt : options_arr)
        {
            print_msg( print_option(opt) )              ;           //Print the menu
        }

        user_option = user_select()                     ;           //Get the option from the user

        //Check out the user-option
        switch(user_option)
        {

            case options::add:
            {
                print_msg("add user. please enter user name and age:\n")        ;
                print_msg("name : ")                                            ;
                std::cin >> name;
                print_msg("age : ")                                             ;
                std::cin >> age;
                add_record(name, age)                                           ;
                print_msg("\nuser record add successfully\n")                   ;
            }
            break;
            
            case options::fetch:
            {
                print_msg("Please enter user id : ")                            ;
                std::cin >> id                                                  ;
                fetch_record(id)                                                ;       
            }
            break;

            case options::quit:
            {
                quit_option       =     true                                    ;
            }
            break;

            default:
                print_msg("Error: Wrong option ! \n")                           ;
            break;

        }

    }
    
    return 0;
}

//This function returns the option description according to the option passed to it.
std::string print_option(const options option)
{
    std::string str                                  ;

    switch(option)
    {
        case options::add:
            str     =       "1. Add Record \n"          ;
            break                                       ;
        
        case options::fetch:
            str     =       "2. Fetch Record \n"        ;
            break                                       ;

        case options::quit:
            str     =       "3. quit \n"                ;
            break                                       ;

        default:
            str     =  "Error : wronge option ! \n"     ;
            break                                       ;
    }

    return str                                          ;
}

//This simple function prints a message passed to it.
void print_msg(const std::string msg){  std::cout << msg    ;   }

//This function gets the option from the user.
options user_select()
{
    options option                                      ;

    print_msg("\nEnter option : ")                      ;
    std::cin >> option                                  ;
    print_msg("\n")                                     ;
    
    return option                                       ;

}

//This is an operator overloadig.
std::istream& operator>>(std::istream& input_stream, options & option)
{
    int input                                           ;

    input_stream >> input                               ;

    option = static_cast<options>(input)                ;

    return input_stream                                 ;


}

//This function takes the user's name and age , creates a record and pushs it into the records_arr.
void add_record(std::string name, int age)
{
    Record user_record                                  ;
    user_record.name = name                             ;
    user_record.age = age                               ;
    Records_Arr[COUNTER] = user_record                  ;     
    COUNTER++                                           ;

}

//This function fetches the record from the records_arr according to the id. 
void fetch_record(int id)
{
    print_msg("user id : " + std::to_string(id) + "\n")                                 ;
    print_msg("user name : " + Records_Arr[id].name + "\n")                             ;
    print_msg("user age : " + std::to_string(Records_Arr[id].age) + "\n")               ;
}