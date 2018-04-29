#include "CircularInt.hpp"
#include <stdexcept>


CircularInt::CircularInt(int const firstNu, int const lastNu){//constractor
    if(firstNum<lastNum) {
        this->firstNum = firstNu;
        this->lastNum = lastNu;
    } else{
        this->firstNum = lastNu;
        this->lastNum = firstNu;
    }
    currectNum=this->firstNum;
}
CircularInt::CircularInt(const CircularInt & other)//constractor
{
    this->firstNum = other.firstNum;
    this->lastNum = other.lastNum;
    this->currectNum = other.currectNum;
}
CircularInt::~CircularInt(){//destractor
}

void CircularInt::refix(){
    int range = this->lastNum-this->firstNum+1;
    while (this->currectNum>this->lastNum)
        this->currectNum-=range;
    while (this->currectNum<this->firstNum)
        this->currectNum+=range;
}
CircularInt& CircularInt::operator=(const int &rhs) {
    currectNum=rhs;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator=(const CircularInt &rhs) {
    currectNum=rhs.currectNum;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator+=(const int &rhs) {
    currectNum+=rhs;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt &rhs) {
    currectNum+=rhs.currectNum;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator-=(const int &rhs) {
    currectNum-=rhs;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator-=(const CircularInt &rhs) {
    currectNum-=rhs.currectNum;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator*=(const int &rhs) {
    currectNum*=rhs;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt &rhs) {
    currectNum*=rhs.currectNum;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator/=(const int &rhs) {
    if(this->currectNum%rhs!=0)
        throw std::runtime_error("There is no number x in {" + to_string(firstNum)+","+to_string(lastNum)+"} such that x*"+to_string(rhs)+"="+to_string(currectNum));
    currectNum/=rhs;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator/=(const CircularInt &rhs) {
    if(this->currectNum%rhs.currectNum!=0)
        throw std::runtime_error("There is no number x in {" + to_string(firstNum)+","+to_string(lastNum)+"} such that x*"+to_string(rhs.currectNum)+"="+to_string(currectNum));
    currectNum/=rhs.currectNum;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator%=(const int &rhs) {
    currectNum%=rhs;
    this->refix();
    return *this;
}
CircularInt& CircularInt::operator%=(const CircularInt &rhs) {
    currectNum%=rhs.currectNum;
    this->refix();
    return *this;
}

bool CircularInt::operator==(const int &rhs) {
    return (rhs == currectNum);
}
bool CircularInt::operator==(const CircularInt &rhs) {
    return (rhs.currectNum == currectNum);
}
CircularInt& CircularInt::operator++() {
    currectNum++;
    this->refix();
    return *this;
}
CircularInt CircularInt::operator++(int) {
    CircularInt temp(*this);
    currectNum++;
    this->refix();
    return temp;
}
CircularInt& CircularInt::operator--() {
    currectNum--;
    this->refix();
    return *this;
}
CircularInt CircularInt::operator--(int) {
    CircularInt temp(*this);
    currectNum--;
    this->refix();
    return temp;
}

CircularInt CircularInt::operator+(const int &rhs) {
    CircularInt temp(*this);
    temp.currectNum+=rhs;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator+(const CircularInt &rhs) {
    CircularInt temp(*this);
    temp.currectNum+=rhs.currectNum;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator-() {
    CircularInt temp(*this);
    temp.currectNum=this->currectNum*-1;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator-(const int &rhs) {
    CircularInt temp(*this);
    temp.currectNum-=rhs;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator-(const CircularInt &rhs) {
    CircularInt temp(*this);
    temp.currectNum-=rhs.currectNum;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator*(const int &rhs) {
    CircularInt temp(*this);
    temp.currectNum*=rhs;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator*(const CircularInt &rhs) {
    CircularInt temp(*this);
    temp.currectNum*=rhs.currectNum;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator/(const int &rhs) {
    if(this->currectNum%rhs!=0)
        throw std::runtime_error("There is no number x in {" + to_string(firstNum)+","+to_string(lastNum)+"} such that x*"+to_string(rhs)+"="+to_string(currectNum));
    CircularInt temp(*this);
    temp.currectNum/=rhs;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator/(const CircularInt &rhs) {
    if(this->currectNum%rhs.currectNum!=0)
        throw std::runtime_error("There is no number x in {" + to_string(firstNum)+","+to_string(lastNum)+"} such that x*"+to_string(rhs.currectNum)+"="+to_string(currectNum));
    CircularInt temp(*this);
    temp.currectNum/=rhs.currectNum;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator%(const int &rhs) {
    CircularInt temp(*this);
    temp.currectNum%=rhs;
    temp.refix();
    return temp;
}
CircularInt CircularInt::operator%(const CircularInt &rhs) {
    CircularInt temp(*this);
    temp.currectNum%=rhs.currectNum;
    temp.refix();
    return temp;
}

ostream& operator<< (ostream& os, const CircularInt& cir){
    return os << cir.currectNum;
}
istream& operator>>(istream & input, CircularInt &D){
    int n;
    input >> n;
    D.currectNum = n;
    D.refix();
    return input;
}
CircularInt operator-(int lhs, const CircularInt & rhs){
    CircularInt res(rhs);
    res.currectNum = lhs - rhs.currectNum;
    res.refix();
    return res;
}

bool CircularInt::operator >(CircularInt const& b){
return this->currectNum > b.currectNum;
}
bool CircularInt::operator <(CircularInt const& b){
    return this->currectNum < b.currectNum;
}
bool CircularInt::operator >(int const& b){
    return this->currectNum > b;
}
bool CircularInt::operator <(int const& b){
    return this->currectNum < b;
}
bool CircularInt::operator >=(CircularInt const& b){
    return this->currectNum >= b.currectNum;
}
bool CircularInt::operator <=(CircularInt const& b){
    return this->currectNum <= b.currectNum;
}
bool CircularInt::operator >=(int const& b){
    return this->currectNum >= b;
}
bool CircularInt::operator <=(int const& b){
    return this->currectNum <= b;
}



