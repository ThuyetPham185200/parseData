#include <QApplication>
#include <QDataStream>
#include <QFile>
#include <vector>
#include<fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int lengthOfDataFrame_ = 0;
    int prevLengthOfDataFrame_ = 0;

    std::ifstream input( "/home/thuyet/Desktop/logs/15-05-28.bin", std::ios::binary );
    std::vector<unsigned char> buffer_(std::istreambuf_iterator<char>(input), {});
    std::vector<unsigned char>  dataFrame_(0);

    for (int i = prevLengthOfDataFrame_; i < buffer_.size() ; i++)
    {
        if(buffer_[i] == 0x0a && buffer_[i+1] == 0x0d)
        {
            lengthOfDataFrame_ = i + 2 - prevLengthOfDataFrame_;
            dataFrame_.resize(lengthOfDataFrame_);
            for (int i = 0; i < 8 ; i ++)
            {
                printf("%02x\n", buffer_[i]);
            }
            for(int j = prevLengthOfDataFrame_ ; j < lengthOfDataFrame_; j++)
            {
                dataFrame_.push_back(buffer_[j - prevLengthOfDataFrame_]);
            }
            prevLengthOfDataFrame_ = lengthOfDataFrame_;
            printf("%02d\n", prevLengthOfDataFrame_);
            for (auto e : dataFrame_ ) printf("%02x\n", e);
            break;
        }

    }
   // std::vector<unsigned char *> dataFrame_;
   return 0;
}


