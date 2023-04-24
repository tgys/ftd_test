#include "stockprices.h"

void Stock::add_highs_lows(const ULD nHigh, const ULD nLow)
{
    if (nHigh > nCurUpr)
        nCurUpr = nHigh;

    if (nLow < nCurLwr)
        nCurLwr = nLow;
}

void Stock::add_volume(const int interval, const ULD vol)
{
    interval_volumes[interval] += vol;
    total_volume += vol;
}

const void Stock::print_vols() {
    if(total_volume == 0){
        throw std::overflow_error("division by 0: total volume is 0");
    } else {
        for(auto& interval_vol : interval_volumes){
            std::cout << name << ' ' << interval_vol.first << ' ' << (interval_vol.second / total_volume)*100 << '\n';
        }
    }
}

const ULD Stock::getHigh(){
    return nCurUpr;
}
const ULD Stock::getLow(){
    return nCurLwr;
}

long double convert_ld(std::string& str){
    char * e;
    errno = 0;
    long double val = std::strtold(str.c_str(), &e);
    if (*e != '\0' || errno != 0) {
        throw std::runtime_error("conversion error, check input file");
    }
    return val;
}

void calculate_prices(std::string filename)
{
    std::ifstream file(filename);
    StockVolumes stock_vol_map;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> tokens;
            size_t pos = 0;
            while ((pos = line.find(' ')) != std::string::npos) {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            tokens.push_back(line.substr(0, pos));
            std::string foo = tokens[0];
            if(stock_vol_map.find(tokens[0]) == stock_vol_map.end()){
                stock_vol_map[tokens[0]] = Stock(tokens[0]);
            }
            stock_vol_map[tokens[0]].add_volume(std::stoi(tokens[1]), convert_ld(tokens[2]));
            stock_vol_map[tokens[0]].add_highs_lows(convert_ld(tokens[3]), convert_ld(tokens[4]));
        }
        file.close();
    }
    for(auto& pstk : stock_vol_map){
        pstk.second.print_vols();
    }
    std::cout << DELIMITER << '\n';
    for(auto& pstk : stock_vol_map){
        std::cout << pstk.first << ' ' << pstk.second.getHigh() << ' ' << pstk.second.getLow() << '\n';
    }
};

