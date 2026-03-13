#include "long_numbers.hpp"

using ttv::LongNumber;
		
LongNumber::LongNumber() : len(1), sign(1) {
	numbers = new int[len];
	numbers[0] = 0;
}

LongNumber::LongNumber(int len, int sign) : len(len), sign(sign) {
	numbers = new int[len];
	for (int i = 0; i < len; i++) {
		numbers[i] = 0;
	}
}

LongNumber::LongNumber(const char* const str) {
	int str_len = get_length(str);
	if (str[0] == '-') {
		sign = -1;
		len = str_len - 1;
	} else {
		sign = 1;
		len = str_len;
	}
	numbers = new int[len];
	for (int i = 0; i < len; i++) {
		numbers[i] = str[str_len - i - 1] - '0';
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	len=x.len;
	sign=x.sign;
	numbers = new int[len];
	for (int i = 0; i < len; i++) {
		numbers[i]=x.numbers[i];
	}

}

LongNumber::LongNumber(LongNumber&& x) {
	len=x.len;
	sign=x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
	x.len = 0;
}

LongNumber::~LongNumber() {
	delete[] numbers;
	len = 0;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	LongNumber temp(str);
	delete[] numbers;
	len = temp.len;
	sign = temp.sign;
	numbers = new int[len];
	for (int i = 0;i < len; i++) {
		numbers[i] = temp.numbers[i];
	}

	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this != &x) {
		delete[] numbers;
		len = x.len;
		sign = x.sign;
		numbers = new int[len];
		for (int i = 0; i < len; i++) {
			numbers[i] = x.numbers[i];
		}
	}
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	if (this != &x){
		delete[] numbers;
		len = x.len;
		sign = x.sign;
		numbers = x.numbers;
		x.numbers = nullptr;
		x.len = 0;
	}
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (sign != x.sign) {
		return false;
	}
	if (len != x.len) {
		return false;
	}
	for (int i = 0; i < len;i++) {
		if ( numbers[i] != x.numbers[i]){
			return false;
		}
	}
	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign != x.sign) {
		return sign > x.sign;
	}
	if (sign == 1){
		if (len != x.len) {
			return len > x.len;
		}
		for (int i = len - 1; i >= 0 ; i--) {
			if ( numbers[i] != x.numbers[i]){
				return numbers[i] > x.numbers[i];
			}
		}
		return false;
	}
	else {
		if (len != x.len) {
			return len < x.len;
		}
		for (int i = len - 1; i >= 0 ; i--) {
			if ( numbers[i] != x.numbers[i]){
				return numbers[i] < x.numbers[i];
			}
		}
		return false;
	}
}

bool LongNumber::operator < (const LongNumber& x) const {
	return !(*this > x) && !(*this == x);
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	LongNumber result;
	if (sign == x.sign) {
		int max_len = (len > x.len) ? len : x.len;
		LongNumber result(max_len + 1, sign);
		int carry = 0;
		for (int i = 0; i < max_len; i++) {
			int d1,d2;
			if ( i < len) {
				d1 = numbers[i];
			} else {
				d1 = 0;
			}
			if ( i < x.len) {
				d2 = x.numbers[i];
			} else {
				d2 = 0;
			}
			int sum  = d1 + d2 + carry;
			result.numbers[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry > 0) {
			result.numbers[max_len] = carry;
			return result;
		} else {
			LongNumber final_result(max_len, sign);
			for ( int i = 0;i < max_len; i++) {
				final_result.numbers[i] = result.numbers[i];
			}
			return final_result;
		}
	} else {
		LongNumber f1 = *this, f2 = x;
        f1.sign = f2.sign = 1;
        LongNumber sum;
        
        if (f1 > f2) {
            sum = LongNumber(len + 1, sign);
            for (int i = 0; i < len; i++)
                sum.numbers[i] = numbers[i];
            for (int i = 0; i < x.len; i++)
                sum.numbers[i] -= x.numbers[i];
        } else {
            sum = LongNumber(x.len + 1, x.sign);
            for (int i = 0; i < x.len; i++)
                sum.numbers[i] = x.numbers[i];
            for (int i = 0; i < len; i++)
                sum.numbers[i] -= numbers[i];
        }   
        for (int i = 0; i < sum.len - 1; i++) {
            while (sum.numbers[i] < 0) {
                sum.numbers[i] += 10;
                sum.numbers[i + 1]--;
            }
        }
		while (sum.len > 1 && sum.numbers[sum.len - 1] == 0) {
            sum.len--; 
		}     
        if (sum.len == 1 && sum.numbers[0] == 0){ 
            sum.sign = 1;  
		}   
        return sum;
	}
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	LongNumber negative_x = x;
    negative_x.sign = -x.sign;
	return *this + negative_x;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	LongNumber result(len + x.len, sign * x.sign);
	for (int i = 0; i < len; i++) {
        int carry = 0;
        for (int j = 0; j < x.len; j++) {
            int prod = numbers[i] * x.numbers[j] + result.numbers[i + j] + carry;
            result.numbers[i + j] = prod % 10;
            carry = prod / 10;
        }
        if (carry > 0) {
            result.numbers[i + x.len] += carry;
        }
    }
	while (result.len > 1 && result.numbers[result.len - 1] == 0) {
	    result.len--;
    }
	if (result.len == 1 && result.numbers[0] == 0) {
        result.sign = 1;
    }
    return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	if (x.len == 1 && x.numbers[0] == 0) {
        return LongNumber("0");
    }
	if (len == 1 && numbers[0] == 0) {
        return LongNumber("0");
    }
	LongNumber a = *this;
    LongNumber b = x;
    a.sign = 1;
    b.sign = 1;
	LongNumber res;
    if (b > a) {
        res = "0";
        res.sign = 1;
    } else {
		int razr1 = a.len;
        int razr2 = b.len;
        res = LongNumber(razr1 - razr2 + 1, 1);
		for (int i = razr1 - razr2; i >= 0; i--) {
			LongNumber vrem(razr2 + i, 1);
            for (int j = 0; j < razr2; j++) {
                vrem.numbers[j + i] = b.numbers[j];
            }
			int skolko = 0;
            while (!(a < vrem)) {
                a = a - vrem;
                skolko++;
            }
            res.numbers[i] = skolko;
        }
		 while (res.len > 1 && res.numbers[res.len - 1] == 0) {
            res.len --;
        }
    }
	LongNumber ostatok = a;

	if (sign == -1) {
		if (ostatok.len != 1 || ostatok.numbers[0] != 0) {
			ostatok = b - ostatok;
			res = res + LongNumber("1");
		}
	}
	res.sign = sign * x.sign;
    return res;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	LongNumber quotient = *this / x;
	LongNumber product = quotient * x;
	LongNumber remainder = *this - product;
	return remainder;
}

bool LongNumber::is_negative() const noexcept {
    return sign == -1;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------

int LongNumber::get_length(const char* const str) const noexcept {
	int l = 0;
	while (str[l] != '\0') {
		++l;
	}
	return l;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace ttv {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.is_negative()) {
            os << '-';
        }
		for (int i = x.len - 1; i >= 0; i--) {
            os << x.numbers[i];
        }   
        return os; 
	}
}
