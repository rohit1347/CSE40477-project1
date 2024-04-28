/*
 * Vending Machine Project
 * CSE-40477
 *
 * ProductRack.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include <cstring>
#include <iostream>
#include<set>
using std::strcmp;
using std::strncpy;

#include "ProductRack.h"

Project1::ProductRack::ProductRack(
    StatusPanel &statusPanel,
    const char *allowedProductName,
    DeliveryChute &deliveryChute,
    unsigned productPriceCents)
    : statusPanel(statusPanel),
      deliveryChute(deliveryChute),
      productPriceCents(productPriceCents)
{
    strncpy(this->allowedProductName, allowedProductName, Product::MAX_NAME_LENGTH - 1);
    for (int i = 0; i < MAX_PRODUCTS; ++i)
    {
        this->products[i] = 0;
        this->productCount = 0;
    }
}

Project1::ProductRack::~ProductRack()
{
    std::set<Product*> deletedProducts;
    for (int i = 0; i < MAX_PRODUCTS; ++i)
    {
        if (products[i] != nullptr && deletedProducts.find(products[i]) == deletedProducts.end())
        {
            delete products[i];
            deletedProducts.insert(products[i]);
        }
    }
    productCount = 0;
}

bool Project1::ProductRack::isCompatibleProduct(const char *productName) const
{
    if (!strcmp(allowedProductName, productName))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Project1::ProductRack::isFull() const
{
    return this->productCount == MAX_PRODUCTS;
}

bool Project1::ProductRack::isEmpty() const
{
    return this->productCount == 0;
}

bool Project1::ProductRack::addProduct(Product *pProduct)
{
    // TODO: Implement
    if (ProductRack::isFull())
    {
        this->statusPanel.displayMessage(StatusPanel::MESSAGECODE_RACK_IS_FULL);
        return false;
    }
    else if (!isCompatibleProduct(pProduct->getName()))
    {
        this->statusPanel.displayMessage(StatusPanel::MESSAGECODE_PRODUCT_DOES_NOT_MATCH_PRODUCT_RACK);
        return false;
    }
    else
    {
        for (int i = 0; i < MAX_PRODUCTS; ++i)
        {
            if (this->products[i] == 0)
            {
                this->products[i] = pProduct;
                this->productCount++;
                return true;
            }
        }
    }
    return false;
}
bool Project1::ProductRack::deliverProduct()
{
    if (this->isEmpty())
    {
        this->statusPanel.displayMessage(StatusPanel::MESSAGECODE_SOLD_OUT);
        return false;
    }

    else if (deliveryChute.insertProduct(products[0])) // Assuming FIFO delivery
    {
        // Shift all products down after delivery
        for (int i = 0; i < productCount - 1; ++i)
        {
            products[i] = products[i + 1];
        }
        // Set the last product to nullptr
        products[productCount - 1] = 0;
        productCount--;
        return true;
    }
    return false;
}

unsigned
Project1::ProductRack::getNumProductsInRack() const
{
    return this->productCount;
}

unsigned
Project1::ProductRack::getProductPriceCents() const
{
    // TODO: Implement
    return this->productPriceCents;
}
