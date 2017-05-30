/**
 * \file
 * \brief     Main of the NAVSYS feature branch
 * \author    Philippe Zwietering
 * \copyright Copyright (c) 2017, The R2D2 Team
 * \license   See ../../LICENSE
 */

#include "server.hh"


int main() {

    std::cout << "Starting server\n";
    Server(5000).run();

    return 0;
}
