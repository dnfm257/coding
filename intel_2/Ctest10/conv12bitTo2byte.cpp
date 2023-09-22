#include <iostream>
#include <bitset>

using namespace std;

class packed12bit{
    uint8_t a = 0;
    uint8_t b = 0;
    uint8_t lsb = 0;

    uint16_t A = 0x0000;
    uint16_t B = 0x0000;

public:
    packed12bit(){};
    ~packed12bit(){};
    int SetData(const uint8_t* a, const uint8_t* b, const uint8_t* lsb);
    int GetData(uint16_t* A, uint16_t* B);
    int convert12bitTo2byte();
    int ShowData(uint16_t a, uint16_t b);
};

int packed12bit::SetData(const uint8_t* a = nullptr, const uint8_t* b = nullptr, const uint8_t* lsb = nullptr){
    this->a = *a;
    this->b = *b;
    this->lsb = *lsb;

    return 1;
}
int packed12bit::GetData(uint16_t* A, uint16_t* B){
    *A = this->A;
    *B = this->B;

    return 1;
}
int packed12bit::convert12bitTo2byte(){
    A = (a << 4) | (lsb >> 4) & 0x0F;
    B = (b << 4) | (lsb >> 0) & 0x0F;

    return 1;
}
int packed12bit::ShowData(uint16_t a, uint16_t b){
    cout << "A = " << a << "  " << bitset<10>(a) << endl;
    cout << "B = " << b << "  " << bitset<10>(b) << endl;

    return 1;
}

int main(){
    uint8_t a = 0x12;
    uint8_t b = 0x35;
    uint8_t lsb = 0xB3;

    uint16_t A = 0x0000;
    uint16_t B = 0x0000;

    packed12bit p;
    p.SetData(&a, &b, &lsb);
    p.convert12bitTo2byte();
    p.GetData(&A, &B);
    p.ShowData(A, B);
}