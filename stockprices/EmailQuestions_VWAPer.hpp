#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <string>

/**
VWAPer v0.1

// Read file in with the following format:
// [Stock],[Interval],[Volume Traded],[High],[Low]

// Calculate the total volume traded per Stock
// Calculate the total volume traded per Stock&Interval

// Write the total volume traded per Stock&Interval as a percentage of the total volume traded per Stock to stdout:
// [Stock],[Interval],[%Volume Traded]

// Write the delimiter '#' to stdout

// Write the maximum High and minimum Low for each Stock to stdout:
// [Stock],[Day High],[Day Low]

// example input:
VOD.L 1 100 184 183.7
BT.LN 1 300 449.4 448.2
VOD.L 2 25 184.1 182.4
BT.LN 2 900 449.8 449.5

// example output:
VOD.L,1,80
BT.LN,1,25
VOD.L,2,20
BT.LN,2,75
#
VOD.L,184.1,182.4
BT.LN,449.8,448.2

**/

#define DELIMITER "#"

using namespace std;

typedef basic_string<char> string;

class	CUpperLower
{
public:
    CUpperLower() : nCurLwr(0), nCurUpr(0) {};

    void	add(int nHigh, int nLow)
    {
        if (nHigh > nCurUpr)
            nCurUpr = nHigh;

        if (nLow < nCurLwr)
            nCurLwr = nLow;
    }

    int& getSum()
    {
        int sum = nCurLwr + nCurUpr;
        return sum;
    }

    int         nCurLwr;
    int         nCurUpr;
};

int test_main(char* argv[])
{
    if (!strcmp("version", argv[1]))
    {
        cerr << "VWAPer version 0.1" << endl;
        return 0;
    }

    FILE*	file = fopen(argv[2], "r");

    cerr << "Reading file" << argv[2] << endl;

    char	line[256];
    char	Stocks[1000][10];
    int         Intervals[1000];
    int         Volumes[1000];
    float	Highs[1000];
    float	Lows[1000];

    int         i = 0;
    int         sum = 0;

    while (fgets(line, 256, file))
    {
        sscanf(line, "%s %d %d %f %f",
               Stocks[i], &Intervals[i],
               &Volumes[i], &Highs[i], &Lows[i++]);
    }

    cerr << "Calculating total volumes" << endl;

    map<std::string, int>		TotalVolumes;

    for (int s = 0; s <= i; ++s)
    {
        std::string	stockname = Stocks[s];

        for (int j =0; j <= i; ++j)
        {
            if (!strcmp(Stocks[j], stockname.c_str()))
            {
                TotalVolumes[stockname] += Volumes[j];
            }
        }
    }

    cerr << "Calculating high lows" << endl;

    map<std::string, CUpperLower>	HighLows;

    for (int s = 0; s <= i; ++s)
    {
        HighLows[Stocks[s]].add(Highs[s], Lows[s]);
        cout << HighLows[Stocks[s]].getSum();
    }

    cerr << "Writing files" << endl;

    for (int s = 0; s <= i; ++s)
    {
        cout << Stocks[s] << "," << Intervals[s] << "," <<
             TotalVolumes[Stocks[s]] / Volumes[s] * 100 << endl;
    }

    cout << DELIMITER << endl;

    map<std::string, CUpperLower>::iterator itr = HighLows.begin();
    while (itr != HighLows.end())
    {
        cout << (*itr).first << "," << (*itr).second.nCurLwr << "," <<
             (*itr).second.nCurUpr << endl;

        ++itr;
    }

    return 1;
}

//int main(int argc, char* argv[])
//{
//    if (!strcmp("version", argv[1]))
//    {
//        cerr << "VWAPer version 0.1" << endl;
//        return 0;
//    }
//
//    FILE*	file = fopen(argv[2], "r");
//
//    cerr << "Reading file" << argv[2] << endl;
//
//    char	line[256];
//    char	Stocks[1000][10];
//    int         Intervals[1000];
//    int         Volumes[1000];
//    float	Highs[1000];
//    float	Lows[1000];
//
//    int         i = 0;
//    int         sum = 0;
//
//    while (fgets(line, 256, file))
//    {
//        sscanf(line, "%s %d %d %f %f",
//               Stocks[i], &Intervals[i],
//               &Volumes[i], &Highs[i], &Lows[i++]);
//    }
//
//    cerr << "Calculating total volumes" << endl;
//
//    map<std::string, int>		TotalVolumes;
//
//    for (int s = 0; s <= i; ++s)
//    {
//        std::string	stockname = Stocks[s];
//
//        for (int j =0; j <= i; ++j)
//        {
//            if (!strcmp(Stocks[j], stockname.c_str()))
//            {
//                TotalVolumes[stockname] += Volumes[j];
//            }
//        }
//    }
//
//    cerr << "Calculating high lows" << endl;
//
//    map<std::string, CUpperLower>	HighLows;
//
//    for (int s = 0; s <= i; ++s)
//    {
//        HighLows[Stocks[s]].add(Highs[s], Lows[s]);
//        cout << HighLows[Stocks[s]].getSum();
//    }
//
//    cerr << "Writing files" << endl;
//
//    for (int s = 0; s <= i; ++s)
//    {
//        cout << Stocks[s] << "," << Intervals[s] << "," <<
//             TotalVolumes[Stocks[s]] / Volumes[s] * 100 << endl;
//    }
//
//    cout << DELIMITER << endl;
//
//    map<std::string, CUpperLower>::iterator itr = HighLows.begin();
//    while (itr != HighLows.end())
//    {
//        cout << (*itr).first << "," << (*itr).second.nCurLwr << "," <<
//             (*itr).second.nCurUpr << endl;
//
//        ++itr;
//    }
//
//    return 1;
//}