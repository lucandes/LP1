#include "../include/message.h"

Message::Message(const std::string &new_message, const Time &current_time, const Date &current_date) 
: content(new_message), time(current_time), date(current_date){
}