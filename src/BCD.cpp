#include "BCD.h"

std::string BCD::to_string_in_decimal() const {
    std::ostringstream oss;

    for(auto digit : digits_before_point) {
        oss << static_cast<int>(digit);
    }

    oss << '.';

    for(auto digit : digits_after_point) {
        oss << static_cast<int>(digit);
    }

    return oss.str();
}


std::string BCD::to_string_in_hexadecimal() const {
    std::ostringstream oss;

    oss << std::hex << std::setfill('0');

    for(auto digit : digits_before_point) {
        oss << std::setw(2) << static_cast<int>(digit);
    }

    oss << '.';

    for(auto digit : digits_after_point) {
        oss << std::setw(2) << static_cast<int>(digit);
    }

    return oss.str();
}


BCD::BCD(const std::string& number_string) {
    size_t i;
    for (i = 0; i < number_string.size(); ++i) {
        if (isdigit(number_string[i])) {
            digits_before_point.push_back(number_string[i] - '0');
        }
        else if (number_string[i] == '.') {
            break;
        }
    }
    for(; i< number_string.size(); ++i) {
        if (isdigit(number_string[i])) {
            digits_after_point.push_back(number_string[i] - '0');
        }
    }
}

BCD BCD::operator+(const BCD& other) const {
    return add(*this, other);
}

BCD BCD::operator-(const BCD& other) const {
    return subtract(*this, other);
}

BCD BCD::operator*(const BCD& other) const {
    return multiply(*this, other);
}

bool BCD::operator>(const BCD& other) const {
    if (this->digits_before_point.size() != other.digits_before_point.size())
        return this->digits_before_point.size() > other.digits_before_point.size();

    for (size_t i = 0; i < this->digits_before_point.size(); ++i) {
        if (this->digits_before_point[i] != other.digits_before_point[i])
            return this->digits_before_point[i] > other.digits_before_point[i];
    }

    for (size_t i = 0; i < this->digits_after_point.size(); ++i) {
        if (this->digits_after_point[i] != other.digits_after_point[i])
            return this->digits_after_point[i] > other.digits_after_point[i];
    }

    return false;
}
