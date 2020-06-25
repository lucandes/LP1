#include "message.h"

Message::Message() : date(), time(), content("")
{}


Message::Message(Date d, Time t, std::string c) : date(d), time(t), content(c)
{}