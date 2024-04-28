/*
 * Vending Machine Project
 * CSE-40477
 *
 * VendingMachine.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include "VendingMachine.h"
#include<iostream>

Project1::VendingMachine::VendingMachine(
    ostream &statusPanelStream,
    const char *productNames[NUM_PRODUCT_RACKS],
    unsigned productPrices[NUM_PRODUCT_RACKS])
    : statusPanel(statusPanelStream),
      deliveryChute(statusPanel),
      numCoins(0),
      unspentMoneyCents(0)
{
    for(int i=0;i<NUM_PRODUCT_RACKS;++i)
    {
        this->productRacks[i]=new ProductRack(statusPanel,productNames[i],deliveryChute,productPrices[i]);
        this->productButtons[i]=new ProductButton(*productRacks[i]);
    }
    // TODO: Implement
}

Project1::VendingMachine::~VendingMachine()
{
    // TODO: Implement
}

bool Project1::VendingMachine::insertCoin(Coin *pCoin)
{
    // TODO: Implement
    if (pCoin->getDenomination() == Coin::COINTYPE_WOODEN_NICKEL)
    {
        this->statusPanel.displayMessage(StatusPanel::MESSAGECODE_BAD_COIN);
        return false;
    }
    else
    {
        this->coinBox[numCoins] = pCoin;
        this->numCoins++;
        this->unspentMoneyCents += pCoin->getValueCents();
        return true;
    }
    return false;
}

bool Project1::VendingMachine::pressButton(int button)
{
    if (button < 0 || button >= NUM_PRODUCT_RACKS)
    {
        this->statusPanel.displayMessage(StatusPanel::MESSAGECODE_WRONG_BUTTON);
        return false;
    }
    else if (this->unspentMoneyCents < this->productRacks[button]->getProductPriceCents())
    {
        this->statusPanel.displayMessage(StatusPanel::MESSAGECODE_INSUFFICIENT_MONEY);
        return false;
    }
    else
    {
        this->productButtons[button]->press();
        this->unspentMoneyCents -= productRacks[button]->getProductPriceCents();
        return true;
    }
    // // TODO: Implement
    return false;
}

Project1::Product *
Project1::VendingMachine::retrieveProduct()
{
    return this->deliveryChute.retrieveProduct();
}

bool Project1::VendingMachine::addProduct(Product *pProduct)
{
    for (int i = 0; i < NUM_PRODUCT_RACKS; ++i)
    {
        if (this->productRacks[i]->isCompatibleProduct(pProduct->getName()))
        {
            if (this->productRacks[i]->addProduct(pProduct))
            {
                return true;
            }
        }
    }
    return false;
}

unsigned
Project1::VendingMachine::getProductCount(const char *productName) const
{
    for (int i = 0; i < NUM_PRODUCT_RACKS; ++i)
    {
        if (this->productRacks[i]->isCompatibleProduct(productName))
        {
            return this->productRacks[i]->getNumProductsInRack();
        }
    }
    return 0;
}

unsigned
Project1::VendingMachine::countTill() const
{
    int sum = 0;
    for (int i = 0; i < this->numCoins; ++i)
    {
        sum += this->coinBox[i]->getValueCents();
    }
    return sum;
}

unsigned
Project1::VendingMachine::getNumCoinsInCoinBox() const
{
    return this->numCoins;
}
