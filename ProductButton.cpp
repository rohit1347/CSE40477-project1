/*
* Vending Machine Project
* CSE-40477
*
* ProductButton.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
using std::strcpy;

#include "ProductButton.h"

Project1::ProductButton::ProductButton(ProductRack &productRack)
    : productRack(productRack)
{
    
    // TODO: Implement
}

bool
Project1::ProductButton::press()
{
    
    // TODO: Implement
    return productRack.deliverProduct();
}

unsigned
Project1::ProductButton::getProductPriceCents() const
{
    // TODO: Implement
    return productRack.getProductPriceCents();
}
