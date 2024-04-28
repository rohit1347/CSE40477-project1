/*
 * Vending Machine Project
 * CSE-40477
 *
 * DeliveryChute.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include "DeliveryChute.h"

Project1::DeliveryChute::DeliveryChute(StatusPanel &statusPanel)
    : statusPanel(statusPanel),
      pProduct(0)
{
    // TODO: Implement
}

Project1::DeliveryChute::~DeliveryChute()
{
    // TODO: Implement
    delete this->pProduct;
}

bool Project1::DeliveryChute::insertProduct(Product *pProduct)
{
    // TODO: Implement
    if (this->pProduct == nullptr)
    {
        this->pProduct = pProduct;
        return true;
    }
    else
    {
        this->statusPanel.displayMessage(StatusPanel::MESSAGECODE_CHUTE_FULL);
        return false;
    }
}

Project1::Product *
Project1::DeliveryChute::retrieveProduct()
{
    // TODO: Implement
    if (!DeliveryChute::containsProduct())
    {
        return 0;
    }
    else
    {
        Product *temp=pProduct;
        pProduct=0;
        return temp;
    }
}

bool Project1::DeliveryChute::containsProduct() const
{
    // TODO: Implement
    if (this->pProduct == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}