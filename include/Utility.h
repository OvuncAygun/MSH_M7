#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <cstdio> 

// 'inline' ekleyerek birden fazla .cpp dosyasýnda dahil edildiðinde çakýþmayý önlüyoruz.
inline std::string IntToString(int value) {
    char buffer[20];
    sprintf(buffer, "%d", value); //
    return std::string(buffer);
}

#endif