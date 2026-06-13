#include "String.h"

#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <iostream>
// #pragma warning(disable: 4996)

static unsigned roundToPowerOfTwo(unsigned n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
    return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}

String::String(size_t stringLength)
{
    allocatedDataCapacity = dataToAllocByStringLen(stringLength);
    data = new char[allocatedDataCapacity];
    data[0] = '\0';
}

void String::resize(size_t newAllocatedDataCapacity)
{
    char* resizedData = new char[newAllocatedDataCapacity];
    if (data) {
        strcpy(resizedData, data);
    } else {
        resizedData[0] = '\0';
    }

    delete[] data;
    data = resizedData;
    allocatedDataCapacity = newAllocatedDataCapacity;
}

void String::free() {
    delete[] data;
    data = nullptr;
    currentSize = allocatedDataCapacity = 0;
}

void String::copyFrom(const String& other) {
    currentSize = other.currentSize;
    allocatedDataCapacity = other.allocatedDataCapacity;
    data = new char[allocatedDataCapacity];
    strcpy(data, other.c_str());
}

void String::moveFrom(String&& other) noexcept {
    currentSize = other.currentSize;
    allocatedDataCapacity = other.allocatedDataCapacity;
    data = other.data;
    other.data = nullptr;
    other.currentSize = other.allocatedDataCapacity = 0;
}

String::String() : String("") {}

String::String(const char* str)
{
    currentSize = strlen(str);
    allocatedDataCapacity = dataToAllocByStringLen(currentSize);
    data = new char[allocatedDataCapacity];
    strcpy(data, str);
}

String::String(const String& other)
{
    copyFrom(other);
}

String& String::operator=(const String& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

String::String(String&& other) noexcept {
    moveFrom(std::move(other));
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

String::~String()
{
    free();
}

size_t String::length() const
{
    return currentSize;
}

const char* String::c_str() const
{
    return data ? data : "";
}

bool String::endsWith(const String &other) const {
    if (other.length() > length()) {
        return false;
    }

    size_t startIndex = length() - other.length();
    for (size_t i = 0; i < other.length(); i++) {
        if (data[startIndex + i] != other[i]) {
            return false;
        }
    }
    return true;
    // banana.joe - 10
}

String& String::operator+=(const String& other)
{
    if (currentSize + other.currentSize + 1 > allocatedDataCapacity) {
        resize(dataToAllocByStringLen(currentSize + other.currentSize));
    }

    strncat(data, other.data, other.currentSize);
    currentSize += other.currentSize;

    return *this;
}

char& String::operator[](size_t index)
{
    if (index >= currentSize) {
        throw std::out_of_range("Invalid index!");
    }
    return data[index];
}

char String::operator[](size_t index) const
{
    if (index >= currentSize) {
        throw std::out_of_range("Invalid index!");
    }
    return data[index];
}

String operator+(const String& lhs, const String& rhs)
{
    String result(lhs.length() + rhs.length());
    result += lhs;
    result += rhs;
    return result;
}

std::istream& getline(std::istream& is, String& str) {
    std::string temp;
    std::getline(is, temp);

    str = temp.c_str();
    return is;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.c_str();
    return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
    char buff[1024];
    is >> buff;
    size_t buffLength = strlen(buff);

    if (buffLength > str.allocatedDataCapacity) {
        str.resize(dataToAllocByStringLen(buffLength));
    }

    strcpy(str.data, buff);
    str.currentSize = buffLength;

    return is;
}

bool operator==(const String& lhs, const String& rhs)
{
    if (lhs.length() != rhs.length()) {
        return false;
    }
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

std::strong_ordering operator<=>(const String& lhs, const String& rhs) {
    int cmp = strcmp(lhs.c_str(), rhs.c_str());

    if (cmp < 0) {
        return std::strong_ordering::less;
    }
    if (cmp > 0) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}