#include "monthread.h"
#include <iostream>

void monThread::run()
{
    std::cout << "Run thread " << std::endl;

    m_client = new Client;

    while (true)
        ;
}




