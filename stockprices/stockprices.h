#pragma once

#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <fstream>

#define DELIMITER "#"
typedef long double ULD;

class Stock
{
private:
    ULD nCurLwr;
    ULD nCurUpr;
    //values in the map == total volume traded per Stock&Interval
    std::map<int, ULD> interval_volumes;
    std::string name;
    //total volume traded per stock
    ULD total_volume;
public:
    Stock() :
        name(""),
        total_volume(0),
        nCurLwr(std::numeric_limits<ULD>::max()),
        nCurUpr(0) {};
    Stock(std::string name) :
        name(name),
        total_volume(0),
        nCurLwr(std::numeric_limits<ULD>::max()),
        nCurUpr(0) {};

    void add_highs_lows(ULD nHigh, ULD nLow);
    void add_volume(int interval, ULD vol);
    const void print_vols();
    const ULD getHigh();
    const ULD getLow();
};

typedef std::map<std::string, Stock> StockVolumes;

long double convert_ld(std::string& str);

void calculate_prices(std::string filename);
