/*
 * Vending Machine Project
 * CSE-40477
 *
 * Product.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include <cstring>
using std::strcpy;

#include "Product.h"

Project1::Product::Product(const char *brand, const char *name, const char *size)
{
    strncpy(this->brand, brand,MAX_BRAND_LENGTH-1);
    strncpy(this->name, name,MAX_NAME_LENGTH-1);
    strncpy(this->size, size,MAX_SIZE_LENGTH-1);
}

const char *
Project1::Product::getBrand() const
{
    // TODO: Implement
    return this->brand;
    // return "";
}

void Project1::Product::setBrand(const char *value)
{
    // TODO: Implement
    strncpy(this->brand,value,MAX_BRAND_LENGTH-1);
}

const char *
Project1::Product::getName() const
{
    // TODO: Implement
    return this->name;
}

void Project1::Product::setName(const char *value)
{
    // TODO: Implement
    strncpy(this->name,value,MAX_NAME_LENGTH-1);
}

const char *
Project1::Product::getSize() const
{
    // TODO: Implement
    return this->size;
}

void Project1::Product::setSize(const char *value)
{
    // TODO: Implement
    strncpy(this->size,value,MAX_SIZE_LENGTH-1);
}
