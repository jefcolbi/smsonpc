#include "message.h"

Message::Message()
{

}

Message::Message(QString pText, time_t pTime, bool pSended)
{
    text = pText;
    time = pTime;
    sended = pSended;
}
