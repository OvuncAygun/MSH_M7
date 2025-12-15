// include/Utility.h
#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <cstdio> // sprintf için gerekli

// C++98 uyumlu tamsayýyý string'e çevirme fonksiyonu
std::string IntToString(int value) {
    char buffer[20];
    // printf yerine güvenli sprintf kullanýmý (tampon boyutunu aþmamalý)
    sprintf(buffer, "%d", value);
    return std::string(buffer);
}

#endif 